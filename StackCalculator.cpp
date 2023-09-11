#include "StackCalculator.hpp"
#include <iostream>
using namespace std;

StackCalculator::StackCalculator(){
    head = NULL;
}

StackCalculator::~StackCalculator(){
    Op *current = head;
    while(head != NULL){
        head = head->next;
        delete current;
        current = current->next;
    }
}

bool StackCalculator::isEmpty(){
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}
void StackCalculator::push(float num){
    Op *node = new Op;
    node->num = num;
    node->next = head;
    head = node;
}

void StackCalculator::pop(){
    if(isEmpty()){
        cout << "Stack empty, cannot pop an item." << endl;
        return;
    }
    else{
        Op *temp = head;
        head = head->next;
        delete temp;
    }
}

Op* StackCalculator::peek(){
    if(isEmpty()){
        cout << "Stack empty, cannot peek." << endl;
        return NULL;
    }
    else{
        return head;
    }
}

bool StackCalculator::calculate(std::string symbol){
    float num1 = 0;
    float num2 = 0;
    float sum = 0;
        if(isEmpty()){
            cout << "err: not enough operands" << endl;
            return false;
        }
        else{
            if(symbol == "+"){
                num1 = head->num;
                pop();
                if(isEmpty()){
                    cout << "err: not enough operands" << endl;
                    push(num1);
                    return false;
                }
                else{
                    num2 = head->num;
                    pop();
                    sum = num1+num2;
                    push(sum);
                    return true;
                }
            }
            if(symbol == "*"){
                num1 = head->num;
                pop();
                if(isEmpty()){
                    cout << "err: not enough operands" << endl;
                    push(num1);
                    return false;
                }
                else{
                    num2 = head->num;
                    pop();
                    sum = num1*num2;
                    push(sum);
                    return true;
                }
            }
            else{
                cout << "err: invalid operation" << endl;
                return false;
            }
        }
}

