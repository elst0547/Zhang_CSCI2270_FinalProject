/*
 ** $FILENAME: main.cpp$
 **
 ** $Description: test file$
 **
 ** $By Peilun Zhang, 2015-04-17$
 */

#include <iostream>
#include <cstdio>
#include "Zcal.h"
using namespace std;

int main()
{
    
    for(;;)
    {
        puts("Please input you expression here");
        string Expression;
        getline(cin, Expression);
        plzstd::Zcal cal(Expression);
        
    }
    return 0;
}
