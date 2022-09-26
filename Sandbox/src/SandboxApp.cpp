#include <Alpha.h>
#include "imgui/imgui.h"
 

class ExampleLayer : public Alpha::Layer {
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{

		
	}
	void OnImGuiRender() override
	{
		
		//ImGui::Text("HEllo world");
		
		static bool show = true;
		ImGui::ShowDemoWindow(&show);
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
