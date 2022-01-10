#ifndef _GHRENDR_WINDOW_H_
#define _GHRENDR_WINDOW_H_

#include <GLFW/glfw3.h>

// Abstract platform based Window class
class Window {
private:
	struct WindowProperties {
		char* title = "ghrendr";
		int width = 1600;
		int height = 900;
	};

protected:
	WindowProperties properties;

public:

	GLFWwindow* m_Window;


	virtual void Init() = 0;
	virtual void createWindow() = 0;
	//virtual void setEventCallback() = 0;
	virtual ~Window() {};
};


#endif