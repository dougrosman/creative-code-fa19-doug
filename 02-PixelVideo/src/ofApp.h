#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    ofVideoGrabber grabber;
    
    ofPixels grabberPix;
    ofTexture texture;
    
    float threshold;
};
