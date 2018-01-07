#pragma once

#include "ofMain.h"
#include "FboSource.h"
#include "Macros.h"

class AbstractSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void setName(string _name);
        void setFadeIn(int _fadeInMode);
    
        float c_min {C_MIN};
        float c_max {C_MAX};
    
        int fadeInMode {0};
        float startTime;
    
};
