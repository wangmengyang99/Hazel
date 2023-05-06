#pragma once
#ifdef HZ_PLATFORM_WINOWS
extern Hazel::Application* Hazel::CreateApplication();
void main(int argc,char** argv) {
	Hazel::Log::Init();
	HZ_CORE_WARN("init log");
	HZ_INFO("init log");
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}
#endif // HZ_PLATFORM_WINDOWS

