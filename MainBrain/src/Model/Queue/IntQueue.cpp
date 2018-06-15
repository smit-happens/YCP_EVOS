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
IntQueue::IntQueue(int length)
{
    //set length of the circular buffer
    if(length <= MAXINT)
        _length = length;
    else
        _length = MAXINT;

    _queueArray = new int[_length];

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
    //queue is empty
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        if (rear == _length - 1)
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
 * @retval integer popped from queue
 */
int IntQueue::dequeue(void)
{
    int poppedMessage = -1;

    //nothing to pop, return -1
    if (front == -1)
    {
        return poppedMessage;
    }

    //number to pop
    poppedMessage = _queueArray[front];

    //queue had one element, set to empty
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == _length - 1)
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


/** 
 * @brief  
 * @note   
 * @retval The total amount of elements in the queue
 */
int IntQueue::getSize(void)
{
    //error if -1
    int currentSize = -1;

    //queue is empty
    if (front == -1)
    {
        currentSize = 0;
    }

    //normal order, front is ahead of rear
    if (front <= rear)
    {
        currentSize = rear - front;
    }
    else
    {
        //buffer has looped around, front is behind rear
        currentSize = (_length - front) + rear;
    }
    
    return currentSize;
}


/** 
 * @brief  
 * @note   
 * @retval average of all the integers in the buffer
 */
int IntQueue::getAverage(void)
{
    return getSum() / getSize();
}


int IntQueue::getSum()
{
    int sum = 0;
    int frontPosition = front, rearPosition = rear;

    //nothing to sum up, return 0
    if (frontPosition == -1)
    {
        return sum;
    }

    //while there are still elements in the queue
    while(frontPosition != -1)
    {
        //number to pop
        sum += _queueArray[frontPosition];

        //queue had one element, set to empty
        if (frontPosition == rearPosition)
        {
            frontPosition = -1;
            rearPosition = -1;
        }
        else
        {
            //looping the front back around
            if (frontPosition == _length - 1)
            {
                frontPosition = 0;
            }
            else
            {
                frontPosition++;
            }
        }
    }

    return sum;
}