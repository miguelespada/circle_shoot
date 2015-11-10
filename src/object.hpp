#include "ofMain.h"

class Object
{
    
public:
    bool bContact = false;
    float x;
    float y;
    float angle;
    float speed;
    float h;
    
    
    Object(){
    };
    
    virtual ~Object(){};
    
    void setContact(){
        bContact = true;
    }
    
    ofPoint getCenter(){
        return  ofPoint(x, y);
    }
    
    virtual int getRadious()=0;
    
    bool contact(Object *o){
        if(bContact || o->bContact)
            return false;
        
        if(getCenter().distance(o->getCenter()) < getRadious() + o->getRadious()){
            setContact();
            o->setContact();
            return true;
        }
        return false;
    }
};

