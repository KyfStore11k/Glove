#pragma once

#include "Core/pch.h"
#include "spdlog/spdlog.h"

namespace Log {

	class Logger {
	public:
		void Init(bool debug);
		void RefreshPattern();
		void SetPattern(const std::string& str);
		void SetFileLog(const std::string& filePath);
		void RemoveFileLogConfig();
		void GetFileLogCoExist(const std::string& filePath);

		class LogSystem {
		public:
			void Info(std::string str);
			void Warn(std::string str);
			void Trace(std::string str);
			void Error(std::string str);
		};
	};
}