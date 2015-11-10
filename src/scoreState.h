
#ifndef __score__state__
#define __score__state__

#include "baseState.h"
#include "app.h"

class ScoreState: public BaseState
{
    App *app;
    
public:
    ScoreState(App *a);
    ~ScoreState();
    string toString() { return "score"; }
    void update();
    void draw();
    void next();
};

#endif