#include "BlackSource.h"

void BlackSource::setup(){
    name = "Black Source";

    allocate(800, 800);
    
}

void BlackSource::reset(){
    
}

void BlackSource::setName(string _name){
    name = _name;
}


// Don't do any drawing here
void BlackSource::update(){
     
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void BlackSource::draw(){
    ofClear(0);
    ofPushStyle();
    ofBackground(c_min);
    ofPopStyle();
}

