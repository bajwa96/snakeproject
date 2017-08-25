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
#include<string>
#define mar 10
#define mac 10
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
int push(){
    cout<<"If u want to save then press s else any other key\n";
    char t;
    cin>>t;
    if(t=='s')
    return 1;
    else return 0;
}
snake *revesnake(snake *head){
    struct snake *temp=new snake;
    temp=NULL;
    while(head!=NULL){
        temp=getval(temp,head->x,head->y);
        head=head->next;
    }
    return temp;
}
snake *getsnakep(string t){
    struct snake *head=new snake;
    int l=(int)t.size(),x,y;
    l=(int)t.find('#');
    //cout<<l<<endl;
    head=NULL;
    for(int i=0;i<l;i++){
        int temp1=0,temp2=0;
        while(i<l&&t.at(i)!=' '){
            temp1=temp1*10+(t.at(i)-'0');
            //cout<<t.at(i);
            i++;
        }
       // cout<<t.at(--i);
        if(i<l&&t.at(i)==' ')i++;
        while(i<l&&(t.at(i)!='#'&&t.at(i)!='*')){
            //cout<<"This"<<t.at(i)<<endl;
            temp2=temp2*10+(t.at(i)-'0');
            i++;
        }
        x=temp1;y=temp2;
        head=getval(head, x, y);
        
                //cout<<temp1<<" "<<temp2<<endl;
    }
    head=revesnake(head);
    return head;
}

food *getfoodp(string t){
    struct food *head=new food;
    //head=NULL;
    int l=(int)t.size();
    int s=(int)t.find('#');
    int temp1=0,temp2=0;
    //cout<<"Food="<<t.at(s)<<endl;
    for(int i=s+1;i<l;i++){
        while(i<l&&t.at(i)!=' '){
            temp1=temp1*10+(t.at(i)-'0');
            
            i++;
        }
        i++;
        while(i<l){
            temp2=temp2*10+(t.at(i)-'0');
            //cout<<t.at(i);
            i++;
        }
    }
    //cout<<"Food="<<temp1<<temp2<<endl;
    if(temp1<20&&temp2<20&&temp1>=0&&temp2>=0){
        head->x=temp1;
        head->y=temp2;}
    else {
            head->x=0;
            head->y=0;
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
    if(head->x==head->next->x&&head->y==head->next->y){
        arr[head->x][head->y]=2;
        head=head->next->next;}else{
            arr[head->x][head->y]=2;head=head->next;
        }
    while(head!=NULL){
        arr[head->x ][ head->y]=1;
        head=head->next;
    }
    head=t;
    if(ro!=NULL&&arr[ro->x][ro->y]!=2)arr[ro->x][ro->y]=3;
    for(int i=0;i<22;i++)cout<<"-";
    cout<<endl;
    for(int i=0;i<20;i++){
        cout<<"|";
        for(int j=0;j<20;j++){
            if(arr[i][j]==1)cout<<"#";
            else if(arr[i][j]==3)cout<<"F";
            else if(arr[i][j]==2)cout<<"H";
            else cout<<" ";
        }
        cout<<"|"<<endl;
    }
    for(int i=0;i<22;i++)cout<<"-";
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
    if(x>19){
        x=0;
    }
    head=moveahead(head, head->x, x);
    return head;
}
snake *movedown(snake *head){
    int x=head->x+1;
    if(x>19){
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
        while(1){
            if(x>=0&&y>=0&&x<20&&y<20&&lastx!=x&&lasty!=y)if( notonsnkae(x,y,snakehead)==true)break;
            lasty=y;lastx=x;
            x=rand()%20;y=rand()%20;
            
        }
        head->x=x;
        head->y=y;
    }else{
        lastx=head->x,lasty=head->y;
        int x=rand()%20,y=rand()%20;
        while(1){
            if(x>=0&&y>=0&&x<20&&y<20)if(x!=lastx&&y!=lasty)if( notonsnkae(x,y,snakehead)==true )break;
            x=rand()%20;y=rand()%20;
        }
    
        head->x=x;
        head->y=y;
        
    }
    return head;
}
snake *reversehead(snake *head){
    snake *h1=new snake;
    h1=NULL;
    while(head!=NULL){
        h1=getval(head, head->x, head->y);
        head=head->next;
    }
    return h1;
}
bool done(food *f,snake *h1){
    if(h1->x==f->x&&h1->y==f->y)return true;
    return false;
}
snake *inclen(snake *h1,food *f){
    if(h1->x==f->x&&h1->y==f->y){
        h1=getval(h1, f->x, f->y);
    }
    return h1;
}

#endif /* linkedlisthandler_h */
