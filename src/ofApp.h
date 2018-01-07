#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "ofxPiMapper.h"
#include "BouncingBallsSource.h"
#include "MovingRectSource.h"

#include "DepthSquaresSource.h"
#include "SquidSource.h"
#include "SimpleLinesSource.h"
#include "TendrilsSource.h"
#include "ParticlesSource.h"
#include "FlashSource.h"
#include "WhiteSource.h"
#include "BlackSource.h"

#include "VideoSource.h"
#include "SceneManager.h"

#define GLOBAL_PADDING 80

class ofApp : public ofBaseApp {
	public:
		void setup();
		void update();
		void draw();
	
		void keyPressed(int key);
		void keyReleased(int key);
	
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseDragged(int x, int y, int button);

		ofxPiMapper piMapper;

        DepthSquaresSource * depthSquaresSource;
        SquidSource * squidSource;
        SimpleLinesSource * simpleLinesSource;
        TendrilsSource * tendrilsSource;
        ParticlesSource * particlesSource;
        WhiteSource * whiteSource;
        BlackSource * blackSource;
    
        vector<FlashSource*> flashSources;

    
        BouncingBallsSource * bouncingBallsSource;
        MovingRectSource * movingRectSource;
        ofImage dummyObjects;

        SceneManager sceneManager;
};
