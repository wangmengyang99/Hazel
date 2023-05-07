#include "hzpch.h"
#include "Application.h"
#include "Event/ApplicationEvent.h"
#include "Log.h"

Hazel::Application::Application()
{
}

Hazel::Application::~Application()
{

}

void Hazel::Application::Run()
{
	WindowResizeEvent e(1280,720);
	if (e.IsInCategory(EventCategoryApplication)) {
		HZ_TRACE(e);
	}
	if (e.IsInCategory(EventCategoryInput)) {
		HZ_TRACE(e);
	}
	while (true);
}
