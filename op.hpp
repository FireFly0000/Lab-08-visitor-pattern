#pragma once
#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "visitor.hpp"
class Op : public Base {
private:
    double _value;
    Op* _node = nullptr;
    bool read = false;
public:
    Op(double value) : _value(value), _node(nullptr) { }; // not sure, may have to fix
    void setRead(bool val) { read = val; };
    bool getRead() { return this->read; }
    double evaluate() { return this->_value; };
    std::string stringify() {
        std::string valuetostring = std::to_string(_value);
        for (int i = 0; i < 7; i++) {
            if (valuetostring.at(valuetostring.size() - 1) == '0' || valuetostring.at(valuetostring.size() - 1) == '.') {
                valuetostring.erase(valuetostring.end() - 1);
            }
            if (valuetostring.at(valuetostring.size() - 1) != '0' && valuetostring.at(valuetostring.size() - 1) != '.') {
                break;
            }
        }
        return valuetostring;
    };
    int number_of_children() {
        return 0;
    }
    Base* get_child(int i) {
        std::cout << "ERROR, AN OPERAND HAS NO CHILDREN" << std::endl;
        return nullptr;
    }
    void accept(Visitor* visitor, int index) {

        visitor->visit_op(this->_node);
    }

    void SetNode(Op* node) {
        this->_node = node;
    }
};


#endif //__OP_HPP__


