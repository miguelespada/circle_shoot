
#ifndef __OscAdapter__
#define __OscAdapter__

#include "ofMain.h"
#include "ofxOsc.h"
#include "app.h"


class BaseOscAdapter{
    ofxOscReceiver *receiver;
    App *app;
    
public:
    BaseOscAdapter(App *a);
    ~BaseOscAdapter();
    bool bOnline;
    virtual void update(ofEventArgs &args);
    virtual void processOscMessage(ofxOscMessage m)=0;
    
};

#endif 