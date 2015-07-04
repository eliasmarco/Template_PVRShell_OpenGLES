#include "painter.hpp"
#include "modeldata.h";

void Painter::vInit(void) {

}  /* init */

void Painter::vSetView(float zoomx, float zoomy) {
    glMatrixMode(GL_PROJECTION);
    glViewport(0,0,400,400);
    //glTranslatef(-1.0f,1.0f, 0.0f);
    glScalef(1/zoomx,1/zoomy, 0.0f);
    //glScalef(2/20.0,2/20.0, 0.0f);

    GLfloat znear = 0.001f, zfar = 1000.0f;
    GLfloat left = 0.0f, right = 0.0f, bottom = 0.0f, top = 0.0f;

    GLfloat fovR = 45 * 3.141592653f / 180.0f;

    right = znear * tanf(fovR / 2.0f);
    top = right ;
    bottom = -top;
    left = -right;

    //glFrustumf(left , right , bottom , top, znear, zfar);
    //glTranslatef(0.0f,0.0f, -10.0f);
}  /* init */

void Painter::vDraw(void) {
    glEnable(GL_DEPTH_TEST);

    vSetView(64.0f,64.0f);

    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glTranslatef(0.0f,0.0f,2.0f);
    glVertexPointer(3,GL_FLOAT,0,vertices);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, texturecoordarray);
    //glDrawArrays(GL_TRIANGLES, 0, 6);
    //glDrawElements(GL_TRIANGLES, 60, GL_UNSIGNED_BYTE, icosahedronFaces);
    GLfloat rot =30* vTim();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightf(GL_LIGHT0,GL_AMBIENT,1.0f);
    glLightf(GL_LIGHT0,GL_DIFFUSE,1.0f);

    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer(GL_FLOAT, 0, squarearray);
    glEnable(GL_COLOR_MATERIAL);

    glTranslatef(0.0f,0.0f,-5.0f);
    glRotatef(rot*10,0.0f,1.0f,1.0f);
    //glDrawElements(GL_TRIANGLES, 60, GL_UNSIGNED_BYTE, icosahedronFaces);

    glPointSize(10.0f);
    glDrawArrays(GL_POINTS,0,60);

    //for(int i = 0 ; i < 100; i++)
    //{
    //    glLoadIdentity();
    //    glTranslatef(0.0f,-2.0f,i);
    //    glRotatef(rot,0.0f,1.0f,1.0f);
    //    glDrawElements(GL_TRIANGLES, 60, GL_UNSIGNED_BYTE, icosahedronFaces);
    //}

    //glDisableClientState(GL_VERTEX_ARRAY);
}  /* draw */

