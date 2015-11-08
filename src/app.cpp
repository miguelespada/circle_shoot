#include "app.h"


App::App():BaseApp(){
    ofSetCircleResolution(300);

}

App::~App(){
}

void App::keyPressed (int key){
    switch (key) {
        case 'w':
            p.up();
            break;
        case 's':
            p.down();
            break;
            
        default:
            break;
    }
}

void App::update(){
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
    
    p.draw();
    
}