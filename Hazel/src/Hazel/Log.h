#pragma once
#include "Core.h"
#include "hzpch.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hazel {
     class HAZEL_API Log 
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetLogger(){ return s_Logger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){ return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
//core logger macros
#define HZ_CORE_TRACE(...) ::Hazel::Log::GetLogger().get()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...) ::Hazel::Log::GetLogger().get()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...) ::Hazel::Log::GetLogger().get()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...) ::Hazel::Log::GetLogger().get()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...) ::Hazel::Log::GetLogger().get()->fatal(__VA_ARGS__)
//client log macros
#define HZ_TRACE(...)  ::Hazel::Log::GetClientLogger().get()->trace(__VA_ARGS__)
#define HZ_INFO(...)   ::Hazel::Log::GetClientLogger().get()->info(__VA_ARGS__)
#define HZ_WARN(...)   ::Hazel::Log::GetClientLogger().get()->warn(__VA_ARGS__)
#define HZ_ERROR(...)  ::Hazel::Log::GetClientLogger().get()->error(__VA_ARGS__)
#define HZ_FATAL(...)  ::Hazel::Log::GetClientLogger().get()->fatal(__VA_ARGS__)
