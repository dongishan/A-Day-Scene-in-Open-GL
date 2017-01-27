//
//  Lamp.h
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 02/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#ifndef __GRA_CW__Lamp__
#define __GRA_CW__Lamp__

#include <stdio.h>
#define _USE_MATH_DEFINES
#include "AnimatedObject.h"
#include <cmath>
#include <string>

using namespace std;

class Lamp : public AnimatedObject{
public:
    Lamp(GLuint* _textureIds);
    ~Lamp(){};
    void update(float dT);
    void display();
    
private:
    void drawLamp();
    void drawStick();
    void drawTop();
    GLuint* textureIds;
};


#endif /* defined(__GRA_CW__Lamp__) */
