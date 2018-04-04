/**  Found from here: https://www.sanfoundry.com/cpp-program-implement-circular-queue/
 *
 * #include "Queue.hpp"
 * Created 3-26-18  By: Smitty
 *
 * A longer description.
 */


#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <FlexCAN.h>

#define MAX 128

class Queue
{
public:
    Queue();

    void enqueue(CAN_message_t item);
    CAN_message_t dequeue(void);

    //queue is empty if both front and rear are -1
    bool isEmpty(void) { return front == -1 && rear == -1; };

    CAN_message_t peek(void) { return _queueArray[front]; };

    // void display(void);

private:
    CAN_message_t *_queueArray;
    int front, rear;
};


#endif  //QUEUE_HPP