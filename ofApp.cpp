#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    webcam.setup(640, 480);
    gray.allocate(webcam.getWidth(), webcam.getHeight());
    color.allocate(webcam.getWidth(), webcam.getHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    webcam.update();
    
    if(webcam.isFrameNew()) {
        color.setFromPixels(webcam.getPixels());
        gray = color;
        myFiducialTracker.findFiducials(gray);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    color.draw(0, 0);
    gray.draw(480, 0);
    //cout << "aaa " << myFiducialTracker._fiducials.size() << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
