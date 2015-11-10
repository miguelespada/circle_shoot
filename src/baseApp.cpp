#include "baseApp.h"


BaseApp::BaseApp(){
    
    ofLogNotice() << "Initializing app...";
    
    assets = (Assets *)Assets::getInstance();
    
    // Register events and actions
    ofAddListener(ofEvents().keyPressed, this, &BaseApp::keyPressed);
    ofAddListener(ofEvents().keyReleased, this, &BaseApp::keyReleased);
    ofAddListener(ofEvents().update, this, &BaseApp::update);
    
    current_state = NULL;
    for(int i = 0; i < 1024; i ++)
        keys[i] = false;
    
    
}

void BaseApp::setCurrentState(BaseState *s){
    current_state = s;
}

void BaseApp::next(){
    if(current_state)
        current_state->next();
}


void BaseApp::update(){
    if(current_state)
        current_state->update();
}

void BaseApp::update(ofEventArgs &args){
    update();
}

void BaseApp::keyPressed (ofKeyEventArgs& eventArgs){
    
    if(eventArgs.key < 1024){
        keys[eventArgs.key] = true;
    }
    keyPressed(eventArgs.key);
}

void BaseApp::keyReleased (ofKeyEventArgs& eventArgs){
    
    if(eventArgs.key < 1024){
        keys[eventArgs.key] = false;
    }
}

void BaseApp::draw(){
    ofPushStyle();
    ofPushMatrix();
    
    if(current_state)
        current_state->draw();
    
    ofPopMatrix();
    ofPopStyle();
}

Assets * BaseApp::getAssets(){
    return assets;
}