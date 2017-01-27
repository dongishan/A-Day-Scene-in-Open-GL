//
//  Lamp.cpp
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 02/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#include "Lamp.h"

Lamp::Lamp(GLuint* _textureIds){
    textureIds = _textureIds;
}

void Lamp::update(float dT){
    //Change lamp fire color
}


/*Initialing the lamp*/
void Lamp::display(){
    glPushMatrix();
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[0], 1.f, 0.f, 0.f);
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    glColor3f(0.5f, 0.5f, 0.5f);
    
    glEnable(GL_CULL_FACE);
    
    drawLamp();
    
    glPopAttrib();
    glPopMatrix();
    
}

/*Drawing the lamp in to stages - top and stick*/
void Lamp::drawLamp(){
    
    drawStick();
    drawTop();
}

/*Drawing the lamp top with ligting enabled*/
void Lamp::drawTop(){
    glPushMatrix();
    glTranslatef(0.f, 5.f, 0.f);
    glRotatef(-90, 1.f, 0.f, 0.f);
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, textureIds[1]);
    
    float colour[] = { 1.f, 1.f, 1.f, 1.f };
    float ambient[] = { 1.f, 1.f, 1.f, 1.f };
    float specular[] = { 1.f, 1.f, 1.f, 1.f };
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, colour);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    
    glNormal3f(0.f, 0.f, 0.f);
    glutSolidCone(2.f, 4.f, 10, 1);
    
    glPopAttrib();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    
    glPopMatrix();
}

/*Drawing the stick with lighting enabled*/
void Lamp::drawStick(){
    glPushMatrix();
    glScalef(1.f, 30.f, 1.f);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureIds[0]);
    
    float colour[]
    = { 1.f, 1.f, 1.f, 1.f };
    float ambient[]
    = { 1.f, 1.f, 1.f, 1.f };
    float specular[]
    = { 1.f, 1.f, 1.f, 1.f };
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, colour);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
   
    
    glBegin(GL_POLYGON);
    
    glTexCoord2f(0.0f, 0.0f); glVertex3f( -0.2, -0.2, -0.2);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( -0.2,  0.2, -0.2);
    glTexCoord2f(1.0f, 1.0f);glVertex3f(  0.2,  0.2, -0.2);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(  0.2, -0.2, -0.2);
    
    
    glEnd();
    //BACK
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(  0.2, -0.2, 0.2 );
    glTexCoord2f(1.0f, 0.0f);glVertex3f(  0.2,  0.2, 0.2 );
    glTexCoord2f(1.0f, 1.0f);glVertex3f( -0.2,  0.2, 0.2 );
    glTexCoord2f(0.0f, 1.0f);glVertex3f( -0.2, -0.2, 0.2 );
    glEnd();
    
    //RIGHT
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);glVertex3f( 0.2, -0.2, -0.2 );
    glTexCoord2f(1.0f, 0.0f);glVertex3f( 0.2,  0.2, -0.2 );
    glTexCoord2f(1.0f, 1.0f);glVertex3f( 0.2,  0.2,  0.2 );
    glTexCoord2f(0.0f, 1.0f);glVertex3f( 0.2, -0.2,  0.2 );
    glEnd();
    
    //LEFT
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);glVertex3f( -0.2, -0.2,  0.2 );
    glTexCoord2f(1.0f, 0.0f);glVertex3f( -0.2,  0.2,  0.2 );
    glTexCoord2f(1.0f, 1.0f);glVertex3f( -0.2,  0.2, -0.2 );
    glTexCoord2f(0.0f, 1.0f);glVertex3f( -0.2, -0.2, -0.2 );
    glEnd();
    
    //TOP
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(  0.2,  0.2,  0.2 );
    glTexCoord2f(1.0f, 0.0f);glVertex3f(  0.2,  0.2, -0.2 );
    glTexCoord2f(1.0f, 1.0f);glVertex3f( -0.2,  0.2, -0.2 );
    glTexCoord2f(0.0f, 1.0f); glVertex3f( -0.2,  0.2,  0.2 );
    glEnd();
    
    //BOTTOM
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0f, 0.0f);glVertex3f(  0.2, -0.2, -0.2 );
    glTexCoord2f(1.0f, 0.0f);glVertex3f(  0.2, -0.2,  0.2 );
    glTexCoord2f(1.0f, 1.0f);glVertex3f( -0.2, -0.2,  0.2 );
    glTexCoord2f(0.0f, 1.0f);glVertex3f( -0.2, -0.2, -0.2 );
    glEnd();
    
    glPopAttrib();
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
    
}