// =====================================================================================
//
//       Filename:  array_list.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年09月24日 15时45分15秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================

#include "array_list.h"

#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <algorithm>

#include "exceptions.h"

namespace base {


template <typename T>
void ChangeLength1D(T *&a, int oldlen, int newlen)
{
	if (newlen < 0) 
	{ 
		throw IllegalParameterValue("new length must be bigger than 0");
	}

	T *p = new T[newlen];
	int number = std::min(oldlen, newlen);
    std::copy(a, a + number, p);
	delete []a;
	a = p;
}

template<typename T>
ArrayList<T>::ArrayList(int initcapacity)
{
	if (initcapacity < 1)
	{
        std::ostringstream s;
		s << "initial capacity : " << initcapacity << " must be bigger than 0";
		throw IllegalParameterValue(s.str());
	}

	size_ = 0;
	capacity_ = initcapacity;
	elements_ = new T[capacity_];
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &array_list)
{
	capacity_ = array_list.capacity_;
	size_ = array_list.size_;
	elements_ = new T[capacity_];
    std::copy(array_list.elements_, array_list.elements_ + size_, elements_);
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    delete []elements_;
    elements_ = NULL;
}

template <typename T>
void ArrayList<T>::CheckIndex(int index) const
{
	if (index < 0 || index >= size_)
	{
        std::ostringstream s;
		s << "index = " << index << " size = " << size_;
		throw IllegalIndex(s.str());
	}
}

template <typename T>
T &ArrayList<T>::get(int index) const
{
	// retrun element whose index is 'index'
	// throw IllegalIndex exception if no such element.
	CheckIndex(index);

	return elements_[index];
}

template <typename T>
int ArrayList<T>::indexof(const T &elem) const
{
	int index = static_cast<int>(std::find(elements_, elements_ + size_, elem) - elements_);
	if (index == size_) 
    {
        return -1;
    }

	return index;
}


} // namespace base
