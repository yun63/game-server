// =====================================================================================
//
//       Filename:  linked_list.cpp
//
//    Description:  带头结点的单链表 
//                  设置头节点的目的是为了方便对链表的操作，如果不设置头节点，而是直接由头指针指向首节点，
//                  这样在对头指针后的节点进行插入删除操作时就会与其他节点进行该操作时有所不同，
//                  便要作为一种特殊情况来分析
//
//        Version:  1.0
//        Created:  2015年09月29日 17时09分45秒
//       Revision:  none
//       Compiler:  gcc
//
//         Author:  leiyunfei (yun63), towardstheway@gmail.com
//   Organization:  
//
// =====================================================================================

#include "linked_list.h"
#include "exceptions.h"

namespace base {


template<class T>
LinkList<T>::LinkList()
{
	head_ = new LNode<T>();                // linklist with head node
	head_->next_ = NULL;
	size_ = 0;
}

template<class T>
LinkList<T>::LinkList(const LinkList<T> &list)
{
	size_ = list.size();
	if (size_ == 0)
	{
		head_->next_ = NULL;
		return;
	}

	LNode<T> *s = list.head_;         // node in the list to copy from
	head_ = new LNode<T>();
	LNode<T> *t = head_;
	T value;
	while (s->next_ != NULL)
	{
		// copy elements		
		value = s->next_->element_;
		t->next_ = new LNode<T>(value);
		t = t->next_;
		s = s->next_;
	}
}

template<class T>
LinkList<T>::~LinkList()
{
	while (head_->next_ != NULL)
	{
		LNode<T> *nextnode = head_->next_;
		head_->next_ = nextnode->next_;
		delete nextnode;
	}
}

template<class T>
void LinkList<T>::CheckIndex(int index) const
{
	if (index < 0 || index >= size_)
	{
		ostringstream s;
		s << "index = " << index << " size = " << size_;
		throw IllegalIndex(s.str());
	}
}

template<class T>
T &LinkList<T>::get(int index) const
{
	// return element whose index is 'index'
	CheckIndex(index);

	// nove to desired node
	LNode<T> *current = head_->next_;
	for (int i = 0; i < index && current; ++i)
	{
		current = current->next_;
	}
	return current->element_;
}

template<class T>
int LinkList<T>::indexof(const T &elem) const
{
	// return index of first occurence of elem
	// return -1 if the elem not exists in list
	//
	LNode<T> *current = head_->next_;
	int index = 0;

	while (current != NULL)
	{
		if (current->element_ == elem)
		{
			return index;
		}
		current = current->next_;
		++index;
	}
	return -1;
}

template<class T>
void LinkList<T>::erase(int index)
{
	// delete the element whose index is 'index'
	CheckIndex(index);

	// valid index, locate node with element ot delete
	LNode<T> *d = NULL;
	LNode<T> *p = head_;
	int i = 0;
	
	while (p->next_ && i < index)
	{
		p = p->next_;
		i++;
	}
	if (!p->next_ || i > index)
	{
		return;
	}
	d = p->next_;
	p->next_ = d->next_;
	delete d;
	d = NULL;
	size_--;
}

template<class T>
void LinkList<T>::insert(int index, const T &elem)
{
	// insert elem so that its index is 'index'
	if (index < 0 || index > size_)
	{
		// invalid index
		ostringstream s;
		s << "index = " << index << " size = " << size_;
		throw IllegalIndex(s.str());
	}

	LNode<T> *p = head_;
	for (int i = 0; p && i < index; ++i)
	{
		p = p->next_;
	}
	// insert after p
	LNode<T> *s = new LNode<T>(elem);
	s->next_ = p->next_;
	p->next_ = s;
	++size_;
}

template<class T>
void LinkList<T>::output(ostream &out) const
{
	// put the list into the stream out.
	for (LNode<T> *p = head_->next_;
					   p != NULL;
					   p = p->next_)
	{
		out << p->element_ << "	";
	}
}

template<class T>
void LinkList<T>::Reverse()
{
	LNode<T> *pre = NULL;
	LNode<T> *cur = head_->next_;
	
	while (cur != NULL)
	{
		LNode<T> *post = cur->next_;
		if (post == NULL)
		{
			head_->next_ = cur;
			cur->next_ = pre;
			return;
		}
		cur->next_ = pre;
		pre = cur;
		cur = post;
	}
	head_->next_ = pre;
}

template<class T>
void LinkList<T>::BinSort(int range)
{// 按分数排序
	assert(range > 0);

	int b; // 箱子索引号
	LNode<T> **bottom, **top;
	// 初始化箱子
	bottom = new LNode<T> *[range + 1];
	top = new LNode<T> *[range + 1];
	for (b = 0; b <= range; ++b)
	{
		bottom[b] = 0;
	}
	// 把结点分配到对应的箱子中
	for (LNode<T> *p = head_->next_; p != NULL; p = p->next_)
	{
		b = p->element_;
		if (bottom[b] == NULL)
		{
			bottom[b] = top[b] = p;
		}
		else
		{
			top[b]->next_ = p;
			top[b] = p;
		}
	}
	// 收集箱子形成排序链表
	LNode<T> *y = NULL;
	for (b = 0; b <= range; ++b)
	{
		if (bottom[b] != NULL)
		{
			if (y == NULL) // 第一个非空箱子
			{
				head_->next_ = bottom[b];
			}
			else
			{
				y->next_ = bottom[b];
			}
			y = top[b];
		}
	}
	if (y != NULL)
	{
		y->next_ = NULL;
	}

	delete []bottom;
	delete []top;
}

template<class T>
void LinkList<T>::BinSort(int range, int(*value)(T &x))
{
	assert(range > 0);

	int b; // 箱子索引号
	LNode<T> **bottom, **top;
	// 初始化箱子
	bottom = new LNode<T> *[range + 1];
	top = new LNode<T> *[range + 1];
	for (b = 0; b <= range; ++b)
	{
		bottom[b] = 0;
	}
	// 把结点分配到对应的箱子中
	for (LNode<T> *p = head_->next_; p != NULL; p = p->next_)
	{
		b = value(p->element_);
		if (bottom[b] == NULL)
		{
			bottom[b] = top[b] = p;
		}
		else
		{
			top[b]->next_ = p;
			top[b] = p;
		}
	}
	// 收集箱子形成排序链表
	LNode<T> *y = NULL;
	for (b = 0; b <= range; ++b)
	{
		if (bottom[b] != NULL)
		{
			if (y == NULL) // 第一个非空箱子
			{
				head_->next_ = bottom[b];
			}
			else
			{
				y->next_ = bottom[b];
			}
			y = top[b];
		}
	}
	if (y != NULL)
	{
		y->next_ = NULL;
	}

	delete []bottom;
	delete []top;

}

// overload <<
template<class T>
ostream &operator << (ostream &out, const LinkList<T> &x)
{
	x.output(out);
	return out;
}


} // namespace base
