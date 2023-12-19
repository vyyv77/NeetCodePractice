#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
    	if(s == " ") return true;
        bool result = false;
        string modified = "";
        for(char c : s){
        	if(isalnum(c)){
        		char x = tolower(c);
        		modified.push_back(x);
        	}
        }
        if(modified.length() == 1 || modified == "") return true;
        cout << modified << endl;
        int j = modified.length()-1;
        for(int i = 0; i < j; i++, j--) {
        	if(modified[i] == modified[j]) {
        		result = true;
        	} else {
        		result = false;
        		break;
        	}
        }
        return result;
    }
};

int main(void) {
	return 0;
}