#pragma once

#include "ofMain.h"
#include "FboSource.h"

class SquidSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void setName(string _name);
        float time;
    
        float c_min {0};
        float c_max {255};
    
        float counter;
        float control_x1, control_y1;
        float control_x2, control_y2;
    
        float n = 10;
        float spacing = 10;
        bool second_control = true;
    

};
