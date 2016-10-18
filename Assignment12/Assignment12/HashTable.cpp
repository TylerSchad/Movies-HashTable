#include "HashTable.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

HashTable::HashTable()
{
    //ctor
    for(int x=0;x<10;x++){
        hashTable[x]=NULL;
    }
}

HashTable::~HashTable()
{
    //dtor
}

void HashTable::printTableContents(){
    int i;
    HashElem *tmp=new HashElem;
    for(int x=0; x<10;x++){
        if(hashTable[x]!=NULL){
            tmp=hashTable[x];
            while(tmp!=NULL){
                cout<<tmp->title<<":"<<tmp->year<<endl;
                tmp=tmp->next;
            }
        }
    }
}

void HashTable::insertMovie(std::string name, int year){
    HashElem *tmp=new HashElem;
    HashElem *node=new HashElem;
    node->title=name;
    node->year=year;
    node->next=NULL;
    node->previous=NULL;
    //tmp->next=NULL;
    int sum=hashSum(name, s);
    //cout<<"hi"<<endl;
    if(hashTable[sum]==NULL){
        hashTable[sum]=node;
    }
    else{
        tmp=hashTable[sum];
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=node;
        node->previous=tmp;
        node->next=NULL;
    }
    //cout<<"end"<<endl;
}

void HashTable::deleteMovie(std::string name){
    int index=hashSum(name,s);
    HashElem *tmp=hashTable[index];
        //traverse list until searchValue is found or tmp=NULL
    if(tmp->title==name){
        if(tmp->next!=NULL){
            hashTable[index]=tmp->next;
            tmp->next->previous=NULL;
            delete tmp;
        }
        else{
            delete tmp;
            hashTable[index]=NULL;
        }
    }
        else{
            //tmp=tmp->next;
            while(tmp!=NULL){

                if(tmp->title==name){
                    if(tmp->next!=NULL){

                        tmp->next->previous=tmp->previous;
                    }
                    tmp->previous->next=tmp->next;
                    //tmp->previous=NULL;
                    //tmp->next=NULL;

                    delete tmp;
                    //break;
                }
                else{
                    tmp=tmp->next;
                }
            }
        }
}

void HashTable::findMovie(std::string name){
    HashElem *tmp=new HashElem;
    int index=hashSum(name,s);
    if(hashTable[index]!=NULL){
        tmp=hashTable[index];
        while(tmp!=NULL){
            if(tmp->title==name){
                cout<<index<<":"<<name<<":"<<tmp->year<<endl;
                break;
            }
            else{
                tmp=tmp->next;
            }
        }
    }
    else{
       cout<<"not found"<<endl;
    }
}

int HashTable::hashSum(std::string x, int s){ //x is key, s is table size
    int sum=0;
    for(int y=0;y<x.size();y++){ //is "size" correct?
        sum=sum+x[y];
    }
    sum=sum%s;
    return sum;
}
