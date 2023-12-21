#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<cstdlib>    // for atoi()
#include<cctype> // isdigit()

using namespace std;

// ["4","13","5","/","+"] , reverse polish notation [(operand1), (operand2), (arithmetic operator)] 
// ===> (operand1) (arithmatic operator) (operand2)
//  (4 + (13 / 5)) = 6
// push till we encounter (two operands & one operator) triplet , which  is immidiately evaluatedand pushed onto stack 
 

class Solution {
public:
	bool isoperator(const string& s) {
        if(s.length() > 1 ) {return false;}
    	if(s == "+" || s == "-" || s == "*" || s == "/") {
    		return true;
    	}
    	return false;
    }

    int evalRPN(vector<string>& tokens) {
        int evaluatedValue;
        stack<string> mystack;


        int currVal = 0;
		for(int i = tokens.size()-1; i >= 0 ; i--) {
            cout << i << endl;
			if(i == 0 && mystack.empty()) {return stoi(tokens[0]);}

			if(isoperator(tokens[i]) == false && isoperator(mystack.top()) == false) {
				int operandFirst = stoi(tokens[i]);
				int operandSecond = stoi(mystack.top());
				mystack.pop();
				if(mystack.top() == "+" || mystack.top() == "-" || mystack.top() == "*" || mystack.top() == "/" ) {
					string c =  mystack.top();
					if(c == "+"){
						currVal = operandFirst + operandSecond;
					} else if(c == "-"){
						currVal = operandFirst - operandSecond;
					} else if(c == "*"){
						currVal = operandFirst * operandSecond;
					} else {
						currVal = operandFirst / operandSecond;
					}
                    cout << " i was here !!!  " << endl;

                    cout << operandFirst << c << operandSecond << " = " << currVal << " i : " << i<< endl;
					if(i == 0 && mystack.empty()) {evaluatedValue = currVal; break;}
                    cout << " i was here !!!  " << endl;
					mystack.pop();
					tokens[i] = to_string(currVal);
                    cout << "token[" << i << "]" << " = " << currVal << endl;
					i++;
                    cout << "after i++ " << i << endl;
				} else {
					mystack.push(to_string(operandSecond));
					mystack.push(to_string(operandFirst));
				}
			} else {
				mystack.push(tokens[i]);
			}

		}
        

        return evaluatedValue;
    }
};

int main(void) {
	return 0;
}