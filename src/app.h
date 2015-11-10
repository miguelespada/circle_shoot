#ifndef __app__
#define __app__

#include "baseApp.h"
#include "player.hpp"
#include "ball.hpp"
#define SCORE 10


class App: public BaseApp
{
    
public:
    App();
    ~App();
    void keyPressed(int key);
    
    void newGame();
    void updateGame();
    void updatePlayer();
    
    void drawFrame();
    void drawPlayer();
    bool contact(Projectile *p, Ball *b);
    
    Player *player_u;
    Player *player_d;
    
    vector<Projectile *> projectiles;
    vector<Ball *> balls;
    void gc();
    void fire();
    int getScore();
};


#endif
