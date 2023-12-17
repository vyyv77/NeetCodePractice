#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> countsOfS;
        unordered_map<char, int> countsOfT;
        
        for(char c : s) {
        	 if(countsOfS.find(c) == countsOfS.end()){
        	 	countsOfS[c] = {1};
         	 } else {
         	 	countsOfS[c]++;
         	 }
        }

        for(char c : t) {
        	 if(countsOfT.find(c) == countsOfT.end()){
        	 	countsOfT[c] = {1};
         	 } else {
         	 	countsOfT[c]++;
         	 }
        }
        
        if(s.length() == t.length()) {
        	for (char c : s) {
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
};



int main(void) {
	return 0;
}