/*
 *  DynamicStack.h
 *  ENSF 694 Lab 3 - Exercise E
 *  Created by Mahmood Moussavi
 *  Submission date: July 17, 2024
 */

#ifndef DynamicStack_H
#define DynamicStack_H
#include <iostream>
using namespace std;
class DynamicStack {
private:
    int entry;
    int initial_capacity;
    int current_capacity;
    int *array;

public:
    /* PROMISES: sets value of entry to 0, initial_capacity and current_capacity to n,
     * and allocates memory space for array */
    DynamicStack(int n);
    
    /* PROMISES: copy constructor for DynamicClass */
    DynamicStack(DynamicStack const &src);
    

    /* PROMISES: destructor for DynamicClass */
    ~DynamicStack();
    
    /* PROMISES: Returns the value at the top of the stack, if the stack is empty returns -1. */
    int top() const;
    
    /* PROMISES: Returns the number values stores in the stack */
    int size() const;
    
    /* PROMISES: Returns true if stack is empty */
    bool empty() const;
    
    /* PROMISES: Returns current capacity of the array in the stack */
    int capacity() const;
    
    void swap( DynamicStack &stack );
    
    /* PROMISES: Assignment operator for DynamicStack class */
    DynamicStack &operator=(const DynamicStack& );
    
    /* PROMISES: The value of v is added at the top of the stack. If the array is full,
     * the current capacity of the array is doubled, the value of v is added.
     */
    void push(const int &obj);
    
    /* PROMISES: Removes the element at the top of the stack. If, only one fourth of
     * the array is full,  and the array's capacity is greater than it's initial capacit, the
     * capacity of the array is halved.
     */
    void pop();
    
    /* PROMISES: removes all the entry values from stack and if necessary resizes
     * the array to its initial capacity.
     */
    void clear();
    
    /* PROMISES: displays all the existing values in the stack */
    void display();
};
#endif
