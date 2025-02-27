#pragma once
template <typename T>
class SmartPointer
{
	T* pointer{};
public:
	SmartPointer(T* pointer = nullptr)
		: pointer{ pointer } {};

	SmartPointer(SmartPointer& other)
	{
		// copy semantic
		/*this->pointer = new T();
		*pointer = *(other.pointer);*/

		// move semantic
		pointer = other.pointer;
		other.pointer = nullptr;
	}

	SmartPointer& operator=(SmartPointer& other)
	{
		// copy semantic
		/*if (&other != this)
		{
			pointer = new T();
			*pointer = *other->pointer;
		}*/
		
		// move semantic
		if (&other != this)
		{
			if (pointer)
				delete pointer;

			pointer = other.pointer;
			other.pointer = nullptr;
		}

		return *this;
	}

	~SmartPointer()
	{
		delete pointer;
	}

	T* operator->() const { return pointer; }
	T& operator*() const { return *pointer; }
};

