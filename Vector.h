#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>


template <class T>
class Vector
{
public:
    Vector();
    ~Vector();
    Vector(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other);
    int getSize() const;
    int getCapacity() const;
    void resizeCapacity();
    void addRecord(const T& element);
    T& operator[](int index);
    const T& operator[](int index) const;

private:
    int size;
    int capacity;
    T* data;
};

template <class T>
Vector<T>::Vector()
    : size(0), capacity(20), data(nullptr)
{
    data = new T[capacity];
}

template <class T>
Vector<T>::~Vector()
{
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

template <class T>
Vector<T>::Vector(const Vector<T>& other)
    : size(other.size), capacity(other.capacity), data(nullptr)
{
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    // Self-assignment guard
    if (this == &other) {
        return *this;
    }

    // Delete old data
    delete[] data;

    // Copy size and capacity
    size = other.size;
    capacity = other.capacity;

    // Allocate new data
    data = new T[capacity];

    // Copy elements
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

    return *this;
}

template <class T>
int Vector<T>::getSize() const
{
    return size;
}

template <class T>
int Vector<T>::getCapacity() const
{
    return capacity;
}

template <class T>
void Vector<T>::resizeCapacity()
{
    int newCapacity = capacity * 2;
    T* newData = new T[newCapacity];

    // Copy existing elements
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    // Delete old array
    delete[] data;

    // Update pointers
    data = newData;
    capacity = newCapacity;
}

template <class T>
void Vector<T>::addRecord(const T& element)
{
    if (size == capacity) {
        resizeCapacity();
    }

    data[size] = element;
    size++;
}

template <class T>
T& Vector<T>::operator[](int index)
{
    return data[index];
}

template <class T>
const T& Vector<T>::operator[](int index) const
{
    return data[index];
}

#endif // VECTOR_H_INCLUDED
