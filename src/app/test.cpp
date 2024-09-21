#include "test.h"

int main()
{
    init_logger_file();  // Initialize the logger

    LOG_INFO("Application started");
    LOG_WARN("This is a warning");
    LOG_ERROR("An error occurred");

    print_test_logs();

    return 0;
}