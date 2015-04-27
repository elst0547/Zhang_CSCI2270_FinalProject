# Zhang_CSCI2270_FinalProject
####**Project	Summary**
A calculator that does calculation by converting infix expressions to reverse polish expressions
####**How	to	Run**
There's a test file named main.cpp. Download all the files to the same directory and compile all the files.
The executable would ask you to input an expression and would print out the result of that expression automatically.


    g++ -std=c++11 main.cpp Zcal.cpp RPolish.cpp  // this is an example for g++
    
####**Some examples**####


    std::string expression = "(1+3)*5/2"; // you can put some more complicated expressions here
    
    
    //Method 1:
    plzstd::RPolish rp1;
    rp1.setExp(expression);
    rp1.change();
    plzstd::Zcal cal1;
    cal1.doCalc(rp1);
    
__What happened?__


First of all, we create a new object whose type is RPolish(defined in RPolish.h). And we set the expression it stores using the method change() which changes the expression "(1+3)*5/2" to "/ 2 * 5 + 3 1" (see details:__ [here](http://en.wikipedia.org/wiki/Reverse_Polish_notation) ). Then we create a new object whose type is Zcal and we call the method doCalc(RPolish) which taking a RPolish object to do calculation.

__Looks complicated?__


    //Method 2:
    plzstd::Zcal cal1(expression);

__What happened?__


        void Zcal::doCalc(string expression){
            RPo.setExp(expression);
            RPo.change();
            doCalc(RPo);
        };

__See wiki of this project here for public methods:__ [Wiki](https://github.com/Pezhin/Zhang_CSCI2270_FinalProject/wiki)    
####**Dependencies**
We are not using any third-party library. All you need is a c++ compiler that supports the standard libraries and standard template libraries(which the compiler is supposed to). Additionally, I use '**auto**' type specifier which is a C++11 extension to to use the range-based loop. You can modify them to normal for-loop so that you would not need to use c++11;



    
    

####**System	Requirements**
Works on windows, mac and linux
####**Group	Members**
Peilun Zhang
####**Contributors**
####**Open	issues/bugs**

