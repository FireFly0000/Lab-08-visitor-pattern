#pragma once
#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "visitor.hpp"

class Sub : public Base {
private:
    Base*  _lop;
    Base*  _rop;
    Sub* _node;

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
            visitor->visit_sub_begin(this->_node);
        }
        else if (index == 1) {
            visitor->visit_sub_middle(this->_node);
        }
        else {
            visitor->visit_sub_end(this->_node);
        }
    }
    void SetNode(Sub* node) {
        this->_node = node;
    }
};

#endif //__SUB_HPP__

