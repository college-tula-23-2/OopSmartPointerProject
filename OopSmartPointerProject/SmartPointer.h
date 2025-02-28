#pragma once
template <typename T>
class SmartPointer
{
	T* pointer{};
public:
	SmartPointer(T* pointer = nullptr)
		: pointer{ pointer } {};

	SmartPointer(const SmartPointer& other)
	{
		// copy semantic
		this->pointer = new T();
		*pointer = *(other.pointer);
	}

	SmartPointer(SmartPointer&& other) : pointer{ other.pointer }
	{
		other.pointer = nullptr;
	}


	SmartPointer& operator=(const SmartPointer& other)
	{
		// copy semantic
		if (&other != this)
		{
			if (pointer)
				delete pointer;

			pointer = new T();
			*pointer = *other->pointer;
		}
		
		// move semantic
		/*if (&other != this)
		{
			if (pointer)
				delete pointer;

			pointer = other.pointer;
			other.pointer = nullptr;
		}*/

		return *this;
	}

	SmartPointer& operator=(SmartPointer&& other)
	{
		if (other != this)
		{
			if(pointer)
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


template <typename T>
class UniqueSmartPointer
{
	T* pointer;
public:
	UniqueSmartPointer(const UniqueSmartPointer&) = delete;
	UniqueSmartPointer& operator=(UniqueSmartPointer&) = delete;
};

