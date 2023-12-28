#include<iostream>
#include<vector>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* reverseList(ListNode* head) {// head->next ===> (*head).next  ==> go to the struct inside struct get the next pointer
        if(head == nullptr) return head;
        if(head->next == nullptr) return head;
        if(head->next->next == nullptr) {
            ListNode* temp = head->next;
            head->next = nullptr;
            temp->next = head;
            head = temp;
            return head;    	// return otherwise next statements would run
        }
        ListNode* temp1 = head->next;
        ListNode*  temp2 = head->next->next;
        head->next = nullptr;
        for ( ; ; ){
        	temp1->next = head;      
        	head = temp1;
        	temp1 = temp2;

        	// if(temp2->next == nullptr) {
        	// 	temp1->next = head;     // temp1 is nullptr here we are trying to access its next
        	// 	head = temp1;
        	// 	break;
        	// }

        	if(temp2 == nullptr) { break; }
        	temp2 = temp2->next;

        }

        return head;
    }
};



int main(void) {
	return 0;
}