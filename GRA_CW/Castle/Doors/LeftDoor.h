//
//  LeftDoor.h
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 02/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#ifndef __GRA_CW__LeftDoor__
#define __GRA_CW__LeftDoor__

#include <stdio.h>
#define _USE_MATH_DEFINES
#include "AnimatedObject.h"
#include <cmath>
#include <string>

using namespace std;

class LeftDoor : public AnimatedObject
{
public:
    LeftDoor(GLuint _textureId);
    ~LeftDoor(){};
    
    bool doCloseDoor;
    
    void display();
    void update(float dT);
    
private:
    GLfloat verticesDoor[48] =
    {
        -2.2f, 0.0f, 0.5f,
        2.2f, 0.0f, 0.5f,
        2.2f, 5.0f, 0.5f,
        -2.2f, 5.0f, 0.5f,
        
        -2.2f, 5.0f, -0.5f,
        2.2f, 5.0f, -0.5f,
        2.2f, 0.0f, -0.5f,
        -2.2f, 0.0f, -0.5f,
        
        2.2f, 0.0f, 0.5f,
        2.2f, 0.0f, -0.5f,
        2.2f, 5.0f, -0.5f,
        2.2f, 5.0f, 0.5f,
        
        -2.2f, 0.0f, -0.5f,
        -2.2f, 0.0f, 0.5f,
        -2.2f, 5.0f, 0.5f,
        -2.2f, 5.0f, -0.5f
    };
    
    GLfloat texcoordsDoor[48] = { 0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,
        0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,
        0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,
        0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0
    };
    
    GLubyte cubeIndicesDoor[24] = {0,1,2,3, 4,5,6,7, 3,2,5,4, 7,6,1,0,
        8,9,10,11, 12,13,14,15};
    
    
    void drawDoor();
    float aT;
    GLuint textureId;
};

#endif /* defined(__GRA_CW__LeftDoor__) */
