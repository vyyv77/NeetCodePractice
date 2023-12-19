#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),  nums.end());
        unordered_set<int> previouslyOccured;
        for(auto & n : nums) {
            cout << n << ", " ;
        }
        cout << endl;

        int allzeroes = 1;
        for(auto & n : nums) {
            if(n != 0) {
                allzeroes = 0;
            } 
        }
        if (allzeroes) {
            result.push_back({0,0,0});
            return result;
        }

        // target = 0
        
        for(int i = 0; i < nums.size(); i++) {

            // if (previouslyOccured.find(nums[i]) != previouslyOccured.end()) { 
            //     continue;
            // } else {
            //     previouslyOccured.insert(nums[i]);
            // }

            int target = -nums[i];
            cout << target << " --> " ;
            int j = 0;
            int k = nums.size()-1;
            for ( ; j < k; ) {
                if(j == i) {j++; continue;}
                if(k == i) {k--; continue;}

                if(nums[j] + nums[k] == target) {
                    cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    sort(v.begin(), v.end());
                    if(find(result.begin(), result.end(), v) == result.end()) result.push_back(v);
                    j++;
                } else if (nums[j] + nums[k] < target) {
                    j++;
                } else {
                    k--;
                }

             }
        }

        for (auto & x : previouslyOccured) {
            cout << x << ", " ;
        }
        cout << endl;

        cout << "result ==> ";
        for(auto & v : result) {
            cout << " {";
            for(auto & n : v) {
                cout << n << ", ";
            }
            cout << "} ";
        }

        set<vector<int>> myresult{result.begin(), result.end()};
        result.assign(myresult.begin(), myresult.end());

        return result;
    }
};

int main(void) {
    Solution sol;
    vector<int> v = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    sol.threeSum(v);
	return 0;
}