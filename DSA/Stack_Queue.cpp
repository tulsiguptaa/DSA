#include <bits/stdc++.h>
using namespace std;

// -----------stack and queue-------------

// --------------implementation of stack using array
class Stack{
    public:
    int capacity;
    int top;
    int *arr;
    Stack(int c){
        this->top = -1;       
        arr = new int[c];
        this->capacity = c;
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
       return top==capacity-1;
    }
    int getTop() {
        if (isEmpty()) {
            cout << "Underflow: Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
    void push(int data) {
        if (isFull()) {
            cout << "Overflow: Stack is full" << endl;
            return;
        }
        top++;
        arr[top] = data;
        cout << data << " pushed to stack\n";
    }
    int pop() {
        if (isEmpty()) {
            cout << "Underflow: Stack is empty" << endl;
            return -1;
        }
        int val = arr[top];
        top--;
        cout << val << " popped from stack\n";
        return val;
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// ---------------implementation of queue using array
class Queue{
    public:
    int capacity;
    int front;
    int back;
    int size;
    int* arr;

    Queue(int c){
        capacity = c;
        front = 0;
        back = -1;
        size = 0;
        arr = new int[c];
    }
    void traverse() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= back; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
     void enqueue(int data) {
        if (isFull()) {
            cout << "Overflow (Queue is full)\n";
            return;
        }
        back++;
        arr[back] = data;
        size++;
        cout << data << " enqueued\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow (Queue is empty)\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        front++;
        size--;
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull(){
        return size == capacity;
    }
    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }
};
 
// --------------------implementation of stack using linked list
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = nullptr;
    }
};      
class Stack1{
    public: 
    Node* top;
    int size;
    public:
    Stack1(){
        top = nullptr;
        size = 0;
    }
    void push(int d){
        Node* newNode = new Node(d);
        newNode->next = top;
        top = newNode;
        size++;
        cout << d << " pushed to stack.\n"; 
    }
    void pop(){
        if (isEmpty()) {
            cout << "Underflow (Stack is empty).\n";
            return;
        }
        Node* temp = top;
        cout << temp->data << " popped from stack.\n";
        top = top->next;
        delete temp;
        size--;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void peek(){
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;  // Indicate empty stack
        }
        cout<<top->data;
    } 
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* temp = top;
        cout << "Stack elements (top to bottom): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }    
    int getSize() {
        return size;
    }
};

// -----------------implementation of queue using linked list
class Queue1{
    public:
    Node* back;
    Node* front;
    int size;
    Queue1(){
        back = nullptr;
        front = nullptr;
        size = 0;
    }
    void push(int d){
        Node* newNode = new Node(d);
        if(front == nullptr){
            front = back = newNode;
        }
        else{
            back->next = newNode;
            back = newNode;
        }
        size++;
    }
    void pop(){
        if(front == nullptr){
            cout<<"Underflow";
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
         if (front == nullptr) {
            back = nullptr;  // FIXED: Reset back if queue becomes empty
        }
    }
    void top(){
        if(front == nullptr){
            cout<<"No item";
            return;
        }
        cout << "Front element: " << front->data << endl;
    }
    bool isEmpty() {
        return size == 0;
    }
    int getSize() {
        return size;
    }
    void display() {
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// // -----------------stack using queue
// class Stack2{
//     public:
//     Queue1<int> q;
//     void push(int d){
//         int s = q.size();
//         q.push(d);
//         for(int i=1;i<s;i++){
//             q.push(q.top());
//             q.pop();
//         }
//     }
//     void pop(){
//         q.pop();
//     }
//     void top(){
//         cout<<q.top();
//     }
// };

// -------------------queue using stack 
// class Queue2{
//     public:
//     Stack1<int> st1;
//     Stack1<int> st2;
//     void push(int d){
//         st.push(d);
//         while(st1.size()){
//             st2.push(st1.top());
//             st1.pop();
//         }
//         st1.push();
//         while(st1.size()){
//             st1.push(st2.top());
//             st2.pop();
//         }
//     }
//     void top(){
//         st1.top();
//     }
//     void pop(){
//         st1.pop();
//     }
// };

// // -------------valid parentheses
void parentheses(string s){
    stack<char> st;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (st.empty()) {
                cout << "False";
                return;
            }
            char top = st.top();
            st.pop();
            if((s[i] == ')' && top!= '(') || (s[i] == ']' && top!='[') || (s[i] == '}' && top!= '{')){
                cout<< "False";
                return;
            }
        }
    }
    if (st.empty()) {
        cout << "True";
    } else {
        cout << "False";
    }
}
  
// ------------infix to postfix conversion
int priority(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3; // if you're using exponentiation
    return 0; // for non-operators or '('
}
string infixPostfix(string s){
    stack<char> st;
    int n = s.length();
    string ans = "";
    for(int i=0;i<n;i++){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans = ans + s[i];
        }
        else if( s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && priority(s[i])<= priority(st.top())){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans +=  st.top();
        st.pop();
    }
    return ans;
}

// --------------infix to prefix
string reverseStr(string s){
    int n = s.length();
    reverse(s.begin(), s.end());
    for(int i=0;i<n;i++){
        if(s[i] == '('){
            s[i] = ')';
        }
        if(s[i] == ')'){
            s[i] = '(';
        }
    }
    return s;
}
string infixPrefix(string s){
    s = reverseStr(s);
    stack<char> st;
    int n = s.length();
    string ans = "";
    for(int i=0;i<n;i++){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            ans = ans + s[i];
        }
        else if( s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(s[i] == '^'){
            while(!st.empty() && priority(s[i]) <= priority(st.top())){
                ans += st.top();
                st.pop();
              }
          }
          else{
            while(!st.empty() && priority(s[i]) < priority(st.top())){
                ans += st.top();
                st.pop();
              }
          }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans +=  st.top();
        st.pop();
    }

    ans = reverseStr(ans);
    return ans;
}

// -------------postfix to infix
string postfixInfix(string s){
    int n = s.length();
    stack<string> st;
    for(int i=0;i<n;i++){
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
           st.push(string(1, s[i]));
        }
        else{
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();
            string ans = '(' + second + s[i] + first + ')'; 
            st.push(ans);
        }
    }
    return st.top();
}

// ---------------prefix to infix
string prefixInfix(string s){
    stack<string> st;
    int n = s.length();
    for(int i=n-1;i>=0;i--){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();
            string ans = '(' + first + s[i] + second + ')';
            st.push(ans);
        }
    }
    return st.top();
}

// -------------postfix to prefix
string postfixPrefix(string s){
    stack<string> st;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();
            string ans = s[i] + second + first;
            st.push(ans);
        }
    }
    return st.top();
}

