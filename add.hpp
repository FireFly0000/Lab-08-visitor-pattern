#pragma once
#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"

class Add : public Base {
private:
    Base* _lop;
    Base* _rop;
public:
    ~Add(){
	delete _lop;
	delete _rop;
    }
    Add(Base* lop, Base* rop) {
        _lop = lop;
        _rop = rop;
    };
    virtual double evaluate() { return _lop->evaluate() + _rop->evaluate(); };
    virtual std::string stringify() {
        std::string res = "(" + _lop->stringify() + "+" +  _rop->stringify() +  ")";
	return res;  
    };
    virtual int number_of_children() {
	return 2;
    }
    virtual Base* get_child(int i) {
	if (i == 0){
		return _lop;
	}
	else if (i == 1){
		return _rop;
        }
	else{
		std:: cout << "ERROR, AN OPERATOR NODE CAN ONLY HAS 2 CHILDREN" << std::endl;
		return nullptr;
	}
   }
};

#endif //__ADD_HPP__



