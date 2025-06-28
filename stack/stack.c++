#include <iostream>
using namespace std;
template<class type>
class stack {

struct node{
     type item;
     node*next;
};

node*top;
node*current;

public:
stack(){
               top = NULL;
               current = NULL;
};
void push(type element)
{
               node*NewItem = new node;
               NewItem->item = element;
               NewItem->next = top;
               top = NewItem;
};
bool isempty(){
return top == NULL;

};

void pop(){
     if(isempty()){
          cout << " No nodes exit ";
     }
     else{
          node*temp = top;
          top = top->next;
          delete temp;
     }
};

void pop(type&stacktop){
     if(isempty()){
          cout << " No nodes exit ";
     }
     else{
          stacktop = top;
          node*temp = top;
          top = top->next;
          delete temp;
     }
};

type gettop(){
     return top->item;
}

void display(){
     if(isempty()){
          cout << "No nodes exist to show";
     }
  
    else{
          current = top;
          while(current != NULL){
               cout << current->item << "  ";
               current = current->next;}
          }
     
};

};



int main(){
     stack<int>s;
     s.push(50);
     s.push(89);
     s.push(34);
     cout << s.gettop() << "\n";
  s.pop();
     cout << s.gettop() << "\n";
     s.display();
};