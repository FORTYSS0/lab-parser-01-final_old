// Copyright 2020 by FORTYSS

#include "parser.hpp"
std::string any_print(const std::any& input) {
  string output;
  if (input.type() == typeid(string)) {
    output = std::any_cast<std::string>(input);
  }else {
    if (input.type() == typeid(int)) {
        std::stringstream out;
        out << std::any_cast<int>(input);
        output = out.str();
    } else {
      if (input.type() == typeid(double)) {
          std::stringstream out;
        out << std::any_cast<double>(input);
        output = out.str();
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
std::string print(const std::vector<Student>& students, size_t len[4]) {
    std::stringstream out;
  out << '|' << std::setfill(' ') << " name"
            << std::setw(len[0]) << '|';
  out << std::setfill(' ') << " group" << std::setw(len[1]);
  out << '|';
  out << std::setfill(' ') << " avg" << std::setw(len[2]);
  out << '|';
  out << std::setfill(' ') << " debt" << std::setw(len[3]);
  out << '|';
  out << std::endl;
  out << '|';
  out << std::setfill('-') << std::setw(len[0] + 5);
  out << '|';
  out << std::setfill('-') << std::setw(len[1] + 6);
  out << '|';
  out << std::setfill('-') << std::setw(len[2] + 4);
  out << '|';
  out << std::setfill('-') << std::setw(len[3] + 5);
  out << '|';
  out << std::endl;

  for (const auto& student : students) {
    out << '|' << ' ' << std::setfill(' ') << std::left
              << std::setw(len[0] + 3) << student.Name << '|' << ' ';
    out << std::setfill(' ') << std::setw(len[1] + 4)
              << any_print(student.Group) << '|' << ' ';
    out << std::setfill(' ') << std::setw(len[2] + 2)
              << any_print(student.Avg) << '|' << ' ';
    out << std::setfill(' ') << std::setw(len[3] + 3)
              << any_print(student.Debt) << '|';
    out << std::endl;
    out << std::setfill('-') << std::setw(len[0] + 5);
    out << '|';
    out << std::setfill('-') << std::setw(len[1] + 6);
    out << '|';
    out << std::setfill('-') << std::setw(len[2] + 4);
    out << '|';
    out << std::setfill('-') << std::setw(len[3] + 5);
    out << '|';
    out << '|';
    out << std::endl;
  }
  //std::cout << out.str();
    return out.str();
}
