#pragma once

#include "ofMain.h"
#include "FboSource.h"

class FlashSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void setName(string _name);
        void setDelay(float _delay);
        void setDuration(float _duration);
        
        float c_min {0};
        float c_max {255};
        float delay;
        float duration;
        float startTime;
    
};
