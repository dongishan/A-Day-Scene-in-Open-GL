//
//  Girrafe.h
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 04/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#ifndef __GRA_CW__Girrafe__
#define __GRA_CW__Girrafe__

#include <stdio.h>
#define _USE_MATH_DEFINES
#include "AnimatedObject.h"
#include <cmath>

class Girrafe : public AnimatedObject {
public:
    Girrafe(GLuint _textureId);
    ~Girrafe(){};
    void display();
    void update(float dT);
    bool isEatingGirrafe;
    
private:
    GLuint textureId;
    
    float aT;
    float animationTime;
    float neckAngle,headY,headX,earY,backLegAngle,frontLegAngle,backLegBottomX,frontLegBottomX;
    
    
    void drawGirrafe();
    void drawBackLeg();
    void drawFrontLeg();
    void drawHone();
    void drawNeck();
    void drawHead();
    void drawTail();
    
    void box(float sx, float sy, float sz);
};

#endif /* defined(__GRA_CW__Girrafe__) */
