#include "spdlog/spdlog.h"

std::shared_ptr<spdlog::logger> logger;

void printLogs()
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

#include "spdlog/sinks/basic_file_sink.h"
void initLog()
{
    try
    {
        logger = spdlog::basic_logger_mt("test main", "logs/basic-log.txt");
    }
    catch (const spdlog::spdlog_ex& ex)
    {
        spdlog::info("Log init failed: {}", ex.what());
    }
}

int main()
{
    printLogs();
    
    initLog();
    if(logger)
        logger->info("test log {0} {1}", "arg 1", "arg 2");

    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    printLogs();    
}