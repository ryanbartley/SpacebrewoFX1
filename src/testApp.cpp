#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
    string host = "54.235.111.53";
    string name = "of-button-example";
    string description = "It's amazing";
    
    spacebrew.addPublish("button", Spacebrew::TYPE_BOOLEAN);
    spacebrew.addSubscribe("backgroundOn", Spacebrew::TYPE_BOOLEAN);
    spacebrew.connect(host, name, description);
    
    Spacebrew::addListener(this, spacebrew);
    
    bButtonPressed  = false;
    radius          = 200;
    
    bBackgroundOn   = false;
    
    ofBackground(0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofEnableSmoothing();
    ofSetCircleResolution(100);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    if ( !bBackgroundOn ) {
        ofBackgroundGradient(ofColor(0,0,0), ofColor(50,50,50));
    } else {
        ofBackgroundGradient(ofColor(100,0,0), ofColor(150,150,150));
    }
    
    string textToDraw = "PRESS ME";
    if ( bButtonPressed ) {
        ofSetColor(150, 0, 0);
        textToDraw = "THANKS";
    } else {
        ofSetColor(150);
    }
    ofCircle(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f, radius);
    ofSetColor(255);
    ofDrawBitmapString(textToDraw, ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
}

void testApp::onMessage( Spacebrew::Message & m ) {
    if (m.name == "backgroundOn")
        bBackgroundOn = m.valueBoolean();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    if ( checkInsideCircle(ofPoint(x,y), ofPoint(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f), radius)) {
        bButtonPressed = true;
        spacebrew.sendBoolean("button", true);
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    if (bButtonPressed) {
        spacebrew.sendBoolean("button", false);
    }
    bButtonPressed = false;
}

bool testApp::checkInsideCircle(ofPoint point, ofPoint position, int radius) {
    return ( point.x < position.x + radius
            && point.x > position.x - radius
            && point.y < position.y + radius
            && point.y > position.y - radius);
}