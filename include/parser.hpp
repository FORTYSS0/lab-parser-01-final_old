// Copyright 2020 Your Name <your_email>

#ifndef INCLUDE_PARSER_HPP_
#define INCLUDE_PARSER_HPP_

#include <any>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <string>

#include "../include/student.h"
using string = std::string;
using json = nlohmann::json;

std::vector<Student> parser(const string& File, size_t len[4], json& data);
bool input(const string& File, json& data);
string any_print(const std::any& object);
void print(const std::vector<Student>& students, size_t len[4]);
#endif  // INCLUDE_PARSER_HPP_
