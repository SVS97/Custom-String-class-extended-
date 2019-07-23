#include <iostream>
#include "string.h"



int main()
{
    try
    {
        char * str = "Hello";
        StringCust s1 (str);
        s1.print();
        s1.upcase(1,4);
        s1.print();
        s1.downcase(2,4);
        s1.print();
        char find = 'E';
        int ind =  s1.index(find);
        std::cout << find << " has index " << (ind+1) << std::endl;
        std::cout << "Length of the string is " <<s1.len() << std::endl;

        StringCust newString {std::move(s1)};
    }
    catch (int e)
    {
        std::cout << "Error " << e << ": Index out of bounds" << std::endl;
    }
    return 0;
}
