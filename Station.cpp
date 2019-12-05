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
vector<FidBlock> fidBlocks;
void Station::drawStation(){
    ofDrawRectangle(leftBorder, topBorder, rightBorder, bottomBorder);
}

bool isCorrectFidBlock(){

}

void addFidBlock(FidBlock fids) {
    fidBlocks.push_back(fids);
}
