#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    //ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    float size = ofMap(ofGetMouseY(), 10, ofGetHeight()-10, 0, 600);
    
    float dx = ofMap(ofGetMouseX(), 10, ofGetWidth(), 1, 10);
    
    xPos+=dx;
    r+=rotation;
    
    ofPushMatrix();
        ofPushStyle();
        ofTranslate(xPos, ofGetHeight()/2);
            ofSetRectMode(OF_RECTMODE_CENTER);
    
            ofNoFill();
    ofSetColor(ofColor::fromHsb(ofMap(xPos, 0, ofGetWidth(), 0, 255), 255, 255));
            ofRotateDeg(r);
            ofDrawRectangle(0, 0, size, size);
        ofPopStyle();
    ofPopMatrix();
    
    
    
    // reset
    if(xPos > ofGetWidth())
    {
        xPos = 0;
        ofSetColor(255);
        ofFill();
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'q')
    {
        rotation-=.25;
    }
    else if (key == 'w') {
        rotation+=.25;
        
    }
    

}
