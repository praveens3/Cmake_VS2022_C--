#ifndef MYLIB_H
#define MYLIB_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <memory>
#include <string>

extern std::string logger_name;

// Initialize a logger (could be called in your library initialization code)
void init_logger_console();

// Initialize a file logger
void init_logger_file();

//print test log content
void print_test_logs();

// Logging macros
#define LOG_INFO(msg) spdlog::get(logger_name)->info(msg)
#define LOG_DEBUG(msg) spdlog::get(logger_name)->debug(msg)
#define LOG_WARN(msg) spdlog::get(logger_name)->warn(msg)
#define LOG_ERROR(msg) spdlog::get(logger_name)->error(msg)
#define LOG_CRITICAL(msg) spdlog::get(logger_name)->critical(msg)

// Function to set the logging level
void set_log_level(spdlog::level::level_enum level);

#endif // MYLIB_H