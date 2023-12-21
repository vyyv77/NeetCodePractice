#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(auto  n : nums) {
        	result ^= n;
        }
        return result;
    }
};


int main(void) {
	return 0;
}