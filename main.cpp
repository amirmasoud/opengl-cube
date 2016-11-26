#include "GL/glut.h"

void init(void)
{
    //specify clear values for the color buffers - background color
    //red, green, blue, alpha
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void display(void)
{
    // Clear color and depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Reset transformations
    glLoadIdentity();
    
    // set the camera
    gluLookAt( 0.0f, 0.0f, 10.0f,
              0.0f, 0.0f, 0.0f,
              0.0f, 1.0f, 0.0f);
    
    //define vertices arrays and colors for all faces of a cube
    GLfloat verticesFront[]	  =   {-0.5, 0.5, 0.5,0.50,0.50,-0.5,-0.5,-0.5};
    GLfloat colorsFront[]	  =   {0.0,1.0,1.0,1.0,1.0,1.0,1.0,0.0,1.0,0.0,0.0,1.0};
    GLfloat verticesRight[]	  =   {0.5,-0.5,0.5,0.5,0.75,0.75,0.75,-0.25};
    GLfloat colorsRight[]	  =   {1.0,1.0,1.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,1.0,1.0};
    GLfloat verticesLeft[]	  =   {-0.5,0.5,-0.25,0.75,-0.25,-0.25,-0.5,-0.5};
    GLfloat colorsLeft[]	  =   {0.0,1.0,1.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0};
    GLfloat verticesBack[]	  =   {-0.25,0.75,0.75,0.75,0.75,-0.25,-0.25,-0.25};
    GLfloat colorsBack[]	  =   {1.0,0.0,0.0,0.0,0.0,1.0,0.0,1.0,1.0,1.0,1.0};
    GLfloat verticesTop[]	  =   {-0.5,0.5,-0.25,0.75,0.75,0.75,0.5,0.5};
    GLfloat colorsTop[]		  =   {0.0,1.0,1.0,0.0,1.0,1.0,1.0,0.0,0.0,1.0,1.0,1.0};
    GLfloat verticesBottom[]  =   {-0.5,-0.5,-0.25,-0.25,0.75,0.75,0.5,0.5};
    GLfloat colorsBottom[]	  =   {0.0,0.0,1.0,0.0,0.0,0.0,1.0,0.0,0.0,1.0,0.0,1.0};
    
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    //front
    glColorPointer(3, GL_FLOAT, 0, colorsFront);
    glVertexPointer(2, GL_FLOAT, 0, verticesFront);
    glBegin(GL_POLYGON);
    glArrayElement(0);
    glArrayElement(1);
    glArrayElement(2);
    glArrayElement(3);
    glEnd();
    
    //back
    glColorPointer(3, GL_FLOAT, 0, colorsBack);
    glVertexPointer(2, GL_FLOAT, 0, verticesBack);
    glBegin(GL_QUADS);
    glArrayElement(0);
    glArrayElement(1);
    glArrayElement(2);
    glArrayElement(3);
    glEnd();
    
    //right
    glColorPointer(3, GL_FLOAT, 0, colorsRight);
    glVertexPointer(2, GL_FLOAT, 0, verticesRight);
    glBegin(GL_QUADS);
    glArrayElement(0);
    glArrayElement(1);
    glArrayElement(2);
    glArrayElement(3);
    glEnd();
    
    //left
    glColorPointer(3, GL_FLOAT, 0, colorsLeft);
    glVertexPointer(2, GL_FLOAT, 0, verticesLeft);
    glBegin(GL_QUADS);
    glArrayElement(0);
    glArrayElement(1);
    glArrayElement(2);
    glArrayElement(3);
    glEnd();
    
    //top
    glColorPointer(3, GL_FLOAT, 0, colorsTop);
    glVertexPointer(2, GL_FLOAT, 0, verticesTop);
    glBegin(GL_QUADS);
    glArrayElement(0);
    glArrayElement(1);
    glArrayElement(2);
    glArrayElement(3);
    glEnd();
    
    //bottom
    glColorPointer(3, GL_FLOAT, 0, colorsBottom);
    glVertexPointer(2, GL_FLOAT, 0, verticesBottom);
    glBegin(GL_QUADS);
    glArrayElement(0);
    glArrayElement(1);
    glArrayElement(2);
    glArrayElement(3);
    glEnd();
    
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    float ratio = w * 1.0  / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(30.0f, ratio, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
