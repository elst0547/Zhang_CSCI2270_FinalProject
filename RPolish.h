/*
 ** $Filename: RPolish.h$
 **
 ** Description:Class that convert infix expression to reverse polish notation
 **
 ** By Peilun Zhang, 2015-04-17
 */




//
#ifndef calculator_RPolish_h
#define calculator_RPolish_h
#include <string>
#include "Stack.h"
using namespace std;


namespace plzstd {
    class RPolish{
    public:
        RPolish();
        RPolish(string);
        ~RPolish();
        void change();
        void setExp(string);
        void clearStack();
        Stack<char> oprt;
        Stack<string> num;
        bool isOperator(char);
        bool isLeftAssoc(char);
        int optPri(char);
        
    private:
        string expression;
        void change(std::string);
    };

    }
#endif
