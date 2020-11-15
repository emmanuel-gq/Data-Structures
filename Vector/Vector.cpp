/***********************************************************************
 * Emmanuel G Q
 * 10-24-2020
 * Vector.cpp
 * 
 * Implementation of constructors and member functions defined in Vector.h
 * ********************************************************************/

#include <cassert>
#include "Vector.h"

using namespace std;
//default constructor 
template <class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
    my_size = size;
    my_capacity = size;
    if(size == 0 )
        buffer = NULL;
    else
    {
        buffer = new T[size];
        assert(buffer != NULL);
    }
    for(int i = 0; i < size; i++){
        buffer[i] = initial;
    }
    
}

//copy constructor
template <class T>
Vector<T>::Vector(const Vector<T> & v)
{
    my_capacity = v.my_capacity;
    my_size = v.my_size;
    if(my_size == 0 )
        buffer = NULL;
    else
    {
        buffer = new T[my_capacity];
        assert(buffer != NULL);
    }
    for(int i = 0; i < my_size; i++){
        buffer[i] = v.buffer[i];
    }
    
}

//move constructror
template<class T>
Vector<T>::Vector(Vector<T> && v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = v.buffer;
    v.my_size = 0;
    v.my_capacity = 0;
    v.buffer = NULL;
}

//destructor
template<class T>
Vector<T>::~Vector()
{
    delete [] buffer;
    my_capacity = 0;
    my_size = 0;
}

//copy assignment 
template<class T>
Vector<T> & Vector<T>::operator=(const Vector<T> & v)
{
    T * temp = new T[v.my_capacity];
    assert(temp != NULL);

    for(int i = 0; i <= v.size(); i++)
        temp[i] = v.buffer[i];
    
    delete buffer;
    buffer = temp;
    my_size = v.my_size;
    my_capacity = v.my_capacity;

    return *this;
}

//move assignment 
template <class T>
Vector<T> & Vector<T>::operator=(Vector<T> && v)
{
    my_size = v.my_size;
    v.my_size = 0;
    my_capacity = v.my_capacity;
    v.my_capacity = 0;
    delete [] buffer;
    buffer = v.buffer;
    v.buffer = NULL;

    return *this;
}

template<class T>
unsigned int Vector<T>::capacity() const
{
    return my_capacity;
}

template<class T>
unsigned int Vector<T>::size() const
{
    return my_size;
}

template<class T>
bool Vector<T>::empty() const 
{
    if(my_size == 0)
        return true;
}

//return iterator to first element 
template<class T>
typename Vector<T>::iterator Vector<T>::begin() 
{
    return buffer;
}

//return iterator to last element
template<class T>
typename Vector<T>::iterator Vector<T>::end()
{
    return begin() + my_size; 
}

//return reference to first element 
template<class T>
T & Vector<T>::front()
{
    return buffer[0];
}

//return reference to last element
template<class T>
T & Vector<T>::back()
{
    return buffer[my_size - 1];
}

template<class T>
void Vector<T>::push_back(const T & value)
{
    if(my_size >= my_capacity)
        reserve(my_capacity + 5);
    buffer[my_size++] = value;
}

template<class T>
void Vector<T>::push_back(T && value)
{
    if(my_size >= my_capacity)
        reserve(my_capacity + 5);
    buffer[my_size++] = value;
}


template<class T>
void Vector<T>::pop_back()
{
    buffer[my_size--].~T();
}

//adjust capacity 
template<class T>
void Vector<T>::reserve(unsigned int capacity)
{
    if(buffer == 0) {
        //no buffer, size 0
        my_capacity = 0;
        my_size = 0;
    }

    //return if its buffer already large enough 
    if(capacity <= my_capacity)
        return;

    //allocate new buffer and assert 
    T * newBuffer = new T [capacity];
    assert(newBuffer);

    //copy values into buffer reset capacity
    copy(buffer, buffer + my_size, newBuffer);
    my_capacity = capacity;

    //alternative solution
    // for(int i = 0; i < my_size; i++){
    //      newBuffer[i] = buffer[i];
    // } my_capacity = capacity;

    //change pointer to buffer
    delete [] buffer;
    buffer = newBuffer; 
}

//adjust size 
template<class T>
void Vector<T>::resize(unsigned int size)
{
    reserve(size);
    my_size = size;
}

template<class T>
T & Vector<T>::operator[] (unsigned int index)
{
    return buffer[index];
}

