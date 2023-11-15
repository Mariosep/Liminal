#pragma once

#ifdef LM_PLATFORM_WINDOWS

extern Liminal::Application* Liminal::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Liminal::CreateApplication();
	app->Run();
	delete app;
}

#endif 
