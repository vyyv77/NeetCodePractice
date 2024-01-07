#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;


// Approach 1 : generate all possibilities and filter out using valid parenthesis

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
                if(mystack.empty()) {			
        		    mystack.push(s[i]);
                    continue;
				}
        		if(s[i] == mymap[mystack.top()]) {    

        			mystack.pop();
                    continue;
        		} else {
                    mystack.push(s[i]);
                }
        	}

        if(mystack.empty() == false) isvalid = false;

        return isvalid;
    }



    vector<string> generateParenthesis(int n) {

        vector<string> possibleParenthes;
        int parenthesisLength = 2 * n;

        string open = "(";
        string close = ")";

        stack<string> currentstack;
        currentstack.push(open);
        currentstack.push(close);
        for ( ; !currentstack.empty() ; ){
        	string currentstring = "";

        	if(currentstack.top().length() >= parenthesisLength) {
        		possibleParenthes.push_back(currentstack.top());
        		currentstack.pop();
        		continue;
        	}
        	currentstring += currentstack.top();
        	currentstack.pop();
        	currentstack.push(currentstring + open);
        	currentstack.push(currentstring + close);


        }

        for (auto str : possibleParenthes) {
        	cout << str << ", " ;
        }
        cout << endl;

        vector<string> correctPossibleParenthesis;
        for (auto str : possibleParenthes) {
        	if(isValid(str)) {
        		correctPossibleParenthesis.push_back(str);
        	} else {
        		continue;
        	}
        }

        return correctPossibleParenthesis;
    }
};


// Out vector will be refrence because we don't want a copy but we want to change or add int the original vector 
// as copy would be destroyed when a function return
// as without "&" "Out" becomes a local variable 
// we may think curr can't be a refrence then the original string will be passed in  succesive calls not the new string created before calling the recursive function
// as after the lower function returns the upper function will not be able to get the dividing point
// where the branch bifurcates as that value is stored in curr in local variable of each function called 
// each function stack has a local "curr" which is used for milestone or point of division for new possibilites to be used 
// but it can be a reference because the 

void possiblilties (string& curr, vector<string>& Out, int limit) {      //void possiblilties (curr),  without type compiler thinks we are executing the function not declaring it
    string Nopen = "(";
    string Nclose = ")";
    string currOne = curr + Nopen;  // 1.) first edit the changes you  want to do
    string currTwo = curr + Nclose;

    cout << " --------> "  << curr << endl;

    if(currOne.length() >= limit) {     // 2.) then check for return condition
        Out.push_back(currOne);
        return ;
    }
    if(currTwo.length() >= limit) {
        Out.push_back(currTwo);
        return ;
    }
    possiblilties(currOne, Out, limit);     // 3.) then recursive call
    possiblilties(currTwo, Out, limit);
}




int  main(void) {

    int n = 3;
    int parenLength = 2 * n;
    vector<string> possibleOutcomes;
    string st = "";
    possiblilties(st, possibleOutcomes, parenLength);

    int numOfCount = 0;

    for (auto str :  possibleOutcomes) {
            cout << str << ", " ;
            numOfCount++;
        }
    cout << endl;
    
    cout  << numOfCount << endl; //  2^(n-1) leaves in the tree as each place has two possibilties and there are 6 places to fill
	return 0;
}