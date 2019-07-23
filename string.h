#ifndef CUSTOM_STRING_H
#define CUSTOM_STRING_H

#include <iostream>

/* Custom C++ string class */
class StringCust
{
private:
    char*    data;                                  /* ASCII characters                     */
    unsigned int length;                            /* Length of data                       */

public:
    StringCust ( );                                 /* Empty String Constructor             */
    StringCust (char c);                            /* Single-character String Constructor  */
    StringCust (const char* c);                     /* Char* String Constructor             */
    StringCust (const StringCust& s);               /* Copy String Constructor              */
    StringCust (StringCust&& s);              /* Move String Constructor              */

    ~StringCust ( );                                /*  Default String Destructor           */

    unsigned len ( ) const;                         /* String length                        */

    int index (char c) const;                       /* String index of @a c                 */

    void upcase (unsigned first, unsigned last);    /* Lowercase  characters to uppercase   */
    void downcase (unsigned first, unsigned last);  /* uppercase  characters to lowercase   */

    void print();

    char  operator[] (unsigned j) const;            /* Access String character              */
    char& operator[] (unsigned j);

};

#endif // CUSTOM_STRING_H
