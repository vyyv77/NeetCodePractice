#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> indices;
        for(int i = 0 ; i < nums.size(); i++) {
        	int complement = target - nums[i];
        	for(int j = i + 1 ; j < nums.size(); j++) {
        		if(nums[j] == complement) {
        			indices.push_back(i);
        			indices.push_back(j);
        			break;
        		} else {
        			continue;
        		}
        	}
        	if(indices.size() != 0) break;
        }
        return indices;
    }
};


int main(void) {
	return 0;
}