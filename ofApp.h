#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxAruco.h"
#include "ofxPS3EyeGrabber.h"
#include "FidBlock.hpp"
#include "Station.hpp"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void playAudioWithMarker(int marker);
    
    ofVideoGrabber grabber;
    ofBaseVideoDraws * video;

    ofxAruco aruco;
    
    FidBlock myFidBlocks[28];
    Station redStation;
    Station greenStation;
    Station orangeStation;
    Station blueStation;
};
