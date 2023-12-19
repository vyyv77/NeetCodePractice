#include<iostream>
#include<vector>

using namespace std;

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//        vector<int> answer;
//        int totalProduct = 1;
//        int numberOfZeroes = 0;
//        for(int num : nums) {
//        	if (num != 0) {
//        		totalProduct *= num;
//        	} 
//        	if (num == 0) {
//        		numberOfZeroes += 1;
//        	}
//        } 
//        for(int num : nums) {
//        	if(num != 0) {
//        		if (numberOfZeroes == 0) {
//        			int productExceptSelfValue = totalProduct / num;
//        			answer.push_back(productExceptSelfValue);
//        		} else {
//        			answer.push_back(0);
//        		}
//        	} else {
//        		if(numberOfZeroes < 2){
//        			answer.push_back(totalProduct);
//        		} else {
//        			answer.push_back(0);
//        		}
//        	}
//        }
//        return answer;

//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         vector<int> answer;
         vector<int> prefixes;
         vector<int> suffixes;

         prefixes.push_back(1);
         for(int i = 1; i < nums.size(); i++) {
             int currPrefix = prefixes[i-1] * nums[i-1];
             prefixes.push_back(currPrefix);

         }

         suffixes.push_back(1);
         for(int i = nums.size() - 1; i > 0; i--) {
            int currSuffix = nums[i] * suffixes.back();
            suffixes.push_back(currSuffix);
         }

         for(int n : suffixes) {
            cout << n << " " ;
         }

         int length = nums.size();
         for(int i = 0; i < length; i++) {
            int currentProduct = prefixes[i] * suffixes[length-1-i];
            answer.push_back(currentProduct);
         }

         return answer;

    }
};


int main(void) {
	return 0;
}