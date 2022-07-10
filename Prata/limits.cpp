#include <iostream>
#include <climits>
#include <cfloat>

int main()
{
    using namespace std;
    short max_short = SHRT_MAX;
    int max_int(INT_MAX);
    long max_long{LONG_MAX};
    long long max_llong{LLONG_MAX};

    cout << "short \ttakes " << sizeof max_short << " bytes\t|\tmaximum value is " << max_short << endl;
    cout << "int \ttakes " << sizeof max_int << " bytes\t|\tmaximum value is " << max_int << endl;
    cout << "long \ttakes " << sizeof max_long << " bytes\t|\tmaximum value is " << max_long << endl;
    cout << "llong \ttakes " << sizeof max_llong << " bytes\t|\tmaximum value is " << max_llong << endl;
    
    cout << "float \ttakes " << sizeof(float) << " bytes\t|\tmaximum value is " << FLT_MAX << endl;
    cout << "double \ttakes " << sizeof(double) << " bytes\t|\tmaximum value is " << DBL_MAX << endl;
    cout << "ldouble\ttakes " << sizeof(long double) << " bytes\t|\tmaximum value is " << LDBL_MAX << endl;
    cout << "Bits per byte: " << CHAR_BIT << endl;

    return 0;
}
