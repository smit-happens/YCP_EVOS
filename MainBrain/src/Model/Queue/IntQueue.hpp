/**  Found from here: https://www.sanfoundry.com/cpp-program-implement-circular-queue/
 *
 * #include "IntQueue.hpp"
 * Created 6-14-18  By: Smitty
 *
 * A longer description.
 */


#ifndef INTQUEUE_HPP
#define INTQUEUE_HPP


#define MAXINT 256

class IntQueue
{
public:
    IntQueue();
    IntQueue(int length);

    ~IntQueue() { delete[] _queueArray; };

    void enqueue(int item);
    int dequeue(void);

    //queue is empty if both front and rear are -1
    bool isEmpty(void) { return front == -1 && rear == -1; };

    int peek(void) { return _queueArray[front]; };

    int getLength(void) { return _length; };

    int getSize(void);
    int getSum(void);
    int getAverage(void);

    // void display(void);

private:
    int *_queueArray;
    int front, rear;
    int _length;
};


#endif  //INTQUEUE_HPP