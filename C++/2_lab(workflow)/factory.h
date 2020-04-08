//
// Created by alexrush1 on 09.12.2019.
//

#ifndef WORKFLOW_FACTORY_H
#define WORKFLOW_FACTORY_H
#include <string>
#include <map>
#include <vector>

#define CREATE_BLOCK(C) static blockCreator<C> C(#C)

enum class function_type{
    R, RW, W
};

class block {
public:
    virtual ~block() = default;
    virtual void execute(std::vector<std::string> &args, std::vector<std::string> &text) = 0;
    virtual function_type getType() = 0;
};

class abstractBlockCreator {
public:
    virtual block * create() const = 0;
};

class blockFactory {
private:
    std::map<std::string, abstractBlockCreator *> _factory;
public:
    void add(const std::string &id, abstractBlockCreator* creator) {
        auto it = _factory.find(id);
        if (it == _factory.end())
            _factory[id] = creator;
    };
    block *create(const std::string &id);
    static blockFactory &Instance();
};

template<class C>
class blockCreator : public abstractBlockCreator {
public:
    blockCreator(const std::string &key){
        blockFactory::Instance().add(key, this);
    }
    block *create() const override {
        return new C;
    }
};


#endif //WORKFLOW_FACTORY_H
