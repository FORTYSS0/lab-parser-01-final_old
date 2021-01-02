// Copyright 2020 by FORTYSS


#include <parser.hpp>

bool input(const string& File, json& data) {
  //json data;
  std::ifstream file;
  file.open(File);
  if (!file)
    throw std::runtime_error("There is no file with this name");
  file >> data;
  if (data.empty())
    throw std::runtime_error("json " + File + " the file is empty");

  if (!data["items"].is_array())
    throw std::runtime_error{"The items field is not an array"};
  if (data["items"].size() != data["_meta"]["count"].get<size_t>())
    throw std::runtime_error{
        "The data in _meta is not equal to the length of the items array"};
  file.close();
  return true;
}

size_t Size(const json& data, const string& valueName, size_t& stringLength) {
  if (data.at(valueName).is_string()) {
    if (static_cast<size_t>(static_cast<string>(data.at(valueName)).length()) >
        stringLength) {
      return static_cast<size_t>(
          static_cast<string>(data.at(valueName)).length());
    } else {
      return stringLength;
    }
  } else {
    if (data.at(valueName).is_array()) {
      if (static_cast<size_t>(
          std::to_string(static_cast<std::vector<std::string>>(
                                 data.at(valueName)).size()).length())>
          stringLength){
            return static_cast<size_t>(
                std::to_string(static_cast<std::vector<std::string>>(
                               data.at(valueName)).size()).length());
      } else {
        return stringLength;
      }
    } else {
      if (static_cast<size_t>(
              std::to_string(static_cast<float>(data.at(valueName))).length()) >
          stringLength) {
        return static_cast<size_t>(
            std::to_string(static_cast<float>(data.at(valueName))).length());
      } else {
        return stringLength;
      }
    }
  }
}
std::any getValue(const json& data, const string& valueName,
                  size_t& stringLength) {
  //std::cout << "as" << data.at(valueName);
  //if (!data.at(valueName)) {
  //throw std::runtime_error{"There is no field with with name: " + valueName};
  //}
  if (data.at(valueName).is_number_integer()) {
    stringLength = Size(data, valueName, stringLength);
    return static_cast<int>(data.at(valueName));
  } else if (data.at(valueName).is_number_float()) {
    stringLength = Size(data, valueName, stringLength);
    return static_cast<double>(data.at(valueName));
  } else if (data.at(valueName).is_string()) {
    stringLength = Size(data, valueName, stringLength);
    return static_cast<string>(data.at(valueName));
  } else if (valueName == "debt") {
    if (data.at(valueName).is_array()) {
      stringLength = Size(data, valueName, stringLength);
      return static_cast<std::vector<std::string>>(data.at(valueName));
    } else if (data.at(valueName).is_null()) {
      return nullptr;
    } else {
      throw std::runtime_error("There is no correct-type field with name: " +
                               valueName);
    }
  } else {
    throw std::runtime_error("There is no correct-type field with name: " +
                             valueName);
  }
}
std::vector<Student> parser(const string& File, size_t len[4], json& data) {
  std::vector<Student> students;
  if (input(File, data)) {
    for (const auto& student : data.at("items")) {
      Student student_now;
      student_now.Name = student.at("name");
      if (static_cast<size_t>(student_now.Name.length()) > len[0])
        len[0] = static_cast<size_t>(student_now.Name.length());
      student_now.Group = getValue(student, "group", len[1]);
      student_now.Avg = getValue(student, "avg", len[2]);
      student_now.Debt = getValue(student, "debt", len[3]);
      students.push_back(student_now);
    }
  }
  std::cout << students.size();
  return students;
}
