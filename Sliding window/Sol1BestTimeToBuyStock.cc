#include<iostream>
#include<vector>

using namespace std;


// Input: prices = [7,1,5,3,6,4]
// if we start at 7 next is 1 and is loss  but weknow that if there is any value in coming days greater than
// 7 then it will definitely be much greater than 1 hence we should buy at (day 2) 1, even if after 1 there are much smaller value that is say -2, then also we are better than if we buy at 7, then search forward,
// i.e. move the buy pointer to new minimum found

// whenever we found a new min buyday we go for a streak untill we encounter a new min, but we store previous streak value
// for eg [7,1,5,3,6,0,4], new streak will start at 0 earning profit of (4-0)4, while previous streak from 1 to 6 made profit of (6-1)5 , hence previous streak is answer
// we store the value of each streaks max



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfitVal = 0;				// always  initialize with zero or known relevant number
        int buyDay = 0;
        int sellDay =  buyDay+1;

        for ( ; sellDay < prices.size(); ) {
        	if(prices[sellDay] < prices[buyDay]) {  // if new minimum found , start a new streak
        		buyDay = sellDay;
        		sellDay++;
        	} else if( prices[sellDay] >= prices[buyDay]) {     // in current streak finding max profit 
        		int currval = prices[sellDay] - prices[buyDay];	// maxProfitVal stores max of current streak also max found in all of the previous streakes
                cout <<  currval << " " ;

        		maxProfitVal = max(maxProfitVal, currval);
                cout<< maxProfitVal << " " << endl;
        		sellDay++;
        	} 

        	
        }

        return maxProfitVal;
    }
};

int main(void) {
	return 0;
}