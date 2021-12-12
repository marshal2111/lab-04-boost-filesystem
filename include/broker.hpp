// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_BROKER_HPP_
#define INCLUDE_BROKER_HPP_

#include <boost/filesystem.hpp>
#include <vector>
#include <string>
#include <regex>
#include <map>

#define broker_account std::tuple<std::string, std::string>
#define boost_path boost::filesystem::path
#define boost_directory_entry boost::filesystem::directory_entry
#define boost_directory_iterator boost::filesystem::directory_iterator

struct accountInfo {
	int files_count;
	int lastdate;
};

auto example() -> void;

void analyzeDirectory(const boost_path dir,
                      std::map<broker_account, accountInfo> &brokers_info);
void analyzeAll(const std::string dir_str);
void printInfo(const std::map<broker_account, accountInfo> &brokers_info);


#endif // INCLUDE_BROKER_HPP_
