#include <iostream>
#include <chrono>

class IntArray
{
    int size;
    int* array;
public:
    IntArray(int size)
        : size{ size }, array{ new int[size] } {};
    ~IntArray()
    {
        delete[] array;
    }

    /*
    IntArray(const IntArray& other) 
        : size{ other.size }, array{ new int[other.size] }
    {
        for (int i{}; i < other.size; i++)
            array[i] = other.array[i];
    }

    IntArray& operator=(const IntArray& other)
    {
        if (&other != this)
        {
            delete[] array;

            this->size = other.size;
            this->array = new int[other.size];

            for (int i{}; i < other.size; i++)
                array[i] = other.array[i];
        }

        return *this;
    }
    */

    IntArray(const IntArray& other) = delete;
    IntArray& operator=(const IntArray& other) = delete;

    IntArray(IntArray&& other)
        : size{ other.size }, array{ other.array }
    {
        other.size = 0;
        other.array = nullptr;
    }

    IntArray& operator=(IntArray&& other)
    {
        if (&other != this)
        {
            delete[] array;

            this->size = other.size;
            this->array = other.array;

            other.size = 0;
            other.array = nullptr;
        }

        return *this;
    }

    int Size() const { return this->size; }
    int& operator[](int index) { return array[index]; }
    const int& operator[](int index) const { return array[index]; }
};

class Timer
{
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> point;
public:
    Timer() : point(clock_t::now()) {}

    void Reset()
    {
        point = clock_t::now();
    }

    double Elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - point).count();
    }
};

IntArray CloneArray(const IntArray& array)
{
    IntArray copy(array.Size());
    for (int i{}; i < array.Size(); i++)
        copy[i] = array[i] * 2;
    return copy;
}

int main()
{
    Timer timer;
    
    IntArray array(1000000);
    for (int i{}; i < array.Size(); i++)
        array[i] = i + 1;

    array = CloneArray(array);

    std::cout << timer.Elapsed() << "\n";
}
