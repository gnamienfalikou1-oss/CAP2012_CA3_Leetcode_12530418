#include <vector>
using namespace std;


class MyCircularDeque {
    private:
        vector<int> data;
        int front;
        int rear;
        int count;
        int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        data.resize(k);
        front = 0;
        rear = 0;
        count = 0;
        
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        
        }
        front = (front - 1 + capacity) % capacity;
        data[front] = value;
        count++;
        return true ;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        data[rear] = value;
        rear = (rear + 1)% capacity;
        count++;
        return true;
    }

    bool deleteFront() {

    if (isEmpty())    {
        return false;
    }
    front = (front + 1) % capacity;
    count --;
    return true;
        
    }
    
    

    
    bool deleteLast() {
        if (isEmpty()){
            return false;
        }  
        rear = ( rear - 1 + capacity) % capacity;
        count--;
        return true;
    }  
    
    
    
    int getFront() {
        if (isEmpty()){
            return -1;
        
    }
    return data[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return data[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
    
