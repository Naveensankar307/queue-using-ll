#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

typedef struct node *Node;
Node front = NULL;
Node rear = NULL;
void enqueue(int data);
void dequeue();
void display();

main(){
    int ch,data;
    while(1){
        cout<<"press 1 for enqueue, 2 for dequeue, 3 for display, 4 for exit"<<"\n";
        cin>>ch;
        switch(ch){
            case 1: cout<<"enter the data ";
                    cin>>data;
                    enqueue(data);
                    break;
            
            case 2: dequeue();
                    break;
            
            case 3: display();
                    break;
            
            case 4: exit(0);
                    break;
            
            default : cout<<"invalid entry";
                      break;
        }
    }
}

void enqueue(int data){
    Node nn;
    nn = (Node)malloc(sizeof(Node));
    nn->data = data;
    nn->next = NULL;
    if(front == NULL && rear == NULL)
        front = rear = nn;
    else{
        rear->next = nn;
        rear = nn;
    }
}

void dequeue(){
    if(front == NULL){
        cout<<"queue is empty";
    }
    else{
        Node temp ;
        temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
    }
}

void display(){
    if(front == NULL){
        cout<<"queue is empty";
    }
    else{
        Node temp=front;
        while(temp->next != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
    }
}
