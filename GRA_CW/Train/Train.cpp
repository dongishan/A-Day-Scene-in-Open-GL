//
//  Train.cpp
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 04/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#include "Train.h"

Train::Train(GLuint* _textureIds){
    textureIds = _textureIds;
}

void Train::update(float dT){
    // Overloaded update function
    if(pos[0]>-1000.f){
        pos[0] -= 400.f*dT;
    }else{
        rotation[0]=-90;
        pos[2]-=150.f*dT;
    }
}

void Train::display(){
    glDisable(GL_LIGHTING);
    glPushMatrix();
    
    glColor3f(0.5f, 0.5f, 0.5f);
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[0], 0.f, 1.f, 0.f);
    
    glEnable(GL_CULL_FACE);
    
    drawTrain();
    
    glPopMatrix();
    glEnable(GL_LIGHTING);
    
}

void Train::drawTrain(){
    glPushMatrix();
    drawCarriage();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-7.f, 10.f, 0.f);
    drawSmokePipe();
    glPopMatrix();
    
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureIds[3]);
    glTranslatef(-12.f, 5.f, 0.f);
    box(4.f,3.f, 3.f);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(12.f, 0.f, 0.f);
    drawConnector();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(24.f, 0.f, 0.f);
    drawCarriage();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(36.f, 0.f, 0.f);
    drawConnector();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(48.f, 0.f, 0.f);
    drawCarriage();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(60.f, 0.f, 0.f);
    drawConnector();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(72.f, 0.f, 0.f);
    drawCarriage();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(84.f, 0.f, 0.f);
    drawConnector();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(96.f, 0.f, 0.f);
    drawCarriage();
    glPopMatrix();
    
    
}

void Train::drawSmokePipe(){
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureIds[0]);
    
    glRotatef(90.f, 0.f, 0.f, 1.f);
    box(5.f, 2.f, 2.f);
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
}
void Train::drawConnector(){
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureIds[1]);
    
    glTranslatef(0.f, 5.f, 0.f);
    box(5.f, 2.f, 2.f);
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
}

void Train::drawCarriage(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureIds[0]);
    
    glPushMatrix();
    glTranslatef(0.f, 5.f, 0.f);
    box(20.f, 5.f, 5.f);
    glPopMatrix();
    
    glPushMatrix();
    drawWheel(6.f, 2.f, 2.f,0.f);
    glPopMatrix();
    
    glPushMatrix();
    drawWheel(-6.f, 2.f, 2.f,0.f);
    glPopMatrix();
    
    glPushMatrix();
    drawWheel(-6.f, 2.f, -2.5f,-180.f);
    glPopMatrix();
    
    glPushMatrix();
    drawWheel(6.f, 2.f, -2.5f,-180.f);
    glPopMatrix();
    
    glDisable(GL_TEXTURE_2D);
    
}

void Train::drawWheel(float tx,float ty, float tz,float wAngle){
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureIds[1]);
    glTranslatef(tx, ty, tz);
    glRotatef(wAngle, 0.f, 0.1f, 0.f);
    glutSolidCone(2.f, 1.f, 50, 100);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    
}

void Train::box(float sx, float sy, float sz){
    glPushMatrix();
    glScalef(sx, sy, sz);
    glBegin(GL_POLYGON);
    
    glTexCoord2f(0.0f, 0.0f); glVertex3f( -0.5, -0.5, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( -0.5,  0.5, -0.5);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(  0.5,  0.5, -0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(  0.5, -0.5, -0.5);
    
    glEnd();
    // BACK
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(  0.5, -0.5, 0.5 );
    glTexCoord2f(1.0f, 0.0f);glVertex3f(  0.5,  0.5, 0.5 );
    glTexCoord2f(1.0f, 1.0f);glVertex3f( -0.5,  0.5, 0.5 );
    glTexCoord2f(0.0f, 1.0f);glVertex3f( -0.5, -0.5, 0.5 );
    glEnd();
    
    //RIGHT
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);glVertex3f( 0.5, -0.5, -0.5 );
    glTexCoord2f(1.0f, 0.0f);glVertex3f( 0.5,  0.5, -0.5 );
    glTexCoord2f(1.0f, 1.0f);glVertex3f( 0.5,  0.5,  0.5 );
    glTexCoord2f(0.0f, 1.0f);glVertex3f( 0.5, -0.5,  0.5 );
    glEnd();
    
    // LEFT
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);glVertex3f( -0.5, -0.5,  0.5 );
    glTexCoord2f(1.0f, 0.0f);glVertex3f( -0.5,  0.5,  0.5 );
    glTexCoord2f(1.0f, 1.0f);glVertex3f( -0.5,  0.5, -0.5 );
    glTexCoord2f(0.0f, 1.0f);glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    
    //TOP
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(  0.5,  0.5,  0.5 );
    glTexCoord2f(1.0f, 0.0f);glVertex3f(  0.5,  0.5, -0.5 );
    glTexCoord2f(1.0f, 1.0f);glVertex3f( -0.5,  0.5, -0.5 );
    glTexCoord2f(0.0f, 1.0f); glVertex3f( -0.5,  0.5,  0.5 );
    glEnd();
    
    // BOTTOM
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(  0.5, -0.5, -0.5 );
    glTexCoord2f(1.0f, 0.0f);glVertex3f(  0.5, -0.5,  0.5 );
    glTexCoord2f(1.0f, 1.0f);glVertex3f( -0.5, -0.5,  0.5 );
    glTexCoord2f(0.0f, 1.0f);glVertex3f( -0.5, -0.5, -0.5 );
    glEnd();
    glPopMatrix();
}
