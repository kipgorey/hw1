#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

#include <iostream>
#include <string>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val)
{
  // code below...

  // 3 options, empty, room left or full

  if(empty()) // empty
  {
    Item* node = new Item();
    node->val[0] = val;
    head_ = node;
    tail_ = node;
    node->first = 0;
    node->last = 1;
    size_++;

  } else { // room left
    
    if(tail_->last < 10)
    {
      tail_->val[tail_->last] = val;
      tail_->last++;

    } else { // full
      // else it should be equal to 10
      Item* node = new Item();
      
      node->next = NULL;
      node->prev = tail_;
      tail_->next = node;
      tail_ = node;


      tail_->val[0] = val;
      tail_->first = 0;
      tail_->last = 1;

      size_++;

    }


  }



}

void ULListStr::push_front(const std::string& val)
{
  //code below
  if(empty())
  {
    Item* node = new Item();
    node->val[9] = val;
    node->first = 9;
    node->last = 10;
    head_ = node;
    tail_ = node;
    size_++;
    
  } else {
    if(head_->first > 0) // only partially full case
    {
      head_->val[head_->first -1] = val;
      head_->first--; // what happens in the case of push_back to create a new node
      // and then a push front call

    } else {
      Item* node = new Item();
      node->next = head_;
      node->prev = NULL;
      head_->prev = node;
      head_ = node;



      // change / reset some of the new values in the new head_ pointer


      head_->val[9] = val;
      head_->first = 9;
      head_->last = 10;

      size_++;

    }
  }




}

void ULListStr::pop_front()
{
  if(!empty())
  {
    if(head_->first != 9) // don't have to delete node
    {
      // memory is already allocated so shouldn't matter
      head_->first += 1;


    } else { // have to delete the node because it will be empty once popped back
      
      if(head_->next != NULL){
        head_ = head_->next;
        delete head_->prev;
        head_->prev = NULL;
      } else {
        head_ = NULL;
        tail_ = NULL;
      }
      size_--;

      // need to put in values for new first and last

      if(head_ != tail_)
      {
        head_->first = 0;
        head_->last = 10;
      } else {
        head_->first = 0;
        head_->last = tail_->last;
      }

    }


  }

}

void ULListStr::pop_back()
{
  // code below
  if(!empty())
  {
    if(tail_->last - tail_->first >1)
    {
      tail_->last--;
    } else {
      tail_ = tail_->prev;
      delete tail_->next;
      tail_->next = NULL;

      size_--;

      // need to put in code for assigning new values to first and last

      if(tail_ != head_)
      {
        tail_->first = 0;
        tail_->last = 10;
      } else {
        tail_->first = head_->first;
        tail_->last = 10;
      }

    }
  }

}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  // code below

  // runs in O(n) time

  Item* temp = head_;
  int index = head_->first;


  for(unsigned int i = 0; i < loc; i++){

      if(index == 9)
      {
        temp = temp->next;
        index = 0;
      } else {
        index++;
      }
  }
  return &temp->val[index];

}

std::string const & ULListStr::back() const {
  // code below
  return tail_->val[tail_->last-1];
}
std::string const & ULListStr::front() const {
  // code below
  return head_->val[head_->first];

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
