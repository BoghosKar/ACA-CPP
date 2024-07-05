#include <iostream>
#include <stdexcept>

template <typename T>
class Vector
{
private:
    T* data;
    int size;
    int capacity;

public:
    Vector() : data(nullptr), size(0), capacity(0) {}
    ~Vector()
    {
        delete[] data;
    }

    void push_back(const T& value)
    {
        if(size == capacity)
        {
            resize(capacity == 0 ? 1 : 2 * capacity);
        }
        data[size++] = value;
    }

    T& operator [] (int index)
    {
        return data[index];
    }

    T& at(int index)
    {
        if(index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    void resize(int new_capacity)
    {
        if(new_capacity > capacity)
        {
            T* new_data = new T[new_capacity];
            for(int i = 0; i < size; ++i)
            {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    }

    int Size() const
    {
        return size;
    }
};

int main()
{
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    try
    {
        std::cout << vec.at(2) << std::endl;
        std::cout << vec.at(5) << std::endl;
    }catch(const std::out_of_range& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}