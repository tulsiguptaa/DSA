#include <bits/stdc++.h>
using namespace std;
int main() {
    // // find the number of digits in a number
    // int num;
    // cout<<"Enter the numbers:";
    // cin>>num;
    // int cnt = log10(num)+1;
    // cout<<cnt<<endl;

    // // reverse a number
    // int rev = 0;
    // while(num > 0){
    //     int rem = num%10;
    //     rev = rev*10 + rem;
    //     num = num/10;
    // }
    // cout<<rev<<endl;

    // // check palindrome
    // int num1;
    // cout<<"Enter the number:";
    // cin>>num1;
    // int tem = num1;
    // int revNum = 0;
    // while(num1 > 0){
    //     int rem = num1%10;
    //     revNum = revNum*10 + rem;
    //     num1 = num1/10;
    // }
    // if(revNum == tem){
    //     cout<<"Palindrome"<<endl;
    //     }
    //     else{
    //         cout<<"Not Palindrome"<<endl;
    //     }

    //     // armstrong number
    //     int num2;
    //     cout<<"Enter the number: ";
    //     cin>>num2;
    //     int temp = num2;
    //     int sum = 0; 
    //     int digit = 0;
    //     while(num2!= 0){
    //         int remainder = num2%10;
    //         num2 = num2/10;
    //         digit++;
    //         sum += pow(remainder,digit);
    //     }
    //     if(temp == sum){
    //         cout<<"Armstrong number"<<endl;
    //     }
    //     else{
    //         cout<<"Not a armstrong number"<<endl;
    //     }

    //     // Factors
    //     int num3;
    //     cout<<"Enter the number to get the factors:";
    //     cin>>num3;
    //     cout<<"Factors are: ";
    //     for(int i=1;i<=num3;i++){
    //         if(num3%i==0){
    //             cout<<i<<" ";
    //         }
    //     }
    //     cout<<endl;

    //     // Another way of finding factors
    //     int num4;
    //     cout<<"Enter the number to get the factors:";
    //     cin>>num4;
    //     vector<int> fact;
    //     for(int i=1;i<=sqrt(num4);i++){
    //         if(num4%i==0){
    //             fact.push_back(i);
            
    //         if(num4/i!= i){
    //             fact.push_back(num4/i);
    //         }
    //     }
    //     }
    //     sort(fact.begin(),fact.end());
    //     cout<<"Factors are: ";
    //     for(auto i = fact.begin();i<fact.end();i++){
    //            cout<<*i<<" ";
    //     }
    //     // or
    //     // for(auto i:fact){
    //     //     cout<<i<<" ";
    //     // }
    //     cout<<endl;

        // // check for prime
        // int num5;
        // cout<<"Enter the number:";
        // cin>>num5;
        // int checkPrime = 0;
        // if(num5<=1) {
        //     cout<<"Not prime";
        // }
        // for(int i=2;i<sqrt(num5);i++)     // other way of writing sqrt = i*i < num5
        // {
        //     if(num5%i==0){
        //         checkPrime++;
        //         if(num5/i!=i){
        //             checkPrime++;
        //         }
        //     }
        // }
        // if(checkPrime != 0){
        //     cout<<"Not prime";
        // }
        // else{
        //     cout<<"Prime";
        // }

    // Greatest common divisor
    // int num6, num7;
    // cout<<"Enter the numbers: ";
    // cin>>num6;
    // cin>>num7;
    // int gcd = 1;
    // for(int i=1;i<=min(num6, num7);i++){
    //     if(num6 % i == 0 && num7 % i == 0){
    //         gcd = i;
    //     }
    // }
    // cout<<"HCF is: "<<gcd;
    // cout<<endl;

    // Another better way of finding GCD
    // int num6, num7;
    // cout<<"Enter the numbers: ";
    // cin>>num6;
    // cin>>num7;
    // for(int i=min(num6,num7);i>=1;i--){
    //     if(num6 % i == 0 && num7 % i == 0){
    //       cout<<i<<endl;
    //       break;
    //     }
    // }

    int a,b;
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;
    while(a>0 && b>0){
      if(a>b){
        a = a % b;
      }  
    else{
        b = b % a;
      }  
   }
   if(a==0){
    cout<<"HCF is:"<<b;
   }
   else{
    cout<<"HCF is:"<<a;
   }


   


    return 0;
}