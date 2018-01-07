#include "SquidSource.h"

void SquidSource::setup(){
    AbstractSource::setup();
    name = "Squid Source";
//    rectColor = ofColor(255);
    allocate(800, 800);
    ofBackground(c_min);
    ofSetColor(c_min);
}

void SquidSource::reset(){
    AbstractSource::reset();
    //reset is called optionally. if you leave it empty nothing is happening
//    rectColor = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    // setup
}


// Don't do any drawing here
void SquidSource::update(){
    AbstractSource::update();
    counter = ofGetFrameNum();
    control_x1 = ofMap(ofNoise(counter/200),0,1,-fbo->getWidth()/3,fbo->getWidth()/3);
    control_y1 = ofMap(ofNoise(counter/300+40),0,1,-fbo->getHeight()/3,fbo->getHeight()/3);
    control_x2 = ofMap(ofNoise(counter/800+10),0,1,-fbo->getWidth()/3,fbo->getWidth()/3);
    control_y2 = ofMap(ofNoise(counter/900),0,1,-fbo->getHeight()/3,fbo->getHeight()/3);
    
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void SquidSource::draw(){
    ofClear(0); //clear the buffer
    
    
//    ofDrawRectangle(20, 20, 60, 60);
    
    ofPushStyle();
    ofBackground(c_max);
    ofSetLineWidth(3);
    ofSetColor(c_min);
    
    ofPushMatrix();
    ofTranslate(fbo->getWidth()/2, fbo->getHeight()/2);

    for(int i=-n/2 ; i < n/2 ; i++) {

        ofPushMatrix();

        ofRotate(i * 360/n);

        float x = i*spacing;
        ofPolyline line;

        line.curveTo(ofMap(ofNoise(counter/20),0,1,-x,x), -fbo->getHeight()/3 + 20);
        line.curveTo(sin(counter/60+10)*x, -fbo->getHeight()/3 + 20);
        line.curveTo(control_x1, control_y1);
        if(second_control) {
            line.curveTo(control_x2, control_y2);
        }
        line.curveTo(cos(counter/40)*x, fbo->getHeight()/3-20);
        line.curveTo(x, fbo->getHeight()/3-20);
        line.draw();

        ofPopMatrix();
    }

    ofPopMatrix();
    ofPopStyle();
    

}

