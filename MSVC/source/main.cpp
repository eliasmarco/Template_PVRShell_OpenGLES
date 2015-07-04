/******************************************************************************

 @File

 @Title

 @Version

 @Copyright    Copyright (c) Imagination Technologies Limited.

 @Platform     Independant

 @Description  Shows how to use the PowerVR framework for initialization. This
 framework allows platform abstraction so applications using it
 will work on any PowerVR enabled device.

 ******************************************************************************/
#if defined(__APPLE__) && defined (TARGET_OS_IPHONE)
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>
#else
#include <GLES/gl.h>
#endif

#include "PVRShell.h"
#include "modeldata.h"
#include "painter.hpp"
#include "particlesystem.hpp"

/*
*	Lesson 2: The PowerVR Shell
*	===========================

The PowerVR shell handles all OS specific initialisation code, and is
extremely convenient for writing portable applications. It also has
several built in command line features, which allow you to specify
attributes like the backbuffer size, vsync and antialiasing modes.

The code is constructed around a "PVRShell" superclass. You must define
your app using a class which inherits from this, which should implement
the following five methods, (which at execution time are essentially
called in the order in which they are listed):


InitApplication:	This is called before any API initialisation has
taken place, and can be used to set up any application data which does
not require API calls, for example object positions, or arrays containing
vertex data, before they are uploaded.

InitView:	This is called after the API has initialised, and can be
used to do any remaining initialisation which requires API functionality.
In this app, it is used to upload the vertex data.

RenderScene:	This is called repeatedly to draw the geometry. Returning
false from this function instructs the app to enter the quit sequence:

ReleaseView:	This function is called before the API is released, and
is used to release any API resources. In this app, it releases the
vertex buffer.

QuitApplication:	This is called last of all, after the API has been
released, and can be used to free any leftover user allocated memory.


The shell framework starts the application by calling a "NewDemo" function,
which must return an instance of the PVRShell class you defined. We will
now use the shell to create a "Hello triangle" app, similar to the previous
one.

*/

/******************************************************************************
 Defines
 ******************************************************************************/

/*!****************************************************************************
 To use the shell, you have to inherit a class from PVRShell
 and implement the five virtual functions which describe how your application
 initializes, runs and releases the ressources.
 ******************************************************************************/
class PVRShell_OGLES : public PVRShell
{
public:
    // Vertex Buffer Object (VBO) handle
    GLuint	m_ui32Vbo;

    Painter oPainter;
    ParticleSystem oParticleSystem;

public:
    virtual bool InitApplication();
    virtual bool InitView();
    virtual bool ReleaseView();
    virtual bool QuitApplication();
    virtual bool RenderScene();
};


/*!****************************************************************************
 @Function		InitApplication
 @Return		bool		true if no error occured
 @Description	Code in InitApplication() will be called by PVRShell once per
 run, before the rendering context is created.
 Used to initialize variables that are not dependant on it
 (e.g. external modules, loading meshes, etc.)
 If the rendering context is lost, InitApplication() will
 not be called again.
 ******************************************************************************/
bool PVRShell_OGLES::InitApplication()
{
    return true;
}

/*!****************************************************************************
 @Function		QuitApplication
 @Return		bool		true if no error occured
 @Description	Code in QuitApplication() will be called by PVRShell once per
 run, just before exiting the program.
 If the rendering context is lost, QuitApplication() will
 not be called.
 ******************************************************************************/
bool PVRShell_OGLES::QuitApplication()
{
    return true;
}

/*!****************************************************************************
 @Function		InitView
 @Return		bool		true if no error occured
 @Description	Code in InitView() will be called by PVRShell upon
 initialization or after a change in the rendering context.
 Used to initialize variables that are dependant on the rendering
 context (e.g. textures, vertex buffers, etc.)
 ******************************************************************************/
bool PVRShell_OGLES::InitView()
{
    oParticleSystem.vInit();

    return true;
}

/*!****************************************************************************
 @Function		ReleaseView
 @Return		bool		true if no error occured
 @Description	Code in ReleaseView() will be called by PVRShell when the
 application quits or before a change in the rendering context.
 ******************************************************************************/
bool PVRShell_OGLES::ReleaseView()
{
    return true;
}

/*!****************************************************************************
 @Function		RenderScene
 @Return		bool		true if no error occured
 @Description	Main rendering loop function of the program. The shell will
 call this function every frame.
 eglSwapBuffers() will be performed by PVRShell automatically.
 PVRShell will also manage important OS events.
 Will also manage relevent OS events. The user has access to
 these events through an abstraction layer provided by PVRShell.
 ******************************************************************************/
bool PVRShell_OGLES::RenderScene()
{
    oParticleSystem.vDraw();

    return true;
}

/*!****************************************************************************
 @Function		NewDemo
 @Return		PVRShell*		The demo supplied by the user
 @Description	This function must be implemented by the user of the shell.
 The user should return its PVRShell object defining the
 behaviour of the application.
 ******************************************************************************/
PVRShell* NewDemo()
{
    return new PVRShell_OGLES();
}

/******************************************************************************
 End of file (PVRShell_OGLES.cpp)
 ******************************************************************************/

