
#ifndef  H_EXCEPTIONS_INC
#define  H_EXCEPTIONS_INC

#include <string>

using std::cout;
using std::endl;
using std::string;

// 参数非法异常
class IllegalParameterValue
{
	public:
		IllegalParameterValue(string msg = "Illegal parameter value")
		{ 
			message_ = msg; 
		}
		void OutputMessage( ) { cout << message_ << endl; }

	private:
		string message_;
};


// 输入异常
class IllegalInputData
{
	public:
		IllegalInputData(string msg = "Illegal data input")
		{
			message_ = msg;
		}
		void OutputMessage( ) { cout << message_ << endl; }
	private:
		string message_;
};

// 索引异常
class IllegalIndex
{
	public:
		IllegalIndex(string msg = "Illegal index")
		{
			message_ = msg;
		}
		void OutputMessage( ) { cout << message_ << endl; }
	private:
		string message_;
};

// Stack empty
class StackEmpty
{
	public:
		StackEmpty(string msg = "Invalid operation on empty stack")
		{
			message_ = msg;
		}
		void OutputMessage( ) { cout << message_ << endl; }
	private:
		string message_;
};

// Queue empty
class QueueEmpty
{
	public:
		QueueEmpty(string msg = "Invalid operation on empty stack")
		{
			message_ = msg;
		}
		void OutputMessage( ) { cout << message_ << endl; }
	private:
		string message_;
};

#endif   // ----- #ifndef EXCEPTIONS_INC  -----
