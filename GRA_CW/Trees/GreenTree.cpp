//
//  GreenTree.cpp
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 02/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#include "GreenTree.h"

//Drawing the tree
GreenTree::GreenTree(GLuint* _textureIds,bool _doAnimate){
    textureIds = _textureIds;
    cone1ExtraY = 110.f;
    cone2ExtraY = 180.f;
    cone3ExtraY = 250.f;
    doAnimate = _doAnimate;
    rotation[0] = -90;
}


void GreenTree::update(float dT){
    // Overloaded update function
    if(doAnimate){
    }
}

//Displaying the tree
void GreenTree::display(){
    glDisable(GL_LIGHTING);
    glPushMatrix();
    
    glColor3f(0.5f, 0.5f, 0.5f);
    
    glEnable(GL_CULL_FACE);
    
    drawTree();
    
    glPopMatrix();
    glEnable(GL_LIGHTING);
    
}

void GreenTree::drawTree(){
    drawBottom();
    drawTop();
}

//Drawing the tree top using glSolidCone
void GreenTree::drawTop(){
    glPushMatrix();
    
    glTranslatef(pos[0], pos[1]+cone1ExtraY, pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[0], 1.f, 0.f, 0.f);
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, textureIds[1]);
    
    glutSolidCone(1.f, 2.f, 10, 1);
    
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();
    
    
    glPushMatrix();
    
    glTranslatef(pos[0], pos[1]+cone2ExtraY, pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[0], 1.f, 0.f, 0.f);
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, textureIds[1]);
    
    glutSolidCone(1.f, 2.f, 10, 1);
    
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();
    
    glPushMatrix();
    
    glTranslatef(pos[0], pos[1]+cone3ExtraY, pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[0], 1.f, 0.f, 0.f);
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, textureIds[1]);
    
    glutSolidCone(1.f, 2.f, 10, 1);
    
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    
    glPopMatrix();
    
}

//drawing the tree bottom as a cylinder
void GreenTree::drawBottom(){
    glPushMatrix();
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.f, 0.f, 0.f);
    
    float res = 0.1f*M_PI;
    float r = 0.15f;
    float x = r, z = 0.f;
    float t = 0.f;
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureIds[0]);
    do{
        glBegin(GL_QUADS);
        glNormal3f(x, 0.f, z);
        glTexCoord2f(0.f, 0.f);
        glVertex3f(x, 0.f, z);
        glTexCoord2f(0.f, 1.f);
        glVertex3f(x, 1.f, z);
        t += res;
        x = r*cos(t);
        z = r*sin(t);
        glNormal3f(x, 0.f, z);
        glTexCoord2f(1.f, 1.f);
        glVertex3f(x, 1.f, z);
        glTexCoord2f(1.f, 0.f);
        glVertex3f(x, 0.f, z);
        glEnd();
    } while (t <= 2 * M_PI);
    glDisable(GL_TEXTURE_2D);
    glPopAttrib();
    glPopMatrix();
}