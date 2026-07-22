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
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         stack<int>s;
//         ListNode* temp=head;
//         while(temp!=nullptr){
//             s.push(temp->val);
//             temp=temp->next;
//         }
//         while(head!=nullptr){
//             int c=s.top();
//             s.pop();

//             if(head->val!=c){
//                 return false;
//             }
//             head=head->next;
//         }
//         return true;
        
//     }
// };


class Solution {
public:

    // reverse linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // compare two lists
    bool isIdentical(ListNode* a, ListNode* b) {
        while (a && b) {
            if (a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = reverseList(slow->next);
        slow->next = NULL;

        bool ans = isIdentical(head, head2);

        head2 = reverseList(head2);
        slow->next = head2;

        return ans;
    }
};
