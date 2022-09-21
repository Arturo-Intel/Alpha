#include <Alpha.h>

class SandboxApp : public Alpha::Application
{
public:
	SandboxApp() 
	{ 

	}

	~SandboxApp()
	{

	}

};

Alpha::Application* Alpha::CreateApplication() 
{
	return new SandboxApp();
}
