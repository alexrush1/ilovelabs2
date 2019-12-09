//
// Created by alexrush1 on 09.12.2019.
//

#ifndef WORKFLOW_GREP_H
#define WORKFLOW_GREP_H


#include "factory.h"
#include <string>

class grep : public block {
public:
    function_type getType() override {
        return function_type::RW;
    }
    void execute(std::vector<std::string> &arguments, std::vector<std::string> &string_vector) override {
        std::vector<std::string> new_string_vector;
        for (int i = 0; i < string_vector.size(); i++) {
            if (string_vector[i].find(arguments[0]) != std::string::npos) {
                new_string_vector.push_back(string_vector[i]);
            }
        }
        string_vector.swap(new_string_vector);
        new_string_vector.clear();
    }
};

CREATE_BLOCK(grep);

#endif //WORKFLOW_GREP_H
