#pragma once

#include "EngineCore/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Alpha {
	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandler);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandler;
	};
}

