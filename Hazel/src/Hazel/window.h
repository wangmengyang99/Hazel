#pragma once
#include "hzpch.h"
#include "Hazel/Core.h"
#include "Hazel/Event/Event.h"
namespace Hazel {
	struct  WindowPorps
	{
		std::string Title;
		unsigned int m_width;
		unsigned int m_Height;
		WindowPorps(const std::string& tit = "Hazel Engine",
			unsigned int width = 1280,
			unsigned int height = 760)
			:Title(tit), m_width(width), m_Height(height) {

		}
	};
	class HAZEL_API window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~window() {}
		virtual void OnUpdate() = 0;
		virtual unsigned int GetWidthSize()const = 0;
		virtual unsigned int GetHeightSize()const = 0;
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync()const = 0;
		static window* Create(const WindowPorps& props = WindowPorps());
	private:

	};


}