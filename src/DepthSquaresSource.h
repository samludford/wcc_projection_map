#pragma once

#include "ofMain.h"
#include "FboSource.h"

class DepthSquaresSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void setName(string _name);
        float time;
    
        int loopLength {200};
        int rectCount {100};
        int drift {400};
        bool negative {true};
        float c_min {0};
        float c_max {255};
};
