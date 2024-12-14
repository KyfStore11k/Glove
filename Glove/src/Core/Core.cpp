#include <iostream>
#include "spdlog/spdlog.h"

int main() {
	spdlog::set_pattern("%+");

	spdlog::info("Initial Commit!");

	std::cin.get();

	return 0;
}
