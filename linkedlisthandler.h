//
//  linkedlisthandler.h
//  Snake
//
//  Created by Navroop Singh Bajwa on 21/08/17.
//  Copyright © 2017 Navroop Singh Bajwa. All rights reserved.
//

#ifndef linkedlisthandler_h
#define linkedlisthandler_h
#include<iostream>
#include <stdlib.h>
using namespace std;
struct snake{
    int x,y;
    struct snake *next;
};
struct food{
    int x,y;
};
snake *getval(snake *head,int x,int y){
    struct snake *t1=new snake;
    t1->x=x;
    t1->y=y;
    if(head==NULL){
        t1->next=NULL;
        head=t1;
    }
    else{
        t1->next=head;
        head=t1;
    }
    return head;
}
void display( snake *head){
    while(head!=NULL){
        cout<<head->x<<" "<<head->y<<endl;
        head=head->next;
    }
}
void displaymat(snake *head,food *ro){
    snake *t=head;
    int arr[20][20]={0};
    arr[head->x][head->y]=2;
    head=head->next;
    while(head!=NULL){
        arr[head->x ][ head->y]=1;
        head=head->next;
    }
    head=t;
    if((ro->x==head->x&&ro->y==head->y))arr[ro->x][ro->y]=2;
    else if(ro!=NULL&&arr[ro->x][ro->y]!=2)arr[ro->x][ro->y]=3;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            if(arr[i][j]==1)cout<<"#";
            else if(arr[i][j]==3)cout<<"F";
            else if(arr[i][j]==2)cout<<"A";
            else cout<<" ";
        }
        cout<<endl;
    }
}
snake *moveahead(snake *head,int x,int y){
    
    snake *temp=head;
    int lastx,lasty;
    while (head!=NULL) {
        lastx=head->x,lasty=head->y;
        head->x=x;
        head->y=y;
        x=lastx;y=lasty;
        
        
        head=head->next;
        
    }
        return temp;
}
snake *moveup(snake *head){
    int x=head->x-1;
    if(x<0){
        x=19;
    }
    head=moveahead(head, x, head->y);
    return head;
}
snake *moveleft(snake *head){
    int x=head->y-1;
    if(x<0){
        x=19;
    }
    head=moveahead(head, head->x, x);
    return head;
}
snake *moveright(snake *head){
    int x=head->y+1;
    if(x>20){
        x=0;
    }
    head=moveahead(head, head->x, x);
    return head;
}
snake *movedown(snake *head){
    int x=head->x+1;
    if(x>20){
        x=0;
    }
    head=moveahead(head, x, head->y);
    return head;
}
bool checktakker(snake *head){
    int hx=head->x,hy=head->y;
    head=head->next;
    while(head!=NULL){
        if(head->x==hx&&head->y==hy)return true;
        head=head->next;
    }
    return false;
}
bool notonsnkae(int x,int y,snake *head){
    while(head!=NULL){
        //cout<<"f"<<x<<" "<<head->x<<" "<<y<<" "<<head->y<<endl;
        if((head->x==x&&head->y==y))return false;
        head=head->next;
    }
    return true;
}
food *chakfood(food *head,snake *snakehead){
    int lastx=-1,lasty=-1;
    if(head==NULL){
        head=new food;
        int x=rand()%20,y=rand()%20;
        cout<<x<<" "<<y<<endl<<endl;
        while(1){
            if(x>=0&&y>=0&&x<20&&y<20&&lastx!=x&&lasty!=y)if( notonsnkae(x,y,snakehead)==true)break;
            cout<<"here"<<x<<" "<<y<<endl;
            lasty=y;lastx=x;
            x=rand()%20;y=rand()%20;
            
        }
        head->x=x;
        head->y=y;
    }else{
        lastx=head->x,lasty=head->y;
        int x=rand()%20,y=rand()%20;
        //cout<<x<<" "<<y<<endl<<endl;
        while(1){
            if(x>=0&&y>=0&&x<20&&y<20)if(x!=lastx&&y!=lasty)if( notonsnkae(x,y,snakehead)==true )break;
            //cout<<x<<" "<<y<<endl;
            x=rand()%20;y=rand()%20;
        }
    
        head->x=x;
        head->y=y;
        
    }
    return head;
}
bool done(food *f,snake *h1){
    if(h1->x==f->x&&h1->y==f->y)return true;
    return false;
}
snake *inclen(snake *h1,food *f){
    //cout<<h1->x<<f->x;
    if(h1->x==f->x&&h1->y==f->y){
        h1=getval(h1, f->x, f->y);
        //h1=moveahead(h1,f->x, f->y);
    }
    return h1;
}

#endif /* linkedlisthandler_h */
