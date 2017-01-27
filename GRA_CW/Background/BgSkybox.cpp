//
//  BgSkybox.cpp
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 03/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#include "BgSkybox.h"

//Initialising the texture id array
BgSkybox::BgSkybox(GLuint *_textureIds){
    textureIds = _textureIds;
}
void BgSkybox::display(){
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.f, 1.f, 0.f);
    glRotatef(rotation[2], 0.f, 0.f, 1.f);
    glRotatef(rotation[0], 1.f, 0.f, 0.f);
    
    drawBackground();
    
    glPopAttrib();
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

//Drawing the skybox
void BgSkybox::drawBackground(){
    glDisable(GL_LIGHTING);
    glColor4f(1.f, 1.f, 1.f, 0.f);
    glEnable(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, textureIds[0]); 
    glBegin(GL_QUADS);
    // LEFT SIDE
    glTexCoord2f(1.f, 1.f);
    glVertex3f(-1.f, 1.f, -1.f);
    glTexCoord2f(0.f, 1.f);
    glVertex3f(-1.f, 1.f, 1.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3f(-1.f, 0.f, 1.f);
    glTexCoord2f(1.f, 0.f);  
    glVertex3f(-1.f, 0.f, -1.f);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, textureIds[1]);
    glBegin(GL_QUADS);
    // RIGHT SIDE
    glTexCoord2f(1.f, 1.f);
    glVertex3f(1.f, 1.f, 1.f);
    glTexCoord2f(0.f, 1.f);
    glVertex3f(1.f, 1.f, -1.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3f(1.f, 0.f, -1.f);
    glTexCoord2f(1.f, 0.f);
    glVertex3f(1.f, 0.f, 1.f);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, textureIds[2]);
    glBegin(GL_QUADS);
    //  FAR SIDE
    glTexCoord2f(1.f, 1.f);
    glVertex3f(1.f, 1.f, -1.f);
    glTexCoord2f(0.f, 1.f);
    glVertex3f(-1.f, 1.f, -1.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3f(-1.f, 0.f, -1.f);
    glTexCoord2f(1.f, 0.f);
    glVertex3f(1.f, 0.f, -1.f);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, textureIds[3]);
    glBegin(GL_QUADS);
    // NEAR SIDE
    glTexCoord2f(1.f, 1.f);
    glVertex3f(-1.f, 1.f, 1.f);
    glTexCoord2f(0.f, 1.f);
    glVertex3f(1.f, 1.f, 1.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3f(1.f, 0.f, 1.f);
    glTexCoord2f(1.f, 0.f);
    glVertex3f(-1.f, 0.f, 1.f);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, textureIds[4]);
    glBegin(GL_QUADS);
    // BOTTOM SIDE
    glTexCoord2f(0.f, 0.f);
    glVertex3f(-1.f, 0.f, 1.f);
    glTexCoord2f(1.f, 0.f);
    glVertex3f(1.f, 0.f, 1.f);
    glTexCoord2f(1.f, 1.f);
    glVertex3f(1.f, 0.f, -1.f);
    glTexCoord2f(0.f, 1.f);
    glVertex3f(-1.f, 0.f, -1.f);
    glEnd();
    
    glBindTexture(GL_TEXTURE_2D, textureIds[5]);
    glBegin(GL_QUADS);
    // TOP SIDE
    glTexCoord2f(1.f, 1.f);
    glVertex3f(1.f, 1.f, 1.f);
    glTexCoord2f(0.f, 1.f);
    glVertex3f(-1.f, 1.f, 1.f);
    glTexCoord2f(0.f, 0.f);
    glVertex3f(-1.f, 1.f, -1.f);
    glTexCoord2f(1.f, 0.f);
    glVertex3f(1.f, 1.f, -1.f);
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
}