class Player
{
    float angle;
    float speed;
    
public:
    Player(){
        angle = 0;
        speed = 0;
    }
    
    void draw(){
        
        angle += speed;
        
        ofPushMatrix();
        ofPushStyle();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofSetColor(255, 0, 0);
        
        float x = (ofGetWidth()/2 - 35) * cos(ofDegToRad(angle));
        float y = (ofGetWidth()/2 - 35) * sin(ofDegToRad(angle));
        
        ofSetColor(255, 0, 0);
        
        ofTranslate(x, y);
        
        ofRotate(ofRadToDeg(-atan2(x, y)));
        ofCircle(0, 0, 25);
        
        ofSetColor(0);
        ofLine(0, 0, 0, -500);
        
        ofPopStyle();
        ofPopMatrix();
    }
    
    void up(){
        speed = 2;
    }
    
    
    void down(){
        speed = -2;
    }
    
};


