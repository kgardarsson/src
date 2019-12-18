//
//  Station.hpp
//  MED3
//
//  Created by Daniel Mazan on 04/12/2019.
//

#ifndef Station_hpp
#define Station_hpp

#include "ofMain.h"
#include "ofxAruco.h"
#include "FidBlock.hpp"
 
class Station{
public:
    Station();
    Station(float leftBorder, float topBorder, float rightBorder, float bottomBorder);
    float leftBorder;
    float topBorder;
    float rightBorder;
    float bottomBorder;
    
    vector<FidBlock> fidBlocks;
    
    void drawStation();
    void addFidBlock(FidBlock fidBlock);
    void playAudio(int id);
    void stopAudio();
    string name;
    void setName(string name);
    
    string getName();
    
};



#endif /* Station_hpp */
