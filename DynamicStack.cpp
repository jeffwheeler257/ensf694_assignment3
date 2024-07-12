/*
 *  DynamicStack.cpp
 *  ENSF 694 Lab 3 - Exercise E
 *  Created by Mahmood Moussavi
 *  Completed by: Jeff Wheeler
 *  Submission date: July 17, 2024
 */

#include "DynamicStack.h"
DynamicStack::DynamicStack(int n): entry(0), initial_capacity(n), current_capacity(n) {
    array = new int[n];
}

DynamicStack::DynamicStack(DynamicStack const &src) {
    this->entry = src.entry;
    this->initial_capacity = src.initial_capacity;
    this->current_capacity = src.current_capacity;
    array = new int[src.current_capacity];

    for (int i =0; i < src.current_capacity; i++){
        this->array[i] = src.array[i];
    }
}

DynamicStack::~DynamicStack() {
    delete[] array;
}

int DynamicStack::top() const {
    if (DynamicStack::empty())
        return -1; // if the stack is empty return -1
    return array[entry - 1];
}

int DynamicStack::size() const {
    return entry;
}

bool DynamicStack::empty() const {
    if (entry == 0)
        return true;
    return false;
}

int DynamicStack::capacity() const {
    return current_capacity;
}

DynamicStack &DynamicStack::operator=( DynamicStack const &rhs ) {
    if (this != &rhs){
        this->entry = rhs.entry;
        this->initial_capacity = rhs.initial_capacity;
        this->current_capacity = rhs.current_capacity;
        delete[] array;
        this->array = new int[rhs.current_capacity];

        for (int i = 0; i < rhs.entry; i++){
            this->array[i] = rhs.array[i];
        }
    }
    return *this;
}

void DynamicStack::push(const int  &obj) {
    array[entry] = obj;
    entry++;
    if(entry == current_capacity){
        DynamicStack new_stack(*this);
        new_stack.current_capacity = this->current_capacity * 2;
        *this = new_stack;
    }
}

void DynamicStack::pop() {
    if (entry == current_capacity / 4 && current_capacity > initial_capacity){
        DynamicStack new_stack(*this);
        new_stack.current_capacity = this->current_capacity / 2;
        *this = new_stack;
    }
    entry--;
}

void DynamicStack::clear() {
    entry = 0;
    if(current_capacity != initial_capacity){
        DynamicStack new_stack(*this);
        new_stack.current_capacity = this->initial_capacity;
        *this = new_stack;
    }
}

void DynamicStack::display(){
    for (int i = 0; i < this->entry; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
}
