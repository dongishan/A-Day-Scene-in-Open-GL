//
//  Sun.h
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 01/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#ifndef __GRA_CW__Sun__
#define __GRA_CW__Sun__

#include <stdio.h>
#define _USE_MATH_DEFINES
#include "AnimatedObject.h"
#include "LeftDoor.h"
#include "RightDoor.h"
#include <cmath>
#include <string>

using namespace std;

class Sun : public AnimatedObject
{
public:
    Sun(GLuint _textureId,LeftDoor *leftDoor, RightDoor *rightDoor);
    ~Sun(){};
    
    void display();
    void update(float dT);

private:
    
    LeftDoor *leftDoor;
    RightDoor *rightDoor;
    
    void drawSun();
    float aT;
    GLuint textureId;
};

#endif /* defined(__GRA_CW__Sun__) */
