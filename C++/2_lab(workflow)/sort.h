//
// Created by alexrush1 on 09.12.2019.
//

#ifndef WORKFLOW_SORT_H
#define WORKFLOW_SORT_H

#include "factory.h"
#include <algorithm>
#include <string>

class sort : public block {
public:
    function_type getType() override {
        return function_type::RW;
    }
    void execute(std::vector<std::string> &arguments, std::vector<std::string> &string_vector) override {
        std::sort(string_vector.begin(), string_vector.end());
    }
};

CREATE_BLOCK(sort);

#endif //WORKFLOW_SORT_H
