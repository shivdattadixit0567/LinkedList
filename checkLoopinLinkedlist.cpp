#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

Node * create(int a[], int n){
    Node * list = new Node(0);
    Node * temp = list;
    for(int i=0;i<n;i++){
        Node * c = new Node(a[i]);
        list->next = c;
        list=list->next;
    }
    cout << (temp->data) << endl;
    return temp;
}

void display(Node* list){
    cout << "Hello" << endl;
    int ct = 10;
    while(list && ct > 0){
        cout << (list->data) << " ";
        list=list->next;
        ct--;
    }
    cout << endl;
}

bool isLoop(Node * list){
    Node * t1 = list->next;
    Node * t2 = list->next;
    
    cout << (t1->data) << " " << (t2->data) << endl;
    while(t1 && t2->next){
        t1=t1->next;
        t2=t2->next->next;
        
        cout << (t1->data) << " " << (t2->data) << endl;
        if(t1==t2) return 1;
    }
    // if(t1==t2) return 1;
    return 0;
}


int main()
{
    int n;cin>>n;
    int a[5];
    for(int i=0;i<n;i++) cin>>a[i];

    Node * list = create(a,n);
    Node * t1,* t2;
    
    display(list);
    
    bool f = isLoop(list);
    if(f){
        cout << "Linked List contains loop" << endl;
    }else{
        cout << "Linked List does not contains loop" << endl;
    }
    
    // let's form loop in list
    
    
    t1 = list->next->next;
    t2 = list->next->next->next->next->next;
    
    t2->next = t1;
    
    display(list);
    
    if(isLoop(list)){
        cout << "Linked List contains loop" << endl;
    }else{
        cout << "Linked List does not contains loop" << endl;
    }
    return 0;
}