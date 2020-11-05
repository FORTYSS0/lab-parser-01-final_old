// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <any>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>

#include "student.h"
using string = std::string;
using json = nlohmann::json;
std::vector<Student> parser(const string& File,int len[4]);
string any_print(const std::any& object);
void print(const std::vector<Student>& students, int len[4]);
#endif  // INCLUDE_HEADER_HPP_
