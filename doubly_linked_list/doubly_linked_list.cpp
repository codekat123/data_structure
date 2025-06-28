#include <iostream>
using namespace std;
template<class type>

class doubly_linked_list{

struct node{
type data;
node*next;
node*previous;
};
int count;
node*first;
node*last;

public:
doubly_linked_list(){
  first = last = NULL;
  count = 0;
};

void insertfirst(type element){
  node*newnode = new node;
  newnode->data = element;
  newnode->next = NULL;
  newnode->previous = NULL;
  if(count == 0 or first == NULL){
    first = last = newnode;
  }
  else{
    newnode->next = first;
    first->previous = newnode;
    first = newnode;
  }
  count++;
};

void insertlast(type element){
  node*newnode = new node;
  newnode->data = element;
  newnode->next = NULL;
  newnode->previous = NULL;
  if(count == 0 or last == NULL){
    first = last = newnode;
  }
  else{
    newnode->previous = last;
    last->next = newnode;
    last = newnode;
  }
  count++;
};

void insert_at_pos(int position , type element){
  if(position < 0 || position > count){
    cout << "out of the range";
    return;
  }
  if(position == 0){
    insertfirst(element);
    return;
  }
  if (position == count){
    insertlast(element);
    return;
  }
  node* current = first;
  for(int i = 1 ; i < position ; i++ ){
    current = current->next;
  }
  node*newnode = new node;
  newnode->data = element;
  newnode->next = current->next;
  newnode->previous = current;
  current->next->previous= newnode;
  current->next = newnode;
  count++;
};

void removefirst(){
  if(count == 0){
    cout << "there's nothing to delete";
    return;
  }
  if(count == 1){
    delete first;
    first = last = NULL;
  }
  else{
    node* current = first;
    first = first->next;
    first->previous = NULL;
    delete current;
  }
  count--;
}

void removelast(){
  if(count == 0){
    cout << "there's nothing to delete";
    return;
  }
  if(count == 1){
    delete first;
    first = last = NULL;
  }
  else{
    node* current = last;
    last = last->previous;
    last->next = NULL;
    delete current;
  }
  count--;
}

void remove(type element){
  if(count == 0){
    cout << "there's nothing to delete it";
    return;
  }
  if(first->data == element){
    removefirst();
    return;
  }
  node*current = first;
  while(current != NULL){
    if(current->data == element)
      break;
    current = current->next;
  }
  if(current == NULL){
    cout << "Nothing to delete";
    return;
  }
  if(current->next == NULL){
    removelast();
    return;
  }
  current->previous->next = current->next;
  current->next->previous = current->previous;
  delete current;
  count--;
}

void print(){
node*current = first;
cout << "your elements are";
while(current != NULL){
cout << current->data << " ";
  current = current->next;
}
};

bool search(type element) {
    node* current = first;
    while (current != NULL) {
        if (current->data == element)
            return true;
        current = current->next;
    }
    return false;
}

type get_first() {
    if (count == 0 || first == NULL) {
        throw std::out_of_range("List is empty");
    }
    return first->data;
}

type get_last() {
    if (count == 0 || last == NULL) {
        throw std::out_of_range("List is empty");
    }
    return last->data;
}

int get_count() {
    return count;
}

};

int main() {
    doubly_linked_list<int> list;
    // Insert elements at the beginning
    list.insertfirst(10);
    list.insertfirst(20);
    // Insert elements at the end
    list.insertlast(30);
    list.insertlast(40);
    // Insert at position
    list.insert_at_pos(2, 25); // Insert 25 at position 2
    // Print all elements
    list.print();
    cout << endl;
    // Remove an element
    list.remove(30);
    list.print();
    cout << endl;
    // Search for elements
    cout << "Search 25: " << (list.search(25) ? "Found" : "Not Found") << endl;
    cout << "Search 100: " << (list.search(100) ? "Found" : "Not Found") << endl;
    // Get first and last elements
    try {
        cout << "First element: " << list.get_first() << endl;
        cout << "Last element: " << list.get_last() << endl;
    } catch (const std::out_of_range& e) {
        cout << e.what() << endl;
    }
    // Get count
    cout << "Count: " << list.get_count() << endl;
    return 0;
}