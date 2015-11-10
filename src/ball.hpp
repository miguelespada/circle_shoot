class Ball: public Object{
    
public:
    
    Ball(){
        angle = int(ofRandom(360 / 18)) * 18;
        
        int r = ofRandom(3);
        h =  150;
        if(ofRandom(1) > 0.5)
            speed = 3;
        else
            speed = -3;
    }
    
    void update(){
        bContact = false;
        angle += speed;
        x = h * cos(ofDegToRad(angle));
        y = h * sin(ofDegToRad(angle));
    }
    
    void draw(){
        
        ofPushMatrix();
        ofPushStyle();
        
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
        ofTranslate(x, y);
        
        ofSetColor(255,0,0);
        
        
        ofCircle(0, 0, getRadious());
        
        ofPopStyle();
        ofPopMatrix();
    }

    int getRadious(){
        return 15;
    }
    
    Projectile *newProjectile(){
        return new Projectile(angle, h + getRadious() , -1);
    }
    
};