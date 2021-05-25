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
#include <sstream>

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
    std::stringstream os;
    Base* two = new Op(2);
    Base* five = new Op(5);
    Base* add = new Add(two, five);

    os << PrintLaTeX(add);

    EXPECT_EQ(os.str(), "${({2}+{5})}$")
}

TEST(LatexTest, AddingandSubtracting) {
    std::stringstream os;
    Base* two = new Op(2);
    Base* five = new Op(5);
    Base* seven = new Op(7);
    Base* add = new Add(two, five);
    Base* min = new Sub(add, seven);

    os << PrintLaTeX(min);

    EXPECT_EQ(os.str(), "${({({2}+{5})}-{7})}$")
}

TEST(LatexTest, MultandDiv) {
    std::stringstream os;
    Base* two = new Op(2);
    Base* five = new Op(5);
    Base* mult = new Mult(two, five);
    Base* div = new Div(mult, two);

    os << PrintLaTeX(div);

    EXPECT_EQ(os.str(), "${\\frac{({2}\\cdot{5})}{2}}$");
}

TEST(LatexTest, AddMultPow) {
    std::stringstream os;
    Base* two = new Op(2);
    Base* five = new Op(5);
    Base* three = new Op(3);
    Base* add = new Add(five, three);
    Base* mult = new Mult(add, two);
    Base* pow = new Pow(mult, three);

    os << PrintLaTeX(pow);

    EXPECT_EQ(os.str(), "$({{({({5}+{3})}\\cdot{2})}^{3})}$");
}
TEST(LatexTest, NegativeMultDiv) {
    std::stringstream os;
    Base* two = new Op(-2);
    Base* five = new Op(5);
    Base* three = new Op(-3);
    Base* mult = new Mult(five, two);
    Base* div = new Div(mult, three);

    os << PrintLaTeX(div);

    EXPECT_EQ(os.str(), "${\\frac{({5}\\cdot{-2})}{-3}}$");
}




#endif

