class MyCircularQueue {
public:
    int* arr;
    int front;
    int rear;
    int size;
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        if((front == 0 && rear == size-1) || ((rear + 1) % size == front)){
            return false;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(rear == size-1 && front!= 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(front == -1){
            return false;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear){
            front = rear = -1;
        }
        else if(front == size -1){
            front = 0;
        }
        else{
            front++;
        }
        return true;
    }
    
    int Front() {
        if(front == -1){
            return -1;
        }
        else{
            return arr[front];
        }
    }
    
    int Rear() {
        if(front == -1){
            return -1;
        }
        else{
            return arr[rear];
        }        
    }
    
    bool isEmpty() {
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if((front == 0 && rear == size-1) || ((rear + 1) % size == front)){
            return true;
        }
        else{
            return false;
        }        
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