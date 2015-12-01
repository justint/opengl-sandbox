#ifdef WIN32
#include <windows.h>
#include <GL/glut.h>
#endif

#ifdef __APPLE__
#include "GL/glew.h"
#include <GLUT/glut.h>
#endif

#include <stdio.h>

// To include helper structures (such as vector)
#include "math_3d.h"

int main(int argc, char** argv)
{
	// Standard GLUT init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", gluErrorString(res));
		return 1;
	}
}