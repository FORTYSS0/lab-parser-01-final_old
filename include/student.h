#ifndef TEMPLATE_STUDENT_H
#define TEMPLATE_STUDENT_H
#include "parser.hpp"
using any = std::any;
using string = std::string;

struct Student {
  string Name;
  any Group;
  any Avg;
  any Debt;
};

#endif  // TEMPLATE_STUDENT_H