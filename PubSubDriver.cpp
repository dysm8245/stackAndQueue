#include "PubSub.hpp"
#include "PubSub.cpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Publisher (Publish items to the queue)" << endl;
	cout << "2. Subscriber (Retrieve items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}
// Use getline for reading
int main(int argc, char const *argv[])
{
	string input;
	bool flag = 1;
	PubSub pub;
	int num = 0;
		while(flag){
			menu();
			getline(cin,input);
			if(input == "1"){
				int itemNum = 1;
				cout << "Enter the number of items to be published:" << endl;
				getline(cin,input);
				num = stoi(input);
				for(int i = 0; i < num; i++){
					cout << "Item" << itemNum << ":" << endl;
					getline(cin,input);
					pub.enqueue(input);
					itemNum++;
				}
			}
			if(input == "2"){
				cout << "Enter the number of items to be retrieved:" << endl;
				getline(cin,input);
				num = stoi(input);
				int num1 = pub.queueSize();
				if(num > num1){
					for(int i = 0; i < num1; i++){
						string item = pub.peek();
						cout << "Retrieved: " << item << endl;
						pub.dequeue();
					}
					cout << "No more items to retrieve from queue" << endl;
				}
				else{
					for(int i = 0; i < num; i++){
						string item = pub.peek();
						cout << "Retrieved: " << item << endl;
						pub.dequeue();
					}
				}
			}
			if(input == "3"){
				cout << "Number of items in the queue:" << pub.queueSize() << endl;
				flag = 0;
			}
		}
}
