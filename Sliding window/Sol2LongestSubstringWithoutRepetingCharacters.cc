#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

// both i and j will move,  if j sees repetition move i by 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 1) return 1;
        int maxLength = 0;
        unordered_set<char> myset{s[0]};

        int i = 0;
        int j = i+1;
        int count = 1;
        for( ; j < s.length() ; ) {
            cout << i << " " << j << endl;
            
        	if(myset.find(s[j]) == myset.end()|| i >= j) {
        	    myset.insert(s[j]);
        		j++;
                count++;
            	maxLength = max(maxLength, count);

                continue;
        	} else {
            	maxLength = max(maxLength, count);

                myset.erase(s[i]);
        		i++;
                count--;	
            }

            
        }

        return maxLength;
    }
};

int main(void) {
	Solution sol;
	int len = sol.lengthOfLongestSubstring("phwjwkew");
	cout << len << endl;
	return 0;
}