//
//  BgSkybox.h
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 03/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#ifndef __GRA_CW__BgSkybox__
#define __GRA_CW__BgSkybox__

#include <stdio.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "TextureManager.h"
#include "DisplayableObject.h"

class BgSkybox : public DisplayableObject
{
public:
    
    BgSkybox(GLuint *_textureIds);
    ~BgSkybox(){};
    void display();
private:
    
    GLuint* textureIds;
    void drawBackground();
};

#endif /* defined(__GRA_CW__BgSkybox__) */
