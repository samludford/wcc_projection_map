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
#include "LineMoveSource.h"

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
        DepthSquaresSource * depthSquaresSourceInWhiteOutBlack;
        DepthSquaresSource * depthSquaresSourceInBlackOutBlack;
        DepthSquaresSource * depthSquaresSourceNeg;
        vector<FlashSource*> flashSources;
        vector<LineMoveSource*> lineMoveSources;
    
        ParticlesSource * particlesSource0;
        ParticlesSource * particlesSource1;
        ParticlesSource * particlesSource2;
        vector<SimpleLinesSource*> simpleLinesSources;
    
        SquidSource * squidSourceIBOW;
        SquidSource * squidSourceIBOB;
        SquidSource * squidSourceIWOB;
    
        SquidSource * squidSourceNegIBOB;
        SquidSource * squidSourceNegIBOW;
    
        vector<TendrilsSource*> tendrilsSources;
    
        WhiteSource * whiteSource;
        BlackSource * blackSource;
    
        BouncingBallsSource * bouncingBallsSource;
        MovingRectSource * movingRectSource;
        ofImage dummyObjects;

        SceneManager sceneManager;
};
