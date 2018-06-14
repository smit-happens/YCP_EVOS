/**  Found from here: https://www.sanfoundry.com/cpp-program-implement-circular-queue/
 *
 * IntQueue.cpp
 * Created 6-14-18  By: Smitty
 *
 * A longer description.
 */

#include "IntQueue.hpp"


/** 
 * @brief  IntQueue constructor
 */
IntQueue::IntQueue()
{
    IntQueue(MAX);
}


/** 
 * @brief  IntQueue constructor
 */
IntQueue::IntQueue(int size)
{
    //set size of the circular buffer
    if(size <= MAX)
        _size = size;
    else
        _size = MAX;

    _queueArray = new int[_size];

    //empty if rear and front are -1
    rear = front = -1;
}


/** 
 * @brief  
 * @note   
 * @param  item: CAN message to store
 * @retval None
 */
void IntQueue::enqueue(int item)
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
int IntQueue::dequeue(void)
{
    int poppedMessage;

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
