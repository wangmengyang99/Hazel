#include "hzpch.h"
#include "WindowsWindow.h"
#include "Hazel/Log.h"

#include "Hazel/Event/ApplicationEvent.h"
#include "Hazel/Event/KeyEvent.h"
#include "Hazel/Event/MouseEvent.h"
namespace Hazel {
	static bool s_GLFWInitializad = false;
	static void GLFWErrorCallBack(int error, const char* des) {
		HZ_CORE_ERROR("GLFW ERROR{0}:{1}",error,des);
	}
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
			glfwSetErrorCallback(GLFWErrorCallBack);
			Hazel::s_GLFWInitializad = true;
		}
		G_window = glfwCreateWindow((int)props.m_width, (int)props.m_Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(G_window);
		glfwSetWindowUserPointer(G_window, &m_data);
		SetVSync(true);

		glfwSetWindowSizeCallback(G_window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		data.m_width = width;
		data.m_height = height;
		WindowResizeEvent event(width, height);
		data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(G_window, [](GLFWwindow* window) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		WindowCloseEvent event;
		data.EventCallback(event);
			});

		glfwSetKeyCallback(G_window, [](GLFWwindow* window, int key, int sancode, int action, int modes) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		switch (action)
		{
		case GLFW_PRESS: {
			KeyPressedEvent event(key, 0);
			data.EventCallback(event);
			break;
		}
		case GLFW_RELEASE: {
			KeyReleasedEvent event(key);
			data.EventCallback(event);
			break;
		}
		case GLFW_REPEAT: {
			KeyPressedEvent event(key, 1);
			data.EventCallback(event);
			break;
		}
		}
			});

		glfwSetMouseButtonCallback(G_window, [](GLFWwindow* window, int button, int action, int modes) {
		WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		switch (action) {
		case GLFW_PRESS: {
			MouseButtonPressedEvent event(button);
			data.EventCallback(event);
			break;
		}
		case GLFW_RELEASE: {
			MouseButtonReleasedEvent event(button);
			data.EventCallback(event);
			break;
		}
		}
			});

		glfwSetScrollCallback(G_window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		     MouseScrolledEvent event((float)xOffset,(float)yOffset);
		    data.EventCallback(event);
			});
		glfwSetCursorPosCallback(G_window, [](GLFWwindow* window, double xPos, double yPos) {
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
		    MouseMovedEvent event((float)xPos,(float)yPos);
			data.EventCallback(event);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(G_window);
	}

}
