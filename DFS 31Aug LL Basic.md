# Single Linked List Basic Programs

Structure of a node, will be given in problems
```#include <iostream>
using namespace std;
struct node{
    char data;
    struct node *next;
}*first=NULL;
```

**Function to Create a LL from array elements**
```void create(char A[],int n){
    int i;
    struct node *p,*last;
    first=new node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++){
        p=new node;
        p->data=A[i];
        p->next=NULL;
        last->next=p;
        last=p;
    }
}
```

Function to display the elements in a LL
```
void Display(struct node *d){
    if(d==NULL){
        cout<<"Empty LL";
        return;
    }
    while(d!=NULL){
        cout<<d->data;
        d=d->next;
    }
    cout<<endl;
    return;
}
```

Function to insert an element with value x in a LL at a specific position
void insertAtPos(int pos,char x){
    //create a node with data x;
    struct node* p;
    p=new node;
    p->data=x;
    p->next=NULL;
    
    struct node *q;
    //inserting at the beginning;
    if(pos==1){
        p->next=first;
        first=p;
        return;
    }
    q=first;
    for(int i=1;i<pos-1 &&q;i++){
        q=q->next;
    }
    p->next=q->next;
    q->next=p;
    return;
}
struct node * returnLastNode(struct node *first){
    struct node* s;
    s=first;
    if(s==NULL){
        cout<<"Empty LL";
    }
    else if(s->next==NULL){
        return s;
    }
    else{
        while(s->next!=NULL){
            s=s->next;
        }
        return s;
    }
}

char returnSecondLastNode(struct node *first)
{
    struct node *s;
    s=first;
    
    if(s==NULL || s->next==NULL){
        cout<<"No second last element in the LL";}
    else{
        while(s->next->next!=NULL){
            s=s->next;
        }
        return s->data;
    }
}
char SecondLastUsingFriend(struct node *first){
    struct node *s,*fnd;
    s=first;
    if(s==NULL || s->next==NULL){
        cout<<"No second last element in the LL";}
    else{
        while(s->next!=NULL){
            fnd=s;
            s=s->next;
        }
    }
    return fnd->data;
}

void insertAtEnd(char x){
    struct node *s;
    struct node *p=new node;
    p->data=x;
    p->next=NULL;
    
    s=first;
    if(first==NULL){
        first=p;
        return;
    }
    else{
        while(s->next!=NULL){
            s=s->next;
        }
        s->next=p;
        return;
    }
}
void insertXbeforeY(){
    struct node *s,*fnd;
    //creating a node p with data x to be inserted
    struct node *p=new node;
    p->data='x';
    p->next=NULL;
    
    s=first;
    
    if(s==NULL){
        cout<<"Empty LL";
    }
    //only 1 elem that too is y so no friend can be created
    if(s->next==NULL && s->data=='y'){
        p->next=s;
        first=p;
    }
    
    else{
        while(s->data!='y' && s->next!=NULL){
            fnd=s;
            s=s->next;
        }
        //if loop ended because s->data was y
        if(s->data=='y'){
             fnd->next=p;
             p->next=s;
        }
        else{
            cout<<"y not found in LL";
        }
        return;
    }
}
void deleteAtEnd(){
    struct node* s=first, *fnd;
    if(s==NULL){
        cout<<"Empty LL";
        return;
    }
    //whenever we use friend concept, we need to put a check for single element also because in that case friend doesn't exit;
    if(s->next==NULL){
        free(s);
        s=NULL;
    }
    while(s->next!=NULL){
        fnd=s;
        s=s->next;
    }
    free(s);
    s=NULL;
    fnd->next==NULL;
    return;
}

void deleteNodeWithDataX(struct node* first,char x){
    struct node* s=first, *fnd=NULL;
    if(s==NULL){
        cout<<"Empty LL";
        return;
    }
    //LL has single element with x in it
    if(s->next==NULL && s->data==x){
        free(s);
        s=NULL;
        return;
    }
    else{
        while(s->next!=NULL && s->data!=x){
            fnd=s;
            s=s->next;
        }
        //if we got out of while if data is x at some point
        //remove that node
        if(s->data==x){
            fnd->next=s->next;
            free(s);
            s=NULL;
            return;
        }
        //if we got out because LL is over
        else{
            cout<<"LL has no element "<<x;
            return;
        }
    }
}

int main() {

    char A[]={'a','b','c','d'};
    create(A,4);
    Display(first);
    insertAtPos(4,'e');
    Display(first);
    insertAtPos(1,'f');
    Display(first);
    Display(returnLastNode(first));
    cout<<returnSecondLastNode(first)<<endl;
    cout<<SecondLastUsingFriend(first)<<endl;
    insertAtEnd('y');
    Display(first);
    insertXbeforeY();
    Display(first);
    deleteAtEnd();
    Display(first);
    deleteNodeWithDataX(first,'c');
    Display(first);
    
    return 0;
}
```

**Output:**
```
abcd
abced
fabced
d
e
e
fabcedy
fabcedxy
fabcedx
```
