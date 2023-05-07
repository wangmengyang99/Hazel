#include "hzpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Hazel {
	std::shared_ptr<spdlog::logger> Log::s_Logger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	void Log::Init()
	{
		spdlog::set_pattern("%^%T %n:%v%$");
		s_Logger = spdlog::stdout_color_mt("Hazel");
		s_Logger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::trace);
	}



}
