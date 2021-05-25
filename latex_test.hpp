#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "visitor.hpp"
#include "visitLaTex.hpp"
#include "iterator.hpp"
#include <ostream>


std::string PrintLaTeX(Base* ptr) {
    VisitLatex* v = new VisitLatex();
    std::string res;
    for (Iterator it(ptr); !it.is_done(); it.next()) {
        it.current_node()->accept(v, it.current_index(), res);
    }
    res = "$" + res + "$";
    return res;
}

TEST(LatexTest, AddingValues) {
    outputstream os;
    Base* two = new Op(2);
    Base* five = new Op(5);
    Base* add = new Add(two, five);

    os << PrintLaTeX(add);

    EXPECT_EQ(os, "${({2}+{5})}$")
}

TEST(LatexTest, AddingandSubtracting) {
    outputstream os;
    Base* two = new Op(2);
    Base* five = new Op(5);
    Base* seven = new Op(7);
    Base* add = new Add(two, five);
    Base* min = new Sub(add, seven);

    os << PrintLaTeX(min);

    EXPECT_EQ(os, "${({({2}+{5})}-{7})}$")
}

TEST(LatexTest, MultandDiv) {
    outputstream os;
    Base* two = new Op(2);
    Base* five = new Op(5);
    Base* mult = new Mult(two, five);
    Base* div = new Div(mult, two);

    os << PrintLaTeX(div);

    EXPECT_EQ(os, "${\\frac{({2}\\cdot{5})}{2}}$");
}

TEST(LatexTest, AddMultPow) {
    outputstream os;
    Base* two = new Op(2);
    Base* five = new Op(5);
    Base* three = new Op(3);
    Base* add = new Add(five, three);
    Base* mult = new Mult(add, two);
    Base* pow = new Pow(mult, three);

    os << PrintLaTeX(pow);

    EXPECT_EQ(os, "$({{({({5}+{3})}\\cdot{2})}^{3})}$");
}
TEST(LatexTest, NegativeMultDiv) {
    outputstream os;
    Base* two = new Op(-2);
    Base* five = new Op(5);
    Base* three = new Op(-3);
    Base* mult = new Mult(five, two);
    Base* div = new Div(mult, three);

    os << PrintLaTeX(div);

    EXPECT_EQ(os, "${\\frac{({5}\\cdot{-2})}{-3}}$");
}




#endif

