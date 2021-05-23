#pragma once
#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "visitor.hpp"
class Add : public Base {
protected:
    Base* _lop;
    Base* _rop;
    Add* _node;

public:
    ~Add() {
        delete _lop;
        delete _rop;
    };
    Add(Base* lop, Base* rop) {
        _lop = lop;
        _node = nullptr;
        _rop = rop;
    };
    virtual double evaluate() { return _lop->evaluate() + _rop->evaluate(); };
    virtual std::string stringify() {
        std::string res = "(" + _lop->stringify() + "+" + _rop->stringify() + ")";
        return res;
    };
    virtual int number_of_children() {
        return 2;
    }
    virtual Base* get_child(int i) {
        if (i == 0) {
            return _lop;
        }
        else if (i == 1) {
            return _rop;
        }
        else {
            std::cout << "ERROR, AN OPERATOR NODE CAN ONLY HAS 2 CHILDREN" << std::endl;
            return nullptr;
        }
    }
    void accept(Visitor* visitor, int index) {

        if (index == 0) {
            visitor->visit_add_begin(this->_node);
        }
        else if (index == 1) {
            visitor->visit_add_middle(this->_node);
        }
        else {
            visitor->visit_add_end(this->_node);
        }
    }
    void SetNode(Add* node) {
        this->_node = node;
    }
};

#endif //__ADD_HPP__



