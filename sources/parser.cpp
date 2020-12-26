//
// Created by FORTYSS on 05.11.2020.
//

#include <parser-lab-1.hpp>
bool input(const string& File){
  std::ifstream file;
  try {
    file.open(File);
    file >> data;
  }
  catch (std::exception& err) {
    if(!file)
      std::cout << "There is no file with this name\nError: " << err.what()
                       << std::endl;
    else if(data.empty())
      std::cout << "json "+File+" the file is empty\nError: " << err.what()
                                   << std::endl;
    return false;
  }
  return true;
}
std::vector<Student> parser(const string& File, int len[4]) {
  //if(File!="" && File!=" ") {
    if (input(File)) {}

      std::vector<Student> students;
      for (const auto& student : data.at("items")) {
        Student student_now;
        student_now.Name = student.at("name");
        if (static_cast<int>(student_now.Name.length()) > len[0])
          len[0] = static_cast<int>(student_now.Name.length());
        if (student.at("group").is_string()) {
          student_now.Group = static_cast<string>(student.at("group"));
          if (static_cast<int>(
                  static_cast<string>(student.at("group")).length()) > len[1])
            len[1] = static_cast<int>(
                static_cast<string>(student.at("group")).length());
        } else {
          student_now.Group = static_cast<int>(student.at("group"));
          if (static_cast<int>(
                  std::to_string(static_cast<int>(student.at("group")))
                      .length()) > len[1])
            len[1] = static_cast<int>(
                std::to_string(static_cast<int>(student.at("group"))).length());
          else
            throw std::runtime_error(
                "The variable Group has the wrong data type");
        }
        if (student.at("avg").is_string()) {
          std::size_t offset = 0;
          string avg_read = student.at("avg");
          student_now.Avg = std::stod(avg_read, &offset);
          if (static_cast<int>(
                  static_cast<string>(student.at("avg")).length()) > len[2])
            len[2] = static_cast<int>(
                static_cast<string>(student.at("avg")).length());
        } else if (student.at("avg").is_number_integer()) {
          student_now.Avg = static_cast<float>(student.at("avg"));
          if (static_cast<int>(
                  std::to_string(static_cast<float>(student.at("avg")))
                      .length()) > len[2])
            len[2] = static_cast<int>(
                std::to_string(static_cast<float>(student.at("avg"))).length());
        } else if (student.at("avg").is_number_float()) {
          student_now.Avg = student.at("avg");
          if (static_cast<int>(
                  std::to_string(static_cast<float>(student.at("avg")))
                      .length()) > len[2])
            len[2] = static_cast<int>(
                std::to_string(static_cast<float>(student.at("avg"))).length());
          else
            throw std::runtime_error(
                "The variable Avg has the wrong data type");
        }
        if (student.at("debt").is_string()) {
          student_now.Debt = static_cast<std::string>(student.at("debt"));
          if (static_cast<int>(
                  static_cast<string>(student.at("debt")).length()) > len[3])
            len[3] = static_cast<int>(
                static_cast<string>(student.at("debt")).length());
        } else if (student.at("debt").is_array()) {
          student_now.Debt =
              static_cast<std::vector<std::string>>(student.at("debt"));
        } else if (student.at("debt").is_null()) {
          student_now.Debt = nullptr;
        } else if (!student.at("debt").is_array())
          throw std::runtime_error(
              "items is not an array\nThe variable Debt has the wrong data type");
        students.push_back(student_now);
      }
      return students;
   // }
  //}else{
  //  throw std::runtime_error(
 //       "The argument does not contain the file path");
 // }
}
