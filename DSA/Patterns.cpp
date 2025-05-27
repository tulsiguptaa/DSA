#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;


    //   *****
    //   *****
    //   *****
    //   *****
    //   *****  

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;


    // *
    // **
    // ***
    // ****
    // *****

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i+1;j++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;


    // 1  
    // 1  2  
    // 1  2  3
    // 1  2  3  4 

    // for(int i=0;i<n;i++){
    //     for(int j=1;j<i+1;j++){
    //         cout<<j<<"  ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;


    // 1  
    // 2  2  
    // 3  3  3  
    // 4  4  4  4  
    // 5  5  5  5  5  

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<i+1;j++){
    //         cout<<i<<"  ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;


    // *****
    // ****
    // ***
    // **
    // *

    // for(int i=0;i<n;i++){
    //     for(int j=n;j>i;j--){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;


    // 5  4  3  2  1  
    // 5  4  3  2  
    // 5  4  3  
    // 5  4  
    // 5  

    //   for(int i=1;i<=n;i++){
    //         for(int j=n;j>=i;j--){
    //             cout<<j<<"  ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;


    //  1  2  3  4  5      
    //  1  2  3  4  
    //  1  2  3  
    //  1  2  
    //  1

    //   for(int i=1;i<=n;i++){
    //         for(int j=1;j<=n-i+1;j++){
    //             cout<<j<<"  ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;

 
    //     *
    //    ***
    //   *****
    //  *******

    //   for(int i=0;i<n;i++){
    //     for(int j=n;j>i;j--){
    //         cout<<" ";
    //     }
    //     for(int k=0;k<2*i+1;k++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;


    //      *
    //     ***
    //    *****
    //   *******
    //  *********

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=n-i+1;j++){
    //         cout<<" ";
    //     }
    //     for(int k=0;k<=i;k++){
    //         cout<<"*";
    //     }
    //     for(int l=0;l<i;l++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;


    // *******
    //  *****
    //   ***
    //    *

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i;j++){
    //         cout<<" ";
    //     }
    //     for(int k=0;k<2*n-1-2*i;k++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;


    // *******
    //  *****
    //   ***
    //    *

    // for(int i=1;i<=n;i++){
    //     for(int l=1;l<i;l++){
    //         cout<<" ";
    //     }
    //     for(int j=1;j<n-i+1;j++){
    //         cout<<"*";
    //     }
    //     for(int k=1;k<=n-i-1;k++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;


    //     *
    //    ***
    //   *****
    //  *******
    // *********
    // *********
    //  *******
    //   *****
    //    ***
    //     *

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n-i-1;j++){
//             cout<<" ";
//         }
//         for(int k=0;k<=i;k++){
//             cout<<"*";
//         }
//         for(int l=0;l<i;l++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//    for(int i=0;i<n;i++){
//         for(int l=1;l<=i;l++){
//             cout<<" ";
//         }
//         for(int j=1;j<n-i+1;j++){
//             cout<<"*";
//         }
//         for(int k=1;k<=n-i-1;k++){
//             cout<<"*";
//         }
//         cout<<endl;
//     }
//     cout<<endl;


    // *
    // **
    // ***
    // ****
    // ***
    // **
    // *

    //     for(int i=1;i<=n;i++){ 
    //         if(i<=n/2){          
    //         for(int j=1;j<=i;j++){
    //             cout<<"*";
    //         }
    //         cout<<endl;
    //     }
    //     else{
    //         for(int k=1;k<=n-i+1;k++){
    //             cout<<"*";
    //         }
    //         cout<<endl;
    //     }
    // }
    //     cout<<endl;


    // 1
    // 01
    // 101
    // 0101
    // 10101

    // for(int i=0;i<n;i++){
    //    int start = 1;
    //  if(i%2 == 0){
    //     start = 1;
    //  }
    //  else{
    //     start=0;
    //  }
    //  for(int j=0;j<=i;j++){
    //     cout<<start;
    //     start = 1-start;
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;


    // 1        1
    // 12      12
    // 123    123
    // 1234  1234
    // 1234512345

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<j+1;
    //     }
    //     for(int k=0;k<n-i-1;k++){
    //         cout<<" ";
    //     }
    //     for(int k=0;k<n-i-1;k++){
    //         cout<<" ";
    //     }
    //     for(int j=0;j<=i;j++){
    //         cout<<j+1;
    //     }
    //     cout<<endl;
    // }


    // 1        1
    // 12      21
    // 123    321
    // 1234  4321
    // 1234554321

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<j+1;
    //     }
    //     for(int k=0;k<n-i-1;k++){
    //         cout<<" ";
    //     }
    //     for(int k=0;k<n-i-1;k++){
    //         cout<<" ";
    //     }
    //     for(int j=i+1;j>0;j--){
    //         cout<<j;
    //     }
    //     cout<<endl;
    // }


    // 1 
    // 2 3 
    // 4 5 6 
    // 7 8 9 10 
    // 11 12 13 14 15 

    // int num = 1;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<num<<" ";
    //         num++;
    //     }
    //     cout<<endl;
    // }


    // A 
    // B C 
    // D E F 
    // G H I J 
    // K L M N O 

    // char num = 'A';
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=i;j++){
    //         cout<<num<<" ";
    //         num++;
    //     }
    //     cout<<endl;
    // }


    // A 
    // A B 
    // A B C 
    // A B C D 
    // A B C D E 

    // for(int i=0;i<n;i++){
    //     for(char j='A';j<= 'A' + i;j++){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }


    // a b c d 
    // e f g 
    // h i 
    // j 

    // char ch = 'a';
    // for(int i=0;i<n;i++){
    //    for(int j=0;j<n-i-1;j++){
    //     cout<<ch<<" ";
    //     ch++;
    //    }
    //     cout<<endl;
    // }


    // A B C D E 
    // A B C D 
    // A B C 
    // A B 
    // A 

    // for(int i=0;i<n;i++){
    //    for(char j='A';j<'A'+ n -i;j++){
    //     cout<<j<<" ";
    //    }
    //     cout<<endl;
    // }


    // A 
    // B B 
    // C C C 
    // D D D D 
    // E E E E E 

    // char ch='A';
    // for(int i=0;i<n;i++){
    //    for(int j=0;j<=i;j++){
    //     cout<<ch<<" ";
    //    }
    //    ch++;
    //     cout<<endl;
    // }


//      A
//     ABA
//    ABCAB
//   ABCDABC

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         cout<<" ";
    //     }
    //     for(char k='A';k<='A' + i;k++){
    //         cout<<k;
    //     }
        
    //     for(char l='A';l<'A' + i;l++){
    //         cout<<l;
    //     }
      
    //     cout<<endl;
    // }


    // e 
    // d e 
    // c d e 
    // b c d e 

    // for(int i=0;i<n;i++){
    //     for(char j='e'-i;j<='e';j++){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }


    // **********
    // ****  ****
    // ***    ***
    // **      **
    // *        *
    // *        *
    // **      **
    // ***    ***
    // ****  ****
    // **********

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n-i;j++){
    //         cout<<"*";
    //     }
    //     for(int k=0;k<i;k++){
    //         cout<<" ";
    //     }
    //     for(int l=0;l<i;l++){
    //         cout<<" ";
    //     }
    //     for(int m=0;m<n-i;m++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<=i;j++){
    //         cout<<"*";
    //     }
    //     for(int k=0;k<n-i-1;k++){
    //         cout<<" ";
    //     }
    //     for(int l=0;l<n-i-1;l++){
    //         cout<<" ";
    //     }
    //     for(int m=0;m<=i;m++){
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }



    // **********
    // ****  ****
    // ***    ***
    // **      **
    // *        *
    // *        *
    // **      **
    // ***    ***
    // ****  ****
    // **********
    
    // for(int i=0;i<n;i++){
    //         for(int j=0;j<n-i;j++){
    //             cout<<"*";
    //         }
    //         for(int k=0;k<=2*i;k++){
    //             cout<<" ";
    //         }
    //         for(int m=0;m<n-i;m++){
    //             cout<<"*";
    //         }
    //         cout<<endl;
    //     }
    //     for(int i=0;i<n;i++){
    //             for(int j=0;j<=i;j++){
    //                 cout<<"*";
    //             }
    //             for(int k=0;k<=2*(n-i-1);k++){
    //                 cout<<" ";
    //             }
    //             for(int m=0;m<=i;m++){
    //                 cout<<"*";
    //             }
    //             cout<<endl;
    //         }


    // *         *
    // **       **
    // ***     ***
    // ****   ****
    // ***** *****
    // ****   ****
    // ***     ***
    // **       **
    // *         *

    // for(int i=0;i<n;i++){
    //             for(int j=0;j<=i;j++){
    //                 cout<<"*";
    //             }
    //             for(int k=0;k<=2*(n-i-1);k++){
    //                 cout<<" ";
    //             }
    //             for(int m=0;m<=i;m++){
    //                 cout<<"*";
    //             }
    //             cout<<endl;
    //         }
    //         for(int i=1;i<=n;i++){
    //             for(int j=0;j<=n-i-1;j++){
    //                 cout<<"*";
    //             }
    //             for(int j=0;j<=2*i;j++){
    //                 cout<<" ";
    //             }
    //             for(int j=0;j<=n-i-1;j++){
    //                 cout<<"*";
    //             }
    //             cout<<endl;
    //         }


    // ******
    // *    *
    // *    *
    // *    *
    // *    *
    // ******

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(i==0 || i==n-1 || j==0 || j==n-1){
    //             cout<<"*";
    //         }
    //         else{
    //             cout<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }


    // this problem is just a copy paste,, i didn't solve it by myself
    // 4 4 4 4 4 4 4 
    // 4 3 3 3 3 3 4 
    // 4 3 2 2 2 3 4 
    // 4 3 2 1 2 3 4 
    // 4 3 2 2 2 3 4 
    // 4 3 3 3 3 3 4 
    // 4 4 4 4 4 4 4 

    // for(int i=0;i<2*n-1;i++){
    //     for(int j=0;j<2*n-1;j++){
    //       int top = i;
    //       int left = j;
    //       int bottom = 2*n-2-j;
    //       int down = 2*n-2-i;
    //       cout<<(n-min(min(top,left),min(bottom,down)))<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}