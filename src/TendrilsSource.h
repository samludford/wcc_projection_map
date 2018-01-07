#pragma once

#include "ofMain.h"
#include "FboSource.h"

#define VEL 5.0
#define CHANCE 7
#define SPACING 5

class TendrilsSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void setName(string _name);
        float time;
    
        float c_min {0};
        float c_max {255};
    
        int tendrilCount {50};
        float part_size {10.0};
        float tendrilWidth;
    
        vector<ofPoint> parts_dark;
    
        void draw_stripes();
};
