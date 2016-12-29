/// =====================================================================================
/// 
///    @filename         :  double_linked_list.h
/// 
///    @description      :  双端链表的实现
///
/// -------------------------------------------------------------------------------------
///    @version          :  1.0
///    @created          :  2014年07月21日 11时57分02秒
///    @revision         :  none
///    @compiler         :  g++
///    @author           :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
///    @Company          :  
/// 
/// =====================================================================================

#ifndef  __DOUBLE_LINKED_LIST__H_
#define  __DOUBLE_LINKED_LIST__H_

#include "macros.h"

namespace base {

template <typename T>
class LinkNode
{
    public:
        LinkNode() : previous_(NULL), next_(NULL) {}
        LinkNode(LinkNode<T> *previous, LinkNode<T> *next)
            : previous_(previous), next_(next) {}

        /**
         * @brief  InsertBefore 在e结点之前插入this结点到链表中
         * @param  e
         */
        void InsertBefore(LinkNode<T> *e)
        {
            this->next_ = e;
            this->previous_ = e->previous_;
            e->previous_->next_ = this;
            e->previous_ = this;
        }

        /**
         * @brief  InsertAfter 在e结点之后插入this结点到链表中
         * @param  e
         */
        void InsertAfter(LinkNode<T> *e)
        {
            this->next_ = e->next_;
            this->previous_ = e;
            e->next_->previous_ = this;
            e->next_ = this;
        }

        /**
         * @brief  RemoveFromList 从链表中删除this结点
         */
        void RemoveFromList()
        {
            this->previous_->next_ = this->next_;
            this->next_->previous_ = this->previous_;
            this->next_ = NULL;
            this->previous_ = NULL;
        }

        LinkNode<T> *previous() const
        {
            return previous_;
        }

        LinkNode<T> *next() const
        {
            return next_;
        }

        const T *value() const
        {
            return static_cast<const T*>(this);
        }

    private:
        DISALLOW_COPY_AND_ASSIGN(LinkNode);

        LinkNode<T> *previous_;
        LinkNode<T> *next_;
};

template <typename T>
class DoubleList
{
    public:
        DoubleList() : root_(&root_, &root_) {}

        /**
         * @brief  Append Appends结点e到链表末尾
         * @param  e
         */
        void Append(LinkNode<T> *e)
        {
            e->InsertBefore(&root_);
        }

        LinkNode<T> *head() const
        {
            return root_.next();
        }

        LinkNode<T> *tail() const
        {
            return root_.previous();
        }

        const LinkNode<T> *end() const
        {
            return &root_;
        }

        bool empty() const 
        {
            return head() == end();
        }

    private:
        DISALLOW_COPY_AND_ASSIGN(DoubleList);

        LinkNode<T> root_;
};

} // namespace base

#endif   // ----- #ifndef __DOUBLE_LINKED_LIST__H_ -----
