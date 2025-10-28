class MyCircularDeque {
    int* arr;
    int size;
    int front;
    int rear;
public:
    MyCircularDeque(int k) {
        arr = new int[k];
        size = k;
        front = -1;
        rear = -1;
    }
    
    bool insertFront(int value) {
        if((front==0 && rear==size-1) || (front != -1 && rear == (front-1))) return 0;
        else if(front==-1){
            front = 0;
            rear = 0;
        }
        else if(front==0){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = value;
        return 1;
    }
    
    bool insertLast(int value) {
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
    
    bool deleteFront() {
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
    
    bool deleteLast() {
        if(front==-1) return 0;
        else if(front==rear){
            front=-1;
            rear=-1;
        }
        else if(rear==0){
            rear = size-1;
        }
        else {
            rear--;
        }
        return 1;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */