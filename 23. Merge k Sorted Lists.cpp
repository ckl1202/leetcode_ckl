#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

struct CompareListElement {
    bool operator ()(const ListNode* a, const ListNode* b) const
    {
        return (a->val > b->val);  //NOTE1： 用大于符号建立小堆
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode*> vecK;
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i] != NULL) {//NOTE2: 判断是否为NULL
                vecK.push_back(lists[i]);
            }
        }

        make_heap(vecK.begin(), vecK.end(), CompareListElement()); //NOTE3.1 comparator 要么全部使用，要么全部不使用
        while(!vecK.empty()) {
            tail->next = vecK.front();
            tail = tail->next;
            pop_heap(vecK.begin(), vecK.end(), CompareListElement()); //NOTE3.2 comparator 要么全部使用，要么全部不使用
            vecK.pop_back();
            if(tail->next != NULL) {
                vecK.push_back(tail->next);
                push_heap(vecK.begin(), vecK.end(), CompareListElement()); //NOTE3.3 comparator 要么全部使用，要么全部不使用
            }
        }
        return dummyHead->next;
    }
};

int main(){
    Solution s;
    vector<ListNode*> lists;
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(4);
    ListNode *p3 = new ListNode(7);
    p1->next = p2; p2->next = p3;
    lists.push_back(p1);
    p1 = new ListNode(2);
    p2 = new ListNode(5);
    p3 = new ListNode(8);
    p1->next = p2; p2->next = p3;
    lists.push_back(p1);
    p1 = new ListNode(3);
    p2 = new ListNode(6);
    p3 = new ListNode(9);
    p1->next = p2; p2 ->next = p3;
    lists.push_back(p1);
    ListNode *newHead = s.mergeKLists(lists);
    while (newHead != NULL){
        cout << newHead->val;
        newHead = newHead->next;
    }
    return 0;
}
