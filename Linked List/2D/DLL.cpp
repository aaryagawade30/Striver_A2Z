#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


Node* deleteHead(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    free(prev);
    return head;
}

Node* deleteTail(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    free(tail);
    return head;
}

Node* removeAtK(Node* head, int k) {

    if(head == NULL) return NULL;
    // stops at kth elem
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL) {
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;

    // if only 1 elem
    if(prev == NULL && front == NULL) {
        free(temp);
        return NULL;
    }
    
    else if(prev == NULL) return deleteHead(head);

    else if(front == NULL) return deleteTail(head);

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return head;
}

void deleteNode(Node* temp) {
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL) {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }

    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
}


Node* insertBeforeHead(Node* head, int val) {
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head, int val) {
    if(head->next = NULL) return insertBeforeHead(head, val);

    Node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(10, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node* insertBeforeKth(Node* head, int val, int k) {
    if(k == 1) return insertBeforeHead(head, val);

    Node* temp = head;
    int cnt = 0; 
    while(temp != NULL) {
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

void();

int main()
{
    vector<int> arr = {2, 5, 3, 6};
    Node* head = convertArr2DLL(arr);
    head = removeAtK(head, 1);
    print(head);
    return 0;
}