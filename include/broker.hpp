// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_BROKER_HPP_
#define INCLUDE_BROKER_HPP_

#include <boost/filesystem.hpp>
#include <vector>
#include <string>
#include <regex>
#include <map>

#define broker_account tuple<string, string>

using namespace boost::filesystem;
using namespace std;

struct accountInfo {
	int files_count;
	int lastdate;
};

auto example() -> void;

void analyzeDirectory(const path dir,
                      map<broker_account, accountInfo> &brokers_info);
void analyzeAll(const string dir_str);
void printInfo(const map<broker_account, accountInfo> &brokers_info);


#endif // INCLUDE_BROKER_HPP_
