#include "hzpch.h"
#include "Application.h"
#include "Event/ApplicationEvent.h"
#include "Log.h"

Hazel::Application::Application()
{
	m_window =std::unique_ptr<window>( window::Create());

}

Hazel::Application::~Application()
{

}

void Hazel::Application::Run()
{
	while (true) {
		m_window->OnUpdate();
	};
}
