#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


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
    sort(array, array+size, compare_fun);

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
