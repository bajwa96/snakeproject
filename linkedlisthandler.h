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
#include <fstream>
#include<string>
#include <thread>
#include <fstream>
#include  <stdlib.h>
#include <set>
#include <algorithm>
#include <cctype>
#include <thread>
#include <chrono>
#include <string.h>
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

struct route{
    char data;
    struct route *next;
};
route *push(route *head,char d){
    route *t=new route;
    t->data=d;
    if(head==NULL){
        t->next=NULL;
        return t;
    }else{
        head->next=t;
        t->next=NULL;
        return t;
    }
}
route *pop(route *head){
    if(head!=NULL){route *hnext=head->next;free(head);return hnext;}
    return NULL;
}
void dele(struct route **head){
    struct route  *current = *head,*next;
    
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    
    /* deref head_ref to affect the real head back
     in the caller. */
    *head = NULL;
    
}
void display(route *rhead){
    if(rhead!=NULL){
        cout<<rhead->data<<" ";
        display(rhead->next);
    }
}

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
void saveit(snake *head,struct food *food){
    string out="";
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
    for(int i=0;i<(int)out.length();i++){
        out[i]=out[i]+='Z';
    }
    ofstream outfile;
    outfile.open("afile.txt", ios::trunc);
    outfile << out;
    outfile.close();

}
string readfromfile(){
    string sentences;
    //set <string> sentences;
    ifstream file("afile.txt");
    if(file.is_open())
    {
        getline(file, sentences);
    }
    file.close();

    return sentences;
    
}
snake *copysnake(snake *head){
    struct snake *temp=new snake;
    temp=NULL;
    while(head!=NULL){
        snake *t=new snake;
        t->x=head->x;
        t->y=head->y;
        if(temp==NULL){
            t->next=NULL;
            temp=t;
        }else{
            t->next=temp;
            temp=t;
        }
        head=head->next;
    }
   // temp=revesnake(temp);
    return temp;
}


snake *cuthead(snake *head){
    snake *t=head;
    int x=head->x,y=head->y;
    if(head!=NULL)head=head->next;
    while(head!=NULL){
        if(head->x==x&&head->y==y)head->next=NULL;
        head=head->next;
    }
    return t;
}

void dele(struct snake **head){
    struct snake  *current = *head;
    struct snake *next;
    
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    
    /* deref head_ref to affect the real head back
     in the caller. */
    *head = NULL;
    
}

char* getnextmove(snake *head,food *ro){
    food *roti=new food;
    roti->x=ro->x;
    roti->y=ro->y;
    int in=0;
    char *t=new char[10];
    char up,dn,le,rt;
    up=dn=le=rt='1';
    snake *xhead=new snake;
    snake *newxhead=new snake;
    int y=head->x,x=head->y;
    int fy=roti->x,fx=roti->y;
    
    xhead=NULL;
    xhead=copysnake(head);
    
    newxhead=NULL;
    newxhead=copysnake(xhead);
    if(checktakker(moveup(newxhead))==false){up='w';}
    dele(&newxhead);
    
    newxhead=NULL;
    newxhead=copysnake(xhead);
    if(checktakker(movedown(newxhead))==false){dn= 's';}
    dele(&newxhead);
    
    newxhead=NULL;
    newxhead=copysnake(xhead);
    if(checktakker(moveright(newxhead))==false){rt='d';}
    dele(&newxhead);
    
    newxhead=NULL;
    newxhead=copysnake(xhead);
    if(checktakker(moveleft(newxhead))==false){le='a';}
    dele(&newxhead);
    dele(&xhead);
    
    
    
    //cout<<"head x = "<<x<<"y = "<<y<<endl<<"food x= "<<fx<<" y= "<<fy<<endl;
    //cout<<"up "<<up<<endl<<"down "<<dn<<endl<<"right "<<rt<<endl<<"left "<<le<<endl;
    
    if(x>=fx){ //(x>fx)
        if(y>fy){
            if(up=='w'){t[in++]=up;}
            if(dn=='s'){t[in++]=dn;}
        }
        if(y<fy){
            if(dn=='s'){t[in++]=dn;}
            if(up=='w'){t[in++]=up;}
        }
        if(le=='a'){t[in++]=le;}
        if(rt=='d'){t[in++]=rt;}
        
    }
    if(x<=fx){
        
        if(y<fy){
            if(dn=='s'){t[in++]=dn;}
            if(up=='w'){t[in++]=up;}
        }
        if(y>fy){
            if(up=='w'){t[in++]=up;}
            if(dn=='s'){t[in++]=dn;}
        }
        if(rt=='d'){t[in++]=rt;}
        if(le=='a'){t[in++]=le;}
        
        
    }
    
    
    
    
    if(up=='w'){t[in++]=up;}
    if(dn=='s'){t[in++]=dn;}
    if(rt=='d'){t[in++]=rt;}
    if(le=='a'){t[in++]=le;}
    t[in]='\0';
    
    return t;
    
}
char *removeduplicay(char t[]){
    char *ret=new char[10];
    int ind=0;
    for(int i=0;i<strlen(t);i++){
        int flag=0;
        for(int j=0;j<strlen(ret);j++){
            if(t[i]==ret[j]){
                flag=1;
                break;
            }
        }
        if(flag==0)ret[ind++]=t[i];
        
    }
    return ret;
}

route *predict(snake *head,food *roti){
    
    snake *xhead=new snake;
    snake *newxhead=new snake;
    xhead=NULL;
    xhead=copysnake(head);
    char *predictions=new char[10];
    predictions=getnextmove(head,roti);
    //cout<<predictions<<" ";
    predictions=removeduplicay(predictions);
    //cout<<predictions<<endl;
    if(strlen(predictions)>0){
        for(int i=0;i<strlen(predictions);i++){
            route *rhead=NULL,*tail=NULL;
            newxhead=NULL;
            newxhead=copysnake(xhead);
            
            rhead=push(rhead,predictions[i]);
            tail=rhead;
            
            if(predictions[i]=='w'){
                newxhead=moveup(newxhead);
            }
            if(predictions[i]=='s'){
                newxhead=movedown(newxhead);
            }
            if(predictions[i]=='d'){
                newxhead=moveright(newxhead);
            }
            if(predictions[i]=='a'){
                newxhead=moveleft(newxhead);
            }
            while(roti->x!=newxhead->x||roti->y!=newxhead->y){
                char *t=getnextmove(newxhead, roti);
                
                if(strlen(t)>0){
                    
                    tail=push(tail, t[0]);
                    
                    if(t[0]=='w'){
                        newxhead=moveup(newxhead);
                    }
                    if(t[0]=='s'){
                        newxhead=movedown(newxhead);
                    }
                    if(t[0]=='d'){
                        newxhead=moveright(newxhead);
                    }
                    if(t[0]=='a'){
                        newxhead=moveleft(newxhead);
                    }
                }else break;
            }
            if(roti->x==newxhead->x&&roti->y==newxhead->y) {
                dele(&newxhead);
                dele(&xhead);
                return rhead;
            }
            dele(&rhead);
            dele(&newxhead);
        }
    }
    dele(&newxhead);
    dele(&xhead);
    
    cout<<"I dnt think I am correct\n";
    route *excption=NULL;
    if(strlen(predictions)>2){excption=push(excption, predictions[2]); return excption;}
    if(strlen(predictions)>1){excption=push(excption, predictions[1]); return excption;}
    if(strlen(predictions)>0){excption=push(excption, predictions[0]); return excption;}
    return NULL;
}


#endif /* linkedlisthandler_h */
