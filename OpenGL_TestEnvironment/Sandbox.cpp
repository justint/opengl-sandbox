#ifdef _WIN32 
#include <windows.h>
#include <GL/glut.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#endif

static void RenderSceneCB(); // 

void cmain(int argc, char** argv)
{
	// Initialize GLUT, taking in args from main() so special GLUT commands may be used.
	glutInit(&argc, argv);
	
	/*
		Configure two GLUT options:
			GLUT_DOUBLE: Enables double buffering for window (drawing to a background buffer 
			while another buffer is displayed). (Default is GLUT_SINGLE)
			GLUT_RGBA: Default, but enables bit mask to select an RGBA mode window.
	*/
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
	glutSwapBuffers(); // Swap the roles of backbuffer and frontbuffer.
}