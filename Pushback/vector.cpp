#include "../Pushback/vector.h"
#include <initializer_list>


template <typename T>
Vector<T>::Vector() : data(nullptr), vecSize(0), vecCapacity(0) {}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> initList) : data(new T[initList.size() * 2]), vecSize(initList.size()), vecCapacity(initList.size() * 2)
{
    int i = 0;
    
    for(const auto& element : initList)
    {
        data[i++] = element;
    }
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] data;
}

//PUSH
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
void Vector<T>::push_front(const T& value)
{
    if (vecSize == vecCapacity)
    {
        resize();
    }
    
    for (int i = vecSize - 1; i >= 0; --i)
    {
        data[i + 1] = data[i];
    }
    
    data[0] = value;
    ++vecSize;
}
//PUSH

template <typename T>
void Vector<T>::insert(int position, const T& value)
{
    
    if (position < 0 || position > vecSize)
    {
        std::cerr << "out of range" << std::endl;
        return;
    }

    if (vecSize == vecCapacity)
    {
        resize();
    }

    for (int i = vecSize; i >= position; --i)
    {
        data[i] = data[i - 1];
    }

    data[position] = value;
    ++vecSize;
}


//POP
template <typename T>
void Vector<T>::pop_back()
{
    if(vecSize == 0)
    {
        return;
    }
    --vecSize;
}

template <typename T>
void Vector<T>::pop_front()
{
    if(vecSize == 0)
    {
        return;
    }

    for(int i= 0; i < vecSize - 1; ++i)
    {
        data[i] = data[i + 1];
    }

    --vecSize;
}
//POP

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