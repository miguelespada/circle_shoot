#pragma once

#include "ofMain.h"
#include "app.h"
#include "oscAdapter.hpp"
#include "gui.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		
        App *app;
    
        OscAdapter *osc;
        Gui *gui;
    
        bool bFull;
        void setFullScreen();
    
    
};
