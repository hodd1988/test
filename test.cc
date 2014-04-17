#include <cstdlib>
#include <cassert>
#include <typeinfo>
#include <iostream>
#include <tr1/unordered_map>
#include <float.h>
#include <unistd.h>
#include <string>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <omp.h>

#include <complex>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iterator>
#include "t2.h"
//#include "testa.h"
//#include "testb.h"
using namespace std;
using std::tr1::unordered_map;
void fun(const char* cstr, char* str)
{
	cout << "cstr = " << cstr << endl;
	str[0] = '0';
	cout << "str = " << str << endl;
}
void sigChld(int signo)
{
	int status;
	pid_t pid;
	if((pid = waitpid(-1, &status, 0)) < 0)
	{
		perror("wait error: " );
	}
	else
	{
		printf("wait pid = %d \n", pid);
	}
}
const char* returnConstStr()
{
	const char* p = "he world1";
	return p;
}
class A
{
public:
	void funa(){
		cout << "funa" << endl;
	}
public:
	int aval;
};
class B
{
private:
	int a;
};
class C: public B
{
	enum
	{
		c1 = 0,
		c2,
		c3,
		c4,
		c5
	};
};
int main()
{
	cout << "sizeof a = " << sizeof(a) << endl;
	return 0;
}

