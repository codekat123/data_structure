#include <iostream>
using namespace std;
template<class type>
class Queue{

     struct node{
          type data;
          node*next;
     };

     node*front;
     node*rear;
     int count;
     public:
     Queue(){
          front = rear = NULL;
          count = 0;
     }
     bool isempty(){
          return front == NULL || count == 0;
     }
     void push(type element){
          node*newnode = new node;
          newnode->data = element;
          newnode->next = nullptr;
          if(isempty()){
               front = rear = newnode;
          }
          else{
               rear->next = newnode;
               rear = newnode;
          }
          count++;
     }     

     void pop(){
          if(isempty()){
               cout << "Nothing to delete. The queue is empty.";
          }
          else{
          if(count == 1 || front->next == NULL){
               delete front;
               front = rear = nullptr;
          }
          else{
               node*temp = front;
               front = front->next;
               delete temp;
          }
          count--;
     }
     }


    type getfront(){
          return front->data;
     }

    type getrear(){
          return rear->data;
     }

    void display(){
     node*current = front;
     cout << "{";
     while(current != NULL){
          cout << current->data << " ";
          current = current->next;
     }
     cout << "}\n";
    }

};

int main(){
     Queue<int> instance;
     instance.push(10);
     instance.push(20);
     instance.push(30);
     instance.push(40);
     instance.display(); 
     cout << instance.getfront()<<"<-front\n";
     cout << instance.getrear()<<"<-rear\n";
     instance.pop();
     instance.display();
}