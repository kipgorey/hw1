#include "split.h"

#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

int main() {

  // test 1


  Node* in = new Node(8, NULL);
  Node* temp = new Node(7,in);
  in = temp;
  Node* temp2 = new Node(5,in);
  in = temp2;
  Node* temp3 = new Node(6, in);
  in = temp3;

  Node* evens = NULL;
  Node* odds = NULL;

  split(in, odds, evens);

  cout << "Value odds is: " << endl;
  cout << odds->value << endl;
  
  odds = odds->next;

  cout << "The new odds value is: " << endl;
  cout << odds->value << endl;

  cout << "The value of evens is: " << endl;
  cout << evens->value << endl;
  cout << "Evens next is: " << endl;
  cout << evens->next->value << endl;

  if(in == nullptr){
    cout << "In is NULL" << endl;
  } else {
    cout << "In still has values" << endl;
    cout << in->value << endl;
  }
  if(odds->next == NULL)
  {
    cout << "The program will no longer continue because the next Node is set to null" << endl;
  }

  // deallocate the memory
  
  delete in;
  delete temp;
  delete temp2;
  delete temp3;
  
  

  return 0;


}