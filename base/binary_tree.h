/// =====================================================================================
/// 
///    @filename         :  tree.h
/// 
///    @description      :  二叉树基类定义
/// 
/// -------------------------------------------------------------------------------------
///    @version          :  1.0
///    @created          :  2013年07月10日 01时34分39秒
///    @revision         :  none
///    @compiler         :  g++
/// 
///    @author           :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
///    @Company          :  
/// 
/// =====================================================================================

#ifndef  H_BINARY_TREE_INC
#define  H_BINARY_TREE_INC

#include <iostream>
#include <functional>
#include "node.h"
#include "queue.h"
#include "exceptions.h"

template<class T>
class TreeBase
{
	public:
		virtual ~Tree() {}
		/**
		 * @brief  empty 判断是否为空子树
		 * @return  
		 */
		virtual bool empty() const = 0;
		/**
		 * @brief  size 返回二叉树的结点数目
		 * @return  
		 */
		virtual int	 size() const = 0;
		/**
		 * @brief  PreOrder 二叉树的先序遍历
		 * @param  
		 */
		virtual void PreOrder(void (*)(T *)) = 0;
		/**
		 * @brief  InOrder 二叉树的中序遍历
		 * @param  
		 */
		virtual void InOrder(void (*)(T *)) = 0;
		/**
		 * @brief  PostOrder 二叉树的后序遍历
		 * @param  
		 */
		virtual void PostOrder(void (*)(T *)) = 0;
		/**
		 * @brief  LevelOrder 二叉树的层序遍历
		 * @param  
		 */
		virtual void LevelOrder(void (*)(T *)) = 0;
};


// 二叉树的定义及实现
template <class T>
class BTree : public TreeBase<BTnode<T> >
{
	public:
		BTree()
            :root_(NULL), size_(0){}
		~BTree() { erase(); }

		bool empty() const { return size_ == 0; }
		int size() const { return size_; }
		void erase();
		T *root() const;
		int GetHeight() const { return GetHeight(root_); }

		void MakeTree(const T &element, BTree<T> &, BTree<T> &);
		BTree<T> &RemoveLeftSubTree();
		BTree<T> &RemoveRightSubTree();

		void Preorder(void (*visit)(Bnode<T> *));
		void Inorder(void (*visit)(Bnode<T> *));
		void Postorder(void (*visit)(Bnode<T> *));
		void Levelorder(void (*visit)(Bnode<T> *));

		void PreOrderOutput();
		void InOrderOutput();
		void PostOrderOutput();

	protected:
		static void (*visit)(Bnode<T> *t);
		static void Preorder(Bnode<T> *t);
		static void Inorder(Bnode<T> *t);
		static void Postorder(Bnode<T> *t);
		static void CountNodes(Bnode<T> *t);
		static void Dispose(Bnode<T> *t);
		static void Output(Bnode<t> *t);
		static void AddToCount(Bnode<T> *t);
		static void GetHeight(Bnode<T> *t);

	protected:
		static int cout_;                       // 用于字树节点计数
		Bnode<T> *root_;
		int size_;
};

#endif   // ----- #ifndef BINARY_TREE_INC  -----
