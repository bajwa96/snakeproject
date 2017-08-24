//
//  main.cpp
//  Snake
//
//  Created by Navroop Singh Bajwa on 21/08/17.
//  Copyright © 2017 Navroop Singh Bajwa. All rights reserved.
//
#include "linkedlisthandler.h"
#include <iostream>
#include <fstream>
#include  <stdlib.h>
#include <set>
#include <algorithm>
#include <cctype>

#include <string>
int main(int argc, const char * argv[]) {
    /*ifstream infile;
    infile.open("afile.dat");*/
    string sentence;
    set <string> sentences;
    
    ifstream file("afile.txt");
    
    if(file.is_open())
    {
        //while(!file.eof())
        //{
            getline(file, sentence);
            //sentence.erase(remove_if(sentence.begin(), sentence.end(), sentence.end());
            //sentences.insert(sentence);
        //}
    }
    
    file.close(); //close file
    
    //infile.seekg(0,ios::beg);
    
    int n=3,x=0,y=0;
    struct food *food=new struct food;
    struct snake *head=new snake;
    head=NULL;
    food=NULL;
    
    while(n--){
        head=getval(head, x, y);
        x++;
    }
    food=new struct food;
    food=NULL;food=chakfood(food,head);
    string out;char ch;
    cout<<"Do you want to continue from previous saved game then press y \n";
    cin>>ch;
    cout<<endl;
    cin.ignore();
    //infile >> out;
    //cout<<out<<endl;
    if(ch=='y'){
        //cout<<"Hello";
        out=sentence;
        //cout<<out<<endl;
        head=getsnakep(out);
        food=getfoodp(out);
    }
       int flag=0;
    
    displaymat(head,food);
    cout<<"Enter next move\n";
    cin>>ch;
    while(ch=='a'||ch=='s'||ch=='d'||ch=='w'||ch=='r'){
        if(ch=='w'){
            head=moveup(head);
        }
        else if(ch=='s'){
            head=movedown(head);
        }
        else if(ch=='d'){
            head=moveright(head);
        }
        else if(ch=='a'){
            head=moveleft(head);
        }
        else if(ch=='r'){
            head=revesnake(head);
        }
        system("CLS");
        if(done(food,head)){head=inclen(head,food);food=chakfood(food,head);}
        else if(checktakker(head)){cout<<"YOU LOST!";break;}
        displaymat(head,food);
        cout<<endl;
        char tempval;
        cin>>tempval;
        if(tempval=='a'||tempval=='s'||tempval=='w'||tempval=='d'||tempval=='r')ch=tempval;
        else {flag=push();break;}
    }
    out="";
    if(flag==1){
        int x,y;
        while(head!=NULL){
            x=head->x;y=head->y;
            out+=to_string(x);
            out+=' ';
            out+=to_string(y);
            if(head->next!=NULL)out+='*';
            head=head->next;
        }
        out+='#';
        x=food->x;y=food->y;
        out+=to_string(x);
        out+=' ';
        out+=to_string(y);
        ofstream outfile;
        outfile.open("afile.txt", ios::trunc);
        outfile << out;
        //cout<<out<<endl;
        outfile.close();
        }
    
   

    return 0;
}
