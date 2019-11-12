#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    camera.setGrabber(std::make_shared<ofxPS3EyeGrabber>());
    camera.setup(ofGetWidth(), ofGetHeight());
    audioLoops[0].load("Audio/Colors_11.wav");
    audioLoops[1].load("Audio/Colors_12.wav");
    audioLoops[2].load("Audio/Colors_13.wav");
    audioLoops[3].load("Audio/Colors_14.wav");
    audioLoops[4].load("Audio/Colors_15.wav");
    audioLoops[5].load("Audio/Colors_21.wav");
    audioLoops[6].load("Audio/Colors_22.wav");
    audioLoops[7].load("Audio/Colors_23.wav");
    audioLoops[8].load("Audio/Colors_24.wav");
    audioLoops[9].load("Audio/Colors_25.wav");
    
    for (int i=0; i<10; i++) {
        audioLoops[i].setVolume(0);
        audioLoops[i].play();
        audioLoops[i].setLoop(true);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    camera.draw(0, 0, ofGetWidth(),ofGetHeight());
    
    for (int i=0; i<5; i++) {
        ofDrawLine(ofGetWidth()/5*i, 0, ofGetWidth()/5*i, ofGetHeight());
    }
    for (int i=0; i<2; i++) {
        ofDrawLine(0, ofGetHeight()/2*i, ofGetWidth(), ofGetHeight()/2*i);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    int horizontalSpaces = 5;
    int verticalSpaces = 2;
    int i=0;
    for (int j=horizontalSpaces; j>0; j--) {
        for (int k=verticalSpaces; k>0; k--) {
            if (    ofGetMouseX() > ofGetWidth() -ofGetWidth()/horizontalSpaces*j
                    && ofGetMouseX() < ofGetWidth() -ofGetWidth()/horizontalSpaces*(j-1)
                    && ofGetMouseY() > ofGetHeight() -ofGetHeight()/verticalSpaces*k
                    && ofGetMouseY() < ofGetHeight() -ofGetHeight()/verticalSpaces*(k-1)  ) {
                audioLoops[i].setVolume(0.6);
            } else {
                audioLoops[i].setVolume(0);
            }
            i++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
