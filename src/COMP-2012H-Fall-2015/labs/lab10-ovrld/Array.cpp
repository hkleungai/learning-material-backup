#include "Array.h"

/* Constructors & Destructor */
Array::Array()
{
    _data = NULL;
    _size = 0;
}

Array::Array (int size)
{
    assert (size >= 0);
    _size = size;
    _data = new T [_size];
}


Array::Array (const Array& arr)
{
    assert (arr.IsValid ());
    _size = arr._size;
    _data = new T [_size];
    for (int i = 0; i < _size; i++)
    {
        _data[i] = arr._data[i];
    }
}

Array::Array (const T * arr, int size)
{
    assert(arr != NULL && size > 0);

    _size = size;
    _data = new T [_size];
    for (int i = 0; i < _size; i++)
    {
        _data[i] = arr[i];
    }
}


Array::~Array ()
{
    if (_data != NULL && _size > 0)
    {
        delete [] _data;
        _data = NULL;
        _size = 0;
    }
}

/* Operators Overloaded */
// The main task
Array& Array::operator=(const Array& arr)
{
    assert(arr.IsValid ());
    // TO DO: complete the operator "="
    // ...
}

bool Array::operator==(const Array& arr) const
{
    // TO DO: complete the operator "=="
    // ...
}

T& Array::operator[](int index)
{
    assert (IsValid ());
    assert (index >=0 && index < _size);
    // TO DO: complete the operator "[]"
    // ...
}

T Array::operator[](int index) const
{
    assert (IsValid ());
    assert (index >=0 && index < _size);
    // TO DO: complete the operator "[]"
    // ...
}

// TO DO: implement the operator "+="
// ...

// ...
// End operator +=


/* Methods */
void Array::Append (const T& item)
{
   if (_data != NULL)
    {
        T* temp = new T [_size+1];
        for (int i = 0; i<_size; i++)
        {
            temp[i] = _data[i];
        }
        temp[_size] = item;
        delete [] _data;
        _data = temp;
        _size++;
    }
    else
    {
        _size = 1;
        _data = new T [_size];
        _data[0] = item;
    }

}

/* Properties */
 bool Array::IsValid () const
{
    return (_data != NULL && _size > 0);
}

int Array::Size () const
{
    return _size;
}
