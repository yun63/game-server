
#ifndef  H_EXCEPTIONS_INC
#define  H_EXCEPTIONS_INC

#include <string>

using namespace std;

// Illegal parameter value

class CIllegalParameterValue
{
	public:
		CIllegalParameterValue(string msg = "Illegal parameter value")
		{ 
			message_ = msg; 
		}
		void OutputMessage( ) { cout << message_ << endl; }

	private:
		string message_;
};


// Illegal input data
class CIllegalInputData
{
	public:
		CIllegalInputData(string msg = "Illegal data input")
		{
			message_ = msg;
		}
		void OutputMessage( ) { cout << message_ << endl; }
	private:
		string message_;
};

// Illegal index
class CIllegalIndex
{
	public:
		CIllegalIndex(string msg = "Illegal index")
		{
			message_ = msg;
		}
		void OutputMessage( ) { cout << message_ << endl; }
	private:
		string message_;
};

// Stack empty
class CStackEmpty
{
	public:
		CStackEmpty(string msg = "Invalid operation on empty stack")
		{
			message_ = msg;
		}
		void OutputMessage( ) { cout << message_ << endl; }
	private:
		string message_;
};

// Queue empty
class CSqueueEmpty
{
	public:
		CSqueueEmpty(string msg = "Invalid operation on empty stack")
		{
			message_ = msg;
		}
		void OutputMessage( ) { cout << message_ << endl; }
	private:
		string message_;
};

#endif   // ----- #ifndef EXCEPTIONS_INC  -----
