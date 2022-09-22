#include "Application.h"

#include "GLCore/Events/ApplicationEvent.h"
#include "GLCore/Log.h"

namespace Alpha {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		LOG_TRACE(e);

		while (true);
	}
}
