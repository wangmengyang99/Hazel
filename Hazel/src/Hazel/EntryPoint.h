#pragma once
#ifdef HZ_PLATFORM_WINOWS
extern Hazel::Application* Hazel::CreateApplication();
void main(int argc,char** argv) {
	Hazel::Log::Init();
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}
#endif // HZ_PLATFORM_WINDOWS

