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
    		}
    		mask = mask << 1; 	
		}
        return numberOfOnes;
    }


    vector<int> countBits(int n) {
        vector<int> numberOf1s ;
        for(uint32_t i = 0; i <= n; i++) {
        	int currentNumberOf1s = hammingWeight(i);
        	numberOf1s.push_back(currentNumberOf1s);
        }
        return numberOf1s;
    }
};

int main(void) {
	return 0;
}