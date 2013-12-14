//Marisa Reddy
//mpr2zp
//9 September 2013
//Filename: ListItr.cpp

#include "ListItr.h"
#include "ListNode.h"
#include <iostream>
using namespace std;


ListItr::ListItr() {
  current = NULL;
}

ListItr::ListItr( ListNode* theNode) {
  current = theNode;
}

bool ListItr::isPastEnd() const {
  if (current->next == NULL){
  return true;
  }
  return false;
}


bool ListItr::isPastBeginning() const {
  if (current->previous == NULL) {
  return true;
  }
  return false;
}


void ListItr::moveForward() {
  if (!(isPastEnd())) {
      current = current->next;
    }
}

void ListItr::moveBackward() {
  if (!(isPastBeginning())) {
    current = current->previous;
  }
}

int ListItr::retrieve() const {
  return current->value;
}
