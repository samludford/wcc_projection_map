#include "SimpleLinesSource.h"

void SimpleLinesSource::setup(){
    AbstractSource::setup();
    name = "Simple Lines Source";
    allocate(800, 800);
    ofBackground(c_min);
    
    // randomly seed start positions
    for(int i=0 ; i < lineCount ; i++) {
        positions.push_back(ofRandom(fbo->getWidth()));
        vels.push_back(ofRandom(-VEL_MAX, VEL_MAX));
        widths.push_back(WIDTH_DEFAULT);
        alphas.push_back(255);
    }
}

void SimpleLinesSource::reset(){
    AbstractSource::reset();
    //reset is called optionally. if you leave it empty nothing is happening
    // setup
}



// Don't do any drawing here
void SimpleLinesSource::update(){
    AbstractSource::update();
    float t = ofGetFrameNum() / 100.0;
    
    for(int i=0 ; i < positions.size() ; i++) {
        
        // update positions
        positions[i] += vels[i];
        
        // adjust velocities for boundaries
        if(positions[i] < 0) {
            vels[i] = abs(vels[i]);
        }
        if(positions[i] > fbo->getWidth()) {
            vels[i] = -abs(vels[i]);
        }
        
        // update widths
        float n = ofNoise(t, i + 10);
        widths[i] = ofMap(n, 0, 1, WIDTH_MIN, WIDTH_MAX);
        
        // update colors
        n = ofNoise(t * 1.3, i / 30.0);
        alphas[i] = ofMap(n, 0, 1, 0, 255);
        
    }
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void SimpleLinesSource::draw(){
    ofClear(0); //clear the buffer
    
    ofPushMatrix();
    ofPushStyle();
    for(int i=0 ; i < positions.size() ; i++) {
        ofSetColor(c_max, alphas[i]);
        ofDrawRectangle(positions[i] - widths[i]/2.0, 0.0, widths[i], fbo->getHeight());
    }
    ofPopStyle();
    ofPopMatrix();

}

