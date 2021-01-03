#ifndef TEMPLATE_STUDENT_H
#define TEMPLATE_STUDENT_H
#include "parser.hpp"
using string = std::string;
using any = std::any;

struct Student {
  string Name;
  any Group;
  any Avg;
  any Debt;
};

#endif  // TEMPLATE_STUDENT_H