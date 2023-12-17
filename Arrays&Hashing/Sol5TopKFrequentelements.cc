#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> topKElements;
        map<int, int> countFrequency; 

        for(const int& num : nums) {
        	countFrequency[num]++;
        }

        int topk = k;
        for(int i = 0; i < topk; i++) {
        	int currmaxnum = 0;
        	int currmaxnumvalue = 0;
        	for(auto x : countFrequency){
        		if(x.second > currmaxnumvalue){
        			currmaxnum = x.first;
        			currmaxnumvalue = x.second;
        		} else {
        			continue;
        		}
        	}
        	countFrequency[currmaxnum] = 0;
        	topKElements.push_back(currmaxnum);

        }

        return topKElements;
    }
};

int main(void) {
	return 0;
}