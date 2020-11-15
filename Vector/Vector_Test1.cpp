// Vector_test1.cpp

#include <iostream>
//#include <string>
#include <cassert>

#include "Vector.cpp"
#include "../String/String.cpp"

using namespace std;

//prints name and contents of Vector
template <class T>
void print(const String & name, Vector<T> & v)
{
    cout << name << ": ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    cout << "\ndefault constructor\n";
    Vector<int> v0(2);
    v0[0] = 10;
    v0[1] = 20;
    print("v0", v0);

    cout << "\ncopy constructor v1(v0)\n";
    Vector<int> v1(v0); 
    print("v0", v0);
    print("v1", v1);

    cout << "\nmove constructor v2(v1)\n";
    Vector<int> v2((Vector<int>&&) v1); 
    print("v1", v1);
    print("v2", v2);

    cout << "\ncopy assignment v1 = v2\n";
    v1 = v2;                  
    print("v1", v1);
    print("v2", v2);

    Vector<int> v3(3);
    v3[0] = 100;
    v3[1] = 200;
    v3[2] = 300;
    cout << endl;
    print("v3", v3);

    cout << "\nmove assignment v2 = v3\n";
    v2 = (Vector<int>&&)v3;            
    print("v2", v2);
    print("v3", v3);

  
    return 0;
}