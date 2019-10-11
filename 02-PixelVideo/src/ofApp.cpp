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
    
    
    if(grabber.isFrameNew())
    {
        
        grabberPix = grabber.getPixels();
    
        for(int y = 0; y < grabberPix.getHeight(); y+=2)
        {
            for (int x = 0; x < grabberPix.getWidth(); x+=2)
            {
                ofColor currColor = grabberPix.getColor(x, y);
                float brightness = currColor.getBrightness();
                threshold = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);
                
                if(brightness > threshold)
                {
                    grabberPix.setColor(x, y, 255);
                }
                else
                {
                    grabberPix.setColor(x, y, 0);
                }
            }
        }
    }
    
    texture.loadData(grabberPix);
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    texture.draw(0, 0);
    
    //grabber.draw(0, 0);
}
