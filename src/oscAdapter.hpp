#include "BaseOscAdapter.h"

class OscAdapter: public BaseOscAdapter
{
public:
    OscAdapter(App *app):BaseOscAdapter(app){}
    
    void processOscMessage(ofxOscMessage m){
    }
};
