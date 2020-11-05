// Copyright 2020 Your Name <your_email>

#include "parser-lab-1.hpp"
/*std::vector<Student> parser(const string& File, int len[4]) {
  file.open(File);
  if (!file) {
    std::cout << "Нет файла с таким именем" << std::endl;
    throw std::runtime_error("file isn't exist");
  }
  json data;
  file >> data;
  std::vector<Student> students;
  for (const auto& student : data.at("items")) {
    Student student_now;
    student_now.Name = student.at("name");
    if (static_cast<int>(student_now.Name.length()) > len[0])
      len[0] = static_cast<int>(student_now.Name.length());
    if (student.at("group").is_string()) {
      student_now.Group = static_cast<string>(student.at("group"));
      if (static_cast<int>(static_cast<string>(student.at("group")).length()) >
          len[1])
        len[1] =
            static_cast<int>(static_cast<string>(student.at("group")).length());
    } else {
      student_now.Group = static_cast<int>(student.at("group"));
      if (static_cast<int>(
              std::to_string(static_cast<int>(student.at("group"))).length()) >
          len[1])
        len[1] = static_cast<int>(
            std::to_string(static_cast<int>(student.at("group"))).length());
    }
    if (student.at("avg").is_string()) {
      std::size_t offset = 0;
      string avg_read = student.at("avg");
      student_now.Avg = std::stod(avg_read, &offset);
      if (static_cast<int>(static_cast<string>(student.at("avg")).length()) >
          len[2])
        len[2] =
            static_cast<int>(static_cast<string>(student.at("avg")).length());
    } else if (student.at("avg").is_number_integer()) {
      student_now.Avg = static_cast<float>(student.at("avg"));
      if (static_cast<int>(
              std::to_string(static_cast<float>(student.at("avg"))).length()) >
          len[2])
        len[2] = static_cast<int>(
            std::to_string(static_cast<float>(student.at("avg"))).length());
    } else if (student.at("avg").is_number_float()) {
      student_now.Avg = student.at("avg");
      if (static_cast<int>(
              std::to_string(static_cast<float>(student.at("avg"))).length()) >
          len[2])
        len[2] = static_cast<int>(
            std::to_string(static_cast<float>(student.at("avg"))).length());
    }
    if (student.at("debt").is_string()) {
      student_now.Debt = static_cast<std::string>(student.at("debt"));
      if (static_cast<int>(static_cast<string>(student.at("debt")).length()) >
          len[3])
        len[3] =
            static_cast<int>(static_cast<string>(student.at("debt")).length());
    } else if (student.at("debt").is_array()) {
      student_now.Debt =
          static_cast<std::vector<std::string>>(student.at("debt"));
    } else if (student.at("debt").is_null()) {
      student_now.Debt = nullptr;
    }
    students.push_back(student_now);
  }
  return students;
}
std::string any_print(const std::any& input) {
  string output;
  if (input.type() == typeid(string))
    output = std::any_cast<std::string>(input);
  else if (input.type() == typeid(int))
    output = std::any_cast<int>(input);
  else if (input.type() == typeid(float))
    output = std::any_cast<float>(input);
  else if (input.type() == typeid(nullptr))
    output = "null";
  else if (input.type() == typeid(std::vector<string>)) {
    std::vector<string> vector = std::any_cast<std::vector<string>>(input);
    int size = vector.size();
    if (size > 1)
      output = std::to_string(size) + " item";
    else if (size == 1)
      output = vector[0];
  } else {
    std::bad_cast ex;
    throw ex;
  }
  return output;
}
void print(const std::vector<Student>& students, int len[4]) {
  std::cout << '|';
  std::cout << std::setfill(' ') << " name" << std::setw(len[0]);
  std::cout << '|';
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
  std::cout << '|';
  std::cout << std::endl;
  for (const auto& student : students) {
    std::cout << '|' << ' ' << std::setfill(' ') << std::left
              << std::setw(len[0] + 3) << student.Name << '|' << ' ';
    std::cout << std::setfill(' ') << std::setw(len[1] + 4)
              << any_print(student.Group) << '|' << ' ';
    std::cout << std::setfill(' ') << std::setw(len[2] + 2) << student.Avg
              << '|' << ' ';
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
    std::cout << '|';
    std::cout << std::endl;
  }
}*/
int main() {
  const ::string File =
      "/home/FORTYSS/Рабочий стол/1/lab-parser-01/sources/Students.json";
  int len[4] = {11, 3, 3, 11};
  std::vector<Student> students = parser(File, len) ;
  print(students, len);
  return 0;
}
