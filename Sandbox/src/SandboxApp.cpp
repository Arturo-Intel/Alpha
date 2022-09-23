#include <Alpha.h>

class ExampleLayer : public Alpha::Layer {
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
		LOG_INFO("ExampleLayer::Update");
	}

	void OnEvent(Alpha::Event& event) override
	{
		LOG_TRACE("{0}", event);
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
