#include <iostream>
#include "SmartPointer.h"

class Resource
{
    int size;
    int* array ;
public:
    Resource(int size = 0)
        : size{ size }, array{ nullptr }
    {
        if (size)
            array = new int[size];
        std::cout << "Resorce construct\n";
    };

    Resource(const Resource& other)
    {
        this->size = other.size;
        this->array = new int[this->size] {};

        for (int i{}; i < other.size; i++)
            this->array[i] = other.array[i];
    }

    int Size() { return size; }
    int& operator[](int index)
    {
        return array[index];
    }

    ~Resource()
    {
        if (array)
            delete[] array;
        std::cout << "Resorce destruct\n";
    }
};

class SimpleResource
{
    int value;
public:
    SimpleResource(int value = 0)
        : value{ value }
    {
        std::cout << "Resorce construct\n";
    }

    int& Value() { return value; }

    ~SimpleResource()
    {
        std::cout << "Resorce destruct\n";
    }
};

template <typename T>
SmartPointer<T> generateResource()
{
    T* resource = new T();
    return SmartPointer<T>(resource);
}

int main()
{
    SmartPointer<SimpleResource> simple(new SimpleResource());
    SmartPointer<SimpleResource> simple2(simple);

    //SmartPointer<Resource> simple3 = generateResource<Resource>();
    //std::cout << simple3->Size();

    int n = 10;
    int& lref = n;
    int&& rref = 10;

    std::cout << &rref;

}
