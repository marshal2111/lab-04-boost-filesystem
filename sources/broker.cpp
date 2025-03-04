// Copyright 2021 Your Name <your_email>

#include <stdexcept>
#include <iostream>

#include <broker.hpp>

using std::string;
using std::map;
using std::tuple;
using std::regex;
using std::get;
using std::cmatch;

auto example() -> void {
    throw std::runtime_error("not implemented");
}

void analyzeAll(const string dir_str) {
    map<broker_account, accountInfo> brokers_info {};
    const boost_path dir{dir_str};
    analyzeDirectory(dir, brokers_info);

    printInfo(brokers_info);
}

void analyzeDirectory(const boost_path dir,
                      map<broker_account, accountInfo> &brokers_info)
{
    for (const boost_directory_entry& x : boost_directory_iterator{dir})
    {
        if (is_directory(x)) {
            analyzeDirectory(x.path(), brokers_info);
        } else if (is_symlink(x)) {
            analyzeDirectory(read_symlink(x.path()), brokers_info);
        } else {
            cmatch m;
            regex reg("balance_([0-9]+)_([0-9]+).txt");
            string filename = x.path().filename().string();

            if (regex_match(filename.c_str(), m, reg) &&
                filename.length() == 29)
            {
                broker_account broker = {dir.filename().string(),
                                     filename.substr(8, 8)};
                if (brokers_info.find(broker) != brokers_info.end()) {
                    brokers_info.at(broker).files_count++;
                    int lastdate = stoi(filename.substr(17, 8));
                    if (lastdate > brokers_info.at(broker).lastdate) {
                        brokers_info.at(broker).lastdate = lastdate;
                    }
                } else {
                    accountInfo acc = {1, stoi(filename.substr(17, 8))};
                    brokers_info[broker] = acc;
                }

                std::cout << get<0>(broker) << " "
                          << filename << std::endl;
            }
        }
    }
}

void printInfo(const map<broker_account, accountInfo> &brokers_info) {
    std::cout << std::endl;
    for (const auto& [broker, acc] : brokers_info) {
        std::cout << "broker:" << get<0>(broker) << " "
                  << "account:" << get<1>(broker) << " "
                  << "files:" << acc.files_count << " "
                  << "lastdate:" << acc.lastdate << std::endl;
    }
}
