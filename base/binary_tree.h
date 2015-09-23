/// =====================================================================================
/// 
///    @filename         :  binary_tree.h
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
#include "btnode.h"
#include "queue.h"
#include "booster.h"
#include "exceptions.h"

using namespace std;

template<class T>
class CBinaryTree
{
	public:
		virtual ~CBinaryTree() { }
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


/// ===========================================================================
///  @class      :  CLinkBinaryTree
///  @description:  二叉树的链式定义及实现
/// ===========================================================================
template<class T>
class CLinkBinaryTree : public CBinaryTree< CBTNode<T> >
{
	public:
		CLinkBinaryTree() { root_ = NULL, size_ = 0; }
		~CLinkBinaryTree() { erase(); }

		bool empty() const { return size_ == 0; }
		int size() const { return size_; }
		void erase();
		T *root() const;
		int height() const { return height(root_); }

		void MakeTree(const T &element, CLinkBinaryTree<T> &, CLinkBinaryTree<T> &);
		CLinkBinaryTree<T> &RemoveLeftSubTree();
		CLinkBinaryTree<T> &RemoveRightSubTree();

		void preorder(void (*visit)(CBTNode<T> *));
		void inorder(void (*visit)(CBTNode<T> *));
		void postorder(void (*visit)(CBTNode<T> *));
		void levelorder(void (*visit)(CBTNode<T> *));

		void PreOrderOutput();
		void InOrderOutput();
		void PostOrderOutput();

	protected:
		static void (*visit)(CBTNode<T> *t);
		static void preorder(CBTNode<T> *t);
		static void inorder(CBTNode<T> *t);
		static void postorder(CBTNode<T> *t);
		static void CountNodes(CBTNode<T> *t);
		static void dispose(CBTNode<T> *t);
		static void output(CBTNode<t> *t);
		static void AddToCount(CBTNode<T> *t);
		static void height(CBTNode<T> *t);

	protected:
		static int cout_;                       // 用于字树节点计数
		CBTNode<T> *root_;
		int size_;
};

#endif   // ----- #ifndef BINARY_TREE_INC  -----
