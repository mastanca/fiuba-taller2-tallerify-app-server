#include <spdlog/spdlog.h>
#include "gmock/gmock.h"

int main(int argc, char **argv) {
    sleep(5);
    ::testing::InitGoogleMock(&argc, argv);
    auto console = spdlog::stdout_logger_mt("console");
    srand(time(NULL));
    return RUN_ALL_TESTS();
}
