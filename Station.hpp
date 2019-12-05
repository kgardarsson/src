//
//  Station.hpp
//  MED3
//
//  Created by Daniel Mazan on 04/12/2019.
//

#ifndef Station_hpp
#define Station_hpp

#include "ofMain.h"
 
class Station{
public:
    Station();
    Station(float leftBorder, float topBorder, float rightBorder, float bottomBorder);
    float leftBorder;
    float topBorder;
    float rightBorder;
    float bottomBorder;
    
    void drawStation();
    
};



#endif /* Station_hpp */
