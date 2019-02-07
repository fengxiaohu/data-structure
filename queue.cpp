// it is a demo of normal queue  described by c 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 6
#define true 1
#define false 0
int array[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;
int dequeue_data = 0;

int peek() //check the front number of array

{
	return array[front];
}

bool isempty()
{
	if (front<0 || front>rear)
		return true;
	else
		return false;

}
bool isfull()
{
	if (rear == MAX - 1)
		return true;
	else
		return false;
}
int enqueue(int data) // enter queue
{
	if (isfull())
		return 0;
	else
		rear = rear + 1;
		array[rear] = data;
		return array[rear];
}
int dequeue() // exit from queue
{
	if (isempty())
		return false;
	else
		dequeue_data = array[front];
		front = front + 1;
		return dequeue_data;
		
}
int main()
{
	enqueue(3);
	enqueue(5);
	enqueue(9);
	enqueue(11);
	printf("front is %d", peek());
	dequeue();
	dequeue();
	return 0;
}