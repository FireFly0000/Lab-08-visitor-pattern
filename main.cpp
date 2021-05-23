#pragma once
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

using namespace std;

int main(int argc, char* argv[]) {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab

    Factory test;
    //const char* args[] = { "-14.2", "**", "3", "-", "-32", "+", "16", "/", "2", "*", "3"}; 
    //const char* args[] = {"4", "-", "3"};
    const char* args[argc-1];
    for(int i = 0; i<argc-1; i++){
	args[i] = argv[i+1];
    }                                                 
    
    for(int i = 0; i< argc-1; i++){
	cout << args[i];
    }
    cout << endl;
    Base* op = test.parse(args, argc - 1);
    
    if (op == nullptr) {
        cout << "Invalid Input Entered" << endl;
    }
    else {	
    cout << " = " << op->evaluate() << endl;
    }
    cout << op->number_of_children() << endl;
    cout << op->get_child(0)->evaluate() << endl;

 
   /*Factory test;
    const char* args[100];
    for (int i = 0; i < argc - 1; ++i) {
        args[i] = argv[i + 1];
    }

    Base* op = test.parse(args, argc-1);

    for (int i = 0; i < argc-1; ++i) {
        cout << args[i];
    }
    cout << " = " << op->evaluate() << endl;*/


    return 0;
}
