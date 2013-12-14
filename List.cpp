//Marisa Reddy
//mpr2zp
//9 September 2013
//Filename: List.cpp

#include <iostream>
#include "List.h"
#include "ListItr.h"
using namespace std;

//default contructor
List::List() {  
  head = new ListNode;
  tail = new ListNode;
  //  head->value = 0;
  head->next = tail;
  head->previous = NULL;
  //tail-> value = 0;
  tail->next = NULL;
  tail->previous = head;
  count = 0;
}

//copy constructor
List::List(const List& source) {     //Copy Constructor
  head=new ListNode;
  tail=new ListNode;
  head->next=tail;
  tail->previous=head;
  count=0;
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {       //deep copy of the list
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

 
List::~List()
{
  //delete all ListNode references
  //delete head and tail nodes
  makeEmpty();
  delete head;
  delete tail;
}

//Equals operator
List& List::operator=(const List& source){ //Equals operator
  if (this == &source)
    return *this;
  else {
    makeEmpty();
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

bool List::isEmpty() const {
  //if the tail and head point to each other, then the list is empty
  //other way to do this (better maybe?) if count == 0
  if (head->next == tail && tail->previous == head) {
  return true;
  }
  return false;
}

void List::makeEmpty() {
  ListItr iter(head->next);
  while (!iter.isPastEnd()) {
    ListNode * now = iter.current;
      iter.moveForward();  
      delete now;
  }
  count = 0;
  head->next=tail;
  tail->previous=head;
}

ListItr List::first() {
  ListItr iter(head->next);
  return iter;
 }

ListItr List::last() {
  ListItr iter(tail->previous);
  return iter;
}

void List::insertAfter( int x, ListItr position ) {
  position.moveForward();
  insertBefore(x, position);
} 


void List::insertBefore( int x, ListItr position ) {
  ListNode* n = new ListNode ();
  n->next = position.current;
  n->previous = position.current->previous;
  position.current->previous = n;
  n->previous->next = n;
  n->value = x;
  count++;
}

void List::insertAtTail( int x ) {
  //create iterator at the tail node, and insert before there
  ListItr iter(tail);
  insertBefore(x, iter);
}

void List::remove( int x ) {
  ListItr iter(head->next);
  while (!iter.isPastEnd()) {
    if (iter.current->value == x) {
      iter.current->next->previous = iter.current->previous;
      iter.current->previous->next = iter.current->next;
      delete iter.current;
      count--;
      break;
    }
    else (iter.moveForward());
  }
}

ListItr List::find( int x ) {
  ListItr iter(head->next);
  while (!iter.isPastEnd()) {
    if (iter.current->value == x) {
      return iter;
    }
    else {
      iter.moveForward();
    }
  }
  iter.current = tail;
  return iter;
}

int List::size() const {
  return count;
}

/*void printList(List& source, bool direction) {
  if (direction) {
    ListItr iter = source.first();
    while (!iter.isPastEnd()) {
      cout << iter.retrieve() << endl;
      iter.moveForward();
    }

  }
  else {
    ListItr iter = source.last();
  while (!iter.isPastBeginning()){
    cout << iter.retrieve() << endl;
    iter.moveBackward();
  }
  }
}*/

void printList(List& source, bool direction) {
  // if (source.size() > 0) {
  if (direction) {
    ListItr iter = source.first();
    for (int n=0; n<source.size(); n++) {
      cout << iter.retrieve() << endl;
      iter.moveForward();
    }
  }
  
  else {
    ListItr iter = source.last();
    for (int n=0; n<source.size(); n++) {
      cout << iter.retrieve() << endl;
      iter.moveBackward();
    }
  } 
  // }
  //else {
  //cout << "The list is empty" << endl;
  //}
} 

