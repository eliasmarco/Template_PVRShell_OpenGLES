#include <GLES/gl.h>

static const GLfloat vertexarray [] = 
{
    0.0f,1.0f,0.0f,
    -1.0f,0.0f,0.0f,
    1.0f,0.0f,0.0f
};

static const GLfloat squarearray64 [] = 
{
    -64.0f,-64.0f,0.0f,
    -64.0f,64.0f,0.0f,
    64.0f,64.0f,0.0f,
    64.0f,-64.0f,0.0f
};

static const GLfloat squarearray [] = 
{
    0.0f,0.0f,0.0f,
    0.0f,1.0f,0.0f,
    1.0f,1.0f,0.0f,
    1.0f,0.0f,0.0f
};

static const GLubyte stripindex [] = 
{
    0,1,2,0,2,3
};

static const GLfloat texturecoordarray [] = 
{
    0.0f,0.0f,
    0.0f,1.0f,
    1.0f,1.0f,
    1.0f,0.0f
};

static const GLfloat texturecoordarrayhalf [] = 
{
    0.5f,0.5f,
    0.5f,1.0f,
    1.0f,1.0f,
    1.0f,0.5f
};

static const GLfloat texturecoordarray64 [] = 
{
    0.0f,0.0f,
    1.0f,0.0f,
    1.0f,1.0f,
    0.0f,1.0f
};

static const GLubyte colorarray [] = 
{
    255,0,0,255,
    255,0,0,255,
    255,0,0,255,
    255,0,0,255
};

static const GLushort fanindex [] = 
{
    0,1,2
};

typedef struct 
{
    GLfloat x;
    GLfloat y;
    GLfloat z;
} Vertex3d;

static const GLfloat vertices[]= {
    0.0f, -0.525731f, 0.850651f,             // vertices[0]
    0.850651f, 0.0f, 0.525731f,              // vertices[1]
    0.850651f, 0.0f, -0.525731f,             // vertices[2]
    -0.850651f, 0.0f, -0.525731f,            // vertices[3]
    -0.850651f, 0.0f, 0.525731f,             // vertices[4]
    -0.525731f, 0.850651, 0.0f,             // vertices[5]
    0.525731f, 0.850651, 0.0f,              // vertices[6]
    0.525731f, -0.850651, 0.0f,             // vertices[7]
    -0.525731f, -0.850651, 0.0f,            // vertices[8]
    0.0f, -0.525731f, -0.850651f,            // vertices[9]
    0.0f, 0.525731f, -0.850651f,             // vertices[10]
    0.0f, 0.525731f, 0.850651f               // vertices[11]
};

typedef struct 
{
    GLfloat r;
    GLfloat g;
    GLfloat b;
    GLfloat a;
} Color3d;

static const GLfloat colors[] = {
     1.0, 0.0, 0.0, 1.0,
     1.0, 0.5, 0.0, 1.0,
     1.0, 1.0, 0.0, 1.0,
     0.5, 1.0, 0.0, 1.0,
     0.0, 1.0, 0.0, 1.0,
     0.0, 1.0, 0.5, 1.0,
     0.0, 1.0, 1.0, 1.0,
     0.0, 0.5, 1.0, 1.0,
     0.0, 0.0, 1.0, 1.0,
     0.5, 0.0, 1.0, 1.0,
     1.0, 0.0, 1.0, 1.0,
     1.0, 0.0, 0.5, 1.0
};

static const GLubyte icosahedronFaces[] = {
    1, 2, 6,
    1, 7, 2,
    3, 4, 5,
    4, 3, 8,
    6, 5, 11,
    5, 6, 10,
    9, 10, 2,
    10, 9, 3,
    7, 8, 9,
    8, 7, 0,
    11, 0, 1,
    0, 11, 4,
    6, 2, 10,
    1, 6, 11,
    3, 5, 10,
    5, 4, 11,
    2, 7, 9,
    7, 1, 0,
    3, 9, 8,
    4, 8, 0,
};