//
//  Castle.cpp
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 01/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#include "Castle.h"

//Initialising the texture id array
Castle::Castle(GLuint _textureId){
    textureId = _textureId;
}

//Displaying the castle
void Castle::display(){
    glDisable(GL_LIGHTING);
    glPushMatrix();
    
    glColor3f(0.5f, 0.5f, 0.5f);
    
    glEnable(GL_CULL_FACE);
    
    drawCastle();
    
    glPopMatrix();
    glEnable(GL_LIGHTING);
}


void Castle::update(float dT){
    // Overloaded update function
    
}

//Drawing the castle
void Castle::drawCastle(){
    drawLeftBuilding();
    drawRightBuilding();
}


//Drawing the left building. glDrawElements, glTexCoordPointer and gl vertexPointer is used to draw the building and texture it using a predefined points in the header file
void Castle::drawLeftBuilding(){
    /*Left Building*/
    glPushMatrix();
    
    glTranslatef(-320.f,220.f,-1000.f);
    glScalef(scale[0], scale[1], scale[2]);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glTexCoordPointer(2, GL_FLOAT, 0, texcoordsBuilding);
    glVertexPointer(3, GL_FLOAT, 0, verticesBuilding);
    
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndicesBuilding);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
    
    /*Left Tower*/
    glPushMatrix();
    
    glTranslatef(-720.f,220.f,-1000.f);
    glScalef(scale[0], scale[1], scale[2]);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glTexCoordPointer(2, GL_FLOAT, 0, texcoordsTower);
    glVertexPointer(3, GL_FLOAT, 0, verticesTower);
    
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndicesTower);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
    
}


//Drawing the right building. glDrawElements, glTexCoordPointer and gl vertexPointer is used to draw the building and texture it using a predefined points in the header file
void Castle::drawRightBuilding(){
    /*Right Tower*/
    glPushMatrix();
    
    glTranslatef(1200.f,220.f,-1100.f);
    glScalef(scale[0], scale[1], scale[2]);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glTexCoordPointer(2, GL_FLOAT, 0, texcoordsTower);
    glVertexPointer(3, GL_FLOAT, 0, verticesTower);
    
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndicesTower);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
    
    /*Right Building*/
    glPushMatrix();
    
    glTranslatef(780.f,220.f,-1100.f);
    glScalef(scale[0], scale[1], scale[2]);
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glTexCoordPointer(2, GL_FLOAT, 0, texcoordsBuilding);
    glVertexPointer(3, GL_FLOAT, 0, verticesBuilding);
    
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndicesBuilding);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisable(GL_TEXTURE_2D);
    
    glPopMatrix();
    
}
