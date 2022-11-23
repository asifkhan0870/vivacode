#include<bits/stdc++.h>

using namespace std;


// this function is simply merge two sorted list/array

void merge(int arr[],int low,int mid,int high){

       int n1=mid-low+1;
       int n2=high-mid;

       int arr1[n1],arr2[n2];


       for(int i=0;i<n1;i++){
          arr1[i]=arr[low+i];
       }

       for(int i=0;i<n2;i++){
        arr2[i]=arr[mid+i+1];
       }

       int i=0,j=0,k=low;

       while(i<n1 and j<n2){

            if(arr1[i]<=arr2[j]){

                arr[k]=arr1[i];
                k++;
                i++;
            }
            else{
                arr[k]=arr2[j];
                k++;
                j++;
            }
       }

       // when one array end and one is not end means some elements are left then we are copying simply this code
       // is simply for that and this will happen when these two auxilary arrays don't have same size other wise our work will end above while loop 

       while(i<n1){
          
          arr[k]=arr1[i];
          i++;
          k++;
       }

       while(j<n2){
          arr[k]=arr2[j];
          j++;
          k++;
       }

}


void mergeSort(int arr[],int n){
    
  /* iterative logic of merge sort very simple and it is based upon bottom up approach means as we know that
  one element is sorted so we merge two elements and then after merging by this we merge 2 2 elements so next itrattion we have to merge two list having two elements and list is sorted so at this time we have to merge four size and so on........*/


    for(int i=1;i<n;i=i*2){

        for(int low=0;low<n-1;low+=2*i){

            
            int mid,r;

            if(low+i-1<n-1){   // means whenever we cross the the size of the array then put the mid maximum to maximum as n-1 it will be not more than it.  and this case be handle when element left while we making the group 
                mid=low+i-1;
            }
            else
                mid=n-1;
            
            
            // this condition is also checking the same as above  
            if(low+2*i-1<n-1){
                r=low+2*i-1;
             }
             else
            
                r=n-1;
            

            merge(arr,low,mid,r);
        }
    }

}

int main(){

      
      int n;cin>>n;

      int arr[n];

      for(int i=0;i<n;i++){
        cin>>arr[i];
      }

      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
      }cout<<endl;

      mergeSort(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
      }cout<<endl;



    return 0;
}