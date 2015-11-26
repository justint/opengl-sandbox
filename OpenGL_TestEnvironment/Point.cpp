#include <GL/glew.h>
#include <GL/glut.h>

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
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
}