//
//  main.cpp
//  Snake
//
//  Created by Navroop Singh Bajwa on 21/08/17.
//  Copyright © 2017 Navroop Singh Bajwa. All rights reserved.
//
#include "linkedlisthandler.h"
#include<conio.h>
int main(int argc, const char * argv[]) {
    int n=3,x=0,y=0;
    char ch;
    string sentence=readfromfile(),out;
    //snake and food declaration
    struct food *food=new struct food;
    struct snake *head=new snake;
    head=NULL;
    food=NULL;
    while(n--){
        head=getval(head, x, y);
        x++;
    }//pre set-snake formation
    food=new struct food;
    food=NULL;
    food=chakfood(food,head);//food location
    struct snake *thead=new snake;
    thead=NULL;
    struct food *tfood=new struct food;
    
    if(sentence.length()>0){
        out=sentence;
        thead=getsnakep(out);
        tfood=getfoodp(out);
        displaymat(thead, tfood);
        cout<<endl<<"Do you want to continue from previous saved game then press y \n";
      	ch=getch();
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
    ch=getch();
    
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
            system("CLS");
            displaymat(head,food);
            cout<<endl<<"\nEnter next move\n";
    		ch=getch();
        }
        system("CLS");
        if(done(food,head)){head=inclen(head,food);
            food=chakfood(food,head);co=0;}
        else if(checktakker(head)){cout<<"YOU LOST!";break;}
        displaymat(head,food);
        cout<<endl;
        cout<<"Enter next move\n";
       
        if(kbhit()){
		char tempval;
		tempval=getch();
        if(tempval=='a'||tempval=='s'||tempval=='w'||tempval=='d'||tempval=='r')ch=tempval;
        else {flag=push();break;}}
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        co++;
        if(co==10){food=chakfood(food, head);co=0;}
    }
    out="";
    if(flag==1) saveit(head,food);
    return 0;
}