void Painter::vDrawTex(void) {
    glEnable(GL_DEPTH_TEST);

    static bool init = false;
    if(!init){
        //vSetView(128.0f,128.0f);
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,squarearray);

    //glEnableClientState(GL_COLOR_ARRAY);
    //glColorPointer(4,GL_UNSIGNED_BYTE,0,colorarray);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 0, texturecoordarray);

    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_BLEND);

    //glEnable(GL_ALPHA_TEST); 
    //glAlphaFunc(GL_GEQUAL, 0.995);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
    //glBlendEquation(GL_FUNC_ADD);

    GLfloat fade[4]  = { 0.0f,0.0f,0.0f,0.0f };

    glColor4f(1.f,1.f,1.0f,0.1f);
    //glClientActiveTexture(GL_TEXTURE0);
    vLoadPng("resource/greencircle.png",1);
    ////glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, fade);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
    //glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_MODULATE);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_RGB, GL_TEXTURE);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC1_RGB, GL_PRIMARY_COLOR);
    //glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_COLOR);
    //glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB, GL_SRC_COLOR);
    //glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_MODULATE);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_ALPHA, GL_TEXTURE);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_ALPHA, GL_PRIMARY_COLOR);
    //glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_ALPHA, GL_SRC_ALPHA);
    //glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_ALPHA, GL_SRC_ALPHA);
    //glTexEnvf(GL_TEXTURE_ENV, GL_ALPHA_SCALE, 1.0f);
        SHOW_ERR(1);

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, stripindex);
    glTranslatef(-0.4f,-0.2f,0.0f);

    //glClientActiveTexture(GL_TEXTURE1);
    vLoadPng("resource/bluecircle.png",1);

    ////glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, fade);
    //glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_REPLACE);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_RGB, GL_PRIMARY_COLOR);
    //glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_COLOR);
    //// setup alpha
    //glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_MODULATE);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_ALPHA, GL_TEXTURE0);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC1_ALPHA, GL_PRIMARY_COLOR);
    //glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_ALPHA, GL_SRC_ALPHA);
    //glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_ALPHA, GL_SRC_ALPHA);
    //glTexEnvf(GL_TEXTURE_ENV, GL_ALPHA_SCALE, 1.0f);

    //glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, fade);
    //glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
    //glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_REPLACE);
    //    SHOW_ERR(2);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_RGB, GL_TEXTURE0);
    //    SHOW_ERR(3);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC1_RGB, GL_TEXTURE1);
    //    SHOW_ERR(4);
    //glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB, GL_SRC_COLOR);
    //glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB, GL_ONE_MINUS_SRC_COLOR);
    ////glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_REPLACE);
    ////glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_ALPHA, GL_TEXTURE);
    ////glTexEnvi(GL_TEXTURE_ENV, GL_SRC1_ALPHA, GL_CONSTANT);
    ////glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ////glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, stripindex);
    //glColor4f    (0.0f, 0.0f, 0.0f, 0.0f);
    //glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


    ////vLoadBitmap("resource/somebitmap.bmp");
    ////glColor4f(0.0f,1.0f,0.0f,1.0f);


    //vLoadPng("resource/bluecircle.png",2);
    //glClientActiveTexture(GL_TEXTURE1);
    //glTranslatef(-0.5f,-0.5f,0.0f);
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, stripindex);

        SHOW_ERR(1);
    //GLfloat f32FadeColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    //glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, f32FadeColor);
    //glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE);
    //glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_MODULATE);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_RGB, GL_PRIMARY_COLOR);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC1_RGB, GL_CONSTANT);
    //glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_MODULATE);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_ALPHA, GL_PRIMARY_COLOR);
    //glTexEnvi(GL_TEXTURE_ENV, GL_SRC1_ALPHA, GL_CONSTANT);
    //glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_ALPHA, GL_SRC_ALPHA);
    //glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_ALPHA, GL_SRC_ALPHA);

    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //glTranslatef(5.f,5.f,0.0f);

    //glColor4f(1.0f,0.0f,0.0f,1.0f);
    //glVertexPointer(3,GL_FLOAT,0,squarearray);
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, stripindex);

    //init = true;
}  /* draw */


float Painter::vTim(void) {
    return (float)clock()/(float)CLOCKS_PER_SEC;
}


#define TEXTURE_LOAD_ERROR 0

GLuint Painter::vLoadPng(const char* filename, int tex)
{
    std::vector<unsigned char> png;
    std::vector<unsigned char> image; //the raw pixels
    unsigned width, height;

    //load and decode
    lodepng::load_file(png, filename);
    unsigned error = lodepng::decode(image, width, height, png);

    if(error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;

    GLuint Texture1;
    GLuint Texture2;
    glEnable(GL_TEXTURE_2D);
    if(tex == 1){
        glActiveTexture(GL_TEXTURE0);
        SHOW_ERR(1);
        glGenTextures(1, &Texture1);
        SHOW_ERR(1);
        glBindTexture(GL_TEXTURE_2D, Texture1);
        SHOW_ERR(1);
    }
    else{
        glActiveTexture(GL_TEXTURE1);
        SHOW_ERR(1);
        glGenTextures(1, &Texture2);
        SHOW_ERR(1);
        glBindTexture(GL_TEXTURE_2D, Texture2);
        SHOW_ERR(1);
    }

    SHOW_ERR(1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    SHOW_ERR(1);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);

    SHOW_ERR(1);

    //return Texture1;

    return 0;
}

GLuint Painter::vLoadBitmap(const char* filename)
{
    int i;
    FILE* file;
    fopen_s(&file,filename, "rb");
    BITMAPFILEHEADER bmpFile;
    unsigned char *bmpImage = NULL;
    unsigned char tmpRGB;

    if(!file)
        return 0 ;

    BITMAPINFOHEADER bmpInfo;

    fread(&bmpFile,sizeof(BITMAPFILEHEADER),1,file);

    fread(&bmpInfo,sizeof(BITMAPINFOHEADER),1,file);
    fseek(file,bmpFile.bfOffBits,SEEK_SET);
    bmpImage = new unsigned char[bmpInfo.biSizeImage];

    fread(bmpImage,1,bmpInfo.biSizeImage,file);

    static int init = false;
    if(!init)
    {
        for (unsigned int i = 0; i < bmpInfo.biSizeImage; i+=3)
        {
            tmpRGB = bmpImage[i];
            bmpImage[i] = bmpImage[i+2];
            bmpImage[i+2] = tmpRGB;
        }
        init = true;
    }
    fclose(file);

    GLuint Texture;
    glEnable(GL_TEXTURE_2D);
    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &Texture);

    SHOW_ERR(1);

    glBindTexture(GL_TEXTURE_2D,  Texture);

    SHOW_ERR(1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    SHOW_ERR(1);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmpInfo.biWidth,bmpInfo.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, (GLvoid *)bmpImage);

    SHOW_ERR(1);

    return Texture;
}



