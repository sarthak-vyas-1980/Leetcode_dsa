class MyCircularQueue {
    int* arr;
    int size;
    int front;
    int rear;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        size = k;
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if((front==0 && rear==size-1) || (front != -1 && rear == (front-1))) return 0;
        else if(front==-1){
            front = 0;
            rear = 0;
        }
        else if(rear==size-1 && front!=0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = value;
        return 1;
    }
    
    bool deQueue() {
        if(front==-1) return 0;
        else if(front==rear){
            front=-1;
            rear=-1;
        }
        else if(front==size-1){
            front = 0;
        }
        else {
            front++;
        }
        return 1;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return (front==0 && rear==size-1) || (front != -1 && rear == (front-1));
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */