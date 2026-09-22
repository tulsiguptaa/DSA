#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

// brute 
void reverse(Node* head){
    if(head == nullptr) return;
    Node* temp = head;
    vector<int> val;
    while(temp!=nullptr){
        val.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    int i = val.size() -1;
    while(temp!=nullptr){
         temp->data = val[i--];
         temp = temp->next;
    }
    
}

// optimal
Node* reverse_(Node* head){
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // reverse(head);
    head = reverse_(head);
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    return 0;
}