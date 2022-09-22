#pragma once

#ifdef ALPHA_PLATFORM_WINDOWS

extern Alpha::Application* Alpha::CreateApplication();

int main(int argc, char** argv)
{
	Alpha::Log::Init();
	LOG_CORE_WARN("Initialized Log!");
	int a = 5;
	LOG_INFO("Hello {0}" ,a);

	auto app = Alpha::CreateApplication();
	app->Run();
	delete app;
}

#endif