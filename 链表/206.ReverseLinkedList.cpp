#include<iostream>
#include<algorithm>
using namespace std;
// HOT
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// v1 自己的写法有点乱 
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
// 迭代形式
ListNode* reverseList(ListNode* head){
    ListNode *prev = nullptr,*tmp;
    while(head){
        tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }
    return prev;
}
// 递归形式
ListNode* reverseList(ListNode* head,ListNode* prev=nullptr){
    ListNode *tmp;
    if(!head) return prev;
    tmp = head->next;
    head->next = prev;
    return reverseList(tmp,head);
}

int main(){
    ListNode *a = new ListNode(1,new ListNode(2,new ListNode(3)));
    // reverseList(a);

}