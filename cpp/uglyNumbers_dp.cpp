// Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. 
// Given a number n, the task is to find n’th Ugly number.

// Examples:  
// Input  : n = 7
// Output : 8

// Input  : n = 10
// Output : 12

// Input  : n = 15
// Output : 24

// Input  : n = 150
// Output : 5832

#include <iostream>
using namespace std;

int maxDivide(int a, int b)
{
	while (a % b == 0)
		a = a / b;	
	return a;
}

int isUgly(int no)
{
	no = maxDivide(no, 2);
	no = maxDivide(no, 3);
	no = maxDivide(no, 5);
	return (no == 1) ? 1 : 0;
}

int getNthUglyNo(int n)
{
	int i = 1;
	int count = 1;
	while (n > count)
	{
		i++;
		if (isUgly(i))
			count++;
	}
	return i;
}


int main()
{

	unsigned no = getNthUglyNo(150);
	cout << "150th ugly no. is " << no;
return 0;
}

