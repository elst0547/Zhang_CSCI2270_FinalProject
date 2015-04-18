/*
 ** $FILENAME: Zcal.cpp$
 **
 ** $Description:Implementation of Zcal.h$
 **
 ** $By Peilun Zhang, 2015-04-17$
 */
#include "Zcal.h"

//default constructor
Zcal::Zcal(){
    
}

//constructor using expression
Zcal::Zcal(string expression)
{
    RPo.setExp(expression);
    RPo.change();
    doCalc();
    
}

//default destructor;
Zcal::~Zcal(){
    //DOTO
}

/*
 Functions to do summation, subtraction, multiplication, division, solving for power and factorials;
 */
inline double Zcal::sum(double a, double b){
    return a+b;
}
inline double Zcal::sub(double a, double b){
    return b-a;
}
inline double Zcal::multi(double a, double b){
    return a*b;
}
inline double Zcal::divide(double a, double b){
    return b/a;
}
inline double Zcal::power(int a, double b){
    return pow(b,a);
}
inline double Zcal::fact(int a){
    return (a == 1? 1 : a * fact(a-1));
}

void Zcal::doCalc(){
    doCalc(RPo);
}
void Zcal::doCalc(string expression){
    RPo.setExp(expression);
    RPo.change();
    doCalc(RPo);
};

void Zcal::doCalc(RPolish rpn){
    Stack<string> tempStack = rpn.num;
    while(!tempStack.empty())
    {
        expressionStack.push(tempStack.pop());
    }
    
    while(!expressionStack.empty())
    {
        
        string numbers = "0123456789.";
        string track = expressionStack.pop();
        int isNumber = 0;
        for(auto i : numbers)
        {
            if(i == track[0])
            {
                isNumber = 1;
                break;
            }
        }
        if(isNumber)
        {
            calcStack.push(track);
            continue;
        }else{
            if(track == "=")
            {
                if( calcStack.size() != 1)
                {
                    cout << " ELEMENTS AFTER '=', CHECK THE EXPRESSION" << endl;
                    exit(-1);
                }else{
                    value = stod(calcStack.pop());
                    continue;
                }
            }
            if(track == "+")
            {
                if( calcStack.size() < 2)
                {
                    cout << "NOT ENOUGH ELEMENTS TO DO CALCULATION, CHEK YOUR EXPRESSION" << endl;
                    exit(-1);
                }else{
                    double result = sum(stod(calcStack.pop()),stod(calcStack.pop()));
                    calcStack.push(to_string(result));
                    continue;
                }
                
            }
            if(track == "-")
            {
                if( calcStack.size() < 2)
                {
                    cout << " NOT ENOUGH ELEMENTS TO DO CALCULATION, CHEK YOUR EXPRESSION" << endl;
                    exit(-1);
                }else{
                    double result = sub(stod(calcStack.pop()),stod(calcStack.pop()));
                    calcStack.push(to_string(result));
                    continue;
                }
                
            }
            if(track == "*")
            {
                if( calcStack.size() < 2)
                {
                    cout << "NOT ENOUGH ELEMENTS TO DO CALCULATION, CHEK YOUR EXPRESSION" << endl;
                    exit(-1);
                }else{
                    double result = multi(stod(calcStack.pop()),stod(calcStack.pop()));
                    calcStack.push(to_string(result));
                    continue;
                }
                
            }
            if(track == "/")
            {
                if( calcStack.size() < 2)
                {
                    cout << "NOT ENOUGH ELEMENTS TO DO CALCULATION, CHEK YOUR EXPRESSION" << endl;
                    exit(-1);
                }else{
                    double result = divide(stod(calcStack.pop()),stod(calcStack.pop()));
                    calcStack.push(to_string(result));
                    continue;
                }
                
            }
            if(track == "^")
            {
                if( calcStack.size() < 2)
                {
                    cout << "NOT ENOUGH ELEMENTS TO DO CALCULATION, CHEK YOUR EXPRESSION" << endl;
                    exit(-1);
                }else{
                    double result = power(stoi(calcStack.pop()),stod(calcStack.pop()));
                    calcStack.push(to_string(result));
                    continue;
                }
                
            }
            if(track == "!")
            {
                if( calcStack.size() < 1)
                {
                    cout << "NOT ENOUGH ELEMENTS TO DO CALCULATION, CHEK YOUR EXPRESSION" << endl;
                    exit(-1);
                }else{
                    string number = calcStack.pop();
                    for(auto i : number)
                    {
                        if(i == '.'){
                            cout << "Cannot solve factorials of fractions" << endl;
                            exit(-1);
                        }
                    }
                    int result = fact(stoi(number));
                    calcStack.push(to_string(result));
                    continue;
                }
                
            }
        }
    }
    if(!calcStack.empty()){
        value = stod(calcStack.pop());
        
    }
    cout << "The result is " << value << endl;
}