//void PointerDraw::vTestDraw(uint16 u16WinPosX, uint16 u16WinPosY, uint16 u16WinWidth, uint16 u16WinHeight)
//{
//    static const GLfloat vertices[]= {
//        0.0f, -0.525731f, 0.850651f,             // vertices[0]
//        0.850651f, 0.0f, 0.525731f,              // vertices[1]
//        0.850651f, 0.0f, -0.525731f,             // vertices[2]
//        -0.850651f, 0.0f, -0.525731f,            // vertices[3]
//        -0.850651f, 0.0f, 0.525731f,             // vertices[4]
//        -0.525731f, 0.850651, 0.0f,             // vertices[5]
//        0.525731f, 0.850651, 0.0f,              // vertices[6]
//        0.525731f, -0.850651, 0.0f,             // vertices[7]
//        -0.525731f, -0.850651, 0.0f,            // vertices[8]
//        0.0f, -0.525731f, -0.850651f,            // vertices[9]
//        0.0f, 0.525731f, -0.850651f,             // vertices[10]
//        0.0f, 0.525731f, 0.850651f               // vertices[11]
//    };

//    static const GLfloat colors[] = {
//         1.0, 0.0, 0.0, 1.0,
//         1.0, 0.5, 0.0, 1.0,
//         1.0, 1.0, 0.0, 1.0,
//         0.5, 1.0, 0.0, 1.0,
//         0.0, 1.0, 0.0, 1.0,
//         0.0, 1.0, 0.5, 1.0,
//         0.0, 1.0, 1.0, 1.0,
//         0.0, 0.5, 1.0, 1.0,
//         0.0, 0.0, 1.0, 1.0,
//         0.5, 0.0, 1.0, 1.0,
//         1.0, 0.0, 1.0, 1.0,
//         1.0, 0.0, 0.5, 1.0
//    };

//    static const GLubyte icosahedronFaces[] = {
//        1, 2, 6,
//        1, 7, 2,
//        3, 4, 5,
//        4, 3, 8,
//        6, 5, 11,
//        5, 6, 10,
//        9, 10, 2,
//        10, 9, 3,
//        7, 8, 9,
//        8, 7, 0,
//        11, 0, 1,
//        0, 11, 4,
//        6, 2, 10,
//        1, 6, 11,
//        3, 5, 10,
//        5, 4, 11,
//        2, 7, 9,
//        7, 1, 0,
//        3, 9, 8,
//        4, 8, 0,
//    };
//    static uint32 count = 0;

//    vSetView(u16WinPosX, u16WinPosY, u16WinWidth, u16WinHeight);

//    glEnable(GL_DEPTH_TEST);
//    glEnableClientState(GL_VERTEX_ARRAY);
//    glVertexPointer(3,GL_FLOAT,0,vertices);
//    glEnableClientState(GL_COLOR_ARRAY);
//    glColorPointer(4,GL_FLOAT,0,colors);


//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glLightf(GL_LIGHT0,GL_AMBIENT,1.0f);
//    glLightf(GL_LIGHT0,GL_DIFFUSE,0.5f);

//    glEnableClientState(GL_NORMAL_ARRAY);
//    glNormalPointer(GL_FLOAT, 0, vertices);
//    glEnable(GL_COLOR_MATERIAL);
//    //glClearColor(1.0f,0.0f,1.0f,0.3f);
//    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    count++;
//    //glTranslatef(-(rot),0.0f,0.0f);
//    GLfloat rot = 3 * count;
//    glRotatef(rot,0.0f,1.0f,1.0f);
//    glDrawElements(GL_TRIANGLES, 60, GL_UNSIGNED_BYTE, icosahedronFaces);

//    glDisableClientState(GL_VERTEX_ARRAY);
//    glDisableClientState(GL_COLOR_ARRAY);
//}