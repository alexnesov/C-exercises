#include <iostream>

int main()
{
    int a;
    int b;
    int* p;
    int* q;
    int* r;

    a = 1;
    b = 2;
    p = &a; // p is a pointer, p gets the memory address of a
    q = &b; // q is a pointer, q gets the memory address of b
    
    std::cout << "p: " << p << std::endl; // p's value is the memory address of a
    std::cout << "*q " << *q << std::endl; // q's value is the memory address of b.

    r = p; 
    // r is initially a pointer, r becomes the same as p. Therefore, r holds the memory address of a. 
    // Therefore r points to the variable "a", or value 1

    std::cout << "*r " << *r << std::endl;

    *q = *r; 
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    // We assign the same value pointed to q as r, which is the variable "a", or the value 1.
    // Here is a big implication. The variable pointed by q, becomes 1. 
    // Therefore, b becomes 1!!!

    r = q; // r holds the value of q, being the memory address of the variable "a", or value 1.
    *p = *r;

    std::cout << a << " " << b << " " << *p << std::endl;    
    // a = 1
    // b = 1
    // *p = 1
}