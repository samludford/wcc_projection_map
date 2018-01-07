#pragma once

#include "ofMain.h"
#include "FboSource.h"
#include "Macros.h"
#include "AbstractSource.h"

class DepthSquaresSource : public AbstractSource {
	public:
    
        void setup();
		void update();
		void draw();
        void reset();
        
        float time;
    
        int loopLength {3000};
        int rectCount {10};
        int drift {400};
        bool negative {true};

    
        
    
    
};
