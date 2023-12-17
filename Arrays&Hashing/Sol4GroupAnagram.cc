#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	inline bool isAnagram(string s, string t) {
		if(s.length() == t.length()) {
	        unordered_map<char, int> countsOfS;
	        unordered_map<char, int> countsOfT;
	        for(const char& c : s) {
	        	 if(countsOfS.find(c) == countsOfS.end()){
	        	 	countsOfS[c] = {1};
	         	 } else {
	         	 	countsOfS[c]++;
	         	 }
	        }
	        for(const char& c : t) {
	        	 if(countsOfT.find(c) == countsOfT.end()){
	        	 	countsOfT[c] = {1};
	         	 } else {
	         	 	countsOfT[c]++;
	         	 }
	        }
	        
	        
        	for (const char& c : s) {
        		if(countsOfT.find(c) != countsOfT.end() && countsOfS[c] == countsOfT[c]) {
        			continue;
        		} else {
        			return false;
        		}
        	}
	        return true;
	        } else {
	        	return false;
	    }

    }
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> myGroupedAnagrams;
		for(int i = 0; i < strs.size(); i++) {
			if(strs[i] != "-"){
				string currentString = strs[i];
				strs[i] = "-";
				vector<string> currentAnagrams = {};
				currentAnagrams.emplace_back(currentString);
				for(int j = i + 1; j < strs.size(); j++) {
					if(strs[j] != "-" && isAnagram(currentString, strs[j])){
						currentAnagrams.emplace_back(strs[j]);
						strs[j] = "-";
					} else {
						continue;	
					}
				}
				myGroupedAnagrams.emplace_back(currentAnagrams);
			} else {
				continue;
			}
		}
		return myGroupedAnagrams;
	}
};



int main(void) {
	return 0;
}