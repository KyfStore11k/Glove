#include "Log.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <filesystem>
namespace fs = std::filesystem;

namespace Log {

	std::string pattern = "%+";

	bool debugLog;

	void Logger::Init(bool debug) {
		debugLog == debug;
		try {
			spdlog::set_pattern(pattern);
			if (debug == true)
				spdlog::info("Logger initialized");
		}
		catch (const spdlog::spdlog_ex& ex) {
			std::cerr << "Logging initialization failed: " << ex.what() << std::endl;
		}
	}

	void Logger::RefreshPattern()
	{
		spdlog::set_pattern(pattern);
	}

	void Logger::SetPattern(const std::string& str)
	{
		pattern = str;
	}

	void Logger::SetFileLog(const std::string& filePath)
	{
		try {
			// Create a file sink (write to the log file)
			auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filePath, true);

			// Check if the logger already exists
			auto logger = spdlog::get("default_logger");

			if (!logger) {
				// If the logger does not exist, create it
				logger = std::make_shared<spdlog::logger>("default_logger", file_sink);
				spdlog::set_default_logger(logger);
				if (debugLog == true)
					spdlog::info("Logger created and set.");
			}
			else {
				// If the logger exists, add the file sink
				logger->sinks().push_back(file_sink);
				if (debugLog == true)
					spdlog::info("File sink added to existing logger.");
			}

			// Set logging level and pattern
			spdlog::set_level(spdlog::level::info);
			logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");

			if (debugLog == true)
				spdlog::info("File logging initialized: {}", filePath);
		}
		catch (const spdlog::spdlog_ex& ex) {
			std::cerr << "Failed to initialize file logging: " << ex.what() << std::endl;
		}
	}

	void Logger::RemoveFileLogConfig()
	{
		try {
			// Get the current default logger
			auto logger = spdlog::get("default_logger");

			if (logger) {
				// Remove all sinks (including the file sink)
				logger->sinks().clear();
				if (debugLog == true)
					spdlog::info("File sink removed.");

				// Create a console sink (for terminal/console logging)
				auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

				// Add the console sink to the logger
				logger->sinks().push_back(console_sink);
				if (debugLog == true)
					spdlog::info("Console sink added to logger.");

				// Set the logging level and pattern for the console sink
				logger->set_level(spdlog::level::info);
				logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");

				if (debugLog == true)
					spdlog::info("Now logging to terminal only.");
			}
			else {
				std::cerr << "No logger available to remove file logging." << std::endl;
			}
		}
		catch (const spdlog::spdlog_ex& ex) {
			std::cerr << "Failed to switch to terminal logging: " << ex.what() << std::endl;
		}
	}

	void Logger::GetFileLogCoExist(const std::string& filePath)
	{
		try {
			// Create sinks for both terminal and file logging
			auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
			auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(filePath, true);

			// Combine the sinks into a multi-sink logger
			std::vector<spdlog::sink_ptr> sinks{ console_sink, file_sink };
			auto logger = std::make_shared<spdlog::logger>("multi_sink_logger", sinks.begin(), sinks.end());

			// Set it as the default logger
			spdlog::set_default_logger(logger);

			// Optionally set the log pattern
			logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v");

			if (debugLog == true)
				spdlog::info("File and terminal logging enabled. File path: {}", filePath);
		}
		catch (const spdlog::spdlog_ex& ex) {
			std::cerr << "Failed to enable file and terminal logging: " << ex.what() << std::endl;
		}
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