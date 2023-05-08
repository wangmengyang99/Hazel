#pragma once
#include <Hazel/window.h>
#include <GLFW/glfw3.h>
namespace Hazel {
	class WindowsWindow :public window {
	public:
		WindowsWindow(const Hazel::WindowPorps& props);
		virtual ~WindowsWindow();
		void OnUpdate()override;
		inline unsigned int GetWidthSize()const override { return m_data.m_width; }
		inline unsigned int GetHeightSize()const override { return m_data.m_height; }
		inline void SetEventCallback(const EventCallbackFn& callback)override { m_data.EventCallback = callback; }
		void SetVSync(bool enabled)override;
		bool IsVSync()const override;
	private:
		void Init(const Hazel::WindowPorps& props);
		virtual void Shutdown();
		GLFWwindow* G_window;
		struct WindowData
		{
			std::string Title;
			unsigned int m_width, m_height;
			bool VSync;
			EventCallbackFn EventCallback;
		};
		WindowData m_data;
	};
}
