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

		LOG_CORE_INFO("OpenGL Info:");
		LOG_CORE_INFO("   Vendor: {0}", glGetString(GL_VENDOR));
		LOG_CORE_INFO("   Renderer: {0}", glGetString(GL_RENDERER));
		LOG_CORE_INFO("   Version: {0}", glGetString(GL_VERSION));
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandler);
	}
}