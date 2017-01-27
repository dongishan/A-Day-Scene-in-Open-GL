//
//  MyScene.cpp
//  GRA_CW
//
//  Created by Gishan Don Ranasinghe on 28/04/2015.
//  Copyright (c) 2015 Gishan Don Ranasinghe. All rights reserved.
//

#include "MyScene.h"

float runtime(){  // remember to add declaration in header file
    int currTime = glutGet(GLUT_ELAPSED_TIME);      // number of milliseconds since start of program
    float dT = (float)(currTime - prevTime)/1000.f; // calculate time difference between calls to runtime
    prevTime = currTime;                            // update time variable
    return dT;                                      // return time change
}

void cylinder(float h, float r){
    float res = 0.1*M_PI;           // resolution (in radians: equivalent to 18 degrees)
    float x = r, z = 0.f;           // initialise x and z on right of cylinder centre
    float t = 0.f;                  // initialise angle as 0
    
    do{
        glBegin(GL_LINE_LOOP);          // new QUAD
        // Create first points
        glVertex3f(x, h, z);    // top
        glVertex3f(x, 0.f, z);  // bottom
        // Iterate around circle
        t += res;               // add increment to angle
        x = r*cos(t);           // move x and z around circle
        z = r*sin(t);
        // Close quad
        glVertex3f(x, 0.f, z);  // bottom
        glVertex3f(x, h, z);    // top
        glEnd();                    // end shape
    } while (t <= 2 * M_PI);        // for a full circle (360 degrees)
}

void rectangle(){
    glTranslatef(-25.f, 0.f, 25.f);
    glRotatef(64.f, 0.f, 1.f, 0.0f);
    glScalef(15.f, 30.f, 15.f);         // scale by 10 in x, y, z directions
    glutWireCube(1.f);
    
    glScalef(0.1f, 0.1f, 0.1f);         // reverse the scaling
    glRotatef(-64.f, 0.f, 1.f, 0.f);    // reverse the rotation
    glTranslatef(25, 0.f, -25.f);       // reverse the translation
}



void setGlobalLight(){
    // Set lighting effect colours and positional parameter
    float ambient[]  = { .2f, .2f, .2f, 1.f };      // ambient light (20% white)
    float diffuse[]  = { .5f, .5f, .5f, 1.f };      // diffuse light (50% white)
    float specular[] = { 1.f, 1.f, 1.f, 1.f };      // specular light (100% white)
    float position[] = { 1.f, .5f, 1.f, 0.f };      // directional light (w = 0)
    // Attach properties to single light source (GL_LIGHT0)
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);      // set ambient parameter of light source
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);      // set diffuse parameter of light source
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);    // set specular parameter of light source
    glLightfv(GL_LIGHT0, GL_POSITION, position);    // set direction vector of light source
    // Enable this lighting effects
    glEnable(GL_LIGHTING);  // enable scene lighting (required to enable a light source)
    glEnable(GL_LIGHT0);    // enable light source with attached parameters (GL_LIGHT0)
}


