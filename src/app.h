#ifndef __app__
#define __app__

#include "baseApp.h"


class App: public BaseApp
{
    
public:
    App();
    ~App();
    void keyPressed(int key);
    
    void update();
    
    
};


#endif
