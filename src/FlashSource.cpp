#include "FlashSource.h"

void FlashSource::setup(){
//    name = "Flash Source";

    allocate(800, 800);
    ofBackground(c_min);
}

void FlashSource::reset(){
    startTime = ofGetElapsedTimeMillis();
}

void FlashSource::setName(string _name){
    name = _name;
    
    cout << "new name: " << this->name << endl;
}

void FlashSource::setDelay(float _delay){
    delay = _delay;
}

void FlashSource::setDuration(float _duration){
    duration = _duration;
}


// Don't do any drawing here
void FlashSource::update(){
     
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void FlashSource::draw(){
    ofClear(0);
    ofPushStyle();
    ofBackground(c_min);
    ofSetColor(c_max);
    float t = ofGetElapsedTimeMillis() - startTime;
    if (t > delay && t <= delay + duration) {
        ofDrawRectangle(0, 0, fbo->getWidth(), fbo->getHeight());
    }
    
    ofPopStyle();

}

