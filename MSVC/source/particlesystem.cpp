
#include "particlesystem.hpp"
#include "modeldata.h";

void ParticleSystem::vInit(void) {
    glEnable(GL_DEPTH_TEST);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glTranslatef(-1.0f,-1.0f,0.0f);
    glScalef(1.0f/10.0f,1.0f/10.0f,0.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightf(GL_LIGHT0,GL_AMBIENT,1.0f);
    glLightf(GL_LIGHT0,GL_DIFFUSE,1.0f);

    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer(GL_FLOAT, 0, squarearray);
    glEnable(GL_COLOR_MATERIAL);

}  /* init */


float ParticleSystem::vTim(void) {
    return (float)clock()/(float)CLOCKS_PER_SEC;
}


void ParticleSystem::vDraw(void) {

    //static const GLfloat vertices[] =
    //{
    //   0.0f,0.0f,0.0f,
    //   0.0f,0.1f,0.0f,
    //   0.1f,0.0f,0.0f,
    //   0.1f,0.1f,0.0f
    //};

    GLfloat color3[] =
    {
        1.0f,1.0f,0,0.5f,
        1.0f,1.0f,0,0.5f,
        1.0f,1.0f,0,0.5f,
        1.0f,1.0f,0,0.5f
    };

    GLfloat color2[] =
    {
        1.0f,0,0,0.5f,
        1.0f,0,0,0.5f,
        1.0f,0,0,0.5f,
        1.0f,0,0,0.5f
    };

    GLfloat yellow[] =
    {
        1.0f,1.0f,0,1.0f,
        1.0f,1.0f,0,1.0f,
        1.0f,1.0f,0,1.0f,
        1.0f,1.0f,0,1.0f
    };


    GLfloat red[] =
    {
        1.0f,0,0,0.5f,
        1.0f,0,0,0.5f,
        1.0f,0,0,0.5f,
        1.0f,0,0,0.5f
    };

    GLfloat blue[] =
    {
        0,0,1.0f,0.5f,
        0,0,1.0f,0.5f,
        0,0,1.0f,0.5f,
        0,0,1.0f,0.5f
    };

    GLfloat green[] =
    {
        0,1.0f,0,0.5f,
        0,1.0f,0,0.5f,
        0,1.0f,0,0.5f,
        0,1.0f,0,0.5f
    };

    static const GLubyte squareindex[] =
    {
        0,1,2,1,2,3
    };

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(4,GL_FLOAT,0,color3);

    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    static GLfloat count = 0;
    static bool flip = false;

    if(!flip)
    count += 0.005f;
    else
    count -= 0.005f;

    if(count >= .50f || count <= -.50f ) flip = !flip;

    const int num_of_particles = 7000;

    static Particle p[num_of_particles];

    for(int i =0 ; i < num_of_particles; i++)
    {
        if(p[i].life == 0){
            p[i].angle    = GLfloat(rand() % 100) + 1;
            p[i].life     = GLfloat(rand() % 100) + 1;
            p[i].position = GLfloat(rand() % 10) + 1;
            p[i].velocity = GLfloat(rand() % 30) + 1;
        }
        else
        {
            p[i].life--;
            p[i].position += p[i].velocity;
        }
    }

    GLfloat rot =180* vTim();

    for(int i =0 ; i < num_of_particles; i++)
    {
        if(p[i].position >15)
        {
            //color3[0] = color3[4] = color3[8] = color3[12] = GLfloat(rand() % 255) + 1;
            //color3[1] = color3[5] = color3[9] = color3[13] = GLfloat(rand() % 255) + 1;
            //color3[2] = color3[6] = color3[10] = color3[14] = GLfloat(rand() % 255) + 1;

            glColorPointer(4,GL_FLOAT,0,colors);

            //int rgb = (rand() % 4) + 1;
            //switch(rgb)
            //{
            //case 1 : {glColorPointer(4,GL_FLOAT,0,red);}
            //break;
            //case 2 : {glColorPointer(4,GL_FLOAT,0,green);}
            //break;
            //case 3 : {glColorPointer(4,GL_FLOAT,0,blue);}
            //break;
            //case 4 : {glColorPointer(4,GL_FLOAT,0,color3);}
            //break;
            //}

            color3[3] = color3[7] = color3[11] = color3[15] = (GLfloat(rand() % 10) + 1)/10.0f;
            red[3] = red[7] = red[11] = red[15] = (GLfloat(rand() % 10) + 1)/10.0f;
            green[3] = green[7] = green[11] = green[15] = (GLfloat(rand() % 10) + 1)/10.0f;
            blue[3] = blue[7] = blue[11] = blue[15] = (GLfloat(rand() % 10) + 1)/10.0f;
        }
        else
        {
            glColorPointer(4,GL_FLOAT,0,colors);
        }
        glLoadIdentity();
        glTranslatef(5.0f,5.0f,0.0f);
        glTranslatef(p[i].angle/10.0f,p[i].position/100.0f,0.0f);
        glRotatef(rot,1.0f,1.0f,1.0f);
        //glDrawElements(GL_TRIANGLES,18,GL_UNSIGNED_BYTE,squareindex);
        glDrawElements(GL_TRIANGLES,60,GL_UNSIGNED_BYTE,icosahedronFaces);
    }
}  /* draw */

