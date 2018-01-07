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
    depthSquaresSource = new DepthSquaresSource();
    depthSquaresSource->setup();
    depthSquaresSource->setFadeOut(FADE_MIN, 4000.0);
    piMapper.registerFboSource(depthSquaresSource);
    
    squidSource = new SquidSource();
    squidSource->setup();
    piMapper.registerFboSource(squidSource);
    
    simpleLinesSource = new SimpleLinesSource();
    simpleLinesSource->setup();
    piMapper.registerFboSource(simpleLinesSource);
    
    tendrilsSource = new TendrilsSource();
    tendrilsSource->setup();
    piMapper.registerFboSource(tendrilsSource);
    
    particlesSource = new ParticlesSource();
    particlesSource->setup();
    piMapper.registerFboSource(particlesSource);
    
    whiteSource = new WhiteSource();
    whiteSource->setup();
    piMapper.registerFboSource(whiteSource);
    
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
        lms->setDuration( 3000.0 );
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
