#include "runningState.h"
#include "scoreState.h"

RunningState::RunningState(App *a):BaseState(){
    BaseState::initialize();
    app = a;
   app->newGame();
};

RunningState::~RunningState(){
};

void RunningState::draw(){
    ofClear(0);
    app->drawFrame();
    app->drawPlayer();
    
    ofPushStyle();
    ofSetColor(0);
    ofTrueTypeFont *font = Assets::getInstance()->getFont(400);
    string msg = ofToString(app->getScore());
    font->drawString(msg, ofGetWidth()/2 - font->stringWidth(msg)/2, ofGetHeight()/2 + font->stringHeight(msg)/2);
    ofPopStyle();
};

void RunningState::update(){
    app->updateGame();
};

void RunningState::next(){
    app->setCurrentState(new ScoreState(app));
    delete this;
};

void RunningState::fire(){
    app->fire();
}
