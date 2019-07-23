#include "string.h"



StringCust::StringCust ()
{
    length = 0;
    data   = "";
}

StringCust::StringCust (char c)
{
    length = 1;
    data   = new char(c);
}

StringCust::StringCust (const char* c)
{
    if (c)
    {
        unsigned n = 0;
        while (c[n] != '\0') n++;
        length = n;
        data   = new char[n];
        for (unsigned j=0; j < n; j++)
            data[j] = c[j];
    } else
    {
        length = 0;
        data   = new char[0];
    }
}

StringCust::StringCust (const StringCust& s)
{
    length = s.len();
    data   = new char[length];
    for (unsigned j=0; j < length; j++)
        data[j] = s[j];
}

StringCust::StringCust (StringCust&& other) : data(other.data), length(other.length)
{
    std::cout << "Move constructor" << std::endl;
    other.data = nullptr;
    other.length = 0;
}

StringCust::~StringCust ( )
{
    delete[] data;
}

unsigned StringCust::len ( ) const
{
    return length;
}

int StringCust::index (char c) const
{
    for (unsigned j=0; j < length; j++)
        if (data[j] == c) return (int)j;
    return -1;
}

char StringCust::operator[] (unsigned j) const
{
    if (j >= length) throw 1;
    return data[j];
}

char& StringCust::operator[] (unsigned j)
{
    if (j >= length) throw 1;
    return data[j];
}

void StringCust::upcase (unsigned first, unsigned last)
{
    if ((first >= last) || (last > length)) throw 1;

    for (unsigned j=first; j < last; j++)
        if ('a' <= data[j] && data[j] <= 'z')
            data[j] -= ('a' - 'A');
}

void StringCust::downcase (unsigned first, unsigned last)
{
    if ((first >= last) || (last > length)) throw 1;

    for (unsigned j=first; j < last; j++)
        if ('A' <= data[j] && data[j] <= 'Z')
            data[j] += ('a' - 'A');
}

void StringCust::print()
{
    std::cout << data << std::endl;
}
