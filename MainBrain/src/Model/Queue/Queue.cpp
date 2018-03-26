/**  Found from here: https://www.sanfoundry.com/cpp-program-implement-circular-queue/
 *
 * Queue.cpp
 * Created 3-26-18  By: Smitty
 *
 * A longer description.
 */

#include "Queue.hpp"


/** 
 * @brief  Queue constructor
 */
Queue::Queue()
{
    _queueArray = new CAN_message_t[MAX];

    //empty if rear and front are -1
    rear = front = -1;
}


/** 
 * @brief  
 * @note   
 * @param  item: CAN message to store
 * @retval None
 */
void Queue::enqueue(CAN_message_t item)
{
    //queue is filled up or has already started overwriting data
    if ((front == 0 && rear == MAX-1) || (front == rear+1))
    {
        return;
    }

    //queue is empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == MAX - 1)
        {
            //circle around
            rear = 0;
        }
        else
        {
            rear = rear + 1;
        }
    }

    _queueArray[rear] = item;

}


/** 
 * @brief  
 * @note   
 * @retval CAN Message popped from queue
 */
CAN_message_t Queue::dequeue(void)
{
    CAN_message_t poppedMessage;

    //nothing to pop, return blank message
    if (front == -1)
    {
        return poppedMessage;
    }

    //message to pop
    poppedMessage = _queueArray[front];

    //queue had one element, set to empty
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    return poppedMessage;
}


/*
* Display Circular Queue
*/
// void Queue::display(void)
// {
//     int front_pos = front;
//     int rear_pos = rear;

//     if (front == -1)
//     {
//         Serial.println("Queue is empty");
//         return;
//     }

//     Serial.println("Queue elements :")

//     if (front_pos <= rear_pos)
//     {
//         while (front_pos <= rear_pos)
//         {
//             Serial.print(_queueArray[front_pos]);
//             Serial.println("  ");

//             front_pos++;
//         }
//     }
//     else
//     {
//         while (front_pos <= MAX - 1)
//         {
//             Serial.print(_queueArray[front_pos]);
//             Serial.print("  ");
//             front_pos++;
//         }

//         front_pos = 0;

//         while (front_pos <= rear_pos)
//         {
//             Serial.print(_queueArray[front_pos]);
//             Serial.print("  ");
//             front_pos++;
//         }
//     }

//     Serial.println();
// }