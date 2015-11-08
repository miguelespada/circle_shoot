#include "ofApp.h"
#include "standByState.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    
    ofLogNotice() << "Running app";
    app = new App();
    
    
    app->setCurrentState(new StandbyState(app));
    
    osc = new OscAdapter(app);
    gui = new Gui(app);
    
    bFull = false;
    ofSetBackgroundAuto(false);
    ofSetWindowPosition(0, 0);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    app->draw();
    gui->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
            
        case 'f':
            bFull = !bFull;
            setFullScreen();
            break;
            
        case 's':
            gui->save();
            break;
            
        case 'l':
            gui->load();
            break;
            
        case '0':
            gui->toggleVisibility();
            break;
            
            
        default:
            break;
    }
}

void ofApp::setFullScreen(){
    if(bFull){
        ofSetFullscreen(true);
    }
    else{
        ofSetFullscreen(false);
    }
    
}