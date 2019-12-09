//
// Created by alexrush1 on 09.12.2019.
//

#ifndef WORKFLOW_WRITEFILE_H
#define WORKFLOW_WRITEFILE_H


#include "factory.h"
#include <fstream>
#include <string>

class writefile : public block {
public:
    function_type getType() override {
        return function_type::W;
    }
    void execute(std::vector<std::string> &arguments, std::vector<std::string> &string_vector) override {
        std::ofstream outFile(arguments[0]);
        for (auto &i : string_vector) {
            outFile << i << std::endl;
        }
    }
};

CREATE_BLOCK(writefile);

#endif //WORKFLOW_WRITEFILE_H
