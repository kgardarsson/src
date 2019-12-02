#include "ofApp.h"

void drawMarker(float size, const ofColor & color){
    ofDrawAxis(size);
    ofPushMatrix();
        // move up from the center by size*.5
        // to draw a box centered at that point
        ofTranslate(0,size*0.5,0);
        ofFill();
        ofSetColor(color,50);
        ofDrawBox(size);
        ofNoFill();
        ofSetColor(color);
        ofDrawBox(size);
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    string cameraIntrinsics = "intrinsics.yml";
    //grabber.setGrabber(std::make_shared<ofxPS3EyeGrabber>());
    
    grabber.setDeviceID(1);
    grabber.initGrabber(ofGetWidth(), ofGetHeight());
    video = &grabber;
    
    string markerFile3 = "marker3.xml";
    aruco.setUseHighlyReliableMarker(markerFile3);
    
    //string markerFile4 = "marker4.xml";
    //aruco.setUseHighlyReliableMarker(markerFile4);

    //string markerFile5 = "marker5.xml";
    //aruco.setUseHighlyReliableMarker(markerFile5);

    aruco.setupXML(cameraIntrinsics, video->getWidth(), video->getHeight());

    showMarkers = true;

    ofEnableAlphaBlending();

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
    
    myFidBlocks[0] = FidBlock("Audio/Stations/Rhythmic/Claps.wav", 8);
    myFidBlocks[1] = FidBlock("Audio/Stations/Rhythmic/Cymbals.wav", 7);
    myFidBlocks[2] = FidBlock("Audio/Stations/Rhythmic/Kick.wav", 6);
    myFidBlocks[3] = FidBlock("Audio/Stations/Rhythmic/Percussion.wav", 5);
    myFidBlocks[4] = FidBlock("Audio/Stations/Rhythmic/Snare.wav", 4);
    myFidBlocks[5] = FidBlock("Audio/Stations/Vocals/BeckColors.wav", 3);
    myFidBlocks[6] = FidBlock("Audio/Stations/Vocals/EWFSeptember.wav", 2);
    myFidBlocks[7] = FidBlock("Audio/Stations/Vocals/JourneyDontStop.wav", 1);
    myFidBlocks[8] = FidBlock("Audio/Stations/Vocals/Vitas7thElement.wav", 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    video->update();
    if(video->isFrameNew()){
        aruco.detectBoards(video->getPixels());
    }
}

void ofApp::playAudioWithMarker(int marker) {
    int horizontalSpaces = 5;
    int verticalSpaces = 2;
    int i=0;
    for (int j=horizontalSpaces; j>0; j--) {
        for (int k=verticalSpaces; k>0; k--) {
            if (aruco.getNumMarkers() == 0) {
                audioLoops[i].setVolume(0);
            } else if (    aruco.getMarkers().at(marker).getCenter().x > ofGetWidth() -ofGetWidth()/horizontalSpaces*j
                    && aruco.getMarkers().at(marker).getCenter().x < ofGetWidth() -ofGetWidth()/horizontalSpaces*(j-1)
                    && aruco.getMarkers().at(marker).getCenter().y > ofGetHeight() -ofGetHeight()/verticalSpaces*k
                    && aruco.getMarkers().at(marker).getCenter().y < ofGetHeight() -ofGetHeight()/verticalSpaces*(k-1)  ) {
                audioLoops[i].setVolume(0.6);
            } else {
                audioLoops[i].setVolume(0);
            }
            i++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    video->draw(0, 0);

    //aruco.draw();

    if (showMarkers) {
        for (int i=0; i<9; i++) {
            myFidBlocks[i].stopAudio();
        }
        for (int i = 0; i<aruco.getNumMarkers(); i++) {
            aruco.begin(i);
            for (int j=0; j<9; j++) {
                if (aruco.getMarkers().at(i).id == myFidBlocks[j].id) {
                    myFidBlocks[j].playAudio();
                }
            }
            cout << "id is: " << aruco.getMarkers().at(i).id << endl;
            drawMarker(0.15, ofColor::white);
            aruco.end();
            //ofApp::playAudioWithMarker(i);
        }
    }
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
