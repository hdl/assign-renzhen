#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void displayDigitProblem3YourName(int* array, int size){
    int table[10]={0};
    for(int i=0; i<size; i++){
        array[i]=abs(array[i]);

        if(array[i]==0)
            table[0]++;
        while(array[i]/10!=0 || array[i]%10!=0){
            if(array[i]%10%2==0)
                table[array[i]%10]++;
            array[i]=array[i]/10;
        }

        for(int j=0; j<10; j++){
            if(table[j]>i+1)
                table[j]=i+1;
        }

    }
    int total=0;
    for(int i=0; i<10; i++){
        if(table[i]==1){
            total++;
        }
    }
    cout << "    From all of the given intergers,"<<endl;
    cout << "      There is/are "<<total<<" uncommon even digit(s)."<<endl;
    cout << "      The uncommon even digit(s) is/are"<<endl;
    for(int i=0; i<10; i++){
        if(table[i]==1){
            cout << "        "<<i<<endl;
        }
    }
}

int main(){
    int choice;
    int num;
    int array[100];
    while(1){
        cout <<"*********************************************************"<<endl;
        cout <<"*                          MENU                         *"<<endl;
        cout <<"* 1. Calling displayDigitProblem3YourName()              *"<<endl;
        cout <<"* 2. Quit                                               *"<<endl;
        cout <<"*********************************************************"<<endl;
        cout <<"Select an option (1 or 2): ";
        cin >> choice;
        if(choice==2){
            cout <<"  Fun Exercise..."<<endl;
            return 0;
        }
        cout <<"  How many integers? ";
        cin >> num;
        for(int i=0; i<num; i++){
            cout << "    Enter interger #"<<i+1<<": ";
            cin >> array[i];
        }

        cout <<"  Calling displayDigitProblem3YourName() –"<<endl;

        displayDigitProblem3YourName(array, num);
    }

}
