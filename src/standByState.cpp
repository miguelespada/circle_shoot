#include "standbyState.h"

StandbyState::StandbyState(App *a):BaseState(){
    BaseState::initialize();
    app = a;
};

StandbyState::~StandbyState(){
};

void StandbyState::draw(){
    ofClear(0);
    app->drawFrame();
    app->drawPlayer();
};

void StandbyState::update(){
};

void StandbyState::next(){
};

