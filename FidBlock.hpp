//
//  FidBlock.hpp
//  MED3
//
//  Created by Kristinn Bragi Garðarsson on 11/12/19.
//

#ifndef FidBlock_hpp
#define FidBlock_hpp

#include "ofMain.h"
#include "ofxAruco.h"

class FidBlock {
public:
    FidBlock()
    FidBlock(std::String audioFile)
    
    void setup();
    void draw();
    
    aruco::Marker marker;
    
    ofSoundPlayer audioLoop;
};

#endif /* FidBlock_hpp */
