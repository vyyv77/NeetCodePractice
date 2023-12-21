#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
    	uint32_t numberOfOnes = 0;
    	uint32_t mask = 1;

    	for(int i = 0; i < 32 ; i++) {
    		if((n & mask) != 0) {
    			numberOfOnes++;
                cout  << "n ,  mask = " << n << ", " << mask << " <----->" << "(n & mask) = " << (n & mask) << endl;
                // if we put mask here  in case of 1101 and mask = 0010 i.e. second iteration we get n&mask = 0 and we don't enter if() and hence we don't get shift and again and again mask remains same 0010 after that
    		}
    		mask = mask << 1; 	// mask will be outside if() because whether we get 0 or any other value based on that we increase numberOfOnes
    							//but in both the cases for each iteration we will shift mask

    	}


        return numberOfOnes;
    }
};

int main(void) {
	return 0;
}