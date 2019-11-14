//
//  FidBlock.cpp
//  MED3
//
//  Created by Kristinn Bragi Garðarsson on 11/12/19.
//

#include "FidBlock.hpp"

FidBlock() {
    
}

FidBlock(String audioFile) {
    audioLoop.load(audioFile);
};


