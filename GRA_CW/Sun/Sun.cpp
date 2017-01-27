//
//  Sun.cpp
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 01/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#include "Sun.h"

//Initialing the textures and two castle doors
Sun::Sun(GLuint _textureId,LeftDoor* _leftDoor,RightDoor* _rightDoor){
    textureId = _textureId;
    leftDoor = _leftDoor;
    rightDoor = _rightDoor;
}

//Moving the sun to show sun rise and set. Als the doCloseDoor boolean is set to true or false based on the sun's location so the doors can be closed or opened.
void Sun::update(float dT){
    // Overloaded update function
    pos[0]-= 30.0f*dT;
    if(pos[0] > 0.0f){
        pos[1] += 10.0f*dT;
    }else{
        pos[1] -= 10.0f*dT;
    }
    
    if(pos[0]<=-800.f){
        leftDoor->doCloseDoor = true;
        rightDoor->doCloseDoor = true;
    }

    if(pos[0] < -1400.f){
        pos[0] = 1200.f;
        leftDoor->doCloseDoor = false;
        rightDoor->doCloseDoor = false;
        
    }
}

//Displaying the sun
void Sun::display(){
    glDisable(GL_LIGHTING);
    glPushMatrix();
    
    glColor3f(0.5f, 0.5f, 0.5f);
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[1], 0.f, 0.f, 0.f);
    
    glEnable(GL_CULL_FACE);
    
    drawSun();
    
    glPopMatrix();
    glEnable(GL_LIGHTING);
    
}

//Drawing the sun
void Sun::drawSun(){
    glPushMatrix();
    
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glBindTexture(GL_TEXTURE_2D, textureId);
    
    glutSolidSphere(1.f, 50, 50);
    
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
    glPopMatrix();
}