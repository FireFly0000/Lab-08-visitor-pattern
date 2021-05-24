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
#include "visitLaTex.hpp"
#include "iterator.hpp"

using namespace std;
/*std::string PrintLaTeX(Base* ptr){
    VisitLatex* v = new VisitLatex();
    for(Iterator it(ptr); !it.is_done();it.next()){
        it.current_node()->accept(v,it.current_index);
    }
}*/

int main(int argc, char* argv[]) {
    Factory test;
    //const char* args[] = { "-14.2", "**", "3", "-", "-32", "+", "16", "/", "2", "*", "3"}; 
    //const char* args[] = {"4", "-", "3"};
    
    
    const char* args[argc-1];
    for(int i = 0; i<argc-1; i++){
	args[i] = argv[i+1];
    }                                                 
    
    //for(int i = 0; i< argc-1; i++){
	//cout << args[i];
    //}
    //cout << endl;
    Base* op = test.parse(args, argc - 1);
    //cout << " = " << op->evaluate() << endl;
    
    //cout << op->number_of_children() << endl;
    //cout << op->get_child(0)->evaluate() << endl;
    
    VisitLatex* v = new VisitLatex();
    for(Iterator it(op); !it.is_done();it.next()){
	it.current_node()->accept(v,it.current_index());	
    }
    cout << endl;
    return 0;
}
