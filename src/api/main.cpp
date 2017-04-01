#include <iostream>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include "spdlog/spdlog.h"

#include "networking/Server.h"
#include "networking/JSONResponse.h"

volatile static bool running = true;

void handle_signal(int sig) {
    if (running) {
        std::cout << "Exiting..." << std::endl;
        running = false;
    }
}

int main(int argc, char *argv[]) {
    std::cout << "Hello tallerify!" << std::endl;

//    mongocxx::instance inst{};
//    mongocxx::client conn{mongocxx::uri{}};
//
//    bsoncxx::builder::stream::document document{};
//
//    auto collection = conn["testdb"]["testcollection"];
//    document << "hello" << "world";
//
//    //collection.insert_one(document.view());
//    auto cursor = collection.find({});
//
//    for (auto &&doc : cursor) {
//        std::cout << bsoncxx::to_json(doc) << std::endl;
//    }

    auto console = spdlog::stdout_color_mt("console");
    spdlog::set_pattern("[%H:%M:%S %z] %v");

    srand(time(NULL));

#ifdef __APPLE__
    signal(SIGINT, handle_signal);
#endif

    Server server;
    server.start();

    while (running) {
        sleep(10);
    }

    server.stop();

    spdlog::drop_all();

    return EXIT_SUCCESS;
}
