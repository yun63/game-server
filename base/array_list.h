// =====================================================================================
//
//       Filename:  array_list.h
//
//    Description:  线性表
//
//        Version:  1.0
//        Created:  2015年09月24日 15时46分29秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================


#ifndef  H_ARRAY_LIST_INC
#define  H_ARRAY_LIST_INC

#include <cstddef>

#include "list_base.h"

namespace base {


template <typename T>
class ArrayList : public ListBase<T>
{
	public:
		ArrayList(int initcapacity = 10);
		ArrayList(const ArrayList<T> &);
		~ArrayList();

		/**
		 * @brief  empty 
		 * @return  
		 */
		bool empty() const { return size_ == 0; }
		/**
		 * @brief  size 
		 * @return  
		 */
		int size() const { return size_; }
		/**
		 * @brief  get 
		 * @param  index
		 * @return  
		 */
		T &get(int index) const;
		/**
		 * @brief  indexof 
		 * @param  elem
		 * @return  
		 */
		int indexof(const T &elem) const;
		/**
		 * @brief  erase 
		 * @param  index
		 */
		void erase(int index);
		/**
		 * @brief  insert 
		 * @param  index
		 * @param  elem
		 */
		void insert(int index, const T &elem);
		/**
		 * @brief  output 
		 * @param  out
		 */
		void output(std::ostream &out) const;

		int capacity() const { return capacity_; }

		// iterators to start and end of list
		class iterator;
		iterator begin() { return iterator(elements_); }
		iterator end() { return iterator(elements_ + size_); }

		// iterator for ArrayList
		class iterator
		{
			public:
				typedef T value_type;
				typedef ptrdiff_t difference_type;
				typedef T *pointer;
				typedef T &reference;

				iterator(T *it = 0) { iter_ = it; }
				T &operator *() const { return *iter_; }
				T *operator ->() const { return &*iter_; }

				/**
				 * @brief  ++() preincrement
				 * @return  
				 */
				iterator &operator ++()
				{
					++iter_;
					return *this;
				}
				/**
				 * @brief  ++(int) postincrement
				 * @param  int
				 * @return  
				 */
				iterator operator ++(int)
				{
					iterator old = *this;
					++iter_;
					return old;
				}
				iterator &operator --() 
				{
					--iter_;
					return *this;
				}
				iterator operator --(int)
				{
					iterator old = *this;
					--iter_;
					return old;
				}

				bool operator != (const iterator right) const
				{
					return iter_ != right.iter_;
				}
				bool operator == (const iterator right) const
				{
					return iter_ == right.iter_;
				}

			protected:
				T *iter_;
		};  

	protected:
		void CheckIndex(int index) const;

    protected:
		T *elements_;                           // array to hold list elements
		int capacity_;                          // capacity of the array
		int size_;                              // number of elements in list
};


} // namespace base

#endif   // ----- #ifndef ARRAY_LIST_INC  -----
