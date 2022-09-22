#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Alpha {

	class ALPHA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

