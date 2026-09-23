#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        next = nullptr;
    }
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;
    vector<int> arr;
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;
    while(temp1!=nullptr){
        arr.push_back(temp1->val);
        temp1 = temp1->next;
    }
    while(temp2!=nullptr){
        arr.push_back(temp2->val);
        temp2 = temp2->next;
    }
    sort(arr.begin(), arr.end());
    ListNode* head =  new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i=1;i<arr.size();i++){
        ListNode* node = new ListNode(arr[i]);
        temp->next = node;
        temp = node;
    }
    return head;
}

//Optimal

ListNode* mergeTwoLists_(ListNode* list1, ListNode* list2){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp1 = list1;
    ListNode* temp2 = list2;
    ListNode* head = dummy;
    while(temp1!=nullptr && temp2 != nullptr){
        if(temp1->val >= temp2->val){
            head->next = temp2;
            head = temp2;
            temp2 = temp2->next;
        }
        else{
            head->next = temp1;
            head = temp1;
            temp1 = temp1->next;
        }
    }
    while(temp1!=nullptr){
        head->next = temp1;
        head = temp1;
        temp1 = temp1->next;
    }
    while(temp2!=nullptr){
        head->next = temp2;
        head = temp1;
        temp2 = temp2->next;
    }
    return dummy->next;
}


int main() {
    ListNode* head1 = new ListNode(10);
    head1->next = new ListNode(20);
    head1->next->next = new ListNode(40);

    ListNode* head2 = new ListNode(10);
    head2->next = new ListNode(30);
    head2->next->next = new ListNode(40);
    
    // ListNode* head = mergeTwoLists(head1, head2);
    // ListNode* temp = head;
    // while(temp!=nullptr){
    //     cout<<temp->val<<"->";
    //     temp = temp->next;
    // }

    // Optimal
    ListNode* head3 = mergeTwoLists_(head1, head2);
    ListNode* temp1 = head3;
    while(temp1!=nullptr){
        cout<<temp1->val<<"->";
        temp1 = temp1->next;
    }
    return 0;
}