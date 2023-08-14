// Queue_and_Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Hannah Beckley

#include <iostream>

using namespace std;

/* Stack
 - Last in First Out (LIFO)
 - all values are set to NULL and nullptr by defualt
 - ~Stack() should be called when user is done with a stack
 - "this" refers to the class object used to call the function
       and is the top most value within the stack
*/
class Stack {
    int data;
    Stack* next;

public:
    Stack() {
        this->data = NULL;
        this->next = nullptr;
    }

    Stack(int d) {
        this->data = d;
        this->next = nullptr;
    }

    Stack(int d, Stack* n) {
        this->data = d;
        this->next = n;
    }

    ~Stack() {
        delete this->next;
        //cout << "\n\nDestructor called\n\n";
    }

    int pop() {
        //"this" refers to the class object used to call the function
        //      and is the top most value of the stack
        int d = this->data;
        if (this->next != NULL) {
            this->data = this->next->data;
            this->next = this->next->next;
        } else {
            //"delete" is not called here in case the
            //    user wants to use the stack again
            this->data = NULL;
            this->next = nullptr;
        }
        return d;
    }

    void push(int d) {
        if (this->data == NULL)
            this->data = d;
          //"next" is nullptr by default
        else {
            Stack* s = new Stack(this->data, this->next);
            this->data = d;
            this->next = s;
        }
    }
};

/* Queue
 - First In First Out (FIFO)
 - all values are set to NULL and nullptr by defualt
 - ~Queue() should be called when user is done with a queue
 - "this" refers to the class object used to call the function
       and is the top most value within the queue
*/
class Queue {
    int data;
    Queue* next;

public:
    Queue() {
        this->data = NULL;
        this->next = nullptr;
    }

    Queue(int d) {
        this->data = d;
        this->next = nullptr;
    }

    Queue(int d, Queue* q) {
        this->data = d;
        this->next = q;
    }

    ~Queue() {
        delete this->next;
        //cout << "\n\nDestructor called\n\n";
    }

    int dequeue() {
        //"this" refers to the class object used to call the function
        //      and is the top most value of the queue.
        int d = this->data;
        if (this->next != NULL) {
            this->data = this->next->data;
            this->next = this->next->next;
        }
        else {
            //"delete" is not called here in case the
            //    user wants to use the queue again
            this->data = NULL;
            this->next = nullptr;
        }
        return d;
    }

    void enqueue(int d) {
        //"this" refers to the class object used to call the function
        //      and begins as the top most value of the queue.
        //      If the queue already contains values it will be called
        //      recursively to put the new value on the end.
        //      Each time the function recurs, "this" becomes the 
        //      proceding value until the end of the queue is reached.
        if (this->data == NULL)
            this->data = d;
          //"next" is nullptr by defualt
        else {
            if (this->next == NULL) {
                Queue* q = new Queue(d);
                this->next = q;
            }
            else
                this->next->enqueue(d);
        }
    }

};

int main()
{
    //std::cout << "Hello World!\n";  //testing

    /****Testing the functionality of the Stack and Queue****/
    //Stack work
    Stack* stack = new Stack(4);
    int data;

    stack->push(11);
    stack->push(8);
    data = stack->pop();
    cout << "Stack 1) First data value: " << data << endl;
    data = stack->pop();
    cout << "Stack 1) Second data value: " << data << endl << endl;

    Stack* s = new Stack();

    s->push(19);
    s->push(20);
    data = s->pop();
    cout << "Stack 2) First data value: " << data << endl;
    data = s->pop();
    cout << "Stack 2) Second data value: " << data << endl << endl;


    data = stack->pop();
    cout << "Stack 1) Third data value: " << data << endl << endl;

    stack->~Stack();
    s->~Stack();

    //Queue work
    Queue* queue = new Queue(5);

    queue->enqueue(8);
    queue->enqueue(12);
    queue->enqueue(14);

    data = queue->dequeue();
    cout << "Queue 1) First data value: " << data << endl;
    data = queue->dequeue();
    cout << "Queue 1) Second data value: " << data << endl;
    data = queue->dequeue();
    cout << "Queue 1) Third data value: " << data << endl;
    data = queue->dequeue();
    cout << "Queue 1) Fourth data value: " << data << endl;

    Queue* q = new Queue();
    q->enqueue(5);

    queue->~Queue();
    q->~Queue();

    return 0;

}
