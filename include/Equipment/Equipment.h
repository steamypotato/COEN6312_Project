//
// Created by Hoopa on 3/1/2025.
//

#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#ifndef __cpp_lib_format
  // std::format polyfill using fmtlib
  #include <fmt/core.h>
  namespace std {
      using fmt::format;
  }
#else
#include <format>
#endif

class Equipment {
public:
    [[nodiscard]] std::string getInformation() const;
    Equipment();
    ~Equipment();

protected:
    std::string m_name;
    std::string m_id;
    std::string m_description;
};

#endif //EQUIPMENT_H
