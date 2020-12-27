//
// Created by FORTYSS on 05.11.2020.
//

#include <parser-lab-1.hpp>

bool input(const string& File){
  std::ifstream file;
    file.open(File);
    file >> data;
    if(!file)
      throw std::runtime_error(
          "There is no file with this name");
    else if(data.empty())
      throw std::runtime_error(
          "json"+File+" the file is empty");
    return false;
}
bool items_is_array() {
  if (!data["items"].is_array()) {
    throw std::runtime_error{"The items field is not an array"};
  } else {
    return true;
  }
}
size_t Size(const json& value, const string& valueName, size_t& stringLength){
  if (static_cast<size_t>(
          std::to_string(static_cast<float>(value.at(valueName)))
              .length()) > stringLength)
    return static_cast<int>(
        std::to_string(static_cast<float>(value.at(valueName))).length());
  else return stringLength;
}
std::any getValue(const json& value, const string& valueName, size_t& stringLength) {
  if (!value.at(valueName)) {
    throw std::runtime_error{"There is no field with with name: " + valueName};
  }
  if (value.at(valueName).is_number_integer()) {
    stringLength = Size(value, valueName, stringLength);
    return std::any_cast<int>(value.at(valueName));
  } else if (value.at(valueName).is_number_float()) {
    stringLength = Size(value, valueName, stringLength);
    return std::any_cast<double>(value.at(valueName));
  } else if (value.at(valueName).is_string()) {
    stringLength = Size(value, valueName, stringLength);
    return std::any_cast<string>(value.at(valueName));
  } else if (valueName == "debt") {
    if (value.at(valueName).is_array()) {
      return std::any_cast<std::vector<std::string>>(value.at(valueName));
    } else if (value.at(valueName).is_null()) {
      return nullptr;
    } else
      throw std::runtime_error("There is no correct-type field with name: " +
                               valueName);
  } else
    throw std::runtime_error("There is no correct-type field with name: " +
                             valueName);
}
std::vector<Student> parser(const string& File, size_t len[4]) {
    if (input(File)) {}
    if(items_is_array()){}
      std::vector<Student> students;
      for (const auto& student : data.at("items")) {
        Student student_now;
        student_now.Name = student.at("name");
        if (static_cast<size_t>(student_now.Name.length()) > len[0])
          len[0] = static_cast<size_t>(student_now.Name.length());
        student_now.Group=getValue(student, "group", len[1]);
        student_now.Avg=getValue(student, "avg", len[2]);
        student_now.Debt=getValue(student, "debt", len[3]);
      }
      return students;
}

