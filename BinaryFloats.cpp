#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void convert (float number)
{	
	int intNum = number; //truncate decimal part
	float decNum = 0;     //truncate integer part to leave decimal part
	int loopCount = 0; 	 //counts number of loops for INT conversion
	int bitCount = 0;   	//counts the number of bit used for integer conversion
	int exponent = 0; 	//will be calculated by the largest count number
	int lastBit = 0;  		//holds the last %2 held
	int sign;
	int remainder;  		//remainder for decimal to binary conversion
	bool done = false; 	//while loop is false
	
	//==========================================
	//Get the Sign bit
	//==========================================
	if (intNum < 0)                          //if it is a negative number sign bit equals 1
	{
		sign = 1;
		intNum -= intNum * 2;            //convert to positive number for converting
		decNum -= (number + intNum); //store positive decimal part
	}
	else
	{
		sign = 0;
		decNum = (number - intNum); //store decimal part
    }	
	
	cout<<sign;                            //first bit is the sign bit
	
	//==========================================
	//convert INTEGER part to binary
	//==========================================
	int temp = intNum;
	while (done == false)
	{
		//we are building the bits from left to right below
		if (temp == 1 || loopCount == lastBit - 1) //makes loop stop at the next to last binary conversion, which is right to left when done on paper.
		{
			cout<< temp % 2;
			bitCount++;
			lastBit = loopCount;
			loopCount = 0;
			
			if (temp == intNum / 2)               //end loop if when it get back to the first conversion
			{
				cout<< intNum % 2;
				bitCount++;
				done = true;
			}
			
			temp = intNum;
		}
		
		temp = temp / 2;
		loopCount ++;
	}

	//==========================================
	//Calculate EXPONENT and convert to binary
	//==========================================
	
	//==========================================
	//convert DECIMAL part to binary
	//==========================================
	
	for(int i = 1; i <= (23 - bitCount); i++)
	{
		remainder = decNum * 2;
		cout<<remainder;
		decNum = (decNum * 2) - remainder;
	}
}
int main()
{
	float original = 112.12783;
	convert(original);
	
	return 0;
}
