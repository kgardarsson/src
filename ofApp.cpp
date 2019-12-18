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

    
    //Use For PS3 Camera
    grabber.setGrabber(std::make_shared<ofxPS3EyeGrabber>());
    
    //Use For Webcam
    //grabber.setDeviceID(1);
    

    grabber.initGrabber(ofGetWidth(), ofGetHeight());
    video = &grabber;
    
    string markerFile3 = "marker3.xml";
    aruco.setUseHighlyReliableMarker(markerFile3);
    
    aruco.setupXML(cameraIntrinsics, video->getWidth(), video->getHeight());

    ofEnableAlphaBlending();
    
    //RED station (left)
    station[0] = Station(0,0,ofGetWidth()/2-140,ofGetHeight());
    //GREEN station (top)
    station[1] = Station(ofGetWidth()/2-140,0,ofGetWidth()/2+140,ofGetHeight()/2);
    //ORANGE station (right)
    station[2] = Station(ofGetWidth()/2+140,0,ofGetWidth(),ofGetHeight());
    //BLUE station (bottom)
    station[3] = Station(ofGetWidth()/2-140,ofGetHeight()/2,ofGetWidth()/2+140,ofGetHeight());

    //RED (left) Station Blocks
    station[0].addFidBlock(FidBlock("Audio/newAudio/BoomChaBlock.wav", 0));
    station[0].addFidBlock(FidBlock("Audio/newAudio/HiBlock.wav", 1));
    station[0].addFidBlock(FidBlock("Audio/newAudio/CongaBlock.wav", 2));
    station[0].addFidBlock(FidBlock("Audio/newAudio/TamboBlock.wav", 3));
    station[0].addFidBlock(FidBlock("Audio/newAudio/RhythmFXBlock.wav", 4));
    
    //GREEN (top) Station Blocks
    station[1].addFidBlock(FidBlock("Audio/newAudio/CalmSynthBlock.wav", 5));
    station[1].addFidBlock(FidBlock("Audio/newAudio/PianoBlock.wav", 6));
    station[1].addFidBlock(FidBlock("Audio/newAudio/AcoGuitarBlock.wav", 7));
    station[1].addFidBlock(FidBlock("Audio/newAudio/OrganBlock.wav", 8));
    station[1].addFidBlock(FidBlock("Audio/newAudio/FunkyBlock.wav", 9));
    
    //ORANGE (right) Station Blocks
    station[2].addFidBlock(FidBlock("Audio/newAudio/DanceFloorPatternBlock.wav", 10));
    station[2].addFidBlock(FidBlock("Audio/newAudio/WowBlock.wav", 11));
    station[2].addFidBlock(FidBlock("Audio/newAudio/RockSteadyBlock.wav", 12));
    station[2].addFidBlock(FidBlock("Audio/newAudio/BassickBlock.wav", 13));
    station[2].addFidBlock(FidBlock("Audio/newAudio/BlazeRunnerBlock.wav", 14));
    
    //BLUE (bottom) Station Blocks
    station[3].addFidBlock(FidBlock("Audio/newAudio/VitaBlock.wav", 15));
    station[3].addFidBlock(FidBlock("Audio/newAudio/SaxoBlock.wav", 16));
    station[3].addFidBlock(FidBlock("Audio/newAudio/ForeverBlock.wav", 17));
    station[3].addFidBlock(FidBlock("Audio/newAudio/MidnightBlock.wav", 18));
    station[3].addFidBlock(FidBlock("Audio/newAudio/SexyTimeBlock.wav", 19));
}

//--------------------------------------------------------------
void ofApp::update(){
    video->update();
    if(video->isFrameNew()){
        aruco.detectBoards(video->getPixels());
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    video->draw(0, 0);
    ofSetColor(255, 255, 255, 125);
    
    int numberOfStations = 4;
    
    /*
     for (int i=0; i<numberOfStations; i++) {
        station[i].drawStation();
    }
    */
    
    //Stop the audio when marker disappears
    for (int i=0; i<numberOfStations; i++) {
        station[i].stopAudio();
    }
    //plays audio for every marker detected
    for (int i = 0; i<aruco.getNumMarkers(); i++) {
        //for every staition, check if markers' center is within its area
        for (int j=0; j<numberOfStations; j++) {
            float fidPosX = aruco.getMarkers().at(i).getCenter().x;
            float fidPosY = aruco.getMarkers().at(i).getCenter().y;
            if (fidPosX > station[j].leftBorder &&
                fidPosX < station[j].rightBorder &&
                fidPosY > station[j].topBorder &&
                fidPosY < station[j].bottomBorder) {
                station[j].playAudio(aruco.getMarkers().at(i).id);
            }
        }
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
