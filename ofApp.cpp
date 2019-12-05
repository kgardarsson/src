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
    //grabber.setGrabber(std::make_shared<ofxPS3EyeGrabber>());
    
    //Use For Webcam
    grabber.setDeviceID(1);
    

    grabber.initGrabber(ofGetWidth(), ofGetHeight());
    video = &grabber;
    
    string markerFile3 = "marker3.xml";
    aruco.setUseHighlyReliableMarker(markerFile3);
    
    aruco.setupXML(cameraIntrinsics, video->getWidth(), video->getHeight());

    ofEnableAlphaBlending();
    //RED station (left)
    myStation[0] = Station(0,0,ofGetWidth()/2-140,ofGetHeight());
    //GREEN station (top)
    myStation[1] = Station(ofGetWidth()/2-140,0,280,ofGetHeight()/2);
    //ORANGE station (right)
    myStation[2] = Station(ofGetWidth()/2+140,0,200,ofGetHeight());
    //BLUE station (bottom)
    myStation[3] = Station(ofGetWidth()/2-140,ofGetHeight()/2,280,ofGetHeight()/2);
    
    

    
    //RED Station Blocks
    myFidBlocks[0] = FidBlock("Audio/CowBlock.wav", 0);
    myFidBlocks[1] = FidBlock("Audio/RockBlock.wav", 1);
    myFidBlocks[2] = FidBlock("Audio/ScreamBlock.wav", 2);
    myFidBlocks[3] = FidBlock("Audio/IndieBlock.wav", 3);
    myFidBlocks[4] = FidBlock("Audio/StrumBlock.wav", 4);
    
    //ORANGE Station Blocks
    myFidBlocks[5] = FidBlock("Audio/DjubBlock.wav", 5);
    myFidBlocks[6] = FidBlock("Audio/SynthBlock.wav", 6);
    myFidBlocks[7] = FidBlock("Audio/VoBlock.wav", 7);
    myFidBlocks[8] = FidBlock("Audio/VitaBlock.wav", 8);
    myFidBlocks[9] = FidBlock("Audio/DiscoBlock.wav", 9);
    
    //GREEN Station Blocks
    myFidBlocks[10] = FidBlock("Audio/ChoBlock.wav", 10);
    myFidBlocks[11] = FidBlock("Audio/BachBlock.wav", 11);
    myFidBlocks[12] = FidBlock("Audio/StringBlock.wav", 12);
    myFidBlocks[13] = FidBlock("Audio/WindBlock.wav", 13);
    myFidBlocks[14] = FidBlock("Audio/ReggaeBlock.wav", 14);
    
    //BLUE Station Blocks
    myFidBlocks[15] = FidBlock("Audio/BlueBlock.wav", 15);
    myFidBlocks[16] = FidBlock("Audio/JungleBlock.wav", 16);
    myFidBlocks[17] = FidBlock("Audio/SexyTimeBlock.wav", 17);
    myFidBlocks[18] = FidBlock("Audio/UpBlock.wav", 18);
    myFidBlocks[19] = FidBlock("Audio/FusionBlock.wav", 19);

    
    //Combo Blocks
    myFidBlocks[20] = FidBlock();
    myFidBlocks[21] = FidBlock();
    myFidBlocks[22] = FidBlock();
    myFidBlocks[23] = FidBlock();
    myFidBlocks[24] = FidBlock();
    myFidBlocks[25] = FidBlock();
    myFidBlocks[26] = FidBlock();
    myFidBlocks[27] = FidBlock();

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
    for (int i=0; i<3; i++){
        myStation[i].drawStation();
    }
    
    //aruco.draw();
   // ofDrawLine(ofGetWidth()/2 + 140, 0,ofGetWidth()/2 + 140, ofGetHeight());
    //ofDrawLine(ofGetWidth()/2 - 140, 0,ofGetWidth()/2 - 140, ofGetHeight());
    //ofDrawLine(ofGetWidth()/2 - 140, ofGetHeight()/2, ofGetWidth()/2 + 140, ofGetHeight()/2);

    for (int i=0; i<28; i++) {
        myFidBlocks[i].stopAudio();
    }
    for (int i = 0; i<aruco.getNumMarkers(); i++) {
        aruco.begin(i);
        for (int j=0; j<28; j++) {
            if (aruco.getMarkers().at(i).id == myFidBlocks[j].id) {
                myFidBlocks[j].playAudio();
            }
        }

        cout << "id is: " << aruco.getMarkers().at(i).id << endl;
        drawMarker(0.15, ofColor::white);
        aruco.end();
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
