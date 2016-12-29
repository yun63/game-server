/// =====================================================================================
/// 
///    @filename         :  node.h
/// 
///    @description      :  树型结构的定义及实现，主要涉及到二叉树的算法
/// 
/// -------------------------------------------------------------------------------------
///    @version          :  1.0
///    @created          :  2013年07月06日 01时40分30秒
///    @revision         :  none
///    @compiler         :  g++
/// 
///    @author           :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
///    @Company          :  
/// 
/// =====================================================================================

#ifndef  H_TREE_INC
#define  H_TREE_INC

// 前置声明
template <class T>
class BTnode;

/// 模板类友元函数声明

// 先序遍历
template <class T>
void preorder(BTnode<T> *t);

// 中序遍历
template <class T>
void inorder(BTnode<T> *t);

// 后序遍历
template <class T>
void postorder(BTnode<T> *t);

// 层序遍历
template <class T>
void levelorder(BTnode<T> *t);

// 二叉树结点定义
template<class T>
class BTnode
{
	public:
		BTnode() 
            : lchild_(NULL), rchild_(NULL) {}
		BTnode(const T &element) 
			: data_(element), lchild_(NULL), rchild_(NULL) {}
		BTnode(const T &element, BTnode *left, BTnode *right)
			: data_(element), lchild_(left), rchild_(right) {}

		T data() const 
        { 
            return data_; 
        }

		BTnode *lchild() const
        { 
            return lchild_; 
        }

		BTnode *rchild() const
        { 
            return rchild_;
        }

	protected:
		T 				data_;                 // 数据域
        BTnode<T>    *lchild_;                 // 左子树
        BTnode<T>    *rchild_;                 // 右子树
};
#endif   // ----- #ifndef TREE_INC  -----
