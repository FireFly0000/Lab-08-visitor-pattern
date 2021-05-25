#pragma once
#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "visitor.hpp"
#include "visitLaTex.hpp"

class Sub : public Base {
private:
    Base*  _lop;
    Base*  _rop;
public:
    ~Sub(){
	delete _lop;
	delete _rop;
    }
    Sub(Base* lop, Base* rop) {
        _lop = lop;
        _rop = rop;
    };
    virtual double evaluate() { return _lop->evaluate() - _rop->evaluate(); };
    virtual std::string stringify() {
        std::string res = "(" + _lop->stringify() + "-" +  _rop->stringify() + ")";
	return res;
    };
    virtual int number_of_children() {
        if(_lop != nullptr && _rop != nullptr){
                return 2;
        }
        else if ( (_lop == nullptr && _rop !=nullptr) || (_rop == nullptr && _lop !=nullptr) ){
                return 1;
        }
        else return 0;

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
virtual void accept(Visitor* visitor, int index, std::string& res){ }	
};

#endif //__SUB_HPP__

