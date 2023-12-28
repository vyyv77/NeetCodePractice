#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
    	bool isHappy = false;

    	string number = to_string(n);
    	int updatedNum = 0;
        unordered_set<int> setOfUpdatedNums;
    	for( ; ; ){
	        string s;
            cout << endl;

	    	for(char & c : number ){
	    		s += c;
                cout <<  "{" <<  s << ", " << c << "} ";

	    		int digit = stoi(s);
	    		updatedNum += pow(digit, 2);
                s.clear();
	    	}
            cout << endl;
            cout << updatedNum << " ";
            if(setOfUpdatedNums.find(updatedNum) != setOfUpdatedNums.end()) {
            	return false;
            } else {
            	setOfUpdatedNums.insert(updatedNum);
            }
	    	if(updatedNum == 1) return true;
	    	number = to_string(updatedNum);
            updatedNum = 0;
            cout << number << endl;
        }
        return isHappy;
    }
};


int main(void) {
	return 0;
}