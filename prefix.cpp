#include<bits/stdc++.h>
using namespace std;

#define max_size 100

class Stack{
     
   int tp;

   public: 

   vector<string>arr;

   Stack(){
     tp=-1;
     arr=vector<string>(max_size,"");
   }

   bool push(string s){
      
      if(tp>=max_size-1){
        cout<<"stack overflow"<<endl;
        return false;
      }
      else{
        arr[++tp]=s;
        return true;
      }
   }

   bool pop(){
      
      if(tp==-1){
        cout<<"stack underflow"<<endl;
         return "";
      }
      else{
         
         tp--;
         return true;
        
      }
   }

   string top(){
       
       if(tp<0){
            cout<<"stack underflow"<<endl;
            return "";
       }
       else{

        return arr[tp];

       }
   }


};

string PrefixToPostfix(string prefix){

    // stack<string>st;

    Stack st;
     

    for(int i=prefix.size()-1;i>=0;i--){

        if(prefix[i]=='*' or prefix[i]=='/' or prefix[i]=='+' or prefix[i]=='-'){

            // remove two operands

            string s1=st.top();
            st.pop();

            string s2=st.top();
            st.pop();

            string temp=s1+s2+prefix[i];
            
           
                st.push(temp);


        }
        else {

            string temp;
            temp+=prefix[i];
            st.push(temp);
        }
    }

    cout<<"prefix to postfix: "<<st.top()<<endl;

    string postfix=st.top();
    st.pop();

    return postfix;


    // for(int i=0;i<postfix.size();i++){


    //     if(postfix[i]>='0' and postfix[i]<='9'){

    //         string temp;
    //         temp+=postfix[i];
    //         st.push(temp);
    //     }
    //     else{

    //         string s1=st.top();
    //         st.pop();

    //         float n1=stof(s1);

    //         string s2=st.top();
    //         st.top();

    //         float n2=stof(s2);

    //         float ans;

    //         if(postfix[i]=='-'){
                
    //             ans=n1-n2;
    //         }
    //         else if(postfix[i]=='+'){
    //             ans=n1+n2;
    //         }
    //         else if(postfix[i]=='/'){
    //             ans=n1/n2;
    //         }
    //         else if(postfix[i]=='*'){
    //             ans=n1*n2;
    //         }

    //         string t=to_string(ans);
    //         st.push(t);
    //     }
    // }

    // return st.top();
}



int main(){

   
   string str;
   cin>>str;

   cout<<PrefixToPostfix(str)<<endl;


   return 0;

}