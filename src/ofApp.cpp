#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);

	// Enable or disable audio for video sources globally
	// Set this to false to save resources on the Raspberry Pi
	ofx::piMapper::VideoSource::enableAudio = true;
	ofx::piMapper::VideoSource::useHDMIForAudio = false;

    // Add our BouncingBallsSource to list of fbo sources of the piMapper
	// FBO sources should be added before piMapper.setup() so the
	// piMapper is able to load the source if it is assigned to
	// a surface in XML settings.
    
    squidSourceIBOW = new SquidSource();
    squidSourceIBOW->setup();
    squidSourceIBOW->setName("Squid Source");
    squidSourceIBOW->setFadeIn(FADE_MIN);
    squidSourceIBOW->setFadeOut(FADE_MAX, 8000.0);
    piMapper.registerFboSource(squidSourceIBOW);
    
    squidSourceIBOB = new SquidSource();
    squidSourceIBOB->setup();
    squidSourceIBOB->setName("Squid Source IBOB");
    squidSourceIBOB->setFadeIn(FADE_MIN);
    squidSourceIBOB->setFadeOut(FADE_MIN, 8000.0);
    piMapper.registerFboSource(squidSourceIBOB);
    
    squidSourceIWOB = new SquidSource();
    squidSourceIWOB->setup();
    squidSourceIWOB->setName("Squid Source IWOB");
    squidSourceIWOB->setFadeIn(FADE_MAX);
    squidSourceIWOB->setFadeOut(FADE_MIN, 8000.0);
    piMapper.registerFboSource(squidSourceIWOB);
    
    squidSourceNegIBOB = new SquidSource();
    squidSourceNegIBOB->setup();
    squidSourceNegIBOB->setName("Squid Source Negative");
    squidSourceNegIBOB->setFadeIn(FADE_MIN);
    squidSourceNegIBOB->setFadeOut(FADE_MIN, 8000.0);
    squidSourceNegIBOB->setNegative(true);
    piMapper.registerFboSource(squidSourceNegIBOB);
    
    squidSourceNegIBOW = new SquidSource();
    squidSourceNegIBOW->setup();
    squidSourceNegIBOW->setName("Squid Source Negative IBOW");
    squidSourceNegIBOW->setFadeIn(FADE_MIN);
    squidSourceNegIBOW->setFadeOut(FADE_MAX, 8000.0);
    squidSourceNegIBOW->setNegative(true);
    piMapper.registerFboSource(squidSourceNegIBOW);
    
    for(int i=0; i<4 ; i++) {
        float angle = i*90.0;
        TendrilsSource *ts = new TendrilsSource();
        ts->setup();
        if(i==0) {
            ts->setName( "Tendrils Squares Source");
        } else {
            ts->setName( "Tendrils Squares Source " + ofToString(angle));
        }
        ts->setAngle(angle);
        ts->setFadeIn(FADE_MIN);
        ts->setFadeOut(FADE_MIN, 8000.0);
        piMapper.registerFboSource(ts);
        tendrilsSources.push_back(ts);
    }
    
    particlesSource0 = new ParticlesSource();
    particlesSource0->setup();
    particlesSource0->setName("Particles Source");
    particlesSource0->setParticleCount(50);
    particlesSource0->setMode(P_MODE_LINES3);
    particlesSource0->trigger_edge_run(12000);
    particlesSource0->setFadeIn(FADE_MIN);
    particlesSource0->setFadeOut(FADE_MIN, 14000);
    piMapper.registerFboSource(particlesSource0);
    
    particlesSource1 = new ParticlesSource();
    particlesSource1->setup();
    particlesSource1->setName("Particles Source 1");
    particlesSource1->setParticleCount(200);
    particlesSource1->setMode(P_MODE_CORNER_FLARES);
    particlesSource1->trigger_edge_run(12000);
    particlesSource1->setFadeIn(FADE_MIN);
    particlesSource1->setFadeOut(FADE_MIN, 14000);
    piMapper.registerFboSource(particlesSource1);
    
    particlesSource2 = new ParticlesSource();
    particlesSource2->setup();
    particlesSource2->setName("Particles Source 2");
    particlesSource2->setParticleCount(100);
    particlesSource2->setMode(P_MODE_MESH);
    particlesSource2->trigger_edge_run(12000);
    particlesSource2->setFadeIn(FADE_MIN);
    particlesSource2->setFadeOut(FADE_MIN, 14000);
    piMapper.registerFboSource(particlesSource2);
    
    for(int i=0; i<4 ; i++) {
        float angle = i*90.0;
        SimpleLinesSource *sls = new SimpleLinesSource();
        sls->setup();
        if(i==0) {
            sls->setName( "Simple Lines Source");
        } else {
            sls->setName( "Simple Lines Source " + ofToString(angle));
        }
        sls->setAngle(angle);
        sls->setFadeIn(FADE_MIN);
        sls->setFadeOut(FADE_MIN, 14000);
        piMapper.registerFboSource(sls);
        simpleLinesSources.push_back(sls);
    }
    
    depthSquaresSource = new DepthSquaresSource();
    depthSquaresSource->setup();
    depthSquaresSource->setName("Depth Squares Source");
    depthSquaresSource->setFadeOut(FADE_MAX, 8000.0);
    depthSquaresSource->setFadeIn(FADE_MAX);
    depthSquaresSource->setNegative(true);
    piMapper.registerFboSource(depthSquaresSource);
    
    depthSquaresSourceInWhiteOutBlack = new DepthSquaresSource();
    depthSquaresSourceInWhiteOutBlack->setup();
    depthSquaresSourceInWhiteOutBlack->setName("Depth Squares Source IWOB");
    depthSquaresSourceInWhiteOutBlack->setFadeOut(FADE_MIN, 8000.0);
    depthSquaresSourceInWhiteOutBlack->setFadeIn(FADE_MAX);
    depthSquaresSourceInWhiteOutBlack->setNegative(true);
    piMapper.registerFboSource(depthSquaresSourceInWhiteOutBlack);
    
    depthSquaresSourceInBlackOutBlack = new DepthSquaresSource();
    depthSquaresSourceInBlackOutBlack->setup();
    depthSquaresSourceInBlackOutBlack->setName("Depth Squares Source IBOB");
    depthSquaresSourceInBlackOutBlack->setFadeOut(FADE_MIN, 8000.0);
    depthSquaresSourceInBlackOutBlack->setFadeIn(FADE_MIN);
    depthSquaresSourceInBlackOutBlack->setNegative(true);
    piMapper.registerFboSource(depthSquaresSourceInBlackOutBlack);
    
    depthSquaresSourceNeg = new DepthSquaresSource();
    depthSquaresSourceNeg->setup();
    depthSquaresSourceNeg->setName("Depth Squares Source Negative");
    depthSquaresSourceNeg->setFadeOut(FADE_MIN, 8000.0);
    depthSquaresSourceNeg->setFadeIn(FADE_MIN);
    depthSquaresSourceNeg->setNegative(false);
    piMapper.registerFboSource(depthSquaresSourceNeg);
    
    
    whiteSource = new WhiteSource();
    whiteSource->setup();
    whiteSource->setName("White Source");
    piMapper.registerFboSource(whiteSource);
    
    whiteSourceINOB = new WhiteSource();
    whiteSourceINOB->setup();
    whiteSourceINOB->setFadeOut(FADE_MIN, 8000.0);
    whiteSourceINOB->setName("White Source INOB");
    piMapper.registerFboSource(whiteSourceINOB);
    
    blackSource = new BlackSource();
    blackSource->setup();
    piMapper.registerFboSource(blackSource);
    
    for(int i=0; i<9 ; i++) {
        FlashSource *fs = new FlashSource();
        fs->setup();
        fs->setName( "Flash Source " + ofToString(i));
        fs->setDuration( 500.0 );
        fs->setDelay( 500.0 * i );
        piMapper.registerFboSource(fs);
        flashSources.push_back(fs);
    }
    
    for(int i=0; i<4 ; i++) {
        float angle = i*90.0;
        LineMoveSource *lms = new LineMoveSource();
        lms->setup();
        lms->setName( "Line Move Source " + ofToString(angle));
        lms->setDuration( 10000.0 );
        lms->setAngle(angle);
        piMapper.registerFboSource(lms);
        lineMoveSources.push_back(lms);
    }
    
    //
    
    bouncingBallsSource = new BouncingBallsSource();
    bouncingBallsSource->setup();
    piMapper.registerFboSource(bouncingBallsSource);

    movingRectSource = new MovingRectSource();
    movingRectSource->setup();
    piMapper.registerFboSource(movingRectSource);
	piMapper.setup();

	// The info layer is hidden by default, press <i> to toggle
	// piMapper.showInfo();
	
	ofSetFullscreen(Settings::instance()->getFullscreen());
	ofSetEscapeQuitsApp(false);

    dummyObjects.load("4-cube.png");

    //setup sceneManager to handle scene/present changes automatically
    sceneManager.setup("scenes.json", &piMapper);
}

