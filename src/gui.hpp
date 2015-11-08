#include "ofxGui.h"
#include "app.h"

class Gui
{
    ofxPanel gui;
    App *app;
    bool bVisible;
    
public:
    
    Gui(App *a){
        app = a;
        gui.setup();
        
        bVisible = true;
        load();
    }
    
    void draw(){
        if(bVisible)
            gui.draw();
    }
    
    void load(){
        string path = ofToDataPath("gui.xml");
        ofLogNotice() << "Loading gui from: " << path;
        gui.loadFromFile(path);
    }
    
    void save(){
        string path = ofToDataPath("gui.xml");
        ofLogNotice() << "Saving gui to: " << path;
        gui.saveToFile(path);
    }
    
    void toggleVisibility(){
        bVisible = !bVisible;
    }
    
};

