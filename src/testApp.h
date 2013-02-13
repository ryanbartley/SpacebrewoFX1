#pragma once

#include "ofMain.h"
#include "ofxSpacebrew.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
    Spacebrew::Connection spacebrew;
    
    void onMessage( Spacebrew::Message& m );
    
    int radius;
    bool bButtonPressed;
    bool bBackgroundOn;
    
    bool checkInsideCircle( ofPoint, ofPoint, int );
    
		
};
