/****************************************************************/
/*                     StackCalculator Class                      */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/

#pragma once
#include <iostream>

struct Op
{
    float num;
    Op* next;
};

class StackCalculator
{
private:
  Op* head; // pointer to the top of the stack

public:
  StackCalculator();
  ~StackCalculator();
  bool isEmpty();
  void push(float num);
  void pop();
  Op* peek();
  Op* getStackHead() { return head; }
  bool calculate(std::string symbol);
};
