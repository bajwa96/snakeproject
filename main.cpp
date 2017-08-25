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
#include <thread>
#include <chrono>
#include <string>
int main(int argc, const char * argv[]) {
    char ch;
    string sentence;string out;
    set <string> sentences;
    ifstream file("afile.txt");
    if(file.is_open())
    {
            getline(file, sentence);
    }
    file.close();
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
    food=NULL;
    food=chakfood(food,head);
    
    
    struct snake *thead=new snake;
    thead=NULL;
    struct food *tfood=new struct food;
    if(sentence.length()>0){
        out=sentence;
        thead=getsnakep(out);
        tfood=getfoodp(out);
        displaymat(thead, tfood);
        cout<<endl<<"Do you want to continue from previous saved game then press y \n";
        cin>>ch;
        cout<<endl;
        if(ch=='y'){
            head=thead;
            food=tfood;
        }

    }
    
    cout<<"Enter s for moving downward\nEnter w for moving upward\nEnter a for moving left\nEnter d for moving right\nEnter r for reverse the snake\nESC:Exit\nA:HEAD\n#:BODY\nF:FOOD\n";
        int flag=0,co=0;
    displaymat(head,food);
    cout<<"\nEnter next move\n";
    cin>>ch;
    while(ch=='a'||ch=='s'||ch=='w'||ch=='d'||ch=='r'){
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
        if(done(food,head)){head=inclen(head,food);
            food=chakfood(food,head);co=0;}
        else if(checktakker(head)){cout<<"YOU LOST!";break;}
        displaymat(head,food);
        cout<<endl;
        cout<<"Enter next move\n";
        char tempval;
        cin>>tempval;
        if(tempval=='a'||tempval=='s'||tempval=='w'||tempval=='d'||tempval=='r')ch=tempval;
        else {flag=push();break;}
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        co++;
        if(co==10){food=chakfood(food, head);co=0;}
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
        outfile.close();
        }
    return 0;
}
