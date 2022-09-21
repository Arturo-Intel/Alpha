#pragma once

#include "Core.h"

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
