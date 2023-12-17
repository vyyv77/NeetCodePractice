#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniques;
        for(int num : nums) {
        	if(uniques.find(num) == uniques.end()){
        		uniques.insert(num);
        	} else {
        		return true;
        	}
        }
        return false;
    }
};


int main(void) {
	return 0;
}