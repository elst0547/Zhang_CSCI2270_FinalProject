/*
 ** $FILENAME: Zcal.h$
 **
 ** $Description:The calculator class$
 **
 ** $By Peilun Zhang, 2015-04-17$
 */
#ifndef Zcal_Zcal_h
#define Zcal_Zcal_h
#include <math.h>
#include "RPolish.h"
using namespace plzstd;
namespace plzstd{
    class Zcal{
    private:
        RPolish RPo;
        string exp;
        double value;
        Stack<string> expressionStack;
        Stack<string> calcStack;
        inline double sum(double, double);
        inline double sub(double, double);
        inline double multi(double, double);
        inline double divide(double,double);
        inline double power(int, double);
        inline double fact(int);
        inline double mod(double, double)
    public:
        Zcal();
        Zcal(string expression);
        ~Zcal();
        void doCalc();
        void doCalc(RPolish rpn);
        void doCalc(string expression);
    };
}
#endif
