#ifndef __app__
#define __app__

#include "baseApp.h"
#include "player.hpp"


class App: public BaseApp
{
    
public:
    App();
    ~App();
    void keyPressed(int key);
    void update();
    
    void drawFrame();
    void drawPlayer();
    
    Player p;
    
};


#endif
