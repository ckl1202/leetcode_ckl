#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        while (l1 != NULL || l2 != NULL){
            ListNode *p;
            if (l1 == NULL){
                p = l2;
                l2 = l2->next;
            }
            else if (l2 == NULL){
                p = l1;
                l1 = l1->next;
            }
            else if (l1 != NULL && l2 != NULL){
                if (l1->val < l2->val){
                    p = l1;
                    l1 = l1->next;
                }
                else{
                    p = l2;
                    l2 = l2->next;
                }
            }
            ListNode *newNode = new ListNode(p->val);
            if (head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }
        }
        return head;
    }
};

int main(){
    ListNode *p11 = new ListNode(1);
    ListNode *p12 = new ListNode(2);
    ListNode *p13 = new ListNode(3);
    p11->next = p12; p12->next = p13;
    ListNode *p21 = new ListNode(4);
    ListNode *p22 = new ListNode(5);
    ListNode *p23 = new ListNode(6);
    p21->next = p22; p22->next = p23;
    Solution s;
    ListNode *newHead = s.mergeTwoLists(p11, p21);
    while (newHead != NULL){
        cout << newHead->val << ' ';
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}
