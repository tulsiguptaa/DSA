#include <bits/stdc++.h>
using namespace std;

// -------------Singly Linked list---------------

// -------declaration using struct 
struct Node1{
    int data;
    Node1* next;
    Node1(int d,Node1* n){
        data = d;
        next = n;
    }
    Node1(int d){      // here we do not need to assign null again and again during creating an object
        data = d;
        next = nullptr;
    }
};

// --------------declaration using class
class Node{
    public:
    int data;
    Node* next;
    Node* child;       // for flattening problem
    Node* random;     // for clone problem
    Node(int d){
        data = d;
        next = nullptr;
        child = nullptr;
        random = nullptr;
    }
};

// ---------------convert array into linked list
Node* ArrayList(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// ------------traversal 
void traversal(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

// -----------length of linked list
void length(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp!=nullptr){
        temp = temp->next;
        cnt++;
    }
    cout<<"The length of the linked list is: "<<cnt;
}

// ----------search an element in linked list
void search(Node* head,int ele){
    Node* temp = head;
    while(temp!=nullptr){
        if(ele == temp->data){
            cout<<"Yes present";
            return;
        }
        temp = temp->next;
    }
    cout<<"Not found";
}

// ------------deletion from head
void deleteAtHead(Node* head){
    Node* temp = head;
    head = head->next;
    delete temp;
    traversal(head);
}

// ------------deletion at tail
void deleteAtTail(Node* head){
    if(head == nullptr || head->next == nullptr){
        return;
    }
    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    traversal(head);
}

// ------------deletion at given position
void deleteAtSpecific(Node* head,int pos){
    if(head == nullptr) return;
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    int cnt = 0;
    while(temp!= nullptr){
        cnt++;
        // this is same, but donot use previous
        // if(cnt+1 == pos){
        //     temp->next = temp->next->next;
        //     break;
        // }
        if(cnt == pos){
            prev->next = prev->next->next;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    traversal(head);
}

// ------------deleting the given value
void deleteByValue(Node* head,int val){
    if(head==nullptr) return;
    if(head->data == val){
        deleteAtHead(head);
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){
        // same
        // if(temp->next->data == val){
        //     temp->next = temp->next->next;
        //     break;
        // }
        if(temp->data == val){
            prev->next = prev->next->next;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    traversal(head);
}

// ----------insertion at head
void insertAtHead(Node* head,int val){
    Node* temp = new Node(val);
    temp->next = head;
    head = temp;
    traversal(head);
}

// ----------insertion at tail
void insertAtTail(Node* head,int val){
    Node* newNode = new Node(val);
    if(head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    traversal(head);
}

// ----------insertion at given position
void insertAtSpecific(Node* head,int val, int pos){
    Node* newNode = new Node(val);
    if(pos == 1 || head == nullptr){
        insertAtHead(head,val);
        return;
    }
    Node* temp = head;
    int cnt = 0;
    while(temp!= nullptr){
        cnt++;
        if(cnt+1 == pos){
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    traversal(head);
}

// ----------insertion element before the vlaue x
void insertBeforeValue(Node* head,int val, int before){
    if(head == nullptr) return;
    Node* newNode = new Node(val);
    if(head->data == before){
        insertAtHead(head,val);
        return;
    }
    Node* temp = head;
    while(temp->next!= nullptr){
        if(temp->next->data == before){
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    traversal(head);
}

// -----------doubly linked list

// -----------declaration using strcut
struct NodeD{
    int data;
    NodeD* next;
    NodeD* prev;
    NodeD(int d){
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

// -----------declaration using class
class Node_D{
    public:
    int data;
    Node_D* next;
    Node_D* prev;
    Node_D(int d){
        data = d;
        next = nullptr;
        prev = nullptr;
    }
};

// --------------convert array to doubly linked list
Node_D* ArrayDoubly(vector<int> &arr){
    if(arr.empty()) return nullptr;
    Node_D* head = new Node_D(arr[0]);
    Node_D* prev = head;
    for(int i=1;i<arr.size();i++){
        Node_D* temp = new Node_D(arr[i]);
        temp->prev = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// -----------traversing doubly linked list
void traversalDoubly(Node_D* head){
    if(head==nullptr) return;
    Node_D* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void traversalBackDoubly(Node_D* head){
    Node_D* temp = head;
    while(temp->next!= nullptr){
        temp = temp->next;
    }
    while(temp!=head){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
}
// ------------deleting the head
void deleteAtHeadDoubly(Node_D* head){
    if(head == nullptr || head->next == nullptr) return;
    Node_D* prev = head;
    head = head->next;
    head->prev = nullptr;
    prev->next = nullptr;
    delete prev;
    traversalDoubly(head);
}

// -------------deletion at tail
void deleteAtTailDoubly(Node_D* head){
    if(head == nullptr || head->next == nullptr) return;
    Node_D* temp = head;
    Node_D* prev = head;
    while(temp->next!=nullptr){
        prev = temp;
        temp = temp->next;
    }
    delete temp;
    prev->next = nullptr;
    traversalDoubly(head);    
}

// -------------deletion at specific -----------something is wrong in this which i unable to catch😔😓
void deleteAtSpecificDoubly(Node_D* head,int pos){
    if(head == nullptr) return;
    if(pos == 1){
        deleteAtHeadDoubly(head);
        return;
    }
    Node_D* temp = head;
    Node_D* prev = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == pos){
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            traversalDoubly(head);
            return;
        }
        if(temp->next == nullptr){
            deleteAtHeadDoubly(head);
        }
        prev = temp;
        temp = temp->next;
    }
}

void deleteAtSpecificDoubly_(Node_D* head,int pos){
    if(head == nullptr) return;
    Node_D* temp = head;
    Node_D* prev = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == pos) break;      /// this means the temp will point to the node which we have to delete
        prev = temp;
        temp = temp->next;
    }
    Node_D* back = temp->prev;
    Node_D* front = temp->next;
    if(back == nullptr && front == nullptr){
        return;
    }
    else if(back == nullptr){
        deleteAtHeadDoubly(head);
        return;
    }
    else if(front == nullptr){
        deleteAtTailDoubly(head);
        return;
    }
    else{
        back->next = front;
        front->prev = back;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }
    traversalDoubly(head);
}

// ------------deleting a node that is given by value
void deleteByValueDoubly(Node_D* head,int val){
    if(val == head->data){
        deleteAtHeadDoubly(head);
        return;
    }
    Node_D* temp = head;
    while(temp!=nullptr){
        // by the above method
        // if(temp->data == val){
        //     break;
        // }
        if (temp->data == val) {
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            }
            delete temp;
            traversalDoubly(head);
            return;
        }
        temp = temp->next;
    }
}

// ----------insertion at head
void insertAtHeadDoubly(Node_D* head,int val){
    Node_D* newNode = new Node_D(val);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    traversalDoubly(head);
}

// -----------insertion at tail
void insertAtTailDoubly(Node_D* head,int val){
    Node_D* temp = head;
    Node_D* newNode = new Node_D(val);
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    traversalDoubly(head);
}

// ----------insertion at specific
void insertAtSpecificDoubly(Node_D* head,int val,int pos){
    if(pos == 1){
        insertAtHeadDoubly(head,val);
        return;
    }
    Node_D* temp = head;
    Node_D* newNode = new Node_D(val);
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == pos){
            break;      //temp is pointing to the position where node has to add
        }
        temp = temp->next;
    }
    Node_D* back = temp->prev;
    back->next = newNode;
    temp->prev = newNode;
    newNode->prev = back;
    newNode->next = temp;
    traversalDoubly(head);
}

// -----------insert at given node
void insertBeforeValueDoubly(Node_D* head,int val,int before){
    if(head==nullptr) return;
    Node_D* temp = head;
    Node_D* newNode = new Node_D(val);
    if(head->data == before){
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
        traversalDoubly(head);
        return;
    }
    while(temp!=nullptr){
        if(temp->next->data == before){
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            traversalDoubly(head);
            return;
        }
        temp = temp->next;
    }
    traversalBackDoubly(head);
}

// ------------reverse a doubly linked list
void reverseDoubly(Node_D* head){
    Node_D* temp = head;
    stack<int> st;
    while(temp!= nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=nullptr){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    traversalDoubly(head);
}

// -------------reverse a doubly linked list using optimisation
void reverseDoubly_(Node_D* head){
    if(head==nullptr || head->next == nullptr){
        return;
    }
    Node_D* current = head;
    Node_D* last = nullptr;
    while(current!=nullptr){
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }
    head = last->prev;
    traversalDoubly(head);
}

// -----------------add two linked list in reverse order
Node* addTwoList(Node* head, Node* head1){
    Node* temp = head;
    Node* temp1 = head1;
    Node* dummy = new Node(-1);
    Node* current = dummy;
    int carry = 0;
    int sum = 0;
    while(temp!=nullptr || temp1!=nullptr){
          sum = carry;
          if(temp){
            sum = sum + temp->data;
          }
          if(temp1){
            sum = sum + temp1->data;
          }
          Node* newNode = new Node(sum%10);
          carry = sum/10;
          current->next = newNode;
          current = current->next;
          if(temp) temp = temp->next;
          if(temp1) temp1 = temp1->next;          
    }
    if(carry){
        Node* newNode = new Node(carry);
        current->next = newNode;
    }
    head = dummy->next;
    traversal(head);
}

// --------------odd and even link list
void oddEven(Node* head){
    Node* temp = head;
    Node* dummy = new Node(-1);
    Node* current = dummy;
    int cnt = 0;
    while(temp!=nullptr){
        cnt++;
        if(cnt%2==1){
            Node* newNode = new Node(temp->data);
            current->next = newNode;
            current = current->next;
        }
        temp = temp->next;
    }
    temp = head;
    cnt = 0;
    while(temp!=nullptr){
        cnt++;
        if(cnt%2==0){
            Node* newNode = new Node(temp->data);
            current->next = newNode;
            current = current->next;
        }
        temp = temp->next;
    }
    head = dummy->next;
    traversal(head);
}

// ------------odd even another method
void oddEven_(Node* head){
    if(head==nullptr || head->next == nullptr) return;
    Node* temp = head;
    queue<int> st;
    while(temp!=nullptr){
        st.push(temp->data);
        if(temp->next)temp = temp->next->next;
        else break;
    }
    temp = head->next;
    while(temp!=nullptr){
        st.push(temp->data);
        if (temp->next) temp = temp->next->next;
        else break;
    }
    temp = head;
    while(temp!=nullptr){
        temp->data = st.front();
        st.pop();
        temp = temp->next;
    }
    traversal(head);
}

// -------------odd even with optimisation
void oddEven__(Node* head ){
    if(head==nullptr || head->next==nullptr) return;
    Node* odd = head;  
    Node* even = head->next;
    Node* temp = even;
    while(odd!=nullptr && even!=nullptr){
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = temp;
    traversal(head);
}

// ------------sort the list having 0,1,2
void sort012(Node* head){
    Node* temp = head;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    while(temp!=nullptr){
        if(temp->data == 0) cnt1++;
        if(temp->data == 1) cnt2++;
        if(temp->data == 2) cnt3++;
        temp = temp->next;
    }
    temp = head;
    while(cnt1!=0){
        temp->data = 0;
        cnt1--;
        temp = temp->next;
    }
    while(cnt2!=0){
        temp->data = 1;
        cnt2--;
        temp = temp->next;
    }
    while(cnt3!=0){
        temp->data = 2;
        cnt3--;
        temp = temp->next;
    }
    traversal(head);    
}

// -------------sort the list haviing 0,1,2 optimise
void sort012_(Node* head){
    if(head==nullptr || head->next==nullptr) return;
    Node* temp = head;
    Node* dumy1 = new Node(-1); 
    Node* dumy2 = new Node(-1); 
    Node* dumy3 = new Node(-1); 
    Node* zero = dumy1;
    Node* one = dumy2;
    Node* two = dumy3;
    while(temp!=nullptr){
        if(temp->data == 0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(temp->data == 1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    zero->next = (dumy2->next)?dumy2->next:dumy3->next;
    one->next = dumy3->next;
    two->next = nullptr;
    head = dumy1->next;
    delete dumy1; delete dumy2; delete dumy3;
    traversal(head);
}

// --------------remove the nth node from end
void removeFromEnd(Node* head,int k){
    if(head == nullptr) return;
    Node* temp = head;
    int cnt = 0;
    while(temp!= nullptr){
        cnt++;
        temp = temp->next;
    }
    temp = head;
    if(cnt == k){
        head = head->next;
        traversal(head);
        return;
    }
    int res = cnt - k;
    while(temp!=nullptr){
        res--; 
        if(res == 0){
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
    traversal(head);
}

// -----------remove the nth node from end with optimisation sliglty not understand🥴
void removeFromEnd_(Node* head, int k){
    Node* fast = head;
    for(int i=0;i<k;i++){
        fast = fast->next;
    }
    if(fast == nullptr){
         head = head->next;
         traversal(head);
         return;
    }
    Node* slow = head;
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    traversal(head);
}

// -----------reverse a linked list
void reverseList(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp!=nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp != nullptr){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    traversal(head);
}

// ------------reverse a linked listvwith optimisaiton
void reverseList_(Node* head){
    if(head == nullptr || head->next == nullptr) return;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    head = prev;
    traversal(head);
}

// ----------reverse a linked list with recursion ---------amazing problem😶‍🌫️
Node* reverseList__(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* newHead = reverseList__(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

// ---------palindrome 
void palindrome(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp!=nullptr){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=nullptr){
        if(temp->data == st.top()){
            st.pop();
            temp = temp->next;
            continue;
        }
        else{
            return;
        }
    }
    cout<<"Palindrome";
}

// ---------palindrone with optimisation
void palindrome_(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseList__(slow->next);
    Node* first = head;
    Node* second = newHead; 
    while(second!=nullptr){
        if(first->data != second->data) {
            reverseList__(newHead);
            cout<<"Not";
            return;
        }
        first = first->next;
        second = second->next;
    } 
    reverseList__(newHead);
    cout<<"Palindrome";
}

// ----------add 1 to the linked list
void AddOne(Node* head){
    if(head == nullptr) return;  
    Node* newHead = reverseList__(head);
    Node* temp1 = newHead;
    int carry = 1;
    while(temp1!=nullptr){
        if(carry==0){
            break;
        }
        int sum = temp1->data + carry;
        temp1->data = (sum)%10;
        carry = sum/10;
        temp1 = temp1->next;
    }
    head = reverseList__(newHead);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    } 
    traversal(head);
}

// ------------add one to the linked list with recursion
int Helper(Node* head){
    if(head == nullptr){
        return 1;
    }
    int carry  = Helper(head->next);
    head->data = head->data + carry;
    if(head->data<10){
        return 0;
    }
    head->data = 0;
    return 1;
}
Node* AddOne_(Node* head){
    if(head==nullptr) return head;
    int carry = Helper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        head = newNode;
    }
    return head;
}

// -------------find the intersection point of linked list
Node* intersection(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    map<Node*, int> mpp;
    while(temp1!=nullptr){
        mpp[temp1] = 1;
        temp1 = temp1->next;
    }
    while(temp2!=nullptr){
        if(mpp.find(temp2)!=mpp.end()){
            return temp2;
        }
        temp2 = temp2->next;
    }
    return nullptr;
}

// -------------find the intersection point of linked list with optimisation
Node* collision(Node* temp1, Node* temp2, int d){
    while(d){
        d--;
        temp2 = temp2->next;
    }
    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}
Node* intersection_(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    int cnt1 = 0,cnt2 = 0;
    while(temp1!=nullptr){
        cnt1++;
        temp1 = temp1->next;
    }
    while(temp2!=nullptr){
        cnt2++;
        temp2 = temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    if(cnt1>cnt2){
        return collision(head1,head2,cnt1-cnt2);
    }
    else{
        return collision(head2,head1,cnt2-cnt1);
    }
} 

// -------------find the intersection point of linked list with optimisation
Node* intersection__(Node* head1,Node* head2){
    if(head1 == nullptr || head2 == nullptr) return nullptr;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == nullptr){
            temp1 = head2;
        }
        if(temp2 == nullptr){
            temp2 = head1;
        }
    }
    return temp1;
}

// ---------------middle of the linked list
Node* middle(Node* head){
    if(head == nullptr) return nullptr;
    Node* temp = head;
    int cnt = 0;
    while(temp!=nullptr){
        cnt++;
        temp = temp->next;
    }
    int mid = (cnt/2) +1;
    temp = head;
    while(temp!=nullptr){   
        mid--;
        if(mid == 0){
            break;
        }
        temp = temp->next;
    }
    return temp;
}

// ------------middle of node with optimisation - Tortoise and hare alg🐢
Node* middle_(Node* head){
    if(head == nullptr) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while(fast!= nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// -----------detect a loop in the linked list
bool loop(Node* head){
    Node* temp = head;
    map<Node*, int> mpp;
    while(temp!=nullptr){
        if(mpp.find(temp) != mpp.end()){
            return true;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

// ----------detect loop using tortoise and hare algo called (floyd's cycle detection)🚩 algo
bool loop_(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        if(slow == fast && slow!=head){        // because at starting both are at head or you can simply write this if function below after slow = slow->next that moves the slow then checks
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

// -------------find the length of the loop
void lengthLoop(Node* head){  
    Node* temp = head;
    map<Node*, int> mpp;
    int cnt = 0;
    while(temp!= nullptr){
        cnt++;
        if(mpp.find(temp) != mpp.end()){
            cnt = cnt - mpp[temp];
            cout<<"The length is: "<<cnt; 
            return;           
        }
        mpp[temp] = cnt;    // store the position (count) of each node
        temp = temp->next;
    }
    cout<<"The length is: 0";
}

// -------------find the length of the loop with optimisation
int findLength(Node* slow, Node* fast){
    int cnt = 1;
    fast = fast->next;
    while(slow!=fast){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}
int lengthLoop_(Node* head){
    Node* slow = head;
    Node* fast = head;
    int cnt = 0;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) return findLength(slow,fast);
    }
    return 0;
}

// --------------delete the middle node of the linked list
void deleteMiddle(Node* head){
    if(head == nullptr || head->next == nullptr) return;
    Node* temp = head;
    int cnt = 0;
    while(temp!=nullptr){
        cnt++;
        temp = temp->next;
    }
    int middle = (cnt/2);
    temp = head;
    while(temp!=nullptr){
        if(middle==1){
            break;
        }
        temp = temp->next;
        middle--;
    } 
    temp->next = temp->next->next;
    traversal(head);
} 

// ------------delete the middle node with floyd's algo
void deleteMiddle_(Node* head){
    if(head == nullptr || head->next == nullptr) return;
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->next == slow){
            break;
        }
        temp = temp->next;
    }
    temp->next = slow->next;
    traversal(head);
}

// ------------delete the middle node with tortoise and hare with sloght change
void deleteMiddle__(Node* head){
    if(head == nullptr || head->next == nullptr) return;
    Node* slow = head;
    Node* fast = head;
    fast = fast->next->next;       // move the fast one step so that the sloe will be one step back, donot need another variable to store value
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    traversal(head);
}

// --------------find starting point of the loop
Node* startingLoopPoint(Node* head){
    if(head == nullptr) return nullptr;
    Node* temp = head;
    map<Node*, int> mpp;
    while(temp!=nullptr){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return nullptr;
}

// -------------find the starting point of the loop using floyd's algo
Node* startingLoopPoint_(Node* head){
    if(head == nullptr) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

// ------------delete all the occurence of a key in DLL
void deleteAllOccurence(Node_D* head,int key){
    if(head==nullptr) return;
    Node_D* temp = head;
    while(temp!=nullptr){
        if(temp->data == key){
            if(temp == head){
                head = head->next;
                head->prev = nullptr;
            }
            if (temp->prev != nullptr) temp->prev->next = temp->next;
            if (temp->next != nullptr) temp->next->prev = temp->prev;
        }
        temp = temp->next;
    }
    traversalDoubly(head);
}

// ---------------find all the pairs with given sum in sorted DLL
void findPairs(Node_D* head, int sum){
    Node_D* temp1 = head;
    while(temp1!=nullptr){
        Node_D* temp2 = temp1->next;
        int res = 0;
        while(temp2!=nullptr && temp1->data + temp2->data<=sum){
            res = temp1->data + temp2->data;
            if(res == sum){
                cout<<"The pairs are: "<<temp1->data<<" and "<<temp2->data<<endl;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

// ---------------find all the pairs with given sum in sorted DLL with optimisation
void findPairs_(Node_D* head, int sum){
    if (head == nullptr) return;
    Node_D* temp = head; 
    Node_D* back = head;
    while(back->next!=nullptr){
        back = back->next;
    }
    while(temp!=back && back->next!=temp){
        if(temp->data + back->data == sum){
            cout<<"The pairs are: "<<temp->data<<" and "<<back->data<<endl;
            temp = temp->next;
            back = back->prev;
        }
        else if(temp->data + back->data > sum){
            back = back->prev;
        }
        else{
            temp = temp->next;
        }
    }
}

// ---------------remove duplicates from sorted DLL
void removeDuplicates(Node_D* head){
    if(head == nullptr || head->next == nullptr) return;
    Node_D* temp = head;
    while(temp!=nullptr && temp->next!=nullptr){
        Node_D* nextNode = temp->next;
        while(temp->data == nextNode->data && nextNode!=nullptr){
            Node_D* duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if(nextNode){
            nextNode->prev = temp;
        }
        temp = temp->next;
    }
    traversalDoubly(head);
}

// -------------reverse nodes in K-grp slight tricky🤕
Node_D* reverseDoubly__(Node_D* head){
    if(head==nullptr || head->next == nullptr){
        return head;
    }
    Node_D* current = head;
    Node_D* last = nullptr;
    while(current!=nullptr){
        last = current->prev;
        current->prev = current->next;
        current->next = last;
        current = current->prev;
    }
    head = last->prev;
    return head;
}
Node_D* getKNode(Node_D* temp, int k){
    k -= 1;
    while(temp!=nullptr && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}
void reverseKGroup(Node_D* head, int k){
    Node_D* temp = head;
    Node_D* back = nullptr;
    while(temp!=nullptr){
        Node_D* KNode = getKNode(temp,k);
        if(KNode ==nullptr){
            if(back) back->next = temp;
            break;
        }
        Node_D* nextNode = KNode->next;
        KNode->next = nullptr;
        reverseDoubly__(temp);
        if(temp == head) head = KNode;
        else back->next = KNode;
        back = temp;
        temp = nextNode;
    }
    traversalDoubly(head);
}

// ------------rotate a linked list by k
void rotateListK(Node* head, int k){
    if(head == nullptr  || head->next == nullptr || k == 0) return;
    Node* temp = head;
    Node* tail = head;
    int len = 1;
    while(tail->next!=nullptr){
        len++;
        tail = tail->next;
    }
    if(k%len == 0) return;
    k = k%len;
    tail->next = head;
    int steps = len - k;
    int cnt = 1;
    while(cnt<steps){
        temp = temp->next;
        cnt++;
    }
    head = temp->next;
    temp->next = nullptr;
    traversal(head);
}

// -------------merge two sorted array
Node* mergesorted(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    set<int> arr;
    while(temp1!=nullptr){
        arr.insert(temp1->data);
        temp1 = temp1->next;
    }
    while(temp2!=nullptr){
        arr.insert(temp2->data);
        temp2 = temp2->next;
    }
    Node* newList = nullptr;
    Node* tail = nullptr;
    while(!arr.empty()){
        auto curr = arr.begin();
        Node* newNode = new Node(*curr);
        if(newList==nullptr){
            newList = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        arr.erase(curr);
    }
    return newList;
}

// --------------merge two sorted linked list ----------i donot know what is issue in this,, this is completly correct😡
void mergesorted_(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data>=temp2->data){
            temp->next = temp2;
            temp2 = temp2->next;
        }
        else{
            temp->next = temp1;
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    if(temp1!=nullptr){
        temp->next = temp1;
    }
    else{
        temp->next = temp2;
    }
    Node* head = dummy->next;
    traversal(head);
}

// -------------flattening a linked list -------different problem🙂‍↕️
void flattening(Node* head){
    Node* temp = head;
    set<int> arr;
    while(temp!=nullptr){
        arr.insert(temp->data);
        Node* childNode = temp->child;
        while(childNode != nullptr){
            arr.insert(childNode->data);
            childNode = childNode->next;
        }
        temp = temp->next;
    }
    Node* newHead = nullptr;
    Node* tail = nullptr;
    while(!arr.empty()){
        auto curr = arr.begin();
        Node* newNode = new Node(*curr);
        if(newHead == nullptr){
            newHead = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        arr.erase(arr.begin());
    }    
    Node* current = newHead;
    while(current!=nullptr){
        cout << current->data << " ";
        current = current->next;
    }
}

// --------------flattening a linked list with optimisation -------different problem🙂‍↕️
Node* mergeList(Node* t1, Node* t2){
    Node* dummy = new Node(-1);
    Node* d = dummy;
    while(t1!=nullptr && t2!=nullptr){
        if(t1->data>=t2->data){
            d->child = t2;
            t2 = t2->child;  
        }
        else{
            d->child = t1;
            t1 = t1->child;  
        }
        d = d->child;
        d->next = nullptr;
    }
    if(t1) d->child = t1;
    else d->child = t2;
    return dummy->child;
}
Node* flattening_(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* mergeHead = flattening_(head->next);
    return mergeList(head,mergeHead);
}

// --------------merge k sorted list -----------good question🫡
void mergeKsorted(vector<Node*> head){
    vector<int> arr;
    for(int i=0;i<head.size();i++){
        Node* temp = head[i];
        while(temp!=nullptr){
            arr.push_back(temp->data);
            temp = temp->next;
        }
    }
    sort(arr.begin(),arr.end());
    Node* newHead = ArrayList(arr);
    traversal(newHead);
}

// ------------merge k sorted array using optimisation
void mergeKsorted_(vector<Node*> head){
    Node* first = head[0];
    for(int i=1;i<head.size();i++){
        first = mergesorted(first,head[i]);
    }
    traversal(first);
}

// -------------merge k sorted array using priority queue implemented using min heap ----slightly tough question😓 but code is more tough🥴
void mergeKsorted__(vector<Node*>head){
    priority_queue<pair<int, Node*>, vector<pair<int,Node*>>, greater<pair<int, Node*>>> pq;
    for(int i=0; i<head.size();i++){
        if(head[i]){
            pq.push({head[i]->data, head[i]});
        }
    }
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.second->next){
            pq.push({it.second->next->data, it.second->next});
        }
        temp->next = it.second;
        temp = temp->next;
    }
    traversal(dummy->next);
}

// ------------------sort a linked list
Node* sortLL(Node* head){
    Node* temp = head;
    vector<int> arr;
    while(temp!=nullptr){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(),arr.end());
    // return ArrayList(arr);     // or
    temp = head;
    for(int i=0;i<arr.size();i++){
        temp->data = arr[i];
        temp = temp->next;
    }
    return head;
}

// ----------------sort a linked list using merge sort------something is wrong----not printing output
Node* mergesorted__(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(temp1!=nullptr && temp2!=nullptr){
        if(temp1->data>=temp2->data){
            temp->next = temp2;
            temp2 = temp2->next;
        }
        else{
            temp->next = temp1;
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    if(temp1!=nullptr){
        temp->next = temp1;
    }
    else{
        temp->next = temp2;
    }
    return dummy->next;
}
Node* sortLL_(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* middle = middle_(head);
    Node* leftHead = head;
    Node* rightHead = middle->next;
    middle->next = nullptr;
    leftHead = sortLL_(leftHead);
    rightHead = sortLL_(rightHead);
    return mergesorted__(leftHead, rightHead);
}  

// --------------clone a linked list with random pointers
Node* clone(Node* head){
    if(head == nullptr) return nullptr;
    Node* temp = head;
    map<Node*, Node*> mpp;
    while(temp!=nullptr){
        Node* newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }  
    temp = head;
    while(temp!=nullptr){
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}

// ---------------clone a linked list with random pointers with optimisation
Node* clone_(Node* head){
    if(head == nullptr) return nullptr;
    Node* temp = head;
    // insert copy node in between
    while(temp!=nullptr){
        Node* copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;  
        temp = temp->next->next;
    } 
    // connect random pointers
    temp = head;
    while(temp!=nullptr){
        Node* copyNode = temp->next;
        if(temp->random){
            copyNode->random = temp->random->next;
        }
        else{
            copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }
    temp = head;
    Node* dummy = new Node(-1);
    Node* res = dummy;
    while(temp!=nullptr){
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next; 
    }
    return dummy->next;
}

// --------------browser history - a real world question
class Node_Browser{
    public:
    string url;
    Node_Browser* prev;
    Node_Browser* next;
    Node_Browser(string u){
        url = u;
        prev = nullptr;
        next = nullptr;
    }
};
class Browser{
    public:
    Node_Browser* current;
    Browser(string homePage){
        current = new Node_Browser(homePage);
    }
    void visit(string url){
        Node_Browser* newPage = new Node_Browser(url);
        current->next = newPage;
        newPage->prev = current;
        current = newPage;
    }
    string back(){
            if(current->prev){
                current = current->prev;
            }
            else{
                cout << "Already at the oldest page.\n";
            }
    }
    string forward(){
            if(current->next){
                current = current->next;
            }
            else{
                 cout << "Already at the latest page.\n";
            }
    }
    void currentPage(){
        cout<<"Current Page: "<<current->url<<endl;
    }
};

 
int main(){
    vector<int> arr = {28,4,5,7,8};
    // creating object without using new and pointer, memory location - stack 
    // Node1 y = Node1(10,nullptr);   // this is also a correct way of doing that
    // cout<<y.data<<endl;      // here we use dot operator to access data

    // creating objecr with new and pointer, memory location - heap
    // Node1* z = new Node1(10,nullptr);
    // cout<<z->data;       // here we use arrow operator as it is pointer

    //-----------class node
    Node* node1 = new Node(10);
    Node* node2 = new Node(2); 
    Node* node3 = new Node(30); 
    Node* node4 = new Node(4); 
    Node* node5 = new Node(5); 
    node1->next = node2; 
    node2->next = node3; 
    node3->next = node4; 
    node4->next = node5;
    node1->random = node4;       // for clone
    node2->random = node1;
    node3->random = node5;
    node4->random = node2;
    node5->random = node3;
    // node5->next = node4;      // for loop

    // -----------converting array to linked list
    // Node* head = ArrayList(arr);
    // cout<<head->data;


    // ------------traversal
    // traversal(node1);


    // ----------length of llinked list
    // length(node1);


    // ----------search an element
    // search(node1,30);


    // ------------deletion from head
    // deleteAtHead(node1);


    // ------------deletion from tail
    // deleteAtTail(node1);


    // -------------deletion at given position
    // int pos;
    // cout<<"Enter the position: ";
    // cin>>pos;
    // deleteAtSpecific(node1,pos);


    // -----------delete by given vlaue
    // int val;
    // cout<<"Enter the value to delete: ";
    // cin>>val;
    // deleteByValue(node1,val);


    // ------------insertion at head
    // int val;
    // cout<<"Enter the value to insert: ";
    // cin>>val;
    // insertAtHead(node1,val);


    // ------------insertion at tail
    // int val;
    // cout<<"Enter the value to insert: ";
    // cin>>val;
    // insertAtTail(node1,val);


    // -------------insertion at given position
    // int pos;
    // cout<<"Enter the position: ";
    // cin>>pos;
    // int val;
    // cout<<"Enter the value to insert: ";
    // cin>>val;
    // insertAtSpecific(node1,val,pos);


    // -----------insertion before given value
    // int val;
    // cout<<"Enter the value to insert: ";
    // cin>>val;
    // int before;
    // cout<<"Enter the value before: ";
    // cin>>before;
    // insertBeforeValue(node1,val,before);


    // --------------doubly linked list
    Node_D* first = new Node_D(1);
    Node_D* second = new Node_D(2);
    Node_D* third = new Node_D(3);
    Node_D* fourth = new Node_D(5);
    Node_D* fifth = new Node_D(9);
    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;

    // -------------convert array to doubly linked list
    // Node_D* head = ArrayDoubly(arr);
    // cout<<head->data<<" ";


    // -------------traversal in doubly linked list
    // traversalDoubly(head);


    // ------------traverse back
    // traversalBackDoubly(first);


    // -------------deletion at head
    // deleteAtHeadDoubly(first);

    
    // --------------deletion at tail
    // deleteAtTailDoubly(first);


    // -------------deletion at specific
    // int pos;
    // cout<<"Enter the position: ";
    // cin>>pos;
    // deleteAtSpecificDoubly(first,pos);


    // -------------deletion at specific another method
    // int pos;
    // cout<<"Enter the position: ";
    // cin>>pos;
    // deleteAtSpecificDoubly_(first,pos);
    

    // -----------deleting a node that is goven by value
    // int val;
    // cout<<"Enter the value to delete: ";
    // cin>>val;
    // deleteByValueDoubly(first,val);


    // ------------insertion at head
    // int val;
    // cout<<"Enter the value to insert: ";
    // cin>>val;
    // insertAtHeadDoubly(first,val);


    // ------------insertion at tail
    // int val;
    // cout<<"Enter the value to insert: ";
    // cin>>val;  
    // insertAtTailDoubly(first,val); 


    // ---------insertion at specific position
    // int val;
    // cout<<"Enter the value to insert: ";
    // cin>>val;
    // int pos;
    // cout<<"Enter the position: ";
    // cin>>pos;
    // insertAtSpecificDoubly(first,val,pos);


    // ------------insert at given node
    // int val;
    // cout<<"Enter the value to insert: ";
    // cin>>val;
    // int before;
    // cout<<"Enter the value before: ";
    // cin>>before;
    // insertBeforeValueDoubly(first,val,before);


    // ------------reverse a doubly linked list
    // reverseDoubly(first);


    // ------------reverse a doubly linked list with optimisaiton
    // reverseDoubly_(first);


    Node* node6 = new Node(11);
    Node* node7 = new Node(10); 
    Node* node8 = new Node(14); 
    Node* node9 = new Node(9); 
    Node* node10 = new Node(7); 
    node6->next = node7; 
    node7->next = node8; 
    node8->next = node9; 
    node9->next = node10;

    // ----------add two linked list
    // addTwoList(node1,node6);


    // ----------odd and even 
    // oddEven(node1);


    // ----------odd and even antoher method
    // oddEven_(node1);


    // ----------odd and even with optimisation
    // oddEven__(node1);


    // -----------sort the list
    // sort012(node6);


    // -----------sort the list
    // sort012_(node6);


    // -----------remove a  node from end
    // int k;
    // cout<<"Enter the node number to delete: ";
    // cin>>k;
    // removeFromEnd(node1,k);


    // -----------remove a  node from end with optimisation
    // int k;
    // cout<<"Enter the node number to delete: ";
    // cin>>k;
    // removeFromEnd_(node1,k);


    // ---------reverse the list
    // reverseList(node1);


    // ---------reverse the list with optimisation
    // reverseList_(node1);


    // ---------reverse the list using recursion
    // Node* head = reverseList__(node1);
    // traversal(head);


    // -----------palindrome
    // palindrome(node6);


    // -----------palindrome with optimisation
    // palindrome_(node6);


    // -----------add one to the list
    // AddOne(node6);


    // -----------add one to the list with optimsaiton
    // Node* head = AddOne_(node6);
    // traversal(head);


    // -----------intersection head of linked list
    // Node* head = intersection(node1,node6);
    // cout<<head;


    // -----------intersection head of linked list with optimisation
    // Node* head = intersection_(node1,node6);
    // cout<<head;


    // -----------intersection head of linked list with optimisation
    // Node* head = intersection__(node1,node6);
    // cout<<head;


    // -----------middle of the linked list
    // Node* mid = middle(node1);
    // cout<<mid->data;


    // ---------middle of the list using tortoise and hare algo
    // Node* mid = middle_(node1);
    // cout<<mid->data;


    // ----------detecting loop
    // cout<<loop(node1);


    // ----------detecting loop with optimisation
    // cout<<loop_(node1);


    // ---------length of the loop
    // lengthLoop(node1);


    // ---------length of the loop with optimisation
    // cout<<"The length is: "<<lengthLoop_(node1);


    // ----------delete the middle node
    // deleteMiddle(node1);

    
    // ----------delete the middle node with floyd's algo
    // deleteMiddle_(node1);


    // ----------delete the middle node with optimisation
    // deleteMiddle__(node1);


    // --------------find the starting point of the loop
    // Node* start = startingLoopPoint(node1);
    // cout<<"The starting point is: "<<start->data;


    // --------------find the starting point of the loop using floyd algo
    // Node* start = startingLoopPoint_(node1);
    // cout<<"The starting point is: "<<start->data;


    // ------------delete all the occurence of a key in DLL
    // int key;
    // cout<<"Enter the value of the key: ";
    // cin>>key;
    // deleteAllOccurence(first,key);


    // -----------find all the pairs with given sum
    // int sum;
    // cout<<"Enter the value of sum: ";
    // cin>>sum;
    // findPairs(first,sum);


    // -----------find all the pairs with given sum with optimisation
    // int sum;
    // cout<<"Enter the value of sum: ";
    // cin>>sum;
    // findPairs_(first,sum);


    // -------------remove duplicates from a sorted DLL
    // removeDuplicates(first);


    // ------------reverse nodes in k- grp
    // int k;
    // cout<<"Enter the value of k: ";
    // cin>>k;
    // reverseKGroup(first,k);


    // -----------rotate list by k 
    // int k;
    // cout<<"Enter the value of k: ";
    // cin>>k;
    // rotateListK(node1,k);


    // -------------merge two sorted linked list
    // Node* head1 = mergesorted(node1,node6);
    // traversal(head1);


    // -------------merge two sorted linked list with optimisation
    // mergesorted_(node1,node6);


    // ------------flattening a linked list
    node1->child = new Node(11);
    node2->child = new Node(80);
    node3->child = new Node(90);
    // flattening(node1);


    // ------------flattening a linked list with optimisation
    // Node* head = flattening_(node1);
    // Node* temp = head;
    // while(temp!=nullptr){
    //     cout<<temp->data<<" ";
    //     temp = temp->child;
    // }


    // ----------k array
    Node* l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(5);

    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);

    Node* l3 = new Node(2);
    l3->next = new Node(6);
    vector<Node*> head = {l1,l2,l3};


    // --------------merge k sorted array
    // mergeKsorted(head);


    // ---------------merge k sorted array with optimisation
    // mergeKsorted_(head);


    // ---------------merge k sorted array using priority queue
    // mergeKsorted__(head);


    // ----------------sort a linked list
    // Node* head1 = sortLL(node1);
    // traversal(head1);


    // ----------------sort a linked list using merge sort
    // Node* head1 = sortLL_(node1);
    // traversal(head1);


    // --------------clone a linked list
    // Node* head1 = clone(node1);
    // while(head1!=nullptr){
    //     cout<<head1->data<<"->"<<head1->random->data<<", ";
    //     head1 = head1->next;
    // }


    // --------------clone a linked list with optimisation
    // Node* head1 = clone_(node1);
    // while(head1!=nullptr){
    //     cout<<head1->data<<"->"<<head1->random->data<<", ";
    //     head1 = head1->next;
    // }


    // -----------browser history
    Browser bh("home.com");

    bh.currentPage();  
    bh.visit("page1.com");
    bh.visit("page2.com");
    bh.visit("page3.com");
    bh.currentPage(); 

    bh.back();
    bh.currentPage(); 

    bh.back();
    bh.currentPage(); 

    bh.forward();
    bh.currentPage(); 
    
    bh.visit("newpage.com");  // forward history is cleared
    bh.currentPage();  // newpage.com

    bh.forward();


    return 0;
}