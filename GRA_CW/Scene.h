//
//  Scene.h
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 03/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#ifndef __GRA_CW__Scene__
#define __GRA_CW__Scene__

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>

#define _USE_MATH_DEFINES
#include <cmath>
#include "BgSkybox.h"
#include "Sun.h"
#include "Castle.h"
#include "LeftDoor.h"
#include "RightDoor.h"
#include "GreenTree.h"
#include "Road.h"
#include "Train.h"
#include "Girrafe.h"
#include "Lamp.h"
#include "TextureManager.h"
#include <string>
#include <map>

TextureManager textureManager;
int width;
int height;
int prevTime;
float camrad, camangle = 0.f;
float eye[3];
float cen[3];

map<string,DisplayableObject*> objects;
map<string,AnimatedObject*> animate;

void setGlobalLight();
void keyPressed(unsigned char key, int xm, int ym);
void keyPressed(int keyCode, int xm, int ym);
void positionCamera();
void cameraRadius();
float runTime();
void reshape(int _width, int _height);
int main(int argc, char **argv);
void setup();
void draw();
void checkGLError();
void destroyObjects();

#endif /* defined(__GRA_CW__Scene__) */
