#include "hzpch.h"
#include "Application.h"
#include "Event/ApplicationEvent.h"
#include "Log.h"
#include "GLFW/glfw3.h"
#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)
Hazel::Application::Application()
{
	m_window =std::unique_ptr<window>( window::Create());
	m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));
}

Hazel::Application::~Application()
{

}

void Hazel::Application::Run()
{
	while (true) {
		glClearColor(1,0,1,1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_window->OnUpdate();
	};
}

void Hazel::Application::OnEvent(Event& e)
{
	HZ_CORE_INFO("{0}", e);
}
