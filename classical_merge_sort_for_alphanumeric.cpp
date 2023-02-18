// Merge sort in C++
#include<time.h>
#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<string>
using namespace std;
// Print the array
void printArray(string arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}


// Merge two subarrays L and M into arr
void merge(string arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
string *L = new string[n1];
string *M = new string[n2];
 //int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i].assign(arr[p + i]);
  for (int j = 0; j < n2; j++)
     M[j].assign(arr[q + 1 + j]);

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;


  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  // int c=0;
  while (i < n1 && j < n2) {
// cout<<"K : "<<k<<endl;
//     cout<<"L : "<<l<<endl;
// c++;
    if (L[i].compare(M[j])<0) {
      arr[k].assign(L[i]);
      i++;
    } else {
      arr[k].assign(M[j]);
      j++;
    }
    k++;
    
  }
// cout<<"\nCout : "<<c<<endl;
  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k].assign(L[i]);
    i++;
    k++;
  }

  while (j < n2) {
    arr[k].assign(M[j]);
    j++;
    k++;
  }


}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(string arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    //cout<<"\n\n"<<endl;
    merge(arr, l, m, r);
  }
}



// Driver program
int main() {
  srand(time(NULL));
    int arr_size = 1000;
    int ch_MAX = 26;

    static const char AlphaNumeric[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int MyLen = sizeof(AlphaNumeric) - 1;


    string arr[arr_size];
    for (int i = 0; i < arr_size; i++)
    {

        string result = "";
        for (int m = 0; m < 5; m++)
        {
            char x = AlphaNumeric[rand() % MyLen];
            result = result + x;
        }
        arr[i] = result;
    }


  int size = sizeof(arr) / sizeof(arr[0]);
    clock_t start,end;
    start=clock();
  mergeSort(arr, 0, size - 1);
 end=clock();
  cout << "Sorted array: \n";
 //printArray(arr, size);

  cout<<" "<<endl;
    cout<<"Time : "<<end-start<<endl;
  return 0;
}