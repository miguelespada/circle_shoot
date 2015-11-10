#ifndef __State__
#define __State__

#include "ofMain.h"

class App;

class BaseState
{
    
protected:
    float timer;
    
public:
    BaseState();
    virtual ~BaseState();
    
    bool isDone(int duration);
    void initialize();
    
    virtual void start(){};
    
    virtual void next()=0;
    virtual string toString()=0;
    virtual void draw()=0;
    virtual void update()=0;
    virtual void reset(){};
    virtual void fire(){
        next();
    }
};


#endif