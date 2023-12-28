#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> temp;
        for( ; !digits.empty() ; ) {
        	if(digits.back() == 9) {
        		temp.push_back(0);
        		digits.pop_back();
        		if(digits.empty()) {
        			digits.push_back(1);
        			break;
        		}
        	} else {
        		digits.back() = digits.back() + 1;
        		break;
        	}
        }

        for(int n : temp) {
        	digits.push_back(n);
        }


        return digits;
    }
};

int main(void) {
	return 0;
}