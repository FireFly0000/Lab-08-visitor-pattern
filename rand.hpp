#pragma once
#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
private:
    double _value;
    bool read = false;
public:
    Rand() { this->_value = rand() % 100; }; // may have to fix
    void setRead(bool val) { read = val; };
    bool getRead() {
        return this->read;
    };
    virtual double evaluate() { return this->_value; };
    virtual std::string stringify() {
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
};

#endif //__RAND_HPP__

