/* Write your test code for the ULListStr in this file */
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{

 
  ULListStr test;
  
  test.push_back("8");

  cout << "The front value is: " + test.front() << endl;

  cout <<"The back value is: " + test.back() << endl;

  test.push_back("7");

  test.push_front("5");
  test.push_front("3");

  test.pop_back();
  test.pop_back(); // here is the error

  cout << "The front is now: " + test.front() << endl;

  cout << "And the back now is: " + test.back() << endl;

  // the front should be 8
  // the back should be 7

  test.push_back("4");
  test.push_back("17");
  test.push_back("11");

  test.push_back("10");
  test.push_back("9");
  test.push_back("8");
  test.push_back("7");
  test.push_back("6");
  test.push_back("5");
  test.push_back("4");
  test.push_back("3");
  test.push_back("2");
  test.push_back("1");

  test.push_back("0");
  test.push_back("14");




  cout << "The 12th value now is: " + test.get(11) << endl; // should be three

  cout << "The back value now is: " + test.back() << endl;










  return 0;
}
