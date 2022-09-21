#pragma once

#ifdef ALPHA_PLATFORM_WINDOWS

extern Alpha::Application* Alpha::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Alpha::CreateApplication();
	app->Run();
	delete app;
}

#endif