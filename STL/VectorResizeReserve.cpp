#include <iostream>


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

    void resize(int new_size)
    {
        if(new_size == size)
        {
            return;
        }
        else if(new_size < size)
        {
            size = new_size;
        }
        else
        {
            reserve(new_size);
            while(size < new_size)
            {
                data[size++] = T();
            }
        }
    }

    void reserve(int new_capacity)
    {
        if (new_capacity > capacity)
        {
            new_capacity = 2 * capacity;   
            T* new_data = new T[new_capacity];
        
            for (int i = 0; i < size; ++i)
            {
                new_data[i] = data[i]; 
            }

            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
}

    void print()
    {
        for(int i = 0; i < size; ++i)
        {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    int Size() const
    {
        return size;
    }
};



int main()
{
    Vector<int> v;

    v.resize(5);
    for(int i = 0; i < 5; ++i)
    {
        v.print();
        v.resize(v.Size() + 1);
    }

    v.reserve(20);
    v.print();


    return 0;
}