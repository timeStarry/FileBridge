#include <cxxopts.hpp>
#include <iostream>
#include <string>
#include <tlog.h>

auto main(int argc, char* argv[]) -> int {
    cxxopts::Options options("fb", "基于C++的端到端文件传输服务");
    options.add_options()
        ("send", "send file")
        ("recv", "recive file")
        ("f,file", "The filename(s) to process",
            cxxopts::value<std::vector<std::string>>())
        ("h,help", "help infomation");
    
    auto result = options.parse(argc, argv);

    if (result.count("help") != 0U) {
        std::cout << options.help();
        return 0;
    }

    if(result.count("send") != 0U){
        tlog::tprint({"send!!!"}, tlog::tlog_status::INFO);
        return 0;
    }
    if(result.count("recv") != 0U){
        tlog::tprint({"recv!!!"}, tlog::tlog_status::INFO);
        return 0;
    }

    if (result.count("file") != 0U) {
        // read file list, like: file1,file2,file3
        auto files = result["file"].as<std::vector<std::string>>();
        for (const auto& val : files) {
            tlog::tprint({"file: ", val}, tlog::tlog_status::INFO);
        }
        return 0;
    }

    std::cout << options.help() << std::endl;
    return 0;
}