void draw(){
    glClearColor(1.f,1.f,1.f,1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    setGlobalLight();
    positionCamera();                               // set the camera position before anything else
    
    glTranslatef(0.f, -height / 2.f, 0.f);          // can now draw at z = 0
    glColor3f(0.f, 0.f, 0.f);      // set draw colour to black
    
    //rectangle();
    //cylinder(10.0f, 5.0f);
    glEnable(GL_NORMALIZE);
    
    // for each pair in the objects map (in this case, one Tree called "tree")
    // pair is type <string, DisplayableObject*> so must call on 'second' element
    for (map <string, DisplayableObject*>::iterator itr = objects.begin(); itr != objects.end(); ++itr){
        itr->second->display();
    }
    
    // calculate runtime between now and last draw call
    float dT = runtime();
    // for each pair in the animated objects map (in this case, one Horse called "horse")
    // pair is type <string, AnimatedObject*> so must call on 'second' element
    for (map <string, AnimatedObject*>::iterator itr = animate.begin(); itr != animate.end(); ++itr){
        itr->second->update(dT);                        // update based on runtime
        itr->second->display();                         // call display method on AnimatedObject
    }
    
    checkGLError();
    glutSwapBuffers();
    
}

void reshape(int _width, int _height){
    width = _width;                 // update global dimension variables
    height = _height;
    cameraRadius();                 // recalculate camrad variable based on current height
    
    glMatrixMode(GL_PROJECTION);    // switch from model/view to projection mode
    glLoadIdentity();               // reset matrix
    gluPerspective(60.0, (GLdouble)width / (GLdouble)height, 1.0, camrad*5.f);      // perspective
    //  glOrtho(-width/2.f, width/2.f, -height/2.f, height/2.f, 1.f, camrad*2.f);       // orthographic
    glMatrixMode(GL_MODELVIEW);     // return matrix mode to modelling and viewing !IMPORTANT!
}


void setup(){
    width = 1200;
    height = 800;
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutInitWindowPosition (100,100);
    glutCreateWindow("GRA CW");
    
    cameraRadius();                     // initialise camrad variable (based on window height)
    
    GLuint* skybox = new GLuint[6];
    skybox[0] = textureManager.loadImage("skybox_left.bmp");
    skybox[1] = textureManager.loadImage("skybox_right.bmp");
    skybox[2] = textureManager.loadImage("skybox_front.bmp");
    skybox[3] = textureManager.loadImage("skybox_back.bmp");
    skybox[4] = textureManager.loadImage("skybox_down.bmp");
    skybox[5] = textureManager.loadImage("skybox_up.bmp");

    BgSkybox* background = new BgSkybox(skybox);         // new instance of Stage object
    background->size(camrad);                // resize to bound scene
    objects["1.background"] = background;           // Add to objects map with id "stage"
    
    
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
    
    Deer* deer1 = new Deer(girrafeSkinTexture1);                     // create new Horse
    deer1->position(-500.f,250.f,100.f);
    deer1->orientation(0.f, 130.f, 0.f);
    deer1->size(20.f);
    deer1->isEatingGirrafe = true;
    animate["z1"] = deer1;                       // add horse to map of AnimatedObjects
    Deer* deer2 = new Deer(girrafeSkinTexture1);                     // create new Horse
    deer2->position(680.f,250.f,100.f);
    deer2->orientation(0.f, 110.f, 0.f);
    deer2->size(20.f);
    deer2->isEatingGirrafe = true;
    animate["z2"] = deer2;                       // add horse to map of
    
    Deer* deer3 = new Deer(girrafeSkinTexture1);                     // create new Horse
    deer3->position(-1200.f,450.f,100.f);
    deer3->orientation(0.f, 0.f, 0.f);
    deer3->size(20.f);
    deer3->isEatingGirrafe = true;
    animate["z3"] = deer3;                       // add horse to map of
    
    Deer* deer4 = new Deer(girrafeSkinTexture1);                     // create new Horse
    deer4->position(150.f,100.f,100.f);
    deer4->orientation(0.f, 90.f, 0.f);
    deer4->size(20.f);
    animate["z4"] = deer4;                       // add horse to map of
    
    Deer* deer5 = new Deer(girrafeSkinTexture2);                     // create new Horse
    deer5->position(-650.f,200.f,100.f);
    deer5->orientation(0.f, 40.f, 0.f);
    deer5->size(8.f);
    deer5->isEatingGirrafe = true;
    animate["z5"] = deer5;                       // add horse to map of
    
    
    Deer* deer6 = new Deer(girrafeSkinTexture2);                     // create new Horse
    deer6->position(-550.f,180.f,100.f);
    deer6->orientation(0.f, -100.f, 0.f);
    deer6->size(5.f);
    deer6->isEatingGirrafe = true;
    animate["z6"] = deer6;                       // add horse to map of
    
    Deer* deer7 = new Deer(girrafeSkinTexture2);                     // create new Horse
    deer7->position(-250.f,100.f,100.f);
    deer7->orientation(0.f, -150.f, 0.f);
    deer7->size(7.f);
    deer7->isEatingGirrafe = true;
    animate["z7"] = deer7;                       // add horse to map of
    
    Deer* deer8 = new Deer(girrafeSkinTexture1);                     // create new Horse
    deer8->position(100.f,100.f,4000.f);
    deer8->orientation(0.f,70.f, 0.f);
    deer8->size(30.f);
    animate["z8"] = deer8;                       // add horse to map of
    
    Deer* deer9 = new Deer(girrafeSkinTexture1);                     // create new Horse
    deer9->position(-1200.f,10.f,100.f);
    deer9->orientation(0.f, 0.f, 0.f);
    deer9->size(40.f);
    animate["z9"] = deer9;                       // add horse to map of
    
    GLuint *lampTextures = new GLuint[2];
    GLuint lampStickTexture = textureManager.loadImage("lamp_texture.bmp");
    GLuint lampCoverTexture = textureManager.loadImage("lamp_cover_texture.bmp");
    lampTextures[0] = lampStickTexture;
    lampTextures[1] = lampCoverTexture;
    
    Lamp* lamp0 = new Lamp(lampTextures);                     // create new Horse
    lamp0->position(1200.f,0.f,-2200.f);
    lamp0->orientation(0.f, 0.f, 0.f);
    lamp0->size(40.f);
    animate["zlamp0"] = lamp0;

    
    Lamp* lamp1 = new Lamp(lampTextures);                     // create new Horse
    lamp1->position(20.f,0.f,-1700.f);
    lamp1->orientation(0.f, 0.f, 0.f);
    lamp1->size(40.f);
    animate["zlamp1"] = lamp1;
   
    Lamp* lamp2 = new Lamp(lampTextures);                     // create new Horse
    lamp2->position(1200.f,0.f,-1700.f);
    lamp2->orientation(0.f, 0.f, 0.f);
    lamp2->size(40.f);
    animate["zlamp2"] = lamp2;

    Lamp* lamp3 = new Lamp(lampTextures);                     // create new Horse
    lamp3->position(20.f,0.f,-1300.f);
    lamp3->orientation(0.f, 0.f, 0.f);
    lamp3->size(40.f);
    animate["zlamp3"] = lamp3;
    
    Lamp* lamp4 = new Lamp(lampTextures);                     // create new Horse
    lamp4->position(1200.f,0.f,-1300.f);
    lamp4->orientation(0.f, 0.f, 0.f);
    lamp4->size(40.f);
    animate["zlamp4"] = lamp4;
    
    Lamp* lamp5 = new Lamp(lampTextures);                     // create new Horse
    lamp5->position(20.f,0.f,-900.f);
    lamp5->orientation(0.f, 0.f, 0.f);
    lamp5->size(40.f);
    animate["zlamp5"] = lamp5;
    
    Lamp* lamp6 = new Lamp(lampTextures);                     // create new Horse
    lamp6->position(1200.f,0.f,-900.f);
    lamp6->orientation(0.f, 0.f, 0.f);
    lamp6->size(40.f);
    animate["zlamp6"] = lamp6;
    
    Lamp* lamp7 = new Lamp(lampTextures);                     // create new Horse
    lamp7->position(20.f,0.f,-500.f);
    lamp7->orientation(0.f, 0.f, 0.f);
    lamp7->size(40.f);
    animate["zlamp7"] = lamp7;
    
    Lamp* lamp8 = new Lamp(lampTextures);                     // create new Horse
    lamp8->position(1200.f,0.f,-500.f);
    lamp8->orientation(0.f, 0.f, 0.f);
    lamp8->size(40.f);
    animate["zlamp8"] = lamp8;
    
    
    Lamp* lamp10 = new Lamp(lampTextures);                     // create new Horse
    lamp10->position(1200.f,0.f,-100.f);
    lamp10->orientation(0.f, 0.f, 0.f);
    lamp10->size(40.f);
    animate["zlamp10"] = lamp10;
    
    
    Lamp* lamp11 = new Lamp(lampTextures);                     // create new Horse
    lamp11->position(1200.f,0.f,300.f);
    lamp11->orientation(0.f, 0.f, 0.f);
    lamp11->size(40.f);
    animate["zlamp11"] = lamp11;

    
    reshape(width, height);   // call reshape function to set perspective
    prevTime = glutGet(GLUT_ELAPSED_TIME);          // initialise animation timer
    
    cen[0] = 0.f;              // sets model centre (pointing at the origin)
    cen[1] = 0.f;
    cen[2] = 0.f;
    
}

int main(int argc, char **argv){
    glutInit(&argc, argv);          // Initialise GL environment
    setup();                        // Call additional initialisation commands
    
    glutKeyboardFunc(keyPressed);       // ASCII key handling
    glutSpecialFunc(keyPressed);        // Coded key handling
    
    glutDisplayFunc(draw);          // Register scene to render contents of draw() function
    glutIdleFunc(draw);             // Register scene to draw content on back buffer
    glutReshapeFunc(reshape);       // Register reshape function to handle window resizing
    
    checkGLError();                 // Check any OpenGL errors in initialisation
    glutMainLoop();                 // Begin rendering sequence
    // Upon exit
    destroyObjects();
    return 0;
}

void keyPressed(int keyCode, int xm, int ym){           // Special (coded) key pressed
    float incr = (float)M_PI / 36.f;                    // increment angle by 5 degrees
    if (keyCode == GLUT_KEY_LEFT){                      // left arrow (move camera left around scene)
        camangle -= incr;                               // decrement camera angle
    } else if (keyCode == GLUT_KEY_RIGHT){              // right arrow (move camera right around scene)
        camangle += incr;                               // increment camera angle
    }
}

void keyPressed(unsigned char key, int xm, int ym){     // ASCII key pressed
    if (key == ' '){                                    // if space bar pressed
        camangle = 0.f;                                 //reset angle to 0.0
    }
}


void positionCamera(){
    cameraRadius();                                 // calculate current camera position
    eye[0] = camrad*sin(camangle);                  // set eye x (at camrad*sin(0)[ = 0])
    eye[1] = cen[1];                                // set eye y (at 0)
    eye[2] = camrad*cos(camangle);                  // set eye z (at camrad*cos(0)[ = 1])
    gluLookAt(eye[0], eye[1], eye[2],               // eye position
              cen[0], cen[1], cen[2],               // point that you are looking at (origin)
              0.f, 1.f, 0.f);                       // up vector (0, 1 0)
}

void cameraRadius(){
    camrad = (height / 2.f) / tan(M_PI / 8.f);      // calcualte camera radius based on height
}

void destroyObjects(){
    for (map <string, DisplayableObject*>::iterator itr = objects.begin(); itr != objects.end(); ++itr){
        delete itr->second;                         // delete all objects from memory
    }
    for (map <string, AnimatedObject*>::iterator itr = animate.begin(); itr != animate.end(); ++itr){
        delete itr->second;                         // delete all animated objects from memory
    }
    objects.clear();                                // clear map
    animate.clear();                                // clear map
}


void checkGLError(){
    int e = 0;
    GLenum error = glGetError();
    while(GL_NO_ERROR != error){
        e++;
        printf("GL Error %i: %s\n", e, gluErrorString(error));
        error = glGetError();
    }
    
    
}