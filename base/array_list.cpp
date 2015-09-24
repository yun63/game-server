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

template <typename T>
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

template <typename T>
void ArrayList<T>::erase(int index)
{                                                                                                                          
    // delete the element whose index is 'index'                                                                           
    // throw CIllegalIndex exception if no such element.                                                                   
    CheckIndex(index);                                                                                                     
                                                                                                                           
    // valid index, shift elements with higher index                                                                       
    std::copy(elements_ + index + 1, elements_ + size_, elements_ + index);                                                     
    elements_[--size_].~T(); // invoke destructor
}                                                                                                                          
                                                            
template <typename T>
void ArrayList<T>::insert(int index, const T &elem)                                                                    
{                                                                                                                       
    if (index < 0 || index > size_)
    {
        std::ostringstream s;
        s << "index = " << index << " size = " << size_;
        throw IllegalIndex(s.str());
    }

    // valid index, make sure we have space
    if (size_ == capacity_)
    {
        // no space, double capacity
        T *p = new T[capacity_ << 1];
        std::copy(elements_, elements_ + capacity_, p);
        delete []elements_;
        elements_ = p;
        capacity_ = capacity_ << 1;
    }                                                                                                                   
                                                                                                                        
    // shift elements right one position                                                                                
    std::copy_backward(elements_ + index, elements_ + size_, elements_ + size_ + 1);
    elements_[index] = elem;                                                                                            
    size_++;                                                                                                            
}

template <typename T>                                                                                                       
void ArrayList<T>::output(std::ostream &out) const                                                                          
{                                                                                                                       
    std::copy(elements_, elements_ + size_, std::ostream_iterator<T>(cout, " "));
}                                                                                                                       
                                                                                                                        
// overload <<                                                                                                          
template<class T>                                                                                                       
std::ostream &operator << (std::ostream &out, const ArrayList<T> &x)
{
    x.output(out);

    return out;
}


} // namespace base
