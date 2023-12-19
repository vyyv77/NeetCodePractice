#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>


using namespace std;

class Solution {
public:
    bool isValid(string s) {
        bool isvalid = true;
        stack<char> mystack;
        unordered_map<char, char> mymap;
        mymap['('] = ')';
        mymap['{'] = '}';
        mymap['['] = ']';

        mystack.push(s[0]);
        for(int i = 1 ; i < s.length() ; i++){
                if(mystack.empty()) {			// if one streak of parenthesis cmplete each other start again by pushing new one to stack
        		    mystack.push(s[i]);
                    continue;
				}
        		if(s[i] == mymap[mystack.top()]) {    // current streak is correct or not

        			mystack.pop();
                    continue;
        		} else {
                    mystack.push(s[i]);
                }
        	}

        if(mystack.empty() == false) isvalid = false;

        return isvalid;
    }
};

int main(void) {
	Solution sol;
	cout << sol.isValid("(){");
	return 0;
}