// #####################################################################################
// 
//    @filename         :  linear_list.h
// 
//    @description      :  abstract class ListBase  
//
//    1	abstract data type specfication for linear list data structure
//
//    2	all methods are pure virtual functions
//
// 
// -------------------------------------------------------------------------------------
//    @version          :  1.0
//    @created          :  05/26/13 20:21:50
//    @revision         :  none
//    @compiler         :  g++
// 
//    @author           :  Lei Yunfei (leiyunfei), yunfei_lei@126.com
//    @Company          :  
// 
// #####################################################################################


#ifndef  H_CLINEAR_LIST_INC
#define  H_CLINEAR_LIST_INC

#include <iostream>

namespace base {


template <typename T>
class ListBase
{
	public:
		virtual ~ListBase() { };
		/**
		 * @brief  return true if list is empty
		 * @return 
		 */
		virtual bool empty() const = 0;      
		/**
		 * @brief  return number of elements in list
		 * @return  
		 */
		virtual int size() const = 0;
		/**
		 * @brief  return element whose index is 'index'
		 * @param  index
		 * @return  
		 */
		virtual T &get(int index) const = 0;
		/**
		 * @brief  return index of the first occurence of the element elem
		 * @param  elem
		 * @return  
		 */
		virtual int indexof(const T &elem) const = 0; 
		/**
		 * @brief  remove the element whose index is 'index'
		 * @param  index
		 */
		virtual void erase(int index) = 0;
		/**
		 * @brief  insert the element elem so that its index is 'index'
		 * @param  index
		 * @param  elem
		 */
		virtual void insert(int index, const T &elem) = 0;
		/**
		 * @brief  insert list into stream out
		 * @param  out
		 */
		virtual void output(std::ostream &out) const = 0;
};

} // namespace base

#endif   // ----- #ifndef CLINEAR_LIST_INC  -----
