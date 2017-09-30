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
    int ch;
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
      	char ch1=getch();
        cout<<endl;
        if(ch1=='y'){
            head=thead;
            food=tfood;
        }
    }
    cout<<"Enter s for moving downward\nEnter w for moving upward\nEnter a for moving left\nEnter d for moving right\nEnter r for reverse the snake\nESC:Exit\nA:HEAD\n#:BODY\nF:FOOD\n";
        int flag=0,co=0;
    displaymat(head,food);
    cout<<"\nEnter next move\n";
    ch=getch();
    if(ch==224)ch=getch();
    while(ch==77||ch==72||ch==75||ch==80||ch==114){
        if(ch==72){
            head=moveup(head);
        }
        else if(ch==80){
            head=movedown(head);
        }
        else if(ch==77){
            head=moveright(head);
        }
        else if(ch==75){
            head=moveleft(head);
        }
        else if(ch==114){
            head=revesnake(head);
            system("CLS");
            displaymat(head,food);
            cout<<endl<<"\nEnter next move\n";
    		ch=getch();
    		if(ch==224)ch=getch();
        }
        system("CLS");
        if(done(food,head)){head=inclen(head,food);
            food=chakfood(food,head);}
        else if(checktakker(head)){head=cuthead(head);co++;  
		if(co==2){
		cout<<"YOU LOST!";break;}
		}
        displaymat(head,food);
        cout<<endl;
        cout<<"Enter next move\n";
       
        if(kbhit()){
		int tempval;
		tempval=getch();
		if(tempval==224)tempval=getch();
        if(tempval==77||tempval==72||tempval==75||tempval==80||tempval==114)ch=tempval;
        else {flag=push();break;}
		}
		else{
        	char move=getnextmove(head,food);
        	if(move=='w')ch=72;
        	if(move=='s')ch=80;
        	if(move=='d')ch=77;
        	if(move=='a')ch=75;
		}
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        
    }
    out="";
    if(flag==1) saveit(head,food);
    return 0;
}
