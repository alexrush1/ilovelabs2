//
// Created by alexrush1 on 09.12.2019.
//

#ifndef WORKFLOW_READFILE_H
#define WORKFLOW_READFILE_H


#include "factory.h"
#include <fstream>
#include <string>

class readfile : public block {
public:
    function_type getType() override {
        return function_type::R;
    }
    void execute(std::vector<std::string> &arguments, std::vector<std::string> &string_vector) override {
        std::ifstream inFile(arguments[0]);
        std::string buffer;
        while (std::getline(inFile, buffer)){
            string_vector.push_back(buffer);
        }
    }
};

CREATE_BLOCK(readfile);

#endif //WORKFLOW_READFILE_H