void ofApp::update(){
	piMapper.update();
    sceneManager.update();
}

void ofApp::draw(){
    dummyObjects.draw(ofGetWidth()/2.0 - dummyObjects.getWidth()/2.0,ofGetHeight()/2.0 - dummyObjects.getHeight()/2.0);
    piMapper.draw();
}

void ofApp::keyPressed(int key){
    //press 5 to go to previous preset (scene)
    if (key=='5') {
        if (piMapper.getNumPresets()>1){
            int targetScene = piMapper.getActivePresetIndex() - 1;
            if (targetScene<0) targetScene = piMapper.getNumPresets()-1;
            piMapper.setPreset(targetScene);
            cout << "Switched to preset: " << piMapper.getActivePresetIndex() << endl;
        } else cout << "only one preset available" << endl;
    }
    //press 6 to go to next preset (scene)
    else if (key=='6') {
        if (piMapper.getNumPresets()>1){
            piMapper.setNextPreset();
            cout << "Switched to preset: " << piMapper.getActivePresetIndex() << endl;
        } else cout << "only one preset available" << endl;
    }
    else if (key == '7'){
        piMapper.cloneActivePreset();
        piMapper.setPreset(piMapper.getNumPresets()-1);
        cout << "Cloned and switched to preset: " << piMapper.getActivePresetIndex() << endl;
    }

	piMapper.keyPressed(key);
}

void ofApp::keyReleased(int key){
	piMapper.keyReleased(key);
}

void ofApp::mousePressed(int x, int y, int button){
	piMapper.mousePressed(x, y, button);
}

void ofApp::mouseReleased(int x, int y, int button){
	piMapper.mouseReleased(x, y, button);
}

void ofApp::mouseDragged(int x, int y, int button){
	piMapper.mouseDragged(x, y, button);
}
