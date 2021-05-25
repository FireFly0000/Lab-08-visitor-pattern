#pragma once

#ifndef __RAND_HPP__
#define __RAND_HPP__

#include <string>
#include "base.hpp"
#include "visitor.hpp"
#include "visitLaTex.hpp"


class Rand : public Base {
private: 
    double _value;
public:
    Rand() { this->_value = rand() % 100; }; // may have to fix
    virtual double evaluate() { return this->_value; };
    virtual std::string stringify() {
        std::string valuetostring = std::to_string(_value);
	for (int i =0; i<7; i++){
		if (valuetostring.at(valuetostring.size()-1) == '0' || valuetostring.at(valuetostring.size()-1) == '.'){
                        valuetostring.erase(valuetostring.end()-1);
                }
                if (valuetostring.at(valuetostring.size()-1) != '0' && valuetostring.at(valuetostring.size()-1) != '.'){
                        break;
                }
        }
        return valuetostring;
    };
    virtual int number_of_children() {
	return 0;
    }
    virtual Base* get_child(int i) {
                std:: cout << "ERROR, AN OPERAND HAS NO CHILDREN" << std::endl;
                return nullptr;
    }
    void accept(Visitor* visitor, int index, std::string& res){
 	if (index == 0)
		visitor->visit_rand(this, res);
    }

};

#endif //__RAND_HPP__
