/***********************************************************************
 * Emmanuel G Q
 * 10-24-2020
 * Vector.h
 * 
 * Vector class definition
 * ********************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

template <class T>  
class Vector
{
public:

    typedef T * iterator;
 
    Vector(unsigned int size = 0, const T & initial = T()); // default constructor
    Vector(const Vector<T> & v);                            // copy constructor
    Vector(Vector<T> && v);                                 // move constructor
    ~Vector();                                              // destructor
    Vector<T> & operator=(const Vector<T> & v);             // copy assignment
    Vector<T> & operator=(Vector<T> && v);                  // move assignment
 
    unsigned int capacity() const;
    unsigned int size() const;   
    bool empty() const;
 
    iterator begin();                      // return iterator to first element
    iterator end();                        // return iterator to past last element
    T & front();                           // return reference to first element
    T & back();                            // return reference to last element
    void push_back(const T & value);
    void push_back(T && value);
    void pop_back();               
 
    void reserve(unsigned int capacity);   // adjust capacity
    void resize(unsigned int size);        // adjust size
 
    T & operator[](unsigned int index);
    void erase(iterator);                  // erase elem iterator points to (shift left from iterator)
 
private:
    unsigned int my_size;
    unsigned int my_capacity;
    T * buffer;
};

#endif