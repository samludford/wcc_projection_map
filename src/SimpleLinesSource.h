#pragma once

#include "ofMain.h"
#include "FboSource.h"

#define WIDTH_DEFAULT 10.0
#define VEL_MAX 10.0
#define VEL_MIN 0.0
#define WIDTH_MAX 30.0
#define WIDTH_MIN 1.0

class SimpleLinesSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void setName(string _name);
        float time;
    
        
        float c_min {0};
        float c_max {255};
        int lineCount {50};
        vector<float> positions;
        vector<float> vels;
        vector<float> accs;
        vector<float> widths;
        vector<float> alphas;
};
