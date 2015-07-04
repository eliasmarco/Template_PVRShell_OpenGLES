#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <iomanip>
#include <vector>

#include "lodepng.h"

#define OBJECT_SCALE 0x10000
#define SHOW_ERR(a)     if(glGetError() != GL_NO_ERROR) { std::cout << "shet " << a ; }

class Painter
{
public:
    Painter();
    ~Painter();

    void vInit(void);
    void vSetView(float zoomx, float zoomy);
    void vDraw(void);
    void vDrawTex(void);
    GLuint vLoadBitmap(const char* filename);
    GLuint vLoadPng(const char* filename, int tex);

private:
    float vTim(void);
};

inline Painter::Painter()
{
}

inline Painter::~Painter()
{
}
