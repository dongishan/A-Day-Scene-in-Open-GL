//
//  GreenTree.h
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 02/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#ifndef __GRA_CW__GreenTree__
#define __GRA_CW__GreenTree__

#include <stdio.h>
#define _USE_MATH_DEFINES
#include "AnimatedObject.h"
#include <cmath>
#include <string>

using namespace std;

class GreenTree : public AnimatedObject
{
public:
    GreenTree(GLuint* _textureIds,bool _doAnimate);
    ~GreenTree(){};
    
    void display();
    void update(float dT);
    
private:
    bool doAnimate;
    float cone1ExtraY,cone2ExtraY,cone3ExtraY;
    void drawTree();
    void drawBottom();
    void drawTop();
    float aT;
    GLuint* textureIds;
};

#endif /* defined(__GRA_CW__GreenTree__) */
