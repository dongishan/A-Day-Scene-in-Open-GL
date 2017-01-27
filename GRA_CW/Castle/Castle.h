//
//  Castle.h
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 01/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#ifndef __GRA_CW__Castle__
#define __GRA_CW__Castle__

#include <stdio.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "TextureManager.h"
#include "AnimatedObject.h"
#include <map>

class Castle : public AnimatedObject
{
public:
    
    Castle(GLuint _textureId);
    ~Castle(){};
    void update(float dT);
    void display();
    
private:
    
    GLfloat verticesTower[48] =
    {
        -1.5f, 0.0f, 2.5f,
        1.5f, 0.0f, 2.5f,
        1.5f, 6.0f, 2.5f,
        -1.5f, 6.0f, 2.5f,
        
        -1.5f, 6.0f, -2.5f,
        1.5f, 6.0f, -2.5f,
        1.5f, 0.0f, -2.5f,
        -1.5f, 0.0f, -2.5f,
        
        1.5f, 0.0f, 2.5f,
        1.5f, 0.0f, -2.5f,
        1.5f, 6.0f, -2.5f,
        1.5f, 6.0f, 2.5f,
        
        -1.5f, 0.0f, -2.5f,
        -1.5f, 0.0f, 2.5f,
        -1.5f, 6.0f, 2.5f,
        -1.5f, 6.0f, -2.5f
    };
    
    GLfloat texcoordsTower[48] = { 0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,
        0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,
        0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,
        0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0
    };
    
    GLubyte cubeIndicesTower[24] = {0,1,2,3, 4,5,6,7, 3,2,5,4, 7,6,1,0,
        8,9,10,11, 12,13,14,15};
    
    
    GLfloat verticesBuilding[48] =
    {
        -2.5f, 0.0f, 2.5f,
        2.5f, 0.0f, 2.5f,
        2.5f, 4.0f, 2.5f,
        -2.5f, 4.0f, 2.5f,
        
        -2.5f, 4.0f, -2.5f,
        2.5f, 4.0f, -2.5f,
        2.5f, 0.0f, -2.5f,
        -2.5f, 0.0f, -2.5f,
        
        2.5f, 0.0f, 2.5f,
        2.5f, 0.0f, -2.5f,
        2.5f, 4.0f, -2.5f,
        2.5f, 4.0f, 2.5f,
        
        -2.5f, 0.0f, -2.5f,
        -2.5f, 0.0f, 2.5f,
        -2.5f, 4.0f, 2.5f,
        -2.5f, 4.0f, -2.5f
    };
    
    GLfloat texcoordsBuilding[48] = { 0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,
        0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,
        0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0,
        0.0,0.0, 1.0,0.0, 1.0,1.0, 0.0,1.0
    };
    
    GLubyte cubeIndicesBuilding[24] = {0,1,2,3, 4,5,6,7, 3,2,5,4, 7,6,1,0,
        8,9,10,11, 12,13,14,15};
    
    
    GLuint textureId;
 
    void drawCastle();
    void drawLeftBuilding();
    void drawRightBuilding();
};
#endif /* defined(__GRA_CW__Castle__) */
