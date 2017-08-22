//
//  main.cpp
//  Snake
//
//  Created by Navroop Singh Bajwa on 21/08/17.
//  Copyright © 2017 Navroop Singh Bajwa. All rights reserved.
//
#include "linkedlisthandler.h"
#include <iostream>
#include  <stdlib.h>
int main(int argc, const char * argv[]) {
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
    //food->x=x;
    //food->y=0;*/
    //cout<<x<<endl;
    //head=inclen(head,food);
    //food=chakfood(food,head);
    //display(head);
   // cin>>x>>y;
    //cout<<checktakker(head)<<endl;
    //display(head);
    //displaymat(head,food);
    //cout<<endl;
    //display(head);
    
    //head=movedown(head);
    //cout<<endl;
    
    //cout<<endl;
    //displaymat(head,food);
    //cout<<endl;
    //display(head);
    //head=moveright(head);
    //head=moveleft(head);
    //head=moveup(head);
    //cout<<checktakker(head)<<endl;
    //displaymat(head);
    //display(head);
    food=chakfood(food,head);
    displaymat(head,food);
    char ch;
    cin>>ch;
    while(ch=='a'||ch=='s'||ch=='d'||ch=='w'){
        if(ch=='w'){
            
            head=moveup(head);
            //if(checkcolide(temp))cout<<"INVALID MOVE"<<endl;
            //else head=temp;
        }
        else if(ch=='s'){
            head=movedown(head);
        }
        else if(ch=='d'){
            head=moveright(head);
        }else{
            head=moveleft(head);
        }
        
        if(done(food,head)){head=inclen(head,food);food=chakfood(food,head);}
        else if(checktakker(head)){cout<<"YOU LOST!";break;}
        displaymat(head,food);
        cout<<endl;
        cin>>ch;
    }
    return 0;
}
