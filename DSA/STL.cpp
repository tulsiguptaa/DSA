#include <bits/stdc++.h>
using namespace std;

// STL includes containers, algorithms, functions and iterators 

void pairContainer(){
    // pair of integers
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << endl;

    // pair of pairs
    pair<int ,pair<int, int>> p1 = {1, {2, 3}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << endl;

    // array of pairs
    pair<int, int> arr[] = {{1, 2}, {2, 3}, {3, 4}};
    cout<<arr[1].second<<endl;
    for(int i = 0; i < 3; i++){
        cout << arr[i].first << " " << arr[i].second << endl;
    }
}

void vector(){
    vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);

    // everytime the size is double like if we push 3 elements to the vector the size id 3 but capacity is 4 ,,it create the  double size
    v.capacity();
    v.emplace_back(7);    // same as push_back but faster

    vector<int> v1(4);   // 4 elements with value 0
    vector<int> v(5, 10);   // 5 elements with value 10

    vector<int> v2(v1);   // copy of v1
    cout<<v.at(2)<<endl;   // same as v[2]

}

void iterator(){
    vector<int> v = {1,2,3,4,5};
    vector<int>::iterator it = v.begin();   // points to first element memory address
    cout<<*it<<endl;    // dereferencing iterator

    vector<int>::iterator it1 = v.end();    // points to next to last element memory address
    vector<int>::iterator it2 = v.rend();    // points to before first element memory address
    vector<int>::iterator it3 = v.rbegin();    // points to last element memory address

    cout<<v.back()<<endl;   // last element

    for(vector<int>::iterator it = v.begin(); it!=v.end();it++){
        cout<<*it<<" ";
    }

    // simpler way to do this is   ,, it automatically assign according to the data type
    for(auto it = v.begin(); it!=v.end();it++){
        cout<<*it<<" ";
    }

    // using for-each loop
    for(auto it: v){
        cout<<it<<" ";
    }

    v.erase(v.begin()+2);    // erase 3rd element
    v.erase(v.begin()+1, v.begin()+3);    // erase 2nd and 3rd element 

    v.insert(v.begin()+2, 3);    // insert 3 at 3rd position
    v.insert(v.begin()+2, 3, 7);    // insert 3 elements of value 7 at 3rd position

    vector<int>copy(2, 10); 

    cout<<v.size()<<endl;    // size of vector
    v.pop_back();    // remove last element
    v.clear();    // remove all elements
    v.swap(v2);    // swap elements of v and copy
    v.empty();    // check if vector is empty

}

void list(){   // doubly linked list
    list<int> l = {1, 2, 3, 4, 5};
    l.push_back(6);
    l.push_front(0);
    l.emplace_back(7);    // same as push_back but faster
    l.emplace_front(-1);    // same as push_front but faster

}

void dequeue(){   // doubly ended queue
    deque<int> dq = {1, 2, 3, 4, 5};
    dq.push_back(6);
    dq.push_front(0);
    dq.emplace_back(7);    // same as push_back but faster
    dq.emplace_front(-1);    // same as push_front but faster

    dq.pop_back();
    dq.pop_front();
    dq.front();
    dq.back();
    dq.size();
    dq.empty();
}

void stack(){
    stack<int> s = {1, 2, 3, 4, 5
    };
    s.push(6);
    s.pop();
    s.top();
    s.size();
    s.empty();
}

void queue(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.front();
    q.back();
    q.size();
    q.empty();
}

void priorityQueue(){
    priority_queue<int> pq;    // max heap

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    cout<<pq.size()<<endl;
    cout<<pq.empty()<<endl;
}

// sort in increasing order and unique elements
void set(){
    set<int> s = {1, 2, 3, 4, 5};
    s.insert(6);
    s.erase(3);
    s.find(4);    // returns iterator to 4
    s.count(4);    // returns 1 if 4 is present else 0
    s.size();
    s.empty();
    s.clear();
}

void multiSet(){   // allows duplicate elements
    multiset<int> s = {1, 2, 3, 4, 5};
    s.insert(6);
    s.erase(3);   // removes all 3
    s.find(4);    // returns iterator to 4
    s.count(4);    // returns 1 if 4 is present else 0
    s.size();
    s.empty();
    s.clear();
} 

void unorderedSet(){
    unordered_set<int> s = {1, 2, 3, 4, 5};
    s.insert(6);
    s.erase(3);
    s.find(4);    // returns iterator to 4
    s.count(4);    // returns 1 if 4 is present else 0
    s.size();
    s.empty();
    s.clear(); 
}

void map(){    // key-value pair in sorted mannar
    map<int, int> m;
    map<pair<int,int>,int> m1;
    m[1] = 2;
    m[2] = 3;
    m.insert({3, 4});
    m.emplace_back(4, 5);

    m.[{2,3}] = 10;
}

void multiMap(){   // allows duplicate keys
    multimap<int, int> m;
    m.insert({1, 2});
    m.insert({1, 3});
    m.insert({2, 3});
    m.insert({2, 4});
    m.insert({3, 4});
    m.insert({3, 5});
    m.insert({4, 5});
    m.insert({4, 6});
    m.insert({5, 6});
    m.insert({5, 7});
}

void unorderedMap(){
    unordered_map<int, int> m;
    m[1] = 2;
    m[2] = 3;
    m.insert({3, 4});
    m.emplace_back(4, 5);

    m.[{2,3}] = 10;
} 

void algorithms(){
    vector<int> v = {1, 2, 3, 4, 5};
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    rotate(v.begin(), v.begin()+1, v.end());

    string s = "abc";
    sort(s.begin(), s.end());
    next_permutation(v.begin(), v.end());
    prev_permutation(v.begin(), v.end());

    int x = 3;
    binary_search(v.begin(), v.end(), x);

    int y = 3;
    lower_bound(v.begin(), v.end(), y);    // returns iterator to first element >= y
    upper_bound(v.begin(), v.end(), y);    // returns iterator to first element > y

    int z = 3;
    int cnt = _builtin_popcount(z);    // number of set bits in z
}



int main() {
    // vector<int> v = {1, 29, 13, 40, 5};
    // sort(v.begin(), v.end());
    // cout<<v[1]<<endl;
    

    return 0;
}