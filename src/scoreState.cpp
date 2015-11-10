#include "scoreState.h"
#include "runningState.h"


ScoreState::ScoreState(App *a):BaseState(){
    BaseState::initialize();
    app = a;
};

ScoreState::~ScoreState(){
};

void ScoreState::draw(){
    ofClear(0);
    ofTrueTypeFont *font = Assets::getInstance()->getFont(400);
    
    ofSetColor(255);
    
    string msg = ofToString(app->getScore());
    font->drawString(msg, ofGetWidth()/2 - font->stringWidth(msg)/2, ofGetHeight()/2 + font->stringHeight(msg)/2);
    
  
    
};

void ScoreState::update(){
};

void ScoreState::next(){
    app->setCurrentState(new RunningState(app));
    delete this;
};

