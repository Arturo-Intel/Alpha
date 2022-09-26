#include "alphapch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Alpha {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandler)
		:m_WindowHandler(windowHandler)
	{
		ALPHA_CORE_ASSERT(windowHandler, "windowHandler is null");
	}
	void OpenGLContext::Init()
		
	{
		glfwMakeContextCurrent(m_WindowHandler);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ALPHA_CORE_ASSERT(status, "Failed to initialize Glad! ");
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandler);
	}
}