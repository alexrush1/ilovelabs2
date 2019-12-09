#pragma once

#include <map>
#include <string>
#include <vector>

class parser {
    std::map<int, std::pair<std::string, std::vector<std::string>>> parsedText;
    std::vector<int> ex_order;
public:
    void parse(const char *fileName);

    std::map<int, std::pair<std::string, std::vector<std::string>>> &getParsedText() {
        return parsedText;
    }

    std::vector<int> &getExOrder() {
        return ex_order;
    }

};
