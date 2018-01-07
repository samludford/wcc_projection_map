#include "AbstractSource.h"
#include "Macros.h"

void AbstractSource::setup(){
//    name = "White Source";
//    allocate(800, 800);
    
    if(fadeInMode == FROM_MAX) {
        c_min = C_MAX;
    } else if(fadeInMode == FROM_MIN) {
        c_max = C_MIN;
    }
    
}

void AbstractSource::setName(string _name){
    cout << "name set: " << _name << endl;
    name = _name;
}

void AbstractSource::setFadeIn(int _fadeInMode){
    fadeInMode = _fadeInMode;
}

void AbstractSource::reset(){
    startTime = ofGetElapsedTimeMillis();
    if(fadeInMode == FROM_MAX) {
        c_min = C_MAX;
    } else if(fadeInMode == FROM_MIN) {
        c_max = C_MIN;
    }
}


// Don't do any drawing here
void AbstractSource::update(){
    if(fadeInMode != NONE) {
        float t = ofGetElapsedTimeMillis() - startTime;
        if(t < FADE_IN) {
            if(fadeInMode==FROM_MAX) {
                c_min = ofMap(t, 0, FADE_IN, C_MAX, C_MIN);
            } else {
                c_max = ofMap(t, 0, FADE_IN, C_MIN, C_MAX);
            }
        } else {
            c_min = C_MIN;
            c_max = C_MAX;
        }
    }
}


void AbstractSource::draw(){
}

