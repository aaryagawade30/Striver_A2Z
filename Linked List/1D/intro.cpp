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

int len_of_LL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int check_searched(Node* head, int val) {
    Node* temp = head;
    while(temp) {
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}


int main()
{
    vector<int> arr = {12, 5, 8, 7};
    /*Node* y = new Node(arr[0]);
    cout << y;
    cout << y->data;
    */
    Node* head = convertArr2LL(arr);
    cout << head->data;   

    // traversal
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<< len_of_LL(head);
    cout << check_searched(head, 8);
    return 0;
}