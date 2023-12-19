#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;


// if width is decreasing then height of the smaller side should increase hence we shouldmove  the smaller side
// in hope for larger smaller side, so that width decrease can be compensated for by (smaller one's)height increase,
// ---> since area is determined by the smaller height

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAreaVal = 0;

        int i = 0;
        int j = height.size() - 1;
        for( ; i < j ; ) {
            int currarea = min(height[i], height[j]) * (j-i);
            cout << currarea << endl;
            maxAreaVal = max(maxAreaVal, currarea);
            cout << maxAreaVal << " ";
            if (height[j] < height[i]) {
                j--;
            } else if(height[j] > height[i]) {
                i++;
            } else {
                j--;
            }
        }
        return maxAreaVal;
    }
};

int main(void) {
	return 0;
}