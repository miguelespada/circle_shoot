
#ifndef __standby__state__
#define __standby__state__

#include "baseState.h"
#include "app.h"

class StandbyState: public BaseState
{
    App *app;
    
public:
    StandbyState(App *a);
    ~StandbyState();
    string toString() { return "stand by"; }
    void update();
    void draw();
    void next();
};

#endif