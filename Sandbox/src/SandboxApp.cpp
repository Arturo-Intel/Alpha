#include <Alpha.h>
#include "imgui/imgui.h"
 
#include <glad/glad.h>

class ExampleLayer : public Alpha::Layer {
public:
	ExampleLayer()
		:Layer("Example")
	{
		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);

		glGenBuffers(1, &m_VertextBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertextBuffer);

		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f,
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glGenBuffers(1, &m_IndexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
		unsigned int indices[3] = { 0, 1, 2 };
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	}

	void OnUpdate() override
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(m_VertexArray);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

		
	}
	void OnImGuiRender() override
	{
		static bool show = false;
		ImGui::ShowDemoWindow(&show);
	}

	void OnEvent(Alpha::Event& event) override
	{

	}
private:
	unsigned int m_VertexArray, m_VertextBuffer, m_IndexBuffer;
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

	void Run()
	{

	}

};

Alpha::Application* Alpha::CreateApplication() 
{
	return new SandboxApp();
}
