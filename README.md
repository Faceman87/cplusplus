cplusplus
=========

Binary representation of a floating point number in C++

                            COUNT
112 % 2 = 0                   0
56  % 2 =  0                   1
28  % 2 =  0                   2
14  % 2 =  0                   3
7   % 2 =  1                   4
3   % 2 =  1                   5
1   % 2 =  1                   6

When we go through the conversion, we work top to bottom.
But the output needs to read from bottom to top.

each line we divide by 2 and store it into an INT, which leaves us with
the Whole number part, THEN take the modulus of that answer, to get the bit.

this is the basic formula everyone uses to convert INT to binary.

So the loop looks like this:
COUNT
0,1,2,3,4,5,6  print 1 % 2
0,1,2,3,4,5    print 3 % 2
0,1,2,3,4      print 7 % 2
0,1,2,3        print 14 % 2
0,1,2          print 28 % 2
0,1            print 56 % 2

if(temp == number / 2)  //which is 56

print 112 % 2

END LOOP
//
