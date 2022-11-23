#include<bits/stdc++.h>

using namespace std;


string solve(int n){
     string res="";

     while(n){
         
         int r=n%10;
         res+=r+'0';
         n/=10;


     }

     reverse(res.begin(),res.end());

     return res;
}

int main(){

   
    int n;cin>>n;
    cout<<solve(n)<<endl;

    return 0;
}