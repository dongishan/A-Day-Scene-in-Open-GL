//
//  Train.h
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 04/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#ifndef __GRA_CW__Train__
#define __GRA_CW__Train__

#include <stdio.h>
#define _USE_MATH_DEFINES
#include "AnimatedObject.h"
#include "LeftDoor.h"
#include "RightDoor.h"
#include <cmath>
#include <string>

using namespace std;

class Train : public AnimatedObject
{
public:
    Train(GLuint* _textureIds);
    ~Train(){};
    
    void display();
    void update(float dT);
    
private:
    
    void drawWheel(float tx,float ty, float tz,float wAngle);
    void drawSmokePipe();
    void drawConnector();
    void drawCarriage();
    void box(float sx, float sy, float sz);
    void drawTrain();
    float aT;
    GLuint* textureIds;
};

#endif /* defined(__GRA_CW__Train__) */
