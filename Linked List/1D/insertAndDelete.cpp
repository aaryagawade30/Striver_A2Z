#include <bits/stdc++.h>
using namespace std;

class Node 
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
    
    public:
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* removeHead(Node* head) {
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* removeTail(Node* head) {
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

Node* removeAtK(Node* head, int k) {
    if(head == NULL) return head;
    if(k == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL) {
        cnt++;
        if(cnt == k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertHead(Node* head, int val) {
    Node* temp  = new Node(val, head);
    return temp;
}

Node* insertTail(Node* head, int val) {
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;

}

Node* insertAtK(Node* head, int el, int k) {
    if(head == NULL) {
        if(k == 1) return new Node(el);
        else return NULL;
    }

    if(k == 1) {
        Node* temp = new Node(el);
        return temp;
    }

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL) {
        cnt++;
        if(cnt = k -1) {
            Node* x = new Node(el);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {2, 3, 5, 3};
    Node* head = convertArr2LL(arr);
    //head = removeHead(head);
    //head = removeTail(head);
    //head = removeAtK(head, 3);
    head = insertAtK(head, 4, 2);
    print(head);
    return 0;
}