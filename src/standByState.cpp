#include "standbyState.h"
#include "runningState.h"

StandbyState::StandbyState(App *a):BaseState(){
    BaseState::initialize();
    app = a;
};

StandbyState::~StandbyState(){
};

void StandbyState::draw(){
    ofClear(0);
    ofTrueTypeFont *font = Assets::getInstance()->getFont(50);
    
    string msg = "KILL THE RED BALLS";
    
    font->drawString(msg, ofGetWidth()/2 - font->stringWidth(msg)/2, ofGetHeight()/2);
    
};

void StandbyState::update(){
};

void StandbyState::next(){
    app->setCurrentState(new RunningState(app));
    delete this;
};

