#include "hzpch.h"
#include "WindowsWindow.h"
#include "Hazel/Log.h"
namespace Hazel {
	static bool s_GLFWInitializad = false;
	window* window::Create(const Hazel::WindowPorps& props) {
		return new WindowsWindow(props);
	}
	WindowsWindow::WindowsWindow(const Hazel::WindowPorps& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(G_window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		m_data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_data.VSync;
	}

	void WindowsWindow::Init(const Hazel::WindowPorps& props)
	{
		m_data.Title = props.Title;
		m_data.m_width = props.m_width;
		m_data.m_height = props.m_Height;
		HZ_CORE_INFO("Create window {0}:({1},{2})", m_data.Title, m_data.m_width, m_data.m_height);
		if (!Hazel::s_GLFWInitializad) {
			int success = glfwInit();
			HZ_CORE_ASSERT(success, "not create window");
			Hazel::s_GLFWInitializad = true;
		}
		G_window = glfwCreateWindow((int)props.m_width, (int)props.m_Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(G_window);
		glfwSetWindowUserPointer(G_window, &m_data);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(G_window);
	}

}
