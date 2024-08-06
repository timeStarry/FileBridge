#include <tlog.h>

#include <cxxopts.hpp>
#include <iostream>
#include <string>

enum rcmode { DEFAULT, SEND, RECV };

auto main(int argc, char* argv[]) -> int {
    rcmode mode{rcmode::DEFAULT};
    bool verbose{false};
    cxxopts::Options options("fb", "基于C++的端到端文件传输服务");

    options.add_options()
        ("send", "send file")
        ("recv", "recive file")
        ("v,verbose", "show more information")
        ("f,file", "The filename(s) to process",
            cxxopts::value<std::vector<std::string>>())
        ("h,help", "help infomation");

    auto result = options.parse(argc, argv);

    if (result.count("help") != 0U) {
        std::cout << options.help();
        return 0;
    }

    if (result.count("verbose") != 0U) {
        verbose = true;
    }

    if (result.count("send") != 0U) {
        mode = rcmode::SEND;
    }
    if (result.count("recv") != 0U) {
        if (mode == rcmode::SEND) {
            if (verbose) {
                tlog::tprint({"send and recv cannot appear at the same time"},
                             tlog::tlog_status::ERROR, tlog::NO_LOG_FILE);
            }
            return 0;
        }
        mode = rcmode::RECV;
    }

    if (result.count("file") != 0U) {
        if (mode == rcmode::DEFAULT) {
            if (verbose) {
                tlog::tprint(
                    {"The operation mode must be specified (send or recv)"},
                    tlog::tlog_status::ERROR, tlog::NO_LOG_FILE);
            }
            return -1;
        }
        // read file list, like: file1,file2,file3
        auto files = result["file"].as<std::vector<std::string>>();
        switch (mode) {
            case SEND:
                if (verbose) {
                    for (const auto& val : files) {
                        tlog::tprint({"send file: ", val},
                                     tlog::tlog_status::INFO,
                                     tlog::NO_LOG_FILE);
                    }
                }
                break;
            case RECV:
                if (verbose) {
                    for (const auto& val : files) {
                        tlog::tprint({"recv file: ", val},
                                     tlog::tlog_status::INFO,
                                     tlog::NO_LOG_FILE);
                    }
                }
                break;
            case DEFAULT:
                tlog::tprint(
                    {"The operation mode must be specified (send or recv)"},
                    tlog::tlog_status::ERROR, tlog::NO_LOG_FILE);
                return -1;
        }
    } else {
        // if mode == send or recv , then we need file(s) to deal with it.
        if (mode != rcmode::DEFAULT) {
            tlog::tprint({"need file(s)"}, tlog::tlog_status::ERROR,
                         tlog::NO_LOG_FILE);
            return -1;
        }
        // if mode == default, then print help message.
        std::cout << options.help() << std::endl;
    }
    return 0;
}
