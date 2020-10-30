
/***********************************************************************
Emmanuel G Q 
10-16-2020
String.cpp

Implementation of constructors and member functions defined in String.h.
************************************************************************/

#include "String.h"
#include <cassert>

//default constructor 
String::String()
{
    size = 0;
    buffer = nullptr;
}

//copy constructor 
String::String(const String & source)
{
    size = source.size;
    buffer = new char[size];
    assert(buffer != nullptr);

    for(int i = 0; i < size; i++)
        buffer[i] = source.buffer[i];
}

//move constructor
String::String(String && source)
{
    size = source.size;
    buffer = source.buffer;
    source.size = 0;
    source.buffer = nullptr;
}

//constructor from "char string" to String
//find size of p, allocate space, assign p to buffer
String::String(const char * p)
{
    size = 0;
    for (const char * q = p; *q; q++)
        size++;
    buffer = new char[size];
    assert(buffer != nullptr);

    for(int i = 0; i < size; i++)
        buffer[i] = p[i];
}

//single char constructor 
String::String(char c)
{
    size = 1;
    buffer = new char[size];
    assert(buffer != nullptr);
    buffer[0] = c;
}

//destructor 
String::~String()
{
    delete [] buffer;
}

//return length of string 
int String::length()
{
    return size;
}

char & String::operator[](const int index)
{
    return buffer[index];
}

//copy assignment 
//similar to char string constructor
//creat be a temp buffer based on source,
//delete existing buffer, then assign temp buffer to buffer 
String & String::operator=(const String & source)
{
    char * temp = new char[source.size];
    assert(temp != nullptr);

    for(int i = 0; i < source.size; i++)
        temp[i] = source.buffer[i];

    delete [] buffer;
    buffer = temp;
    size = source.size;

    return *this;
}

//move assignment 
String & String::operator=(String && source)
{
    char * temp = new char[source.size];
    assert(temp != nullptr);

    for(int i = 0; i < source.size; i++)
        temp[i] = source.buffer[i];

    delete [] buffer;
    buffer = temp;
    size = source.size;

    source.size = 0; source.buffer = nullptr;
    return *this;
}

//addition operator 
String & String::operator+=(const String & source)
{
    int tempSize = size + source.size;
    char * temp;
    temp = new char[tempSize];
    assert(temp != nullptr);

    int i;
    for(i = 0; i < size; i++)
        temp[i] = buffer[i];
    for(int j = 0; j < source.size; j++, i++)
        temp[i] = source.buffer[j];
        
    size = tempSize;
    delete [] buffer;
    buffer = temp;

    return *this;
}

//subtract operator string
String String::operator-(const String & source)
{
    String temp = *this;
    int i = 0, j, k;
    while(i <= temp.size - source.size){
        j = i;
        k = 0;
        while(k < source.size)
            if(temp.buffer[j] == source.buffer[k]){
                j++;
                k++;
            } else 
                break;
        
        if(k == source.size){
            for(j = i + source.size; j < temp.size; j++)
                temp.buffer[j - source.size] = temp.buffer[j];
            temp.size -= source.size;
        } else 
            i++;
    }
    return temp;
}  

//substring function starting at pos ending at end of string
String String::substr(unsigned pos) const
{
    String temp = "";
    for(int i = 0; pos + i < size; i++)
        temp[i] += buffer[pos + i];

    return temp;
}

//substring function starting at pos and the length of len  
String String::substr(unsigned pos, unsigned len) const
{
    String temp = "";

    for(int i = 0; i < len && pos + i < size; i++)
        temp += buffer[pos + i];

    return temp;
}

//comparison operator 
bool operator==(const String & left, const String & right)
{
    if(left.size != right.size)
        return false;

    for(int i = 0; i < left.size; i++)
        if(left.buffer[i] != right.buffer[i])
            return false;
    
    return true;
}


//returns true if left string is equal to or less than right string 
bool operator<=(const String & left, const String & right)
{
    if(left < right || left == right)
        return true;
    return false;
}

//returns true if left string is less than left string 
bool operator<(const String & left, const String & right)
{
    for(int i = 0; i < left.size && i < right.size; i++){
        if(left.buffer[i] < right.buffer[i])
            return true;
        else if(left.buffer[i] > right.buffer[i])
            return false;
    }

    if(left.size < right.size)
        return true;
    return false;
}

//outstream operator 
ostream & operator<<(ostream & out, const String & s)
{
    for(int i = 0; i < s.size; i++)
        out << s.buffer[i];
    return out;
}

//instream operator 
istream & operator>>(istream & in, String & s)
{
    s = "";
    char t = ' ';

    while(t == ' ' || t == '\t' || t == '\n')
        in.get(t);
    
    while(t != ' ' && t != '\t' && t != '\n'){
        s += t;
        in.get(t);
    }

    cin.unget();
    return in;    
}