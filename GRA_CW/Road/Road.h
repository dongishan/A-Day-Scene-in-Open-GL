//
//  Road.h
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 02/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#ifndef __GRA_CW__Road__
#define __GRA_CW__Road__

#include <stdio.h>

#define _USE_MATH_DEFINES
#include "DisplayableObject.h"
#include <cmath>
#include <string>

using namespace std;

class Road : public DisplayableObject
{
public:
    Road(GLuint _textureId);
    ~Road(){};
    
    void display();
    
private:
    
    void drawRoad();
    GLuint textureId;
};

#endif /* defined(__GRA_CW__Road__) */
