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
    StringCust (StringCust&& s);                    /* Move String Constructor              */

    ~StringCust ( );                                /*  Default String Destructor           */

    unsigned len ( ) const;                         /* String length                        */

    int index (char c) const;                       /* String index of @a c                 */

    void upcase (unsigned first, unsigned last);    /* Lowercase  characters to uppercase   */
    void downcase (unsigned first, unsigned last);  /* uppercase  characters to lowercase   */

    void print();

    char  operator[] (unsigned j) const;            /* Access String character              */
    char& operator[] (unsigned j);

    StringCust& operator= (const StringCust& s);    /* Sets String value                    */

    friend std::ostream& operator<< (std::ostream& so, const StringCust& s);    /* Stream operators */
    friend std::istream& operator>> (std::istream& so,       StringCust& s);

    StringCust& operator+= (const StringCust& s);   /* Append to String                     */

    friend StringCust operator+ (const StringCust& lhs, const StringCust& rhs); /* String concatenation (addition) */
    friend StringCust operator+ (const StringCust& lhs, char          rhs);
    friend StringCust operator+ (const StringCust& lhs, const char*   rhs);
    friend StringCust operator+ (char          lhs, const StringCust& rhs);
    friend StringCust operator+ (const char*   lhs, const StringCust& rhs);

    friend bool operator== (const StringCust& lhs, const StringCust& rhs);              /* String equality */
    friend bool operator== (const StringCust& lhs, char          rhs);
    friend bool operator== (const StringCust& lhs, const char*   rhs);
    friend bool operator== (char          lhs, const StringCust& rhs);
    friend bool operator== (const char*   lhs, const StringCust& rhs);

    friend bool operator!= (const StringCust& lhs, const StringCust& rhs);
    friend bool operator!= (const StringCust& lhs, char          rhs);
    friend bool operator!= (const StringCust& lhs, const char*   rhs);
    friend bool operator!= (char          lhs, const StringCust& rhs);
    friend bool operator!= (const char*   lhs, const StringCust& rhs);

};

#endif // CUSTOM_STRING_H
