#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    grabber.setup(1280, 720);
    grabberPix.allocate(grabber.getWidth(), grabber.getHeight(), OF_PIXELS_RGB);
    texture.allocate(grabberPix.getWidth(), grabberPix.getHeight(), GL_RGB);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    grabber.update();
    
    if(grabber.isFrameNew()) {
        
        grabberPix = grabber.getPixels();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    float spacing = ofClamp(ofMap(ofGetMouseX(), 0, ofGetWidth(), 10, 200), 10, 200);
    
    for (int y = 0; y < grabberPix.getHeight(); y+=spacing)
    {
        for(int x = 0; x < grabberPix.getWidth(); x+=spacing)
        {
            ofColor currColor = grabberPix.getColor(x, y);
            float brightness = currColor.getBrightness();
            
            float size = ofMap(brightness, 0, 255, 1, 50);
            
            ofPushMatrix();
                ofTranslate(ofGetWidth(), 0);
                ofScale(-1, 1);
                ofPushMatrix();
                    ofTranslate(x, y);
                    ofSetColor(currColor);
                    ofDrawRectangle(0, 0, size, size);
                ofPopMatrix();
            ofPopMatrix();
        }
    }
    

}
