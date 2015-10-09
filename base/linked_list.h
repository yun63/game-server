// #####################################################################################
// 
//    @filename         :  link_list.h
// 
//    @description      :  单链表结点及单链表的定义
//
//######################################################################################
//    @version          :  1.0
//    @created          :  05/26/13 23:16:58
//    @revision         :  none
//    @compiler         :  g++
// 
//    @author           :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
//    @Company          :  
// 
// #####################################################################################


#ifndef  H_LINK_LIST_INC
#define  H_LINK_LIST_INC

#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

#include "list_base.h"
#include "exceptions.h"

using namespace std;

namespace base {


template <typename T>
class LNode
{
    public:
        LNode() : next_(NULL) {}
        ~LNode() {}
        LNode(const T &elem) : element_(elem), next_(NULL) {}
        LNode(const T &elem, LNode<T> *n) : element_(elem), next_(n){}

    public:
        T element_;
        LNode<T> *next_;
};

template <typename T>
class LinkList : public ListBase<T>
{
	public:
		// constructor, copy constructor and destructor
		LinkList();
		LinkList(const LinkList<T> &);
		~LinkList();

		bool empty() const { return size_ == 0; }
		int size() const { return size_; }
		T &get(int index) const;
		int indexof(const T &elem) const;
		void erase(int index);
		void insert(int index, const T &elem);
		void output(ostream &out) const;
		void Reverse();
		
		void BinSort(int range);
		void BinSort(int range, int (*value)(T &x));

		// iterators to start and end of link list
		class iterator;
		iterator begin() { return iterator(head_->next_); }
		iterator end() { return iterator(NULL); }

		// iterator for LinkList
		class iterator
		{
			public:
				// typedefs required by C++ for a forward iterator
				typedef forward_iterator_tag iterator_category;
				typedef T value_type;
				typedef ptrdiff_t difference_type;
				typedef T *pointer;
				typedef T &reference;

				// constructor
				iterator(LNode<T> *node = NULL) { node_ = node; }
				
				// dereferencing operations
				T &operator *() const { return node_->element_; }
				T *operator ->() const { return &node_->element_; }

				// increment
				iterator &operator ++() // preincrement
				{
					node_ = node_->next_;
					return *this;
				}
				iterator operator ++(int) // postincrement
				{
					iterator old = *this;
					node_ = node_->next_;
					return old;
				}

				// equality testing
				bool operator != (const iterator right) const
				{
					return node_ != right.node_;
				}
				bool operator == (const iterator right) const
				{
					return node_ == right.node_;
				}

			protected:
				LNode<T> *node_;
		};

	protected:
		void CheckIndex(int index) const;

		LNode<T> *head_;                    // pointer to first node in linklist
		int size_;                              // number of elements in linklist
};

} // namespace base

#endif   // ----- #ifndef LINK_LIST_INC  -----
