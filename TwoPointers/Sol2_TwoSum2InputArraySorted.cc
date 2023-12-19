#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;

        int j = numbers.size()-1;
        int i = 0;
        for( ; i < j ; ){
            cout << "i: " <<  i << " j : " << j << endl;
        	if(numbers[i] + numbers[j] == target) {
        		result.push_back(i+1);
        		result.push_back(j+1);
        		break;
        	} else if(numbers[i] + numbers[j] > target) {
        		j--;
        	} else {
        		i++;
        	}
            
        }
        return result;
    }
};

int main(void) {
	return 0;
}