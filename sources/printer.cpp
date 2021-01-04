// Copyright 2020 by FORTYSS

#include "parser.hpp"
std::string any_print(const std::any& input) {
  string output;
  if (input.type() == typeid(string)) {
    output = std::any_cast<std::string>(input);
  }else {
    if (input.type() == typeid(int)) {
      std::cout << std::any_cast<int>(input);
      output = std::any_cast<int>(input);
    } else {
      if (input.type() == typeid(double)) {
        std::cout << std::any_cast<double>(input);
        output = std::any_cast<double>(input);
      } else {
        if (input.type() == typeid(nullptr)) {
          output = "null";
        } else {
          if (input.type() == typeid(std::vector<string>)) {
            std::vector<string> vector =
                std::any_cast<std::vector<string>>(input);
            int size = vector.size();
            if (size > 1) {
              output = std::to_string(size) + " item";
            } else {
              if (size == 1) {
                output = vector[0];
              }
            }
          } else {
            std::bad_cast ex;
            throw ex;
          }
        }
      }
    }
  }
  return output;
}
void print(const std::vector<Student>& students, size_t len[4]) {
  std::cout << '|' << std::setfill(' ') << " name"
            << std::setw(len[0]) << '|';
  std::cout << std::setfill(' ') << " group" << std::setw(len[1]);
  std::cout << '|';
  std::cout << std::setfill(' ') << " avg" << std::setw(len[2]);
  std::cout << '|';
  std::cout << std::setfill(' ') << " debt" << std::setw(len[3]);
  std::cout << '|';
  std::cout << std::endl;
  std::cout << '|';
  std::cout << std::setfill('-') << std::setw(len[0] + 5);
  std::cout << '|';
  std::cout << std::setfill('-') << std::setw(len[1] + 6);
  std::cout << '|';
  std::cout << std::setfill('-') << std::setw(len[2] + 4);
  std::cout << '|';
  std::cout << std::setfill('-') << std::setw(len[3] + 5);
  std::cout << '|\n';

  for (const auto& student : students) {
    std::cout << '|' << ' ' << std::setfill(' ') << std::left
              << std::setw(len[0] + 3) << student.Name << '|' << ' ';
    std::cout << std::setfill(' ') << std::setw(len[1] + 4)
              << any_print(student.Group) << '|' << ' ';
    std::cout << std::setfill(' ') << std::setw(len[2] + 2)
              << any_print(student.Avg) << '|' << ' ';
    std::cout << std::setfill(' ') << std::setw(len[3] + 3)
              << any_print(student.Debt) << '|';
    std::cout << std::endl;
    std::cout << std::setfill('-') << std::setw(len[0] + 5);
    std::cout << '|';
    std::cout << std::setfill('-') << std::setw(len[1] + 6);
    std::cout << '|';
    std::cout << std::setfill('-') << std::setw(len[2] + 4);
    std::cout << '|';
    std::cout << std::setfill('-') << std::setw(len[3] + 5);
    std::cout << '|';
    std::cout << '|\n';
  }
}
