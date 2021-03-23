#include<iostream>
#include<algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if(!head) return head;
    // head表示顺序的头指针 revtile逆序的尾指针
    ListNode *revhead= head;
    head = head->next;
    revhead->next = nullptr;
    while(head){
        ListNode *tmp = head;
        head = head->next;
        tmp->next = revhead;
        revhead = tmp;
    }
    return revhead;
}

int main(){
    ListNode *a = new ListNode(1,new ListNode(2,new ListNode(3)));
    // a->val = 1;
    // a->next = b;
    // b->val =  2;
    // b->next = c;
    // c->val = 23;
    // c->next = nullptr;
    reverseList(a);

}