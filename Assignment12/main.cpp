#include <iostream>
#include <stdlib.h>
#include "HashTable.h"

using namespace std;

int main()
{
    string command="";
    string inputString1;
    string inputInt;
    bool menu=true;
    int totalItems=0;
    HashTable h;

    while(menu==true){
        cout << "======Main Menu======" << endl;
        cout<<"1. Insert movie"<<endl;
        cout<<"2. Delete movie"<<endl;
        cout<<"3. Find movie"<<endl;
        cout<<"4. Print table contents"<<endl;
        cout<<"5. Quit"<<endl;
        getline(cin,command);

        if(command=="1"){ //INSERT MOVIE
            cout<<"Enter title:"<<endl;
            getline(cin,inputString1);
            cout<<"Enter year:"<<endl;
            getline(cin,inputInt);
            int year=atoi(inputInt.c_str());
            h.insertMovie(inputString1,year); //run
            totalItems++;
            menu=true;
        }
        else if(command=="2"){ //DELETE MOVIE
            cout<<"Enter title:"<<endl;
            getline(cin,inputString1);
            h.deleteMovie(inputString1); //run
            menu=true;
            totalItems--;
        }
        else if(command=="3"){ //FIND MOVIE
            cout<<"Enter title:"<<endl;
            getline(cin,inputString1);
            h.findMovie(inputString1); //run
            menu=true;
        }
        else if(command=="4"){ //PRINT TABLE CONTENTS
            if(totalItems==0){
                cout<<"empty"<<endl;
            }
            else{
                h.printTableContents();
            }
            menu=true;
        }
        else if(command=="5"){ //QUIT
            cout<<"Goodbye!"<<endl;
            menu=false;
        }
    }
    return 0;
}
