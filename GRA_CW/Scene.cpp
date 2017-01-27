//
//  Scene.cpp
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 03/05/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#include "Scene.h"

/*Returns the delta time for the animations*/
float runtime(){
    int currTime = glutGet(GLUT_ELAPSED_TIME);
    float dT = (float)(currTime - prevTime)/1000.f;
    prevTime = currTime;
    return dT;
}

/*Setting the global light to the scene. Objects has liting enable and reflect this light*/
void setGlobalLight(){
    float ambient[]  = { .2f, .2f, .2f, 1.f };
    float diffuse[]  = { .5f, .5f, .5f, 1.f };
    float specular[] = { 1.f, 1.f, 1.f, 1.f };
    float position[] = { 1.f, .5f, 1.f, 0.f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

/*Drawing the scene*/
void draw(){
    glClearColor(1.f,1.f,1.f,1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    setGlobalLight();
    positionCamera();
    
    glTranslatef(0.f, -height / 2.f, 0.f);
    glColor3f(0.f, 0.f, 0.f);
    
    glEnable(GL_NORMALIZE);
    
    for (map <string, DisplayableObject*>::iterator itr = objects.begin(); itr != objects.end(); ++itr){
        itr->second->display();
    }
    
    float dT = runtime();
    for (map <string, AnimatedObject*>::iterator itr = animate.begin(); itr != animate.end(); ++itr){
        itr->second->update(dT);
        itr->second->display();
    }
    
    checkGLError();
    glutSwapBuffers();
    
}

void reshape(int _width, int _height){
    width = _width;
    height = _height;
    cameraRadius();
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, (GLdouble)width / (GLdouble)height, 10.0, camrad*5.f);
    //  gluOrtho2D(100, 1200, 1000, 400);
    glMatrixMode(GL_MODELVIEW);
}

/*Initialising the scene window and initialising the objects*/
void setup(){
    
    width = 1200;
    height = 800;
    
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    //Centering the scene
    glutInitWindowPosition (100,100);
    glutCreateWindow("GRA CW");
    
    cameraRadius();
    
    GLuint* skyboxes = new GLuint[6];
    skyboxes[0] = textureManager.loadImage("skybox_left.bmp");
    skyboxes[1] = textureManager.loadImage("skybox_right.bmp");
    skyboxes[2] = textureManager.loadImage("skybox_front.bmp");
    skyboxes[3] = textureManager.loadImage("skybox_back.bmp");
    skyboxes[4] = textureManager.loadImage("skybox_down.bmp");
    skyboxes[5] = textureManager.loadImage("skybox_up.bmp");
    
    BgSkybox* background = new BgSkybox(skyboxes);
    background->size(camrad);
    objects["1.background"] = background;
    
    GLuint wallTexture = textureManager.loadImage("wall.bmp");
    Castle *castle = new Castle(wallTexture);
    castle->size(100.f);
    animate["3.castle"] = castle;
    
    GLuint doorTexture = textureManager.loadImage("door.bmp");
    LeftDoor *leftDoor = new LeftDoor(doorTexture);
    leftDoor->position(30.f,200.f,-1000.f);
    leftDoor->size(100.f);
    animate["4.leftDoor"] = leftDoor;
    
    RightDoor *rightDoor = new RightDoor(doorTexture);
    rightDoor->position(480.f,200.f,-1000.f);
    rightDoor->size(100.f);
    animate["5.rightDoor"] = rightDoor;
    
    GLuint sunTexture = textureManager.loadImage("sun_texture.bmp");
    Sun *sun = new Sun(sunTexture,leftDoor,rightDoor);
    sun->position(width/1.f,700.f,-width/2.f);
    sun->size(80.f);
    animate["2.sun"] = sun;
    
    GLuint* treeTextures = new GLuint[2];
    GLuint rootTexture = textureManager.loadImage("tree_root.bmp");
    GLuint leafTexture = textureManager.loadImage("leaf_texture.bmp");
    
    treeTextures[0] = rootTexture;
    treeTextures[1] = leafTexture;
    
    GreenTree *greenTree1 = new GreenTree(treeTextures,false);
    greenTree1->position(-800.f,200.f,-200.f);
    greenTree1->size(120.f);
    animate["6.greenTree1"] = greenTree1;
    
    GreenTree *greenTree2 = new GreenTree(treeTextures,false);
    greenTree2->position(-1200.f,400.f,-200.f);
    greenTree2->size(120.f);
    animate["7.greenTree2"] = greenTree2;
    
    GreenTree *greenTree3 = new GreenTree(treeTextures,false);
    greenTree3->position(1000.f,400.f,-200.f);
    greenTree3->size(120.f);
    animate["8.greenTree3"] = greenTree3;
    
    GreenTree *greenTree4 = new GreenTree(treeTextures,false);
    greenTree4->position(600.f,200.f,-200.f);
    greenTree4->size(110.f);
    animate["9.greenTree4"] = greenTree4;
    
    GreenTree *greenTree5 = new GreenTree(treeTextures,false);
    greenTree5->position(800.f,200.f,-3000.f);
    greenTree5->size(110.f);
    animate["10.greenTree5"] = greenTree5;
    
    GLuint roadTexture = textureManager.loadImage("road_texture.bmp");
    Road *road = new Road(roadTexture);
    road->position(400.f,100.f,-2000.f);
    road->size(100.f);
    objects["11.road"] = road;
    
    Road *road2 = new Road(roadTexture);
    road2->position(400.f,100.f,-1000.f);
    road2->size(100.f);
    objects["12.road2"] = road2;
    
    
    Road *road3 = new Road(roadTexture);
    road3->position(400.f,100.f,0.f);
    road3->size(100.f);
    objects["13.road3"] = road3;
    
    Road *road4 = new Road(roadTexture);
    road4->position(400.f,100.f,1000.f);
    road4->size(100.f);
    objects["14.road4"] = road4;
    
    Road *road5 = new Road(roadTexture);
    road5->position(400.f,100.f,2000.f);
    road5->size(100.f);
    objects["15.road5"] = road5;
    
    GLuint girrafeSkinTexture1 = textureManager.loadImage("deer_skin_texture.bmp");
    GLuint girrafeSkinTexture2 = textureManager.loadImage("girrafe_skin_texture_2.bmp");
    
    Girrafe* girrafe1 = new Girrafe(girrafeSkinTexture1);
    girrafe1->position(-500.f,250.f,100.f);
    girrafe1->orientation(0.f, 130.f, 0.f);
    girrafe1->size(20.f);
    girrafe1->isEatingGirrafe = true;
    animate["z1"] = girrafe1;
    
    Girrafe* girrafe2 = new Girrafe(girrafeSkinTexture1);
    girrafe2->position(680.f,250.f,100.f);
    girrafe2->orientation(0.f, 110.f, 0.f);
    girrafe2->size(20.f);
    girrafe2->isEatingGirrafe = true;
    animate["z2"] = girrafe2;
    
    Girrafe* girrafe3 = new Girrafe(girrafeSkinTexture1);
    girrafe3->position(-1200.f,450.f,100.f);
    girrafe3->orientation(0.f, 0.f, 0.f);
    girrafe3->size(20.f);
    girrafe3->isEatingGirrafe = true;
    animate["z3"] = girrafe3;
    
    Girrafe* girrafe4 = new Girrafe(girrafeSkinTexture1);
    girrafe4->position(150.f,100.f,100.f);
    girrafe4->orientation(0.f, 90.f, 0.f);
    girrafe4->size(20.f);
    animate["z4"] = girrafe4;
    
    Girrafe* girrafe5 = new Girrafe(girrafeSkinTexture2);
    girrafe5->position(-650.f,200.f,100.f);
    girrafe5->orientation(0.f, 40.f, 0.f);
    girrafe5->size(8.f);
    girrafe5->isEatingGirrafe = true;
    animate["z5"] = girrafe5;
    
    Girrafe* girrafe6 = new Girrafe(girrafeSkinTexture2);
    girrafe6->position(-550.f,180.f,100.f);
    girrafe6->orientation(0.f, -100.f, 0.f);
    girrafe6->size(5.f);
    girrafe6->isEatingGirrafe = true;
    animate["z6"] = girrafe6;
    
    Girrafe* girrafe7 = new Girrafe(girrafeSkinTexture2);
    girrafe7->position(-250.f,100.f,100.f);
    girrafe7->orientation(0.f, -150.f, 0.f);
    girrafe7->size(7.f);
    girrafe7->isEatingGirrafe = true;
    animate["z7"] = girrafe7;
    
    Girrafe* girrafe8 = new Girrafe(girrafeSkinTexture1);
    girrafe8->position(100.f,100.f,4000.f);
    girrafe8->orientation(0.f,70.f, 0.f);
    girrafe8->size(30.f);
    animate["z8"] = girrafe8;
    
    Girrafe* girrafe9 = new Girrafe(girrafeSkinTexture1);
    girrafe9->position(-1200.f,10.f,100.f);
    girrafe9->orientation(0.f, 0.f, 0.f);
    girrafe9->size(40.f);
    animate["z9"] = girrafe9;
    
    GLuint *lampTextures = new GLuint[2];
    GLuint lampStickTexture = textureManager.loadImage("lamp_texture.bmp");
    GLuint lampCoverTexture = textureManager.loadImage("lamp_cover_texture.bmp");
    lampTextures[0] = lampStickTexture;
    lampTextures[1] = lampCoverTexture;
    
    Lamp* lamp0 = new Lamp(lampTextures);
    lamp0->position(1200.f,0.f,-2200.f);
    lamp0->orientation(0.f, 0.f, 0.f);
    lamp0->size(40.f);
    animate["zlamp0"] = lamp0;
    
    
    Lamp* lamp1 = new Lamp(lampTextures);
    lamp1->position(20.f,0.f,-1700.f);
    lamp1->orientation(0.f, 0.f, 0.f);
    lamp1->size(40.f);
    animate["zlamp1"] = lamp1;
    
    Lamp* lamp2 = new Lamp(lampTextures);
    lamp2->position(1200.f,0.f,-1700.f);
    lamp2->orientation(0.f, 0.f, 0.f);
    lamp2->size(40.f);
    animate["zlamp2"] = lamp2;
    
    Lamp* lamp3 = new Lamp(lampTextures);
    lamp3->position(20.f,0.f,-1300.f);
    lamp3->orientation(0.f, 0.f, 0.f);
    lamp3->size(40.f);
    animate["zlamp3"] = lamp3;
    
    Lamp* lamp4 = new Lamp(lampTextures);
    lamp4->position(1200.f,0.f,-1300.f);
    lamp4->orientation(0.f, 0.f, 0.f);
    lamp4->size(40.f);
    animate["zlamp4"] = lamp4;
    
    Lamp* lamp5 = new Lamp(lampTextures);
    lamp5->position(20.f,0.f,-900.f);
    lamp5->orientation(0.f, 0.f, 0.f);
    lamp5->size(40.f);
    animate["zlamp5"] = lamp5;
    
    Lamp* lamp6 = new Lamp(lampTextures);
    lamp6->position(1200.f,0.f,-900.f);
    lamp6->orientation(0.f, 0.f, 0.f);
    lamp6->size(40.f);
    animate["zlamp6"] = lamp6;
    
    GLuint *trainTextures = new GLuint[2];
    GLuint carriageTexture = textureManager.loadImage("train_texture.bmp");
    GLuint connectorTexture = textureManager.loadImage("train_con_texture.bmp");
    GLuint wheelTexture = textureManager.loadImage("train_wheel.bmp");
    GLuint faceTexture = textureManager.loadImage("train_face.bmp");
    
    trainTextures[0] = carriageTexture;
    trainTextures[1] = connectorTexture;
    trainTextures[2] = wheelTexture;
    trainTextures[3] = faceTexture;
    
    Train* train = new Train(trainTextures);
    train->position(1000.f,400.f,3000.f);
    train->orientation(0.f, 0.f, 0.f);
    train->size(40.f);
    animate["1.train"] = train;
    
    reshape(width, height);
    prevTime = glutGet(GLUT_ELAPSED_TIME);
    
    cen[0] = 0.f;
    cen[1] = 0.f;
    cen[2] = 0.f;
    
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    setup();
    glutKeyboardFunc(keyPressed);
    glutSpecialFunc(keyPressed);
    
    glutDisplayFunc(draw);
    glutIdleFunc(draw);
    glutReshapeFunc(reshape);
    
    checkGLError();
    glutMainLoop();
    destroyObjects();
    return 0;
}

//Handling left and right arrow keys
void keyPressed(int keyCode, int xm, int ym){
    float incr = (float)M_PI / 36.f;
    if (keyCode == GLUT_KEY_LEFT){
        camangle -= incr;
    } else if (keyCode == GLUT_KEY_RIGHT){
        camangle += incr;
    }
}

//Resetting the camera when space key pressed
void keyPressed(unsigned char key, int xm, int ym){
    if (key == ' '){
        camangle = 0.f;
    }
}

//Initialising the camera
void positionCamera(){
    cameraRadius();
    eye[0] = camrad*sin(camangle);
    eye[1] = cen[1];
    eye[2] = camrad*cos(camangle);
    gluLookAt(eye[0], eye[1], eye[2],
              cen[0], cen[1], cen[2],
              0.f, 1.f, 0.f);
}

//Calcuslating camera radius
void cameraRadius(){
    camrad = (height / 2.f) / tan(M_PI / 8.f);
}

//Destroying the objects from memory
void destroyObjects(){
    for (map <string, DisplayableObject*>::iterator itr = objects.begin(); itr != objects.end(); ++itr){
        delete itr->second;
    }
    for (map <string, AnimatedObject*>::iterator itr = animate.begin(); itr != animate.end(); ++itr){
        delete itr->second;
    }
    objects.clear();
    animate.clear();
}

//Printing open gl errors
void checkGLError(){
    int e = 0;
    GLenum error = glGetError();
    while(GL_NO_ERROR != error){
        e++;
        printf("GL Error %i: %s\n", e, gluErrorString(error));
        error = glGetError();
    }
    
    
}