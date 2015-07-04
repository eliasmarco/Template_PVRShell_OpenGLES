#include <stdio.h>
#include <stdlib.h>
#include <EGL/egl.h>
#include <GLES/gl.h>
#include <math.h>
#include <time.h>

#define NUM_PARTICLES 30
 
typedef struct Particle
{
    GLfloat     angle;
    GLfloat     life;
    GLfloat     velocity;
    GLfloat     position;
}
Particle;

class ParticleSystem
{
public:
    ParticleSystem();
    ~ParticleSystem();

    void vInit(void);
    void vDraw(void);

private:
    float vTim(void);
};

inline ParticleSystem::ParticleSystem()
{
}

inline ParticleSystem::~ParticleSystem()
{
}
