#include "myLib.h"
#include "spdlog/sinks/basic_file_sink.h"

std::string logger_name; // Define the variable

// Initialize a logger (could be called in your library initialization code)
void init_logger_console() {
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::trace);
    console_sink->set_pattern("[%Y-%m-%d %H:%M:%S] [%^%l%$] %v");
    logger_name = "console-logger";
    auto logger = std::make_shared<spdlog::logger>(logger_name.c_str(), console_sink);
    spdlog::register_logger(logger);
}

// Initialize a file logger
void init_logger_file() {
    try {
        logger_name = "file-logger";
        auto file_logger = spdlog::basic_logger_mt(logger_name, "logs/my_log.txt");
        spdlog::set_default_logger(file_logger);
        spdlog::set_pattern("%Y-%m-%d %H:%M:%S.%e [%n] [%l] [thread %t] %v");
        spdlog::set_level(spdlog::level::debug); // Set the desired log level
        spdlog::info("log initialized");
        spdlog::set_pattern("%Y-%m-%d %H:%M:%S.%e [%l] [thread %t] %v");
    }
    catch (const spdlog::spdlog_ex& ex) {
        spdlog::warn("Log initialization failed: {0}", ex.what());
    }
}

void set_log_level(spdlog::level::level_enum level) {
    spdlog::set_level(level);
}

void print_test_logs()
{
    spdlog::set_level(spdlog::level::info); // Set global log level to debug

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::debug("This message should not be displayed..");
    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..\n\n");
}