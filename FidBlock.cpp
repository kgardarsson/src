//
//  FidBlock.cpp
//  MED3
//
//  Created by Kristinn Bragi Garðarsson on 11/12/19.
//

#include "FidBlock.hpp"

FidBlock::FidBlock() {
    audioLoop.load("");
};

FidBlock::FidBlock(string audioFile, int id) {
    audioLoop.load(audioFile);
    audioLoop.setVolume(0);
    audioLoop.play();
    audioLoop.setLoop(true);
    this->id = id;
};

void FidBlock::playAudio() {
    audioLoop.setVolume(0.6);
}

void FidBlock::stopAudio() {
    audioLoop.setVolume(0);
}
