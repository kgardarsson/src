//
//  Station.cpp
//  MED3
//
//  Created by Daniel Mazan on 04/12/2019.
//

#include "Station.hpp"
Station::Station(){
    
};

Station::Station(float leftBorder, float topBorder, float rightBorder, float bottomBorder){
    this->leftBorder = leftBorder;
    this->topBorder = topBorder;
    this->rightBorder = rightBorder;
    this->bottomBorder = bottomBorder;
};

void Station::drawStation(){
    ofDrawRectangle(leftBorder, topBorder, rightBorder-leftBorder, bottomBorder-topBorder);
}

void Station::addFidBlock(FidBlock fidBlock) {
    fidBlocks.push_back(fidBlock);
}

void Station::playAudio(int id) {
    for (int i=0; i<fidBlocks.size(); i++) {
        if (id == fidBlocks[i].id) {
            fidBlocks[i].playAudio();
            break;
        }
    }
}

void Station::stopAudio() {
    for (int i=0; i<fidBlocks.size(); i++) {
        fidBlocks[i].stopAudio();
    }
}

void Station::setName(string name) {
    this->name = name;
}

string Station::getName() {
    return name;
}
