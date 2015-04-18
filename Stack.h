/*
 ** $FILENAME: Stack.h$
 **
 ** $Description:Stack data structure$
 **
 ** $By Peilun Zhang, 2015-04-17$
 */
#ifndef Stack_H
#define Stack_H
#include <iostream>
using namespace std;

template<class T>
class Stack
{
public:
    Stack();
    ~Stack();
    T top();
    T pop();
    inline bool empty();
    int size();
    void clear();
    void printAll();
    void push(T value);

    
private:
    T* store;
    int index;
    int cap;
    void isFull();
};

//Default constructor
template <class T>
Stack<T>::Stack():index(0),cap(20){
    
    store =  new T[cap];
}

//Default destructor
template <class T>
Stack<T>::~Stack(){
    //TODO;
}

//return the top element of the stack
template <class T>
T Stack<T>::top()
{
    if(index == 0){
        cout<< "stack is empty";
        return 0;
    }
    return store[index-1];
}
template <class T>
void Stack<T>::clear()
{
    index = 0;
}
//pop the top element
template <class T>
T Stack<T>::pop()
{
    return store[--index];
}

//is the stack empty?
template <class T>
inline bool Stack<T>::empty()
{
    return ( index==0 );
}

//add element to the stack
template <class T>
void Stack<T>::push(T val)
{
    isFull();
    store[index++]=val;
}

//double the capacity if the stack is full;
template <class T>
void Stack<T>::isFull()
{
    if(index >= cap)
    {
        T * original = store;
        cap = 2 * index;
        store = new T[cap];
        
        for(int i = 0;i < index ;i++)
            store[i] = original[i];
        delete []original;
    }
}

//print all the elements in the stack. Use this to debug;
template <class T>
void Stack<T>::printAll(){
    int temp = index;
    for(int i = 0; i < temp; i++)
    {
        cout << store[i] << " ";
    }
    cout << endl;
}

// return the number of elements in the stack.
template <class T>
int Stack<T>::size()
{
    return index;
}

#endif