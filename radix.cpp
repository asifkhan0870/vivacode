#include<bits/stdc++.h>
using namespace std;

void PrintArray(int arr[],int n){
      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
      }cout<<endl;

}

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
   
   int n;cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];

   }

   PrintArray(arr,n);

   RadixSort(arr,n);

//   CountSort(arr,n);

   PrintArray(arr,n);

    return 0;
}