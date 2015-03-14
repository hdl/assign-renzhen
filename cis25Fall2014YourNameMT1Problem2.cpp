#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void merge (int *A, int a, int *B, int b, int *C);
void merge_sort(int *A, int n);

int num_of_even(int num){
    int counter=0;
    num = abs(num);
    if(num==0)
        return 0;
    while(num/10!=0 || num%10!=0){
        if(num%10%2==0)
            counter++;
        num=num/10;
    }
    //cout << num << ":" << counter;
    return counter;

}
bool compare_fun(int a, int b){
    //cout <<"here"<<endl;
    if(num_of_even(a)>num_of_even(b))
        return 1;
    else
        return 0;
}
void updateArrayProblem2YourName(int* array, int size){
    //num_of_even(array[0]);
    merge_sort(array, size);

    cout << "  The updated array:"<<endl;
        for(int i=0; i<size; i++){
            cout<<"    "<<array[i]<<endl;
        }
}

int main(){
    int choice;
    int num;
    int array[100];
    while(1){
        cout <<"*********************************************************"<<endl;
        cout <<"*                          MENU                         *"<<endl;
        cout <<"* 1. Calling updateArrayProblem2YourName()              *"<<endl;
        cout <<"* 2. Quit                                               *"<<endl;
        cout <<"*********************************************************"<<endl;
        cout <<"Select an option (1 or 2): ";
        cin >> choice;
        if(choice==2){
            cout <<"  Have Fun ..."<<endl;
            return 0;
        }
        cout <<"  How many integers? ";
        cin >> num;
        for(int i=0; i<num; i++){
            cout << "    Enter interger #"<<i+1<<": ";
            cin >> array[i];
        }
        cout << "  The original array:"<<endl;
        for(int i=0; i<num; i++){
            cout<<"    "<<array[i]<<endl;
        }
        cout <<"  Calling updateArrayProblem2YourName() –"<<endl;

        updateArrayProblem2YourName(array, num);
    }

}


void
merge (int *A, int a, int *B, int b, int *C)
{
  int i,j,k;
  i = 0;
  j = 0;
  k = 0;
  while (i < a && j < b) {
    //num_of_even(a)>num_of_even(b)
    if(num_of_even(A[i])>=num_of_even(B[j])){
    //if (A[i] <= B[j]) {
      /* copy A[i] to C[k] and move the pointer i and k forward */
      C[k] = A[i];
      i++;
      k++;
    }
    else {
      /* copy B[j] to C[k] and move the pointer j and k forward */
      C[k] = B[j];
      j++;
      k++;
    }
  }
  /* move the remaining elements in A into C */
  while (i < a) {
    C[k]= A[i];
    i++;
    k++;
  }
  /* move the remaining elements in B into C */
  while (j < b)  {
    C[k]= B[j];
    j++;
    k++;
  }
}

/**
 * merge_sort()
 * Sort array A with n integers, using merge-sort algorithm.
 **/
void
merge_sort(int *A, int n)
{
  int i;
  int *A1, *A2;
  int n1, n2;

  if (n < 2)
    return;   /* the array is sorted when n=1.*/

  /* divide A into two array A1 and A2 */
  n1 = n / 2;   /* the number of elements in A1 */
  n2 = n - n1;  /* the number of elements in A2 */
  A1 = (int*)malloc(sizeof(int) * n1);
  A2 = (int*)malloc(sizeof(int) * n2);

  /* move the first n/2 elements to A1 */
  for (i =0; i < n1; i++) {
    A1[i] = A[i];
  }
  /* move the rest to A2 */
  for (i = 0; i < n2; i++) {
    A2[i] = A[i+n1];
  }
  /* recursive call */
  merge_sort(A1, n1);
  merge_sort(A2, n2);

  /* conquer */
  merge(A1, n1, A2, n2, A);
  free(A1);
  free(A2);
}
