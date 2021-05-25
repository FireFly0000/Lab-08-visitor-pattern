//#pragma once
#include <iostream>

//#include "base.hpp"
#include "base.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "op.hpp"
#include "add.hpp"
#include "factory.hpp"
#include "iterator.cpp"
#include "visitor.hpp"
#include "visitMathMl.hpp"
#include "visitLaTex.hpp"
#include "iterator.hpp"

using namespace std;
std::string PrintLaTeX(Base* ptr){
        VisitLatex* v = new VisitLatex();
        std::string res;
        for(Iterator it(ptr); !it.is_done();it.next()){
                it.current_node()->accept(v,it.current_index(), res);
        }
	res = "$" + res + "$";
        return res;
}
std::string PrintMathML(Base* ptr){
	VisitMathml* v = new VisitMathml();
        std::string res;
        for(Iterator it(ptr); !it.is_done();it.next()){
                it.current_node()->accept(v,it.current_index(), res);
        }
        res = "<math>\n" + res + "</math>";
	return res;
}

int main(int argc, char* argv[]) {
    //Factory test;
    //const char* args[] = { "-14.2", "**", "3", "-", "-32", "+", "16", "/", "2", "*", "3"}; 
    /*const char* args[argc-1];
    for(int i = 0; i<argc-1; i++){
	args[i] = argv[i+1];
    }*/                                                 
    //for(int i = 0; i< argc-1; i++){
	//cout << args[i];
    //}
    //cout << endl;
    //Base* op = test.parse(args, argc - 1);
    //cout << " = " << op->evaluate() << endl;
    
    Base* five = new Op(5);
    Base* zero = new Op(0);
    Base* one = new Op(1);
    Base* add = new Add(five, zero);
    Base* add_1 = new Add(one, add); 
    cout << add_1->stringify() << " = ";
    cout << PrintLaTeX(add_1) << endl;

    Base* seven = new Op(7);
    Base* two = new Op(2);
    Base* three = new Op(3);   
    Base* sub_1 = new Sub(seven, two);
    Base* sub_2 = new Add(three, one);
    Base* sub_3 = new Sub(sub_1, sub_2);
    cout << sub_3->stringify() << " = ";
    cout << PrintLaTeX(sub_3) << endl;

    Base* six = new Op(6);
    Base* sixAthree = new Add(six, three);
    Base* mult = new Mult(sixAthree, two);
    cout << mult->stringify() << " = ";
    cout << PrintLaTeX(mult) << endl;
    
    Base* div = new Div(six, seven);
    cout << div->stringify() << " = ";
    cout << PrintLaTeX(div) << endl;
    
    Base* pow = new Pow(add, seven);
    cout << pow->stringify() << " = ";
    cout << PrintLaTeX(pow) << endl;
    
    cout << endl << endl;	
    cout << add_1->stringify() << " = " << endl; 
    cout << PrintMathML(add_1) << endl;
 
    return 0;
}
