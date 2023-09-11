#include "PubSub.hpp"
#include <iostream>
using namespace std;

PubSub::PubSub(){
    queueFront = 0;
    queueEnd = 0;
    for(int i = 0; i < 20; i++){
        queue[i] = "";
    }
}

bool PubSub::isEmpty(){
    int count = 0;
    for(int i = 0; i < 20; i++){
        if(queue[i] == ""){
            count++;
        }
    }
    if(count == 20){
        return true;
    }
    return false;
}
bool PubSub::isFull(){
    if(counter == 20){
        return true;
    }
    return false;
}
void PubSub::enqueue(string item){
    if(isEmpty()){
        queue[queueFront] = item;
        queueEnd++;
        counter++;
    }
    else if(isFull()){
        cout << "Queue full, cannot add new item" << endl;
    }
    else{
        if(queueEnd < 20){
            queue[queueEnd] = item;
            queueEnd++;
            counter++;
            if(counter == 20){
                queueEnd = queueFront;
            }
        }
        else if(queueEnd == 20){
            queue[0] = item;
            queueEnd = 1;
            counter++;
            if(counter == 20){
                queueEnd = queueFront;
            }
        }
    }
}
void PubSub::dequeue(){
    if(isEmpty()){
        cout << "Queue empty, cannot dequeue an item" << endl;
    }
    else{
        if(queueFront < 20){
            queue[queueFront] = "";
            queueFront++;
            counter--;
        }
        if(queueFront == 20){
            queueFront = 0;
        }
    }
}
string PubSub::peek(){
    string word;
    if(isEmpty()){
        cout << "Queue empty, cannot peek" << endl;
        word = "";
    }
    else{
        word = queue[queueFront];
    }
    return word;
}
  int PubSub::queueSize(){
      return counter;
  }