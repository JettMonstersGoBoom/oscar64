#pragma once

#include <assert.h>

typedef unsigned __int32		uint32;

class NumberSet
{
protected:
	uint32				* bits;
	int					size, dwsize;
public:
	NumberSet(void);
	NumberSet(int size, bool set = false);
	NumberSet(const NumberSet& set);
	~NumberSet(void);

	void Reset(int size, bool set = false);

	NumberSet& operator+=(int elem);
	NumberSet& operator-=(int elem);

	bool operator[](int elem) const;

	NumberSet& operator=(const NumberSet& set);

	NumberSet& operator&=(const NumberSet& set);
	NumberSet& operator|=(const NumberSet& set);
	NumberSet& operator-=(const NumberSet& set);

	bool operator<=(const NumberSet& set);

	void Clear(void);

	int Size(void) { return size; }
};

__forceinline NumberSet& NumberSet::operator+=(int elem)
{
	assert(elem >= 0 && elem < size);
	bits[elem >> 5] |= (1UL << (elem & 31));

	return *this;
}

__forceinline NumberSet& NumberSet::operator-=(int elem)
{
	assert(elem >= 0 && elem < size);
	bits[elem >> 5] &= ~(1UL << (elem & 31));

	return *this;
}

__forceinline bool NumberSet::operator[](int elem) const
{
	assert(elem >= 0 && elem < size);
	return (bits[elem >> 5] & (1UL << (elem & 31))) != 0;
}


class FastNumberSet
{
protected:
	uint32	*	buffer;
	int			size, num, asize;
public:
	FastNumberSet(void);
	FastNumberSet(int size, bool set = false);
	FastNumberSet(const FastNumberSet& set);
	~FastNumberSet(void);

	void Reset(int size, bool set = false);

	FastNumberSet& operator+=(int elem);
	FastNumberSet& operator-=(int elem);

	bool operator[](int elem);

	FastNumberSet& operator=(const FastNumberSet& set);

	bool Empty(void) { return !num; }
	void Clear(void);

	int Num(void) { return num; }
	int Element(int i);

	int Size(void) { return size; }
	int Index(int elem);
};

__forceinline bool FastNumberSet::operator[](int elem)
{
	uint32 dw = buffer[size + elem];

	return (dw < uint32(num) && buffer[dw] == elem);
}

__forceinline FastNumberSet& FastNumberSet::operator+=(int elem)
{
	uint32 dw = buffer[size + elem];

	if (dw >= uint32(num) || buffer[dw] != elem)
	{
		buffer[num] = elem;
		buffer[size + elem] = num;
		num++;
	}

	return *this;
}

__forceinline FastNumberSet& FastNumberSet::operator-=(int elem)
{
	uint32 dw = buffer[size + elem];

	if (dw < uint32(num) && buffer[dw] == elem)
	{
		num--;
		buffer[dw] = buffer[num];
		buffer[size + buffer[dw]] = dw;
	}

	return *this;
}

__forceinline int FastNumberSet::Element(int i)
{
	if (i < num)
		return buffer[i];
	else
		return -1;
}
