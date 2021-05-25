#pragma once
#ifndef __DIV_HPP__
#define __DIV_HPP__
#include "visitor.hpp"
#include "base.hpp"

class Div : public Base {
private:
    Base* _lop;
    Base* _rop;
    Div* _node;
public:
    ~Div(){
      delete _lop;
      delete _rop;
    }
    Div(Base* lop, Base* rop)
    {
        _lop = lop;
        _rop = rop;
    };
    virtual double evaluate() { return _lop->evaluate() / _rop->evaluate(); };
    virtual std::string stringify() {
        std::string res = "(" + _lop->stringify() + "/" +  _rop->stringify() +  ")";
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

    void accept(Visitor* visitor, int index) {
        if (index == 0) {
            visitor->visit_div_begin(this->_node);
        }
        else if (index == 1) {
            visitor->visit_div_middle(this->_node);
        }
        else {
            visitor->visit_div_end(this->_node);
        }
    }
    void SetNode(Div* node) {
        this->_node = node;
    }
};

#endif //__DIV_HPP__


