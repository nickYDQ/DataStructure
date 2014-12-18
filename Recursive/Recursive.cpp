#include<iostream>
using namespace std;

int print(int i)
{
	
	if (i == 0)
		return i;
	print(i - 1);
	return i;
}

int main()
{
	print(3);
	return 0;
}


