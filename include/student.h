#ifndef TEMPLATE_STUDENT_H
#define TEMPLATE_STUDENT_H
#include "parser.hpp"

struct Student {
  std::string Name;
  std::any Group;
  std::any Avg;
  std::any Debt;
};

#endif  // TEMPLATE_STUDENT_H