# Zhang_CSCI2270_FinalProject

For any questions, mail me at p@oath.pl



####**Project	Summary**
A calculator that does calculation by converting infix expressions to reverse polish expressions
The description of the algorithms we use in this project:


[Reverse Polish Notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation)


[Shunting-yard algorithm](http://en.wikipedia.org/wiki/Shunting-yard_algorithm)
####**How	to	Run**
Follwing is the specific instructions using terminal(command line tools)


1. Download __all__ the files to a directory 
2. Open your terminal(powershell or commandline)
3. Change the current directory to the project folder
4. Enter this command into the terminal(You need a GNU make to do this but it is usually installed already.
 

        make
5. Run the executable
 

        ./a.out
    
The executable would ask you to input an expression and would print out the result of that expression automatically.



    
####**Some examples**####


    std::string expression = "(1+3)*5/2"; // you can put some more complicated expressions here
    
    
    //Method 1:
    plzstd::RPolish rp1;
    rp1.setExp(expression);
    rp1.change();
    plzstd::Zcal cal1;
    cal1.doCalc(rp1);
    
__What happened?__


First of all, we create a new object whose type is RPolish(defined in RPolish.h). And we set the expression it stores using the method change() which changes the expression __"(1+3)*5/2"__ to __"/2*5+31"__ (see details: [here](http://en.wikipedia.org/wiki/Reverse_Polish_notation) ). Then we create a new object whose type is Zcal and we call the method doCalc(RPolish) which takes a RPolish object to do calculation.

__Looks complicated? Is there a simple way to do it?__


    //Method 2:
    plzstd::Zcal cal1(expression);

__What happened?__




    Zcal::Zcal(string expression)
    {
        //RPo is the private member initialized with the class Zcal
        RPo.setExp(expression);
        RPo.change();
        doCalc();
    }
    

__See wiki of this project here for public methods:__ [Wiki](https://github.com/Pezhin/Zhang_CSCI2270_FinalProject/wiki)    
####**Dependencies**
We are not using any third-party library. All you need is a c++ compiler that supports the standard libraries and standard template libraries(which the compiler is supposed to). Additionally, I use '**auto**' type specifier which is a C++11 extension to to use the range-based loop. You can modify them to normal for-loop so that you would not need to use c++11;



    
    

####**System	Requirements**
Works on windows, mac and linux
####**Group	Members**
Peilun Zhang
####**Contributors**
####**Open	issues/bugs**

