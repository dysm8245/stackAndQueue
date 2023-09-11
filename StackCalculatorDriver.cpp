/****************************************************************/
/*                  Stack Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "StackCalculator.hpp"
#include "StackCalculator.cpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  StackCalculator stack;
  string input;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  while(true)
  {
    cout << "#> ";
    getline(cin, input);
    /* TODO
       1. Read input (operators and operands) until you encounter a "="
       2. Use the isNumber function to check if the input is an operand
       3. push all operands to the stack
       4. If input is not an operand, call the compute function to evaluate
          the partial expression
    */
    if(isNumber(input)){
      float num = stof(input);
      stack.push(num);
    }
    if(input == "="){
      if(stack.isEmpty()){
        cout << "No operands: Nothing to evaluate" << endl;
        return 0;
      }
      else{
        float num1;
        Op *con;
        con = stack.peek();
        num1 = con->num;
        stack.pop();
        if(stack.isEmpty()){
          cout << num1 << endl;
        }
        else{
          cout << "Invalid expression" << endl;
        }
      }
      break; 
    }
    if(!isNumber(input) && input != "="){
      stack.calculate(input);
    }
  }
  /* TODO - If the stack is empty then print "No operands: Nothing to evaluate" */

  /* TODO - Validate the expression
      1. If valid then print the result
      2. Else, print "Invalid expression"*/

  return 0;
}
