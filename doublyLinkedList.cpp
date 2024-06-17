#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * prev , *next;
};

Node* create(vector<int>a,int n){
    Node * list = new Node;
    Node * temp = list;
    
    list->data = a[0];
    list->prev = NULL;
    list->next = NULL;
    
    for(int i=1;i<n;i++){
        Node * new_node=new Node;
        new_node->data=a[i];
        new_node->next=NULL;
        new_node->prev=list;
        list->next=new_node;
        list=list->next;
    }
    return temp;
}

Node * insertAtpos(Node*list,int data,int pos){
    pos=pos-1;
    if(pos==0){
        Node * new_node = new Node;
        new_node->data=data;
        new_node->next=list;
        new_node->prev=NULL;
        list->prev=new_node;
        list=new_node;
        
    }else{
        Node* temp=list;
        while(temp && pos>1){
            temp=temp->next;
            pos--;
        }
        
        Node * new_node = new Node;
        new_node->data=data;
        new_node->next=temp->next;
        new_node->prev=temp;
        temp->next=new_node;
    }
    return list;
}

Node * deleteAtpos(Node*list,int pos){
    pos=pos-1;
    
    if(pos==0){
        Node* temp=list->next;
        delete list;
        if(temp) temp->prev=NULL;
        list=temp;
    }else{
        Node * temp=list;
        while(temp && pos>1){
            temp=temp->next;
            pos--;
        }
        
        if(temp->next->next){
            Node * p = temp->next->next;
            delete temp->next;
            temp->next = p;
            p->prev=temp;
            // list=temp;
        }else{
            delete temp->next;
            temp->next=NULL;
            // list=temp;
        }
    }
    return list;
}

Node * reverse(Node * list){
    Node * temp = list;
    temp->prev=temp->next;
    temp->next=NULL;
    temp=temp->prev;
    
    while(temp){
        Node * t = temp->prev;
        temp->prev=temp->next;
        temp->next=t;
        temp=temp->prev;
        if(temp!=NULL && temp->next==NULL){
            list=temp;
        }
    }
    return list;
}

void display(Node * list){
    while(list){
        cout << (list->data) << " ";
        list=list->next;
    }
    cout << endl;
}

int main()
{
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
   Node * list = create(a,n);
   display(list);
   list = insertAtpos(list,10,6);
   display(list);
   list = deleteAtpos(list,3);
   display(list);
   list = reverse(list);
   display(list);
    return 0;
}