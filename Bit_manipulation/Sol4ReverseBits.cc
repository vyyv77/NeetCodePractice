#include<iostream>
#include<vector>

using namespace std;


// reversing 001101 --> 101100

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
     	uint32_t reversed = 0;
     	uint32_t mask = 1;

     	for(uint32_t i = 0; i < 32 ; i++) {
     		reversed = reversed << 1;         // first shift reversed value since if() should work on the new 0 added in the right
     									// shifting reversed after if() statement, reversed would get the same rightmost value in the new iteration and it will be or'ed in the if() statement
     									// hence every second iteration is correctly done but that also not on the right place 
     		if((n & mask) != 0){
     			reversed = reversed | 1;   // | or & or ^ or ~ are opertators the evaluated value need a variable to get stored otherwise value is just evaluated and destroyed not stored
     			// reversed | 1;			// hence nothing will happen in this case we have to store the evaluated value, reversed |= 1; 
     		}
            n = n >> 1;
            cout << "n : " << n << endl;
            cout << "   ---> reversed : " << reversed << endl;
            

     	}
     	return reversed;   
    }
};

int main(void) {
	return 0;
}