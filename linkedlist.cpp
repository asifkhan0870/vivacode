#include<bits/stdc++.h>

using namespace std;

struct Linkedlist{

     int val;
     Linkedlist *next;

     Linkedlist (int val){

      this->val=val;
      this->next=NULL;
     }

     
};



void PrintLinkedlist(Linkedlist *head){

          Linkedlist *ptr=head;
          while(ptr){
            cout<<ptr->val<<"->";
            ptr=ptr->next;
          }cout<<"NULL"<<endl;
}



  
  Linkedlist *atBeginning(Linkedlist *head,int data){

       // creating the node of this data

       Linkedlist *n=new Linkedlist(data);
       n->next=head;
       head=n;
       return head;
  }

  Linkedlist *atEnd(Linkedlist *head,int data){

      
      // creating node of this value
      Linkedlist *n=new Linkedlist (data);

      Linkedlist *ptr=head;

      while(ptr->next!=NULL){
         ptr=ptr->next;
      }

      ptr->next=n;
      return head;
  }

  Linkedlist *atPosition(Linkedlist *head,int data,int pos){
      
      // creating node
      Linkedlist *n=new Linkedlist (data);

      Linkedlist *ptr=head;
      pos=pos-2;

      while(pos--){
         ptr=ptr->next;
      }

      Linkedlist *ptr1=ptr->next;
      ptr->next=n;
      n->next=ptr1;
      return head;


  }


  Linkedlist *deletionBeginning(Linkedlist *head){
     
     return head->next;
  }


  Linkedlist *deletionAtEnd(Linkedlist *head){
     
     Linkedlist *ptr=head;

     while(ptr->next->next){
         ptr=ptr->next;
     }
   //   cout<<ptr->val<<" ";
     ptr->next=NULL;

     return head;
  }


  Linkedlist *deletionAtPos(Linkedlist *head,int pos){
     
        Linkedlist *ptr=head;

        pos=pos-3;

        while(pos--){
           
           ptr=ptr->next;
        }
        ptr->next=ptr->next->next;

      //   cout<<ptr->val<<endl;

        return head;
  }

   
   Linkedlist *delParticularEl(Linkedlist *head,int ele){
        
        Linkedlist *ptr=head;

        while(ptr->next->val!=ele){
         ptr=ptr->next;
        }
        ptr->next=ptr->next->next;
        return head;
   }


   int len(Linkedlist *head){
       
       int l=0;

       while(head){
         l++;
         head=head->next;
       };
       return l;
   }

   // Linkedlist


   void CountSort(int arr[],int n,int pos){
      
      // countsort is based on the finding the occrence of the element in original array

      int mx=arr[0];

      // finding the maximum element
      for(int i=1;i<n;i++){
          
          mx=max(mx,arr[i]);
      }

      // now make a auxilary array which will store the store the mode of each element

      int count[mx+1];

      for(int i=0;i<=mx;i++){
        count[i]=0;
      }

      //now storing the occerence

      for(int i=0;i<n;i++){

        count[(arr[i]/pos)%10]++;
      }

      // now finding the cummulative sum of each element

      for(int i=1;i<=mx;i++){

          count[i]=count[i]+count[i-1];
      }

     int res[n];

     //now finding the correct index of each element

     for(int i=n-1;i>=0;i--){
          
          res[count[(arr[i]/pos)%10]-1]=arr[i];
          count[(arr[i]/pos)%10]--;
     }

     for(int i=0;i<n;i++){
        arr[i]=res[i];
     } 
}


 Linkedlist *convert(int arr[],int n){

    Linkedlist *head=new Linkedlist (arr[0]);

    for(int i=1;i<n;i++){
        
        Linkedlist *ptr=head;

        while(ptr->next){
         ptr=ptr->next;
        }

        ptr->next=new Linkedlist(arr[i]);

    }

    return head;
 }

void RadixSort(int arr[],int n){
      
      
      int mx=arr[0];

      for(int i=1;i<n;i++){
          
          mx=max(mx,arr[i]);
      }


      for(int pos=1;mx/pos>0;pos*=10){
          
          CountSort(arr,n,pos);
      }

}

int main(){
   
  Linkedlist *head=NULL;
   head=atBeginning(head,34);
   head=atBeginning(head,12);
   head=atBeginning(head,90);
   head=atBeginning(head,23);
   head=atBeginning(head,45);
   head=atBeginning(head,89);

   PrintLinkedlist(head);

   
    
    int sz=len(head);

   int arr[sz];
    int i=0;
   Linkedlist *ptr=head;
   while(ptr){
         arr[i++]=ptr->val;
         ptr=ptr->next;
   }

   // arr[i]=ptr->val;

   // for(int i=0;i<sz;i++){
   //    cout<<arr[i]<<" ";
   // }cout<<endl;

   RadixSort(arr,sz);

   // for(int i=0;i<sz;i++){
   //    cout<<arr[i]<<" ";
   // }cout<<endl;

   Linkedlist *h=convert(arr,sz);

   PrintLinkedlist(h);


   return 0;
}