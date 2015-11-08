#include "BaseOscAdapter.h"
#include "assets.h"

BaseOscAdapter::BaseOscAdapter(App *a){
    app = a;
    int localPort = Assets::getInstance()->getLocalPort();
    receiver = new ofxOscReceiver;
    receiver->setup(localPort);
    
    ofLogNotice() << "listening for osc messages on port " << localPort;
    bOnline = false;
    
    ofAddListener(ofEvents().update, this, &BaseOscAdapter::update);
}

BaseOscAdapter::~BaseOscAdapter(){
    delete receiver;
}

void BaseOscAdapter::update(ofEventArgs &args){
    if(ofGetFrameNum() % 100 == 0)
        bOnline = false;
    
    while(receiver->hasWaitingMessages()){
        bOnline = true;
        ofxOscMessage m;
        receiver->getNextMessage(&m);
        
    }
}
