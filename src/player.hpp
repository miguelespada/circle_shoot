#include "projectile.hpp"

class Player: public Object{

    int score;
public:
    
    Player(int a){
        angle = a;
        speed = 2;
        score = 0;
        bContact = false;
    }
    
    void update(){
        bContact = false;
        x = (ofGetWidth()/2 - 35) * cos(ofDegToRad(angle));
        y = (ofGetWidth()/2 - 35) * sin(ofDegToRad(angle));
    }
    
    void draw(){
        drawCircle();
    }
    
    void drawCircle(){
        
        ofPushMatrix();
        ofPushStyle();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofSetColor(0 );
    
        
        ofTranslate(x, y);
        
        ofRotate(ofRadToDeg(-atan2(x, y)));
        ofCircle(0, 0, getRadious());
        
        
        ofSetColor(0);
        ofPopStyle();
        ofPopMatrix();
    }
    
    void up(){
        angle += speed;
    }
    
    
    void down(){
        angle -= speed;
    }
    
    float getAngle(){
        return angle;
    }
    
    void incScore(){
        score ++;
    }
    
    int getRadious(){
        return 25;
    }
    
    Projectile *newProjectile(){
        return new Projectile(angle, ofGetHeight()/2 - (getRadious() * 2 + 15)  );
    }
    
    void die(){
    }
    
    int getScore(){
        return score;
    }
};


