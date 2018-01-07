#pragma once

#include "ofMain.h"
#include "FboSource.h"

class WhiteSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void setName(string _name);
        
        float c_min {0};
        float c_max {255};
    
};
