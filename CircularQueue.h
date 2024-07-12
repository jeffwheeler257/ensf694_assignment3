/*
 *  CircularQueue.h
 *  ENSF 694 Lab 3 - Exercise D
 *  Created by Mahmood Moussavi
 *  Submission date: July 17, 2024
 */

#ifndef CircularQueue_h
#define CircularQueue_h

#include <iostream>
#define SIZE 10

class CircularQueue {
private:
    int head;      // position of head
    int tail;      // position of tail
    int arr[SIZE]; // a queue array with maximum SIZE elements
    int count;     // keeps track of number of valid data in the queue
    
public:
    
    /* PROMISES: set initial values for head, tail, and count */
    CircularQueue();
    
    /* PROMISES: return value is true if queue is full */
    bool isFull()const;
    
    /* PROMISES: return value is true if queue is empty */
    bool isEmpty()const;
    
    /* PROMISES: adds value v to the tail and returns the position of tail */
    int enqueue(int v);
    
    /* PROMISES: returns the position of head, eliminates its value */
    int dequeue();
    
    /* PROMISES: displays the existing values in the queue */
    void displayQueue()const;
    
    /* PROMISES: returns the number of values in the queue */
    int counter()const;
    
    /* PROMISES: returns the address of the array arr */
    const int* get_arr()const;
};
#endif /* CircularQueue_h */