// -------------prefix to postfix
string prefixPostfix(string s){
    int n = s.length();
    stack<string> st;
    for(int i=n-1;i>=0;i--){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string first = st.top();
            st.pop();
            string second = st.top();
            st.pop();
            string ans = first + second + s[i];
            st.push(ans);
        }
    }
    return st.top();
}

// ------------implement min stack
class minStack{
    stack<pair<int, int>> st;
    public:
    void push(int val){
        if(st.empty()){
            st.push({val,val});
        }
        else{
            st.push({val,min(val,st.top().second)});
        }
    }
    void pop() {
        if (!st.empty())
            st.pop();
    }
    int getMin(){
        return st.top().second;
    }
    int top(){
        return st.top().first;
    }
};

// ------------implement min stack using optimisation -- great logic behind this intution
class minStack_{
    stack<int> st;
    int minElement = INT_MAX;
    public:
    void push(int x) {
        if (st.empty()) {
            minElement = x;
            st.push(x);
        } else {
            if (x >= minElement) {
                st.push(x);
            } else {
                // Push encoded value
                st.push((2 * x) - minElement);
                minElement = x;
            }
        }
    }
    void pop() {
        if (st.empty()) return;
        int top = st.top();
        st.pop();
        if (top < minElement) {
            // Retrieve previous minElement
            minElement = (2 * minElement) - top;
        }
    }
    int getMin(){
        return minElement;
    }
    int top() {
        if (st.empty()) return -1; 
        int top = st.top();
        return (top >= minElement) ? top : minElement;
    }
};

