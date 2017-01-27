//
//  RightDoor.cpp
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 02/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#include "RightDoor.h"

RightDoor::RightDoor(GLuint _textureId){
    textureId = _textureId;
}

//Opening the door when sun rises. And closing when sun sets. The boolean is controled at the sun.cpp
void RightDoor::update(float dT){
    // Overloaded update function
        if(doCloseDoor == false && rotation[0]<85){
            printf("opening right door\n");
            rotation[0]+= 11.f*dT;
            pos[0]+=5.5f*dT;
        }else if(doCloseDoor == true && rotation[0]>0){
            printf("opening right door\n");
            rotation[0]-= 11.f*dT;
            pos[0]-=5.5f*dT;
        }
}

void RightDoor::display(){
    glDisable(GL_LIGHTING);
    glPushMatrix();
    
    glColor3f(0.5f, 0.5f, 0.5f);
    
    glEnable(GL_CULL_FACE);
    
    drawDoor();
    
    glPopMatrix();
    glEnable(GL_LIGHTING);
}

//Drawing the right door. glDrawElements, glTexCoordPointer and gl vertexPointer is used to draw the building and texture it using a predefined points in the header file
void RightDoor::drawDoor(){
    glPushMatrix();
    
    glTranslatef(pos[0], pos[1], pos[2]);
    glScalef(scale[0], scale[1], scale[2]);
    glRotatef(rotation[0], 0.f, 1.f, 0.f);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glTexCoordPointer(2, GL_FLOAT, 0, texcoordsDoor);
    glVertexPointer(3, GL_FLOAT, 0, verticesDoor);
    
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndicesDoor);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
    
    
}
