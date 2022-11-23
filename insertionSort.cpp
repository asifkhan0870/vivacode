
// insertion sort 
#include<bits/stdc++.h>

using namespace std;


void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void insertionSort(int arr[],int n){


    for(int i=1;i<n;i++){

        // take the key
        int key=arr[i];

        int j=i-1;

        // now check the suitable place for the key

        // check on left side untill you will get smaller element from key if not then move the elements in right side


        while(key <arr[j] and j>=0){

            arr[j+1]=arr[j];  // shifting in right side

            printArray(arr,n);
            j--;
        }

        // now the while loop will end when got the smaller element than key so put the key before that 

        // but have decreases our j so first we will increament the count then put
        arr[j+1]=key;

        cout<<"at step "<<i<<"=>";
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
     
    cout<<"Our original Array: ";
     printArray(arr,n);

     insertionSort(arr,n);
   cout<<"final sorted Array: ";
    printArray(arr,n);


    return 0;
}