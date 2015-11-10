#include "object.hpp"

class Projectile: public Object{
    static const int R = 5;
    int speed = 5;
    int dir;
public:
    
    Projectile(float a, int init_h, int _dir = 1 ){
        h = init_h;
        angle = a;
        dir = _dir;
        
    }
    
    void update(){
        bContact = false;
        h -= speed * dir;
        x = h * cos(ofDegToRad(angle));
        y = h * sin(ofDegToRad(angle));
        
    }
    
    void draw(){
        
        ofPushMatrix();
        ofPushStyle();
        
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        
        ofTranslate(x, y);
        
        ofSetColor(0);
        
        ofCircle(0, 0, getRadious());
        
        ofEnableAlphaBlending();
        ofSetColor(0, 30);
        
        ofLine(0, 0, x, y);
        ofPopStyle();
        ofPopMatrix();
    }
  
    
    int getRadious(){
        return R;
    }
};