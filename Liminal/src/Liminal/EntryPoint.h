#pragma once

#ifdef LM_PLATFORM_WINDOWS

extern Liminal::Application* Liminal::CreateApplication();

int main(int argc, char** argv)
{
	Liminal::Log::Init();
	LM_CORE_WARN("Initialized Log!");
	LM_INFO("Hello! Var={0}", 4);

	auto app = Liminal::CreateApplication();
	app->Run();
	delete app;
}

#endif 
