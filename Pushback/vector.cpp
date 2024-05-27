#include "../Pushback/vector.h"

template <typename T>
Vector<T>::Vector() : data(nullptr), vecSize(0), vecCapacity(0) {}

template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}

template <typename T>
void Vector<T>::push_back(const T& value)
{
    if(vecSize == vecCapacity)
    {
        resize();
    }
    
    data[vecSize] = value;
    ++vecSize;
}

template <typename T>
T& Vector<T>::operator [] (int index)
{
    if(index >= vecSize || index < 0)
    {
        std::cerr << "Index out of range" << std::endl;
    }
    return data[index];
}

template <typename T>
int Vector<T>::size() const
{
    return vecSize;
}

template <typename T>
int Vector<T>::capacity() const
{
    return vecCapacity;
}

template<typename T>
void Vector<T>::resize()
{
    vecCapacity = (vecCapacity == 0) ? 1 : vecCapacity * 2;
    T* newData = new T[vecCapacity];
    
    for(int i = 0; i < vecSize; ++i)
    {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
}


template class Vector<int>;
template class Vector<double>;
template class Vector<std::string>;