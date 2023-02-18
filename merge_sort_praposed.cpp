// Merge sort in C++
#include<time.h>
#include <iostream>
using namespace std;
// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}
// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
int *L = new int[n1];
int *M = new int[n2];
 //int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  int a=n1-1;
  int b=n2-1;
//   printf("Array L : ");
//   printArray(L,q-p+1); 
//   printf("Array M : ");
//   printArray(M,r-q);
  k = p;
  int l=r;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i <= a && j <= b) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;

    if(L[a] >= M[b])
    {
        arr[l]=L[a];
        a--;
    }
    else{
        arr[l]=M[b];
        b--;
    }
    l--;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i <= a) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j <= b) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}



// Driver program
int main() {
  int arr_size=500000;
  //int *arr=new int[arr_size];
	int arr[arr_size];
	for(int i=0;i<arr_size;i++){
        arr[i]=rand();
    }
  int size = sizeof(arr) / sizeof(arr[0]);
    clock_t start,end;
    start=clock();
  mergeSort(arr, 0, size - 1);
 end=clock();
  cout << "Sorted array: \n";
 // printArray(arr, size);

  cout<<" "<<endl;
    cout<<"Time : "<<end-start<<endl;
  return 0;
}