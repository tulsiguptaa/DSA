#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int first = 0;
    int last = n-1;
    while(first<last){
        if(numbers[first] + numbers[last] == target) return {first, last};
        else if(numbers[first] + numbers[last] > target) last --;
        else first++;
    }        
    return -1;

}
int main() {
    
    return 0;
}