// ------------next greater element 
vector<int> nextGreater(int arr[], int n){
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

// ------------next greater element - monotonic stack (elements in specific order) - decreasing
vector<int> nextGreater_(int arr[], int n){
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

// ------------next greater element - for circular array
vector<int> nextGreater__(int arr[], int n){
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<(i+n);j++){
            int idx = j%n;
            if(arr[idx] > arr[i]){
                ans[i] = arr[idx];
                break;
            }
        }
    }
    return ans; 
}

// ------------next greater element - for circular array with optimisation - (decreasing slope)
vector<int> nextGreater___(int arr[], int n){
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=(2*n)-1;i>=0;i++){
        while(!st.empty() && st.top() <= arr[i%n]){
            st.pop();
        }
        if(i<n){
            ans[i] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i%n]);
    }
    return ans;
}

// --------------nearest smaller element
vector<int> previousSmaller(int arr[], int n){
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
}

// --------------nearest smaller element using optimisation (increasing slope)
vector<int> previousSmaller_(int arr[], int n){
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=arr[i]){
             st.pop();
        }
        if(!st.empty()){
            ans[i] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}

// ----------------trapping of rainwater - slight tricky 😵‍💫
int trappingRainwater(int arr[], int n){
    int prefixmax[n];
    prefixmax[0] = arr[0];
    for(int i=1;i<n;i++){
        prefixmax[i] = max(prefixmax[i-1], arr[i]);
    }
    int sufixmax[n];
    sufixmax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        sufixmax[i] = max(sufixmax[i+1], arr[i]);
    }
    int total = 0;
    for(int i=0;i<n;i++){
        int leftmax = prefixmax[i];
        int rightmax = sufixmax[i];
        if(arr[i]<leftmax && arr[i] < rightmax){
            total += min(leftmax, rightmax)-arr[i];
        }
    }
    return total;
}

// ----------------trapping of rainwater using optimisation- slight tricky 😵‍💫
int trappingRainwater_(int arr[], int n){
    int leftmax = 0;
    int rightmax = 0;
    int total = 0;
    int l = 0;
    int r = n-1;
    while(l<r){
        if(arr[l]<=arr[r]){
            if(leftmax>arr[l]){
                total += leftmax - arr[l];
            }
            else{
                leftmax = arr[l];
            }
            l = l+1;
        }
        else{
            if(rightmax > arr[r]){
                total += rightmax - arr[r];
            }
            else{
                rightmax = arr[r];
            }
            r = r-1;
        }
    }
    return total;
}

// --------------sum of subarray minimums
int subarraySumMin(int arr[], int n){
    int res = 0;
    for(int i=0;i<n;i++){
        int submin = arr[i];
        for(int j=i;j<n;j++){
                submin = min(arr[j], submin);
                res += submin;
        }
    }
    return res;
}

// --------------sum minimum of all subarray 
int subarraySumMin_(int arr[], int n){
    vector<int> prevSmaller(n);
    vector<int> nextSmaller(n);
    stack<int> st;
    const int MOD = 1e9 + 7;

    // Previous Smaller Element (Distance)
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        prevSmaller[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    // Clear stack
    while (!st.empty()) st.pop();
     // Next Smaller Element (Distance)
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        nextSmaller[i] = st.empty() ? n : st.top();
        st.push(i);
    }
     // Calculate result
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        long long left = i - prevSmaller[i];
        long long right = nextSmaller[i] - i;
        result = (result + (arr[i] * left * right) % MOD) % MOD;
    }
    return result ;
}


