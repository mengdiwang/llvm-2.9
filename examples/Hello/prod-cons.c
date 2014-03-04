#include <stdio.h>

int test3(int b)
{
	return b;
}

int test4(int b)
{
	return b;
}

void test2(int b)
{
	if(b>0)
		test3(b);
	else
		test4(b);
}

int test(int a, int b)
{
	
	int c = 0;
	if(a==1)
	{
		a++;
		if(b==1)
		{
			test2(1);
		}
		else
		{
			test2(-1);
		}
		return c;
	}
	return c;
}


int main() {
  	int a;
	int b;
	klee_make_symbolic(&a, sizeof(a), "a");
	klee_make_symbolic(&b, sizeof(b), "b");
	//a = 1;
	//b = 3;
	if(a>b)
	{
		test(a, b);
	}
	else
	{
		test(b, a);
	}
	return 0;
}
