#include <iostream>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

#include "spdlog/spdlog.h"

#include "networking/Server.h"

int main(int argc, char *argv[]) {
    std::cout << "Hello tallerify!" << std::endl;

    mongocxx::instance inst{};
    mongocxx::client conn{mongocxx::uri{}};

    bsoncxx::builder::stream::document document{};

    auto collection = conn["testdb"]["testcollection"];
    document << "hello" << "world";

    //collection.insert_one(document.view());
    auto cursor = collection.find({});

    for (auto &&doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }

    auto console = spdlog::stdout_color_mt("console");
    console->info("Welcome to spdlog!");

    Controller pingController;
    Server server(8000);
    server.registerController(&pingController);
    server.start();

    while(true) {
        sleep(10);
    }

    server.stop();
}
