#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // allocate a blank pixel obect and texture
    myPixels.allocate(256, 256, 3);
    texture.allocate(myPixels.getWidth(), myPixels.getHeight(), GL_RGB);
    
    // load and allocate image
    myImage.load("bottle.jpg");
    imgPixels.allocate(myImage.getWidth(), myImage.getHeight(), OF_PIXELS_RGB);
    imgTexture.allocate(myImage.getWidth(), myImage.getHeight(), GL_RGB);
    

    for(int y = 0; y < myPixels.getHeight(); y++)
    {
        for(int x = 0; x < myPixels.getWidth(); x++)
        {
            myPixels.setColor(x, y, ofColor::fromHsb(x, 255, 255));
        }
    }
    
    texture.loadData(myPixels);
    
    // load imgPixels with pixels from myImage
    imgPixels = myImage.getPixels();
    
    for(int y = 0; y < imgPixels.getHeight(); y++)
    {
        for(int x = 0; x < imgPixels.getWidth(); x++)
        {
            ofColor currColor = imgPixels.getColor(x, y);
            float r = currColor.r;
            float g = currColor.g;
            float b = currColor.b;
            float brightness = currColor.getBrightness();
            
            ofColor negativeColor = (r-255, g-255, b-255);
            
            //if(brightness > 220)
            //{
            imgPixels.setColor(x, y, negativeColor);
            //}
        }
    }
    
    
    
    
    
    imgTexture.loadData(imgPixels);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    texture.draw(0, 0);
    
    imgTexture.draw(300, 0);
    
    

}
