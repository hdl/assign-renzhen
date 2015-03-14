#include <iostream>
#include <string>

using namespace std;

void extractMostSeenEvenDigitProblem1YourName(int num){
    int original = num;
    int table[10]={0};
    int visit_seq[10]={0};
    int counter=0;
    int total_num=0;
    int even_num=0;
    int max;
    if(num==0){
        total_num=1;
        even_num=1;
        table[0]=1;
        visit_seq[0]=0;
        counter++;
    }
    while(num/10!=0 || num%10!=0){
        if(num%10%2==0){
            if(table[num%10]==0){// the first time
                visit_seq[counter] = num%10;
                counter++;
            }
            even_num++;
            table[num%10]++;

        }

        num = num/10;
        total_num++;

    }


    cout << "    There is/are " <<total_num<<" digit(s) with "<<even_num<<" even digit(s)."<<endl;
    cout << "    With the "<<even_num<<" even digit(s),"<<endl<<endl;

    max = table[visit_seq[0]];

    for(int i=0; i<counter; i++){
        cout<<"        "<<visit_seq[i]<<" occurs "<<table[visit_seq[i]]<<" time(s)"<<endl;
        if(table[max]<table[visit_seq[i]])
            max=visit_seq[i];
    }
    cout << "    Digit "<<max<<" is seen "<<table[max]<< " time(s) in "<< original <<endl;

}

int main(){
    int choice;
    int num;
    while(1){
        cout <<"*********************************************************"<<endl;
        cout <<"*                          MENU                         *"<<endl;
        cout <<"* 1. Calling extractMostSeenEvenDigitProblem1YourName() *"<<endl;
        cout <<"* 2. Quit *"<<endl;
        cout <<"*********************************************************"<<endl;
        cout <<"Select an option (1 or 2): ";
        cin >> choice;
        if(choice==2){
            cout <<"  Have Fun ..."<<endl;
            return 0;
        }
        cout <<"  Enter an integer: ";
        cin >> num;
        cout <<"  Calling displayDigitProblem1YourName() –"<<endl;

        extractMostSeenEvenDigitProblem1YourName(num);
    }

}
