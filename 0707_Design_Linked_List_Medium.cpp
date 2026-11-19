class MyLinkedList {
private:
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int x) : val(x), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int size;

public:

    MyLinkedList() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }

        Node* curr;
        if (index < size / 2) {
            curr = head->next;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
        } else {
            curr = tail->prev;
            for (int i = 0; i < size - 1 - index; i++) {
                curr = curr->prev;
            }
        }
        return curr->val;
    }

    void addAtHead(int val) {
        Node* first = head->next;
        Node* newNode = new Node(val);

        newNode->prev = head;
        newNode->next = first;
        head->next = newNode;
        first->prev = newNode;
        size++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        Node* last = tail->prev;

        newNode->prev = last;
        newNode->next = tail;
        last->next = newNode;
        tail->prev = newNode;
        size++ ;
    }
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if ( index == size ) {
            addAtTail(val);
            return;
        }       

        Node* curr = head->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }


        Node* prevNode = curr->prev;
        Node* newNode = new Node(val); 
        newNode->prev = prevNode;
        newNode->next = curr;
        prevNode->next = newNode;
        curr->prev = newNode;
        size++;
    } 
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }

        Node* curr = head->next;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        Node* prevNode = curr->prev;
        Node* nextNode = curr->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete curr;
        size--;
    }   
};
    







        
  
