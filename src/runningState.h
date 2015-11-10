
#ifndef __running__state__
#define __running__state__

#include "baseState.h"
#include "app.h"

class RunningState: public BaseState
{
    App *app;
    
public:
    RunningState(App *a);
    ~RunningState();
    string toString() { return "running"; }
    void update();
    void draw();
    void next();
    void fire();
};

#endif