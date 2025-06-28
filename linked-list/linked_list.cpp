#include <iostream>
using namespace std;
template<class type>
class linkedlist {

struct node{
type item;
node*next;
};

node*head;
node*tail;
int length;
public:
linkedlist(){
  head=tail=NULL;
  length = 0;
};



void insertfirst(type element){
  node*newnode = new node;
  newnode->item = element;
  if(length == 0){
    head = tail = newnode;
    newnode->next = NULL;
  }
  else{
    newnode->next = head;
    head = newnode;
  }
  length++;
};


void insertlast(type element){
  node*newnode = new node;
  newnode->item = element;
  if(length == 0){
    head = tail = newnode;
    newnode->next = NULL;
  }
  else{
    tail->next = newnode;
    tail = newnode;
  }
  length++;
};

void insert_at_pos(int position, type element){
  if(position == 0){
    insertfirst(element);
  }
  else if(position == length){
    insertlast(element);
  }
  else{
    node*cur = head;
    
    for(int i = 1 ; i < position ; i++){
      cur = cur->next;
    }

    node*newnode = new node;
    newnode->next = cur->next;
    cur->next = newnode;
    
  }
};

void display(){
  node*cur = head;
  while(cur != NULL){
    cout << cur->item << " ";
    cur = cur->next;
  };
};

type gethead(){
  return head->item;
}

type gettail(){
  return tail->item;
}





void removefirst(){
  if(length == 0){
    cout << "you don't have anything to delete";
  }
  else if(length == 1){
    delete head;
    head = tail = NULL;
  }
  else {
   node*temp = head;
   head = head->next;
    delete temp;
  }  
};

void removelast(){
  
  if(length == 0){
    cout << "you don't have anything to delete";
  }
  else if(length == 1){
    delete head;
    head = tail = NULL;
  }
  else {
    node*current = head->next;
    node*prvious = head;
    while(current != NULL){
      prvious = current;
      current = current->next;
    };
    delete current;
    tail = prvious;
    prvious->next = NULL;
  } 
};





void remove(type element){
  node*previous; 
  node*current; 
  if(length == 0){
    cout << "you don't have anything to delete it";
  }
else if(head->item == element){
  current = head;
  head = head->next;
  delete current;
  length--;
  if(length == 0){
    tail =  NULL;
  }
  else{
    current = head->next;
    previous = head;
    while(current != NULL){
      previous = current;
      current = current->next;
      if(current->item == element ){
        break;
      }
    }
    if(current == NULL){
      cout << "not found";
    }
    else{
      previous = current->next;
      if(current == tail){
        tail == previous;
      }
      delete current;
      length--;
    }
  }
}
else {
  
}
}
};


int main(){
  linkedlist<int> s;
  s.insertfirst(1);
  s.insertlast(2);
  s.insertfirst(3);
  s.display();
  cout << "head is" << s.gethead();
  cout << "tail is" << s.gettail();
};