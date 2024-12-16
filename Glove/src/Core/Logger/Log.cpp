#include "Log.h"

namespace Log {

	std::string pattern = "%+";

	void Logger::Init() {
		RefreshPattern();
	}

	void Logger::RefreshPattern()
	{
		spdlog::set_pattern(pattern);
	}

	void Logger::SetPattern(const std::string& str)
	{
		pattern = str;
	}

	void Logger::LogSystem::Info(std::string str)
	{
		spdlog::info(str);
	}

	void Logger::LogSystem::Trace(std::string str)
	{
		spdlog::trace(str);
	}

	void Logger::LogSystem::Warn(std::string str)
	{
		spdlog::warn(str);
	}

	void Logger::LogSystem::Error(std::string str)
	{
		spdlog::error(str);
	}

}