#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void convert (float number)
{  
	int intNum = number; //truncate decimal part
	int decNum = 0;
	int count = 0; //counts number of loops
	int lastBit = 0;  //holds the last %2 held
	int sign;
	bool done = false;
	
	if (intNum < 0) //if it is a negative number assign appropriate sign bit
	{
		sign = 1;
		intNum -= intNum * 2;   //convert to positive number
	}
	else
		sign = 0;
		
	cout<<sign;  //first bit is the sign bit
	
	int temp = intNum;
	while(done == false)
	{
		//we are building the bits from left to right below
		if(temp == 1 || count == lastBit - 1) //makes loop stop at the next to last binary conversion, which is right to left when done on paper.
		{
			cout<<temp%2;
			lastBit = count;
			count = 0;
			if(temp == intNum / 2) //end loop if when it get back to the first conversion
			{
				cout<<intNum % 2;
				done = true;
			}				
			temp = intNum;
		}
		
		temp = temp / 2;
		count ++;
	}
}

int main()
{
	float original = -112.12783;
	convert(original);
	
	return 0;
}
