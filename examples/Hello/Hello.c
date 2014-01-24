#include <stdio.h>

int test(int a)
{
	int b = 0;
	int c = 0;
	if(a==1)
	{
		b-=1;
		a++;
		if(b==1)
		{
			c = 2;
		}
		else
		{
			c = 0;
		}
	}
	else
	{
		b+=1;
		a++;
		if(b==1)
		{
			c = 2;
		}
		else
		{
			c = 0;
		}
	}
	return c;
}


int main() {
  	int a = 1;
	if(a>1)
	{
		test(a);
	}
	else
	{
		test(a+1);
  	}
	return 0;
}