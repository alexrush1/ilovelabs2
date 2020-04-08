#include "readfile.h"
#include "writefile.h"
#include "replace.h"
#include "sort.h"
#include "dump.h"
#include "grep.h"
#include "worker.h"
#include "parser.h"
#include "factory.h"
#include <iostream>

void worker::all_process(const char * inFile) {
    parser p;
    p.parse(inFile);
    auto parsedText = p.getParsedText();
    auto ex_order = p.getExOrder();
    int command_counter = 0;
    for (auto &i : ex_order) {
        block *block_ = blockFactory::Instance().create(parsedText[i].first);
        if (command_counter == 0) {
            if (block_->getType() != function_type::R)
                throw std::runtime_error("Wrong execution order!");
        } else if (command_counter == ex_order.size()-1) {
            if (block_->getType() != function_type::W)
                throw std::runtime_error("Wrong execution order!");
        } else if (block_->getType() != function_type::RW)
            throw std::runtime_error("Wrong execution order!");
        block_->execute(parsedText[i].second, text);
        command_counter++;
        delete block_;
    }
}