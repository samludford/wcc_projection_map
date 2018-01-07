#include "WhiteSource.h"

void WhiteSource::setup(){
    name = "White Source";

    allocate(800, 800);
    
}

void WhiteSource::reset(){
    
}

void WhiteSource::setName(string _name){
    name = _name;
}


// Don't do any drawing here
void WhiteSource::update(){
     
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void WhiteSource::draw(){
    ofClear(0);
    ofPushStyle();
    ofBackground(c_max);
    ofPopStyle();
}

