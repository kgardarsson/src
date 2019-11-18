#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxAruco.h"
#include "FidBlock.hpp"

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
    
    ofSoundPlayer audioLoops[10];

    ofVideoGrabber grabber;
    ofVideoPlayer player;

    ofBaseVideoDraws * video;

    ofxAruco aruco;
    bool useVideo;
    bool showMarkers;
    bool showBoard;
    bool showBoardImage;
    ofImage board;
    ofImage marker;
    
    FidBlock myFidBlocks[10];
    
};
