

// selection sort  

#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[],int n){

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}


void swap(int *a,int *b){

    int temp=*a;
    *a=*b;
    *b=temp;
}


void selectionSort(int arr[],int n){


     for(int i=0;i<n-1;i++){

        int minEl_index=i;  // choose the element present at this index and assumed to be  minimum
        

        // now finding the index where element is minimum other than i index so we run the loop i+1 to the end

        cout<<"intermediate step: "<<i+1<<":: "<<endl;
        for(int j=i+1;j<n;j++){
          // whenever we got small element then updata the minimum index 
            if(arr[j]<arr[minEl_index]){
                minEl_index=j;
            }

            printArray(arr,n);
        }

        // in last we swap the the current element with minimum element means we have put the minimum element at the 
        // the front and this is the logic of selection sort 

        // means we are choosing the minimum element from unosorted array and then putting it at the front
        

        cout<<"minimum element from step: "<<i+1<<" is: "<<arr[minEl_index]<<endl;
        swap(&arr[minEl_index],&arr[i]);

        cout<<"step: "<<i+1<<"=> ";
        printArray(arr,n);
     }
}

int main(){

   int n;
   cin>>n;

   int arr[n];

   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
  

  cout<<"Initial given array: "<<endl;
   printArray(arr,n);

   selectionSort(arr,n);

   cout<<"final array after sort: "<<endl;

   printArray(arr,n);

    return 0;
}