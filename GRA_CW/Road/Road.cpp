//
//  Road.cpp
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 02/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#include "Road.h"

//Initialising the textures
Road::Road(GLuint _textureId){
    textureId = _textureId;
}

//Displaying the road
void Road::display(){
    glDisable(GL_LIGHTING);
    glPushMatrix();
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(90.f, 1.f, 0.f, 0.f);
    
    glColor3f(0.5f, 0.5f, 0.5f);
    
    glEnable(GL_CULL_FACE);
    
    drawRoad();
    
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

//Drawing the road using vertexes
void Road::drawRoad(){
    glPushMatrix();
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex2f(-4.f, 5.f);//Top-Left
    glTexCoord2f(1.0, 0.0); glVertex2f(4.f, 5.f);//Top-Right
    glTexCoord2f(1.0, 1.0); glVertex2f(4.f, -5.f);//Bottom-Right
    glTexCoord2f(0.0, 1.0); glVertex2f(-4.f ,-5.f);//Bottom-Left
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
}
