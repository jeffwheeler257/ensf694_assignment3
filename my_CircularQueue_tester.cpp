/*
 *  CircularQueue_tester copy.cpp
 *  ENSF 694 Lab 3 - Exercise D
 *  Created by Mahmood Moussavi
 *  Completed by: Jeff Wheeler
 *  Submission date: July 17, 2024
 */

#include "CircularQueue.h"
using namespace std;

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.displayQueue();

    cout << "\nCount = " << q.counter() << std::endl;
    cout << "isFull = " << q.isFull() << std::endl;


    cout << "Dequeue value = " << q.dequeue() << std::endl;
    cout << "Dequeue value = " << q.dequeue() << std::endl;

    q.displayQueue();

    cout << "\nCount = " << q.counter() << std::endl;
    cout << "isFull = " << q.isFull() << std::endl;

    cout << "Dequeue value = " << q.dequeue() << std::endl;

    cout << "\nCount = " << q.counter() << std::endl;
    cout << "isEmpty = " << q.isEmpty() << std::endl;

    return 0;
}