//
// Created by alexrush1 on 09.12.2019.
//

#ifndef WORKFLOW_DUMP_H
#define WORKFLOW_DUMP_H


#include <fstream>
#include "factory.h"

class dump : public block {
public:
    function_type getType() override {
        return function_type::RW;
    }
    void execute(std::vector<std::string> &arguments, std::vector<std::string> &string_vector) override {
        std::ofstream outFile(arguments[0]);
        for (auto &i : string_vector) {
            outFile << i << std::endl;
        }
    }
};

CREATE_BLOCK(dump);

#endif //WORKFLOW_DUMP_H
