#pragma once

#ifdef ALPHA_PLATFORM_WINDOWS

extern Alpha::Application* Alpha::CreateApplication();

int main(int argc, char** argv)
{
	Alpha::Log::Init();
	LOG_CORE_WARN("Initialized Log!");

	auto app = Alpha::CreateApplication();
	app->Run();
	delete app;
}

#endif