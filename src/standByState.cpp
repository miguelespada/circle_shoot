#include "standbyState.h"

StandbyState::StandbyState(App *a):BaseState(){
    BaseState::initialize();
    app = a;
};

StandbyState::~StandbyState(){
};

void StandbyState::draw(){
    ofClear(255);
};

void StandbyState::update(){
};

void StandbyState::next(){
};

