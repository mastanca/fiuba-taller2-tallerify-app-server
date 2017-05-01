#include <iostream>

#include "spdlog/spdlog.h"

#include "networking/Server.h"

volatile static bool running = true;

void handle_signal(int sig) {
    if (running) {
        std::cout << "Exiting..." << std::endl;
        running = false;
    }
}

int main(int argc, char *argv[]) {
    auto console = spdlog::stdout_color_mt("console");
    spdlog::set_pattern("[%H:%M:%S %z] %v");
    srand(time(NULL));

#ifdef __APPLE__
    signal(SIGINT, handle_signal);
#endif

    std::string ip = argv[1];
    Server server(8080, ip);
    server.start();

    while (running) {
        sleep(10);
    }

    server.stop();

    spdlog::drop_all();

    return EXIT_SUCCESS;
}
