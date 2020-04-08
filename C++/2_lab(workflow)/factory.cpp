//
// Created by alexrush1 on 09.12.2019.
//

#include "factory.h"

blockFactory &blockFactory::Instance() {
    static blockFactory factory;
    return factory;
}

block *blockFactory::create(const std::string &order_num) {
    auto it = _factory.find(order_num);
    if (it != _factory.end()) {
        return it->second->create();
    } else {
        throw std::logic_error("Unknown function");
    }
}