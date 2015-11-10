#include "app.h"

#define LEFT_KEY 356
#define RIGHT_KEY 358

App::App():BaseApp(){
}

App::~App(){
}

void App::keyPressed (int key){
    switch (key) {
        case ' ':
            current_state->fire();
            break;
    
        default:
            break;
    }
}

void App::fire(){
    projectiles.push_back(player_u->newProjectile());
    projectiles.push_back(player_d->newProjectile());
    
    for(vector<Ball *>::iterator it = balls.begin(); it != balls.end(); ++it){
        Ball *b = (*it);
        projectiles.push_back(b->newProjectile());
    }
}

void App::newGame(){
    player_u = new Player(90);
    
    player_d = new Player(-90);
    balls.clear();
    projectiles.clear();
}

void App::updateGame(){
    
    if(keys[' '])
        current_state->fire();

        
    if(keys[LEFT_KEY]){
        player_d->up();
        player_u->up();
    }
    
    if(keys[RIGHT_KEY]){
        player_d->down();
        player_u->down();
    }
    
    if(ofGetFrameNum() %  60 == 0)
        balls.push_back(new Ball());
    
    updatePlayer();
    
    gc();
}

void App::updatePlayer(){
    
    
    
    player_d->update();
    player_u->update();
    
    for(vector<Projectile *>::iterator it = projectiles.begin(); it != projectiles.end(); ++it){
        Projectile *p = (*it);
        p->update();

      
        if(player_u->contact(p) || player_d->contact(p)){
            current_state->next();
            break;
        }
    }
    
    for(vector<Ball *>::iterator it = balls.begin(); it != balls.end(); ++it){
        Ball *b = (*it);
        b->update();
        
        for(vector<Projectile *>::iterator it2 = projectiles.begin(); it2 != projectiles.end(); ++it2){
            Projectile *p = (*it2);
            if(p->contact(b)){
                player_u->incScore();
            }
        }
    }
    
    
    
}

void App::gc(){
    for(vector<Projectile *>::iterator it = projectiles.begin(); it != projectiles.end(); ){
        if((*it)->bContact)
            it = projectiles.erase(it);
        else
            ++it;
    }
    
    for(vector<Ball *>::iterator it = balls.begin(); it != balls.end();){
        if((*it)->bContact)
            it = balls.erase(it);
        else
            ++it;
    }
}



void App::drawFrame(){
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(255);
    ofCircle(0, 0, ofGetWidth()/2 - 5);
    ofPopStyle();
    ofPopMatrix();
}


void App::drawPlayer(){
    
    player_u->draw();
    player_d->draw();
    
    for(vector<Projectile *>::iterator it = projectiles.begin(); it != projectiles.end(); ++it)
        (*it)->draw();
    
    
    for(vector<Ball *>::iterator it = balls.begin(); it != balls.end(); ++it)
        (*it)->draw();
    
}

int App::getScore(){
    return player_u->getScore();
}
