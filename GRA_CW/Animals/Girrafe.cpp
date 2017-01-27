//
//  Girrafe.cpp
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 04/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#include "Girrafe.h"

/*Initialising the variables in constructor*/
Girrafe::Girrafe(GLuint _textureId) :
animationTime(2.f), neckAngle(-50.f), headX(7.8f), headY(4.2f),earY(4.6f),backLegAngle(-10.f),frontLegAngle(10.f),backLegBottomX(-0.2f),frontLegBottomX(0.1f){
    textureId = _textureId;
}

/*Girrafe movenment animations. Legs and girrafe itself is animated*/
void Girrafe::update(float dT){
    // Overloaded update function
    
    aT = fmod(aT + dT, animationTime);
    float aS = 2.f*aT / animationTime;
    if(isEatingGirrafe == true){
        if(aS < 1.f){
            neckAngle = -50.f;
            headY = 4.2f;
            earY = 4.6f;
        }else{
            neckAngle = -70.f;
            headY = 3.2f;
            earY = 3.6f;
        }
    }else{
        pos[2]-=60.f*dT;
        
        if(aS < 1.f){
            backLegAngle = 10.f;
            backLegBottomX = 0.2f;
            frontLegAngle = 30.f;
            frontLegBottomX = 0.3f;
        }else{
            backLegAngle = -10.f;
            backLegBottomX = -0.2f;
            frontLegAngle = 10.f;
            frontLegBottomX = 0.1f;
        }
        
    }
}

/*Displaying the girrafe*/
void Girrafe::display(){
    glDisable(GL_LIGHTING);
    glPushMatrix();
    glPushAttrib(GL_ALL_ATTRIB_BITS);
   
    glColor3f(0.5f, 0.5f, 0.5f);
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.f, 1.f, 0.f);
    glRotatef(rotation[2], 0.f, 0.f, 1.f);
    glRotatef(rotation[0], 1.f, 0.f, 0.f);
  
    glEnable(GL_CULL_FACE);
    
    drawGirrafe();
    
    glPopAttrib();
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

/*Girrafe is drawn*/
void Girrafe::drawGirrafe(){
    glTranslatef(0.f, 2.f, 0.f);
    
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    box(6.f, 2.f, 2.f);
   
    glPushMatrix();
    glTranslatef(2.0f, 1.5f, 1.f);
    drawFrontLeg();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(2.55f, 1.5f, -1.f);
    drawFrontLeg();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.50f, 1.5f, 1.f);
    drawBackLeg();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2.05f, 1.5f, -1.f);
    drawBackLeg();
    
    glPopMatrix();
    glPushMatrix();
    glTranslatef(4.7f, 1.5f, 0.f);
    glRotatef(neckAngle,0.f,0.f,1.f);
    drawNeck();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(headX, headY, 0.f);
    glRotatef(-138.f,0.f,0.f,1.f);
    drawHead();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-3.6f, 0.f, 0.f);
    glRotatef(-30.f, 0.0f, 0.f, 1.f);
    drawTail();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(7.1f, earY, 0.f);
    glRotatef(60.f, 0.0f, 0.f, 1.f);
    drawHone();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(7.56f, earY, 0.f);
    glRotatef(-10.f, 0.0f, 0.f, 1.f);
    drawHone();
    glPopMatrix();
    
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
}

//Drawing back leg
void Girrafe::drawBackLeg(){
    glPushMatrix();
    glTranslatef(0.f, -3.f, 0.f);
    glRotatef(backLegAngle, 0.f, 0.f, 1.f);
    box(0.5f, 2.5f, 0.25f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(backLegBottomX, -5.5f, 0.f);
    box(0.5f, 2.5f, 0.25f);
    glPopMatrix();
    
}

//Drawing front leg
void Girrafe::drawFrontLeg(){
    glPushMatrix();
    glTranslatef(0.f, -3.f, 0.f);
    glRotatef(frontLegAngle, 0.f, 0.f, 1.f);
    box(0.5f, 1.5f, 0.25f);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(frontLegBottomX, -4.5f, 0.f);
    box(0.5f, 2.5f, 0.25f);
    glPopMatrix();
    
}

//Drawing the neck
void Girrafe::drawNeck(){
    glTranslatef(0.f, 0.75f, 0.f);
    box(0.5f, 6.2f, 0.8f);
    glTranslatef(0.f, 0.75f, 0.f);
}

//Drawing the head
void Girrafe::drawHead(){
    glTranslatef(0.f, 1.f, 0.f);
    box(1.f, 2.5f, 0.75f);
}

//Drawing the hones
void Girrafe::drawHone(){
    box(.2f, 1.f, 0.2f);
}
//Drawing the tail
void Girrafe::drawTail(){
    box(0.2f, 2.5f, 0.2f);
}

//Returing each body part as a box with texture
void Girrafe::box(float sx, float sy, float sz){
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
