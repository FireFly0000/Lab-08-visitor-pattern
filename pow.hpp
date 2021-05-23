#pragma once
#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <cmath> // for pow
#include "visitor.hpp"
class Pow : public Base {
private:
    Base* _lop;
    Base* _rop;
public:
    ~Pow(){
	delete _lop;
	delete _rop;
    } 
    Pow(Base* lop, Base* rop)
    {
        _lop = lop;
        _rop = rop;
    };
    virtual double evaluate() { return pow(_lop->evaluate(), _rop->evaluate()); };
    virtual std::string stringify() {
        std::string res = "(" + _lop->stringify() + "**" +  _rop->stringify() +  ")";
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

    void accept(Visitor* visitor, int index);
};

#endif //__POW_HPP__