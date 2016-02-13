#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
// To include helper structures (such as vector)
#include "math_3d.h"

static void RenderSceneCB();


int main(int argc, char** argv)
{
	// Standard GLUT init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// Configure dimensions of and produce window.
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0); // Not sure if this is required but following tut soo
	glutCreateWindow("Sandbox");

	// See documention for RenderSceneCB() later in this source.
	glutDisplayFunc(RenderSceneCB);

	/*
	Sets the color that will be used when clearing the framebuffer.
	(R, G, B, A), range: 0.0 - 1.0
	*/
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);



	// Initialize GLEW and check for errors
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		system("pause");
		return 1;
	}

	// Passes control to GLUT, beginning its internal loop (calling RenderSceneCB continuously).
	glutMainLoop();
}

/*
Not particularly mentioned in tutorial I'm following, but using the power of Google I've found
this is an important function called to do the rendering of one frame. It's apparently
continuously called by a GLUT internal loop.
*/
static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear the framebuffer using specified glClearColor in main().

	// Create an array of one Vector3f, initialize to center (0,0,0)
	Vector3f Vertices[1];
	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);

	// Vertex buffer object
	GLuint VBO;

	// Generating object - 1 for count
	glGenBuffers(1, &VBO);
	// Bind handle to target name to later execute commands on target
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Fill binded buffer with data
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	// Enable vertex attribute for data to be accessible in pipeline
	glEnableVertexAttribArray(0);

	// Rebind buffer (usually called every frame to update pipeline state, but point is static
	// so no frame-by-frame calling necessary)
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// "How to interpret the data" (index of attrib [0 by default], component count [3 = XYZ],
	// data type, do we want attribute to be normalized? [GL_FALSE], "the stride" - number of
	// bytes between two instances of buffer, necessary for passing size of structures with
	// positions and normals [0 for one attribute, data tightly packed], offset of stride
	// attribute [0 for no stride/extra attribute])
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Draw pointed using ordered draw call (Points, 0 for first index, 1 for count = one point)
	glDrawArrays(GL_POINTS, 0, 1);

	glDisableVertexAttribArray(0);

	glutSwapBuffers(); // Swap the roles of backbuffer and frontbuffer.
}