#pragma once
#include "Core.h"
#include "Hazel/window.h"
namespace  Hazel {
	class HAZEL_API Application
	{
	public:
		Application();
	 virtual ~Application();
	 void Run();
	private:
		std::unique_ptr<window> m_window;
	};
	//to be defined in client
	Application* CreateApplication();
}

