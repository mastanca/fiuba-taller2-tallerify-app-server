#include <spdlog/spdlog.h>
#include "gmock/gmock.h"

int main(int argc, char **argv) {
    ::testing::InitGoogleMock(&argc, argv);
    auto console = spdlog::stdout_color_mt("console");
    return RUN_ALL_TESTS();
}
