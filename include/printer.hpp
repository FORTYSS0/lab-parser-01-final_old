//
// Created by FORTYSS on 05.11.2020.
//

#ifndef LAB_PARSER_01_PRINTER_HPP
#define LAB_PARSER_01_PRINTER_HPP
#include <any>
#include <iostream>
#include <vector>

#include "student.h"
string any_print(const std::any& object);
void print(const std::vector<Student>& students, int len[4]);
#endif  // LAB_PARSER_01_PRINTER_HPP
