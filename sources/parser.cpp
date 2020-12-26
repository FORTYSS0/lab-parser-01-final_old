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
      throw std::runtime_error(
          "There is no file with this name");
    else if(data.empty())
      throw std::runtime_error(
          "json"+File+" the file is empty");
    return false;
  }
  return true;
}
size_t Size(const json& value, const string& valueName, size_t& stringLength){
  if (static_cast<size_t>(
          std::to_string(static_cast<float>(value.at(valueName)))
              .length()) > stringLength)
    return static_cast<int>(
        std::to_string(static_cast<float>(value.at(valueName))).length());
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
  //if(File!="" && File!=" ") {
    if (input(File)) {}

      std::vector<Student> students;
      for (const auto& student : data.at("items")) {
        Student student_now;
        student_now.Name = student.at("name");
        if (static_cast<size_t>(student_now.Name.length()) > len[0])
          len[0] = static_cast<size_t>(student_now.Name.length());
        student_now.Group=getValue(student, "group", len[1]);
        student_now.Avg=getValue(student, "avg", len[2]);
        student_now.Debt=getValue(student, "debt", len[3]);

        /*

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
               "items is not an array\nThe variable Debt has the wrong data
       type"); students.push_back(student_now);
       */
      }
      return students;
   // }
  //}else{
  //  throw std::runtime_error(
 //       "The argument does not contain the file path");
 // }
}

