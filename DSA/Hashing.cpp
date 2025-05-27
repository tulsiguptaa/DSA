#include <bits/stdc++.h>
using namespace std;

// -------------without hashing

int count(int arr[],int n,int num){
    int count = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            count++;
        }
    }
    return count;
}

// -------------hashing - counting the number of times a value repeats and stores it in index

int main() {
    // int n;
    // cout<<"Enter the size of the array: ";
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }

    // -------------without hashing - O(n)
    // int num;
    // cout<<"Enter the number you want to check: ";
    // cin>>num;
    // cout<<"The number of time num comes is: ";
    // cout<<count(arr,n,num);

    // -------------precalculation

    // -------------integer values - array hashing
    // int hash[13] = {0};
    // for(int i=0;i<n;i++){
    //     hash[arr[i]] += 1;          // hash[1] += 1
    // } 

    // int q;
    // cout<<"Enter how many numbers you want to check: ";
    // cin>>q;
    // while(q--){
    //     int num;
    //     cout<<"Enter the numbers you want to check: ";
    //     cin>>num;
    //     // -------------fetch
    //     cout<<hash[num]<<endl;
    // }
    

    // -------------char values -- for all lower case alphabhet
    // string name;
    // cout<<"Enter your name: ";
    // // cin>>name;
    // getline(cin,name);
    // int charHash[26] ={0};
    // for(int i=0;i<name.size();i++){
    //     charHash[name[i] - 'a'] ++;
    // }
    // int query;
    // cout<<"Enter the number of char you want to check: ";
    // cin>>query;
    // while(query--){
    //     char c;
    //     cout<<"Enter the char you want to check: ";
    //     cin>>c;

    //     // -------------fetch
    //     cout<<charHash[c-'a']<<endl;

        // -------------char values -for all the ascii char
    //     string name;
    //     cout<<"Enter your name: ";
    //     getline(cin,name);
    //     int charHash[256] ={0};
    //     for(int i=0;i<name.size();i++){
    //         charHash[name[i]] ++;
    //     }
    //     int query;
    //     cout<<"Enter the number of char you want to check: ";
    //     cin>>query;
    //     while(query--){
    //         char c;
    //         cout<<"Enter the char you want to check: ";
    //         cin>>c;
    
    //         // ------fetch
    //         cout<<charHash[c]<<endl;
    // }

    // ----------------- Using map in STL ----it takes less memroy than using hash array normal
    // time complexity - O(log n)
//    int n;
//     cout<<"Enter the size of the array: ";
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }

//     // this also works same in unordered map,,,the only difference is this - the key is not storeed in a sorted mannar
    

//     map<long, long> Hash;
//     for(int i=0;i<n;i++){
//         Hash[arr[i]]++;
//     }

//     // key - values pair
//     for(auto i:Hash){
//         cout<<i.first<<"->"<<i.second<<endl;
//     }

//     int q;
//     cout<<"Enter how many numbers you want to check: ";
//     cin>>q;
//     while(q--){
//         int num;
//         cout<<"Enter the numbers you want to find: ";
//         cin>>num;
        
//         // --------fetch
//         cout<<Hash[num]<<endl;
//     }


        int n;
        cout<<"Enter the size of the array: ";
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        int hash[15] = {0};
        for(int i=0;i<n;i++){
            hash[arr[i]]++;
        }

        // finding the frequency of the highest in the array

        int high = 0,low = 0;
        for(int i=0;i<n;i++){
            if(hash[i+1]>hash[i]){
                high = i+1;
            }

        }
        cout<<"The element with the highest frequency is: "<<high<<endl;
       
        
        // finding the frequency of the lowest in the array
        for(int i=0;i<n;i++){
            if(hash[i]>hash[i+1]){
                low = i+1;
            }
        }
        
        cout<<"The element with the lowest frequency is: "<<low<<endl;


   

    return 0;
}