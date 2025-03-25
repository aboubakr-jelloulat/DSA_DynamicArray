#pragma once
#include <cassert>
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{

protected:
	int _Size{};
	T *_TempArray;

public:
	T *OriginalArray{nullptr};

	clsDynamicArray(int Size = 0)
	{
		if (Size < 0)
			Size = 0;

		_Size = Size;

		OriginalArray = new T[_Size];
	}

	bool SetItem(int index, T Value)
	{

		if (index >= _Size || _Size < 0)
			return false;

		// also you can use  assert func
		// assert (0 <= index && index < _Size)

		OriginalArray[index] = Value;
		return true;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}

	void PrintList()
	{

		for (int i = 0; i <= _Size - 1; i++)
		{
			cout << OriginalArray[i] << " ";
		}

		cout << "\n";
	}

	/*

	void Resize(int New_size)
	{
		T *new_array  = new T[New_size];

		for (int i = 0; i < New_size; i++)
			new_array[i] = OriginalArray[i];

		swap(OriginalArray, new_array);
		delete[] new_array;
		_Size = New_size;
	}

	*/

	void Resize(int NewSize)
	{
		if (NewSize < 0)
		{
			NewSize = 0;
		}

		_TempArray = new T[NewSize];

		// limit the original size (5) to the new size(2) if it is less.
		if (NewSize < _Size)
			_Size = NewSize;

		// copy all data from original array until the size
		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_Size = NewSize;

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	 T GetItem(int index)
    {
        return OriginalArray[index];

    }


    void  Reverse()
    {

        _TempArray = new T[_Size];



        for (int i = _Size - 1, u = 0; i >= 0; i--, u++)
        {

            _TempArray[u] = OriginalArray[i];

        }

        delete[] OriginalArray;
        OriginalArray = _TempArray;

    }

    void Clear()
    {
        _Size = 0;
        _TempArray = new T[0];
        delete[] OriginalArray;
        OriginalArray = _TempArray;
    }

	void DeleteItemAt(int index)
	{
		assert (index >= 0 && index < _Size);

		for (int i = index + 1; i < _Size; i++)
		{
			OriginalArray[i - 1] = OriginalArray[i];
		}

		-- _Size;
		Resize(_Size);
	}


	~clsDynamicArray()
	{
		delete[] OriginalArray;
		OriginalArray = nullptr; // no leaks
	}
};
