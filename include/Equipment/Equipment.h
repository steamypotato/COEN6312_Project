//
// Created by Hoopa on 3/1/2025.
//

#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <format>

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
