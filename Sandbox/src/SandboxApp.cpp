#include <Alpha.h>

class ExampleLayer : public Alpha::Layer {
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{

	}

	void OnEvent(Alpha::Event& event) override
	{

	}
};

class SandboxApp : public Alpha::Application
{
public:
	SandboxApp() 
	{ 
		PushLayer(new ExampleLayer());
	}

	~SandboxApp()
	{

	}

};

Alpha::Application* Alpha::CreateApplication() 
{
	return new SandboxApp();
}
