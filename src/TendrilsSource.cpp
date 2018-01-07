#include "TendrilsSource.h"

void TendrilsSource::setup(){
    name = "Tendrils Squares Source";
//    rectColor = ofColor(255);
    allocate(800, 800);
    
    tendrilWidth = fbo->getWidth() / (float) tendrilCount;
    ofSetCircleResolution(100);
    
    // create seed particles
    for(int i=1 ; i < tendrilCount ; i+=2) {
        for(int j=0 ; j < tendrilCount ; j+=2) {
            bool shouldCreateParticle = ((int) ofRandom(CHANCE) == 0);
            if(shouldCreateParticle) {
                ofPoint part = ofPoint(i * tendrilWidth + tendrilWidth/2.0, j * tendrilWidth);
                parts_dark.push_back(part);
            }
        }
    }
    
}

void TendrilsSource::reset(){
    //reset is called optionally. if you leave it empty nothing is happening
//    rectColor = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    // setup
}

void TendrilsSource::setName(string _name){
    name = _name;
}


// Don't do any drawing here
void TendrilsSource::update(){
    // move particles
    for(int i=0 ; i < parts_dark.size() ; i++) {
        parts_dark[i].y += VEL;
        // put it back to the top
        if(parts_dark[i].y > fbo->getHeight()) {
            parts_dark[i].y = 0;
        }
    }
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void TendrilsSource::draw(){
    ofClear(0); //clear the buffer
    
    draw_stripes();
    
    ofPushMatrix();
    ofPushStyle();
    
    ofSetColor(c_min);
    
    float t = ofGetFrameNum() / 100.0;
    
    for(int i=0 ; i < parts_dark.size() ; i++) {
        
        float n = ofMap(ofNoise(t, i),0,1,0,20);
        ofDrawCircle(parts_dark[i].x, parts_dark[i].y, n);
        //        ofDrawCircle(parts_dark[i].x, parts_dark[i].y, part_size);
    }
    
    ofPopStyle();
    ofPopMatrix();
    


}

void TendrilsSource::draw_stripes() {
    ofPushStyle();
    ofSetColor(c_max);
    for(int i=0 ; i < tendrilCount ; i+=2) {
        ofDrawRectangle(i * tendrilWidth, 0, tendrilWidth, fbo->getHeight());
    }
    ofPopStyle();
}

