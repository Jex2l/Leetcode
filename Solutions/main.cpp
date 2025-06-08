#include <iostream>
using namespace std;

// ===============================================Single Linked List ========================================!
// class Node {
//     public:
//     int data;
//     Node* next;
//     Node(int data) {
//         this->data = data;
//         this->next = NULL;
//     }
//     ~Node() {
//         int value = this->data;
//         if (this->next != NULL) {
//             delete next;
//             this->next = NULL;
//         }
//         cout << "Deleted : " << value << endl;
//     }
// };
//
// void InsertAtHead(Node* &head, int data) {
//     Node* temp = new Node(data);
//     temp->next = head;
//     head = temp;
// }
//
// void InsertAtTail(Node* &tail, int data) {
//     Node* temp = new Node(data);
//     tail->next = temp;
//     tail = tail->next;
// }
//
// void InsertAtPosition(Node* &tail, Node* &head, int position, int data) {
//     if (position == 1) {
//         InsertAtHead(head, data);
//         return;
//     }
//     Node* temp = head;
//     int cnt = 1;
//     while (cnt < position - 1 && temp != NULL) {
//         temp = temp->next;
//         cnt++;
//     }
//     if (temp == NULL) {
//         InsertAtTail(tail, data);
//         return;
//     }
//     Node* nodeToInsert = new Node(data);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }
//
// void DeleteAtPosition(Node* &head, int position) {
//     if (position == 1) {
//         Node* temp = head;
//         head = head->next;
//         temp->next = NULL;
//         delete temp;
//     }
//     else {
//         Node* current = head;
//         Node* previous = NULL;
//         int cnt = 1;
//         while (cnt < position) {
//             previous = current;
//             current = current->next;
//             cnt++;
//         }
//         previous->next = current->next;
//         current->next = NULL;
//         delete current;
//     }
// }
//
//
// void print(Node* &head) {
//     Node* temp = head;
//     while (temp != NULL) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
// }




// ===============================================Double Linked List ========================================!

// class Node {
//     public:
//     int data;
//     Node* next;
//     Node* prev;
//
//     // Constructor
//     Node(int d) {
//         this->data = d;
//         this->next = NULL;
//         this->prev = NULL;
//     }
//
//     // Destructor
//     ~Node() {
//         int val = this->data;
//         if (next!=NULL) {
//             delete next;
//             next = NULL;
//         }
//         cout << "Deleted " << val << endl;
//     }
//
// };
//
// void InsertAtHead(Node* &head,Node* &tail, int d) {
//     if (head == NULL) {
//         Node* temp = new Node(d);
//         head = temp;
//         tail = temp;
//     }
//     else {
//         Node* temp = new Node(d);
//         temp->next = head;
//         head -> prev = temp;
//         head = temp;
//     }
// }
//
// void InsertAtTail(Node* &tail, Node* &head, int d) {
//     if (tail == NULL) {
//         Node* temp = new Node(d);
//         tail = temp;
//         head = temp;
//     }
//     else {
//         Node* temp = new Node(d);
//         tail->next = temp;
//         temp->prev = tail;
//         tail = temp;
//     }
// }
//
// void InsertAtPosition(Node* &tail, Node* &head, int position, int data) {
//     if (position == 1) {
//         InsertAtHead(head, tail, data);
//         return;
//     }
//     Node* temp = head;
//     int cnt = 1;
//     while (cnt < position - 1 && temp != NULL) {
//         temp = temp->next;
//         cnt++;
//     }
//     if (temp == NULL || temp->next == NULL) {
//         InsertAtTail(tail, head, data);
//         return;
//     }
//     Node* nodeToInsert = new Node(data);
//     nodeToInsert->next = temp->next;
//     temp->next->prev = nodeToInsert;
//     temp->next = nodeToInsert;
//     nodeToInsert->prev = temp;
// }
//
// void DeleteAtPosition(Node* &head, int position) {
//     if (position == 1) {
//         Node* temp = head;
//         temp->next->prev = NULL;
//         head = temp->next;
//         temp->next = NULL;
//         delete temp;
//     }
//     else {
//         Node* current = head;
//         Node* prev = NULL;
//         int cnt = 1;
//         while (cnt < position) {
//             prev = current;
//             current = current->next;
//             cnt++;
//         }
//         current->prev = NULL;
//         prev->next = current->next;
//         current->next = NULL;
//         delete current;
//     }
// }
//
// int getLength(Node* head) {
//     int len = 0;
//     Node* temp = head;
//     while(temp != NULL) {
//         len++;
//         temp = temp->next;
//     }
//     return len;
// }
//
//
// void print(Node* head) {
//     Node* temp = head;
//     while(temp != NULL) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }





// ===============================================Circular Linked List ========================================!
//
// class Node {
//     public:
//     int data;
//     Node* next;
//
//     // Constructor
//     Node(int d) {
//         this->data = d;
//         this->next = NULL;
//     }
//
//     // Destructor
//     ~Node() {
//         int val = this->data;
//         if (this->next!=NULL) {
//             delete next;
//             next = NULL;
//         }
//         cout << "Deleted " << val << endl;
//     }
//
// };
//
// void InsertNode(Node* &tail, int element, int d) {
//     if (tail==NULL) {
//         Node* newNode = new Node(d);
//         tail = newNode;
//         newNode->next = newNode;
//     }
//     else {
//         Node* curr = tail;
//         while (curr->data!=element) {
//             curr = curr->next;
//         }
//         Node* temp = new Node(d);
//         temp->next = curr->next;
//         curr->next = temp;
//     }
// }
//
//
// void DeleteAtPosition(Node* &tail, int value) {
//     if (tail==NULL) {
//         cout<<"Empty list"<<endl;
//         return;
//     }
//     else {
//         Node* prev = tail;
//         Node* curr = prev->next;
//         while (curr->data!=value) {
//             prev = curr;
//             curr = curr->next;
//         }
//         prev->next = curr->next;
//         if (curr == prev) {
//             tail = NULL;
//         }
//         else if (tail==curr) {
//             tail = prev;
//         }
//         curr->next = NULL;
//         delete curr;
//     }
// }
//
//
//
// void print(Node* tail) {
//     Node* temp = tail;
//     if (tail==NULL) {
//         cout<<"Empty list"<<endl;
//         return;
//     }
//     do {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     while(tail!=temp);
//     cout << endl;
// }



// Reverse Linked List ============================================================================

// void reverseList(ListNode* head) {
//     if(head == NULL || head->next == NULL){
//         return head;
//     }
//     ListNode* prev = NULL;
//     ListNode* curr = head;
//     ListNode* forward = NULL;
//
//     while(curr!=NULL){
//         forward = curr -> next;
//         curr -> next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     return prev;
// }

class Stack {
    // properties
    public:
        int *arr;
        int top;
        int size;

    // Behavior
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    // Functions

    void push(int element) {
        if (size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop() {
        if (top>=0) {
            top--;
        }
        else {
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek() {
        if (top>=0&& top<size) {
            return arr[top];
        }
        else {
            cout<<"Stack Empty"<<endl;
            return -1;
        }
    }

    bool empty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }

};


int main() {

    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);

    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    return 0;
}


























