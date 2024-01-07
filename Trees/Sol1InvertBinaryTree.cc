#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(root == nullptr) return root;
//         // if(root->left == nullptr || root->right == nullptr) {  // check not required if we do this check then we return and we don't traverse further path , when such further traversing is still possible 
//         //     TreeNode* temp = root->left;				// as only one of the left and right subtree is null , hence traversing either invertTree(rootLeft) or invertTree(rootRight) is still possible
//         //     root->left = root->right;
//         //     root->right = temp;
//         //     return root;
//         // }


//         TreeNode* rootLeft = root->left;		// in each stack frame we are storing the pointers then exchanging them in the same frame then calling inverttree with the new pointers as root
//         TreeNode* rootRight = root->right;

//         TreeNode* temp = root->left;		//  node remains at same position we just exchange what the pointer are pointing to
//         root->left = root->right;
//         root->right = temp;


//         invertTree(rootLeft);
//         invertTree(rootRight);
//         return root;    // not optional as it helps return from root and subtree roots functions
//     }
// };

// Recursion steps :
// 1.) condition when we have to terminate traversing, return from there 
// 2.) new input variables to start our traversing or manipulate variables or data in current stack frame beforenew search
//     new input is smaller subproblem of bigger input

// 3.) return from the intial/root function


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // if(root == nullptr) return root;

        // TreeNode* rootLeft = root->left;		
        // TreeNode* rootRight = root->right;

        // TreeNode* temp = root->left;	
        // root->left = root->right;
        // root->right = temp;
        
        stack<TreeNode*> treeStack;

        treeStack.push(root);

        for( ; !treeStack.empty() ; ) {      // for loop with stack can be replaced by recursive function

        	if(treeStack.top() == nullptr) {
                treeStack.pop();
                continue;}

        	TreeNode* aux = treeStack.top();
        	treeStack.pop();

        	TreeNode* rootLeft = aux->left;
        	TreeNode* rootRight = aux->right;

        	TreeNode* temp = aux->left;	// exchange the pointers and push onto the stack
        	aux->left = aux->right;
        	aux->right = temp;

        	treeStack.push(rootLeft);
        	treeStack.push(rootRight);
        }

        return root;
    }

};

int main(void) {


	return 0;
}