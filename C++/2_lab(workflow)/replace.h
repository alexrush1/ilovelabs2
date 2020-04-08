//
// Created by alexrush1 on 09.12.2019.
//

#ifndef WORKFLOW_REPLACE_H
#define WORKFLOW_REPLACE_H


#include "factory.h"
#include <iostream>

class replace : public block {
public:
    function_type getType() override {
        return function_type::RW;
    }
    void execute(std::vector<std::string> &arguments, std::vector<std::string> &string_vector) override {
        int found = 0;
        for (int i = 0; i < string_vector.size(); i++) {
            found = string_vector[i].find(arguments[0]);
            while (found != std::string::npos) {
                string_vector[i].replace(found, arguments[0].length(), arguments[1]);
                found = string_vector[i].find(arguments[0]);
            }
        }
    }
};

CREATE_BLOCK(replace);

#endif //WORKFLOW_REPLACE_H
