/*
 *  CircularQueue.cpp
 *  ENSF 694 Lab 3 - Exercise D
 *  Created by Mahmood Moussavi
 *  Completed by: Jeff Wheeler
 *  Submission date: July 17, 2024
 */

#include "CircularQueue.h"


CircularQueue::CircularQueue() {
    head = 1;
    tail = 1;
    count = 0;
}

bool CircularQueue::isFull()const {
    if (head == tail + 1)
        return true;
    return false;
}

bool CircularQueue::isEmpty()const {
    if (head == tail)
        return true;
    return false;
}

int CircularQueue::enqueue(int element) {
    if(CircularQueue::isFull()){
        std::cout << "Queue is full\n";
        return tail;
    }
    tail = (tail +1) % SIZE;
    arr[tail] = element;
    count++;
    return tail;
}

int CircularQueue::dequeue() {
    if(CircularQueue::isEmpty()){
        std::cout << "Queue is empty\n";
        return head;
    }
    head = (head + 1) % SIZE;
    // int dequeue_value = arr[head];
    count--;
    return head;
}

int CircularQueue::counter()const{
    return count;
}

const int* CircularQueue::get_arr()const{
    return arr;
}

void CircularQueue::displayQueue()const {
    std::cout << "\nElements in the queue:\n";
    if(CircularQueue::isEmpty()){
        std::cout << "Queue is empty\n";
    }
    else if (tail > head && tail < SIZE){    
        for (int i = head + 1; i <= tail; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    else if (tail < head){
        for(int i = head + 1; i < SIZE; i++){
            std::cout << arr[i] << " ";
        }
        for (int i = 0; i <= tail; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
}
