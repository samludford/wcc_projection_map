#include "DepthSquaresSource.h"

void DepthSquaresSource::setup(){
    name = "Depth Squares Source";
//    rectColor = ofColor(255);
    allocate(800, 800);
    ofBackground(c_min);
    
    drift = ofGetWidth() * 0.7;
}

void DepthSquaresSource::reset(){
    //reset is called optionally. if you leave it empty nothing is happening
//    rectColor = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    // setup
}

void DepthSquaresSource::setName(string _name){
    name = _name;
}


// Don't do any drawing here
void DepthSquaresSource::update(){
     time = ofGetFrameNum()*2;
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void DepthSquaresSource::draw(){
    ofClear(0); //clear the buffer
    
    float t = (ofGetFrameNum() % loopLength) / (float) loopLength;
    ofPushMatrix();
    ofPushStyle();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(c_max);
    ofTranslate(fbo->getWidth()/2.0,fbo->getHeight()/2.0);
    float x_offset = ofMap(ofNoise(ofGetFrameNum() / 200.0), 0, 1, -drift, drift);
    float y_offset = ofMap(ofNoise(ofGetFrameNum() / 200.0 + 40), 0, 1, -drift, drift);
    for(int i=rectCount ; i >= 0 ; i--) {
        float p = ofMap(i, 0, rectCount, 0, 1);
        float c = ofMap(sin(t * TWO_PI + p*5),-1,1,0.2,1);
        if(negative) c = (1-c);
        float x = (1-p) * x_offset;
        float y = (1-p) * y_offset;
        ofPushMatrix();
        ofTranslate(x, y);
        ofSetColor(c * 255);
        float rectSize = p * ofGetWidth();
        ofDrawRectangle(0, 0, rectSize, rectSize);
        ofPopMatrix();
    }
    ofPopStyle();
    ofPopMatrix();

}

