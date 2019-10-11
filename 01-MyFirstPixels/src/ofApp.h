#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void draw();

    ofPixels myPixels;
    ofPixels imgPixels;
    
    ofImage myImage;
    
    ofTexture texture;
    ofTexture imgTexture;
		
};