int main() {

    // ----------------built in function-----------
    // stack<int> st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // cout<<"The top element is "<<st.top()<<endl;
    // st.pop();
    // cout<<"The top element is "<<st.top()<<endl;
    // cout<<"Is stack empty "<<st.empty()<<endl;


    // ------------------built in function-------------
    // queue<int> qu;
    // qu.push(10);
    // qu.push(20);
    // qu.push(30);
    // qu.pop();
    // qu.push(40);
    // while(not qu.empty()){
    //     cout<<qu.front()<<" ";
    //     qu.pop();
    // }


    // ---------------stack using array
    // Stack s(5);
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.display();
    // s.pop();
    // s.display();
    // cout << "Top element is: " << s.getTop() << endl;


    // ---------------queue using array
    // Queue q(5);
    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // q.traverse();        
    // q.dequeue();            
    // q.traverse();          
    // cout << "Front element: " << q.frontElement() << endl;


    // ---------------stack using linked list
    // Stack1 s;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.display();
    // s.peek();
    // s.pop();
    // s.display();
    // s.pop();
    // s.pop();
    // s.pop();


    // ---------------queue using linked list
    // Queue1 q;
    // q.push(10);
    // q.push(20);
    // q.display();
    // q.top();    
    // q.pop();     
    // q.top();     
    // q.pop();
    // q.pop();


    // ----------valid parentheses
    // string input = "([)]";
    // parentheses(input);


    // ---------------infix to postfix 
    // string infix = "A*(B+C)";
    // cout << "Postfix: " << infixPostfix(infix) << endl;


    // --------------infix to prefix
    // string infix = "A*(B+C)";
    // cout << "Prefix: " << infixPrefix(infix) << endl;


    // ----------------postfix to infix
    // string postfix = "ab+c*";
    // cout << "Infix: " << postfixInfix(postfix) << endl;


    // --------------prefix to infix
    // string prefix = "*+AB-CD";
    // cout << prefixInfix(prefix) << endl;


    // ---------------postfix to prefix
    // string postfix = "AB+CD-*";
    // cout<< postfixPrefix(postfix)<<endl;


    // ----------------prefix to postfix
    // string prefix = "*+AB-CD";
    // cout << prefixPostfix(prefix) << endl;


    // -------------min stack
    // minStack ms;
    // ms.push(5);
    // ms.push(2);
    // ms.push(3);
    // ms.push(1);
    // cout << "Min: " << ms.getMin() << endl;
    // ms.pop();
    // cout << "Top: " << ms.top() << endl;
    // cout << "Min: " << ms.getMin() << endl; 


    // -------------min stack using optimisation
    // minStack_ ms;
    // ms.push(5);
    // ms.push(2);
    // ms.push(3);
    // ms.push(1);
    // cout << "Min: " << ms.getMin() << endl;
    // ms.pop();
    // cout << "Top: " << ms.top() << endl;
    // cout << "Min: " << ms.getMin() << endl; 


    // -------------next greater
    // int arr[] = {2, 1, 5, 3, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // vector<int> result = nextGreater(arr, n);
    // for (int val : result) cout << val << " ";


    // -------------next greater with optimisation
    // int arr[] = {2, 1, 5, 3, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // vector<int> result = nextGreater_(arr, n);
    // for (int val : result) cout << val << " ";


    // -------------next greater -- circular array
    // int arr[] = {2, 8, 5, 3, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // vector<int> result = nextGreater__(arr, n);
    // for (int val : result) cout << val << " ";


    // -------------next greater- circular array with optimisation
    // int arr[] = {2, 8, 5, 3, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // vector<int> result = nextGreater__(arr, n);
    // for (int val : result) cout << val << " ";


    // -------------previous smaller element
    // int arr[] = {2, 8, 5, 3, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // vector<int> result = previousSmaller(arr, n);
    // for (int val : result) cout << val << " ";


    // -------------previous smaller element using optimsation
    // int arr[] = {2, 8, 5, 3, 6};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // vector<int> result = previousSmaller_(arr, n);
    // for (int val : result) cout << val << " ";


    // ------------trapping rainwater
    // int arr[] = {3, 0, 2, 0, 4};
    // int n = 5;
    // cout << trappingRainwater(arr, n);


    // ------------trapping rainwater with optimisation
    // int arr[] = {3, 0, 2, 0, 4};
    // int n = 5;
    // cout << trappingRainwater_(arr, n);


    // --------------minimum of subarray sum
    // int arr[] = {3, 1, 2};
    // int n = 3;
    // cout<<subarraySumMin(arr,n);


    // --------------minimum of subarray sum with optimisation
    int arr[] = {3, 1, 2, 4};
    cout << "Sum of all minimums of subarrays = " << subarraySumMin_(arr,4);




    return 0;
}