#include <iostream>
#include <bitset>
using namespace std;
int main()
{
    //9F hexadecimal is 1 Byte (8-bits) in size, 1 char holds 1 Byte.
    unsigned char byte = 0x9F;
	// C++ Bitsets give the programmer a set of bits as a data structure.
	// <8> is the number of bits you want in your data structure.
	// myByteBitSet is the name of the structure.
	// (byte) is optional and initializes your data structure with a value, in this case, the value 0x9F.
	bitset<8> myByteBitSet(byte);
	cout << myByteBitSet << endl;

	//Sets bit 5 to 1
	myByteBitSet.set(5);
	cout << myByteBitSet << endl;

	//Resets bit 5 to 0
	myByteBitSet.reset(5);
	cout << myByteBitSet << endl;

	//Sets all the bits to 1
	myByteBitSet.set();
	cout << myByteBitSet << endl;

	//Resets all the bits to 0
	myByteBitSet.reset();
	cout << myByteBitSet << endl;

	//test returns the bit at position specified
	cout << "Bit 2 = " << myByteBitSet.test(2) << endl;
return 0;
}
