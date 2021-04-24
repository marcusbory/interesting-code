#include <iostream>
using namespace std;

class Node {
private:
    int _data;
    Node* _next;
public:
    Node(int x) {
        _data = x;
        _next = nullptr;
    }
    friend class HashTable;
};

// An array of Node pointers in Heap
class HashTable {
private:
    Node** _hashTable;
public:
    HashTable();
    int hash(int key);
    void insert(int key);
    bool exist(int key);
    ~HashTable();
    friend class Node;
};

void menu() {
    cout << "Option 1: Check if a number exists in the (mod 7) Hash Table. " << endl;
    cout << "Option 2: Insert a key. " << endl;
    cout << "Option 3: Quit. " << endl;
}

int main() {
    cout << "Enter number of elements to be hashed into a (mod 7) Chaining Hash Table: ";
    int size; cin >> size;
    cout << endl << "Enter your " << size << " elements to be inserted into Chaining Hash Table: ";
    int* arr = new int[size];
    HashTable* ht = new HashTable;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    for (int ii = 0; ii < size; ii++)
        ht->insert(arr[ii]);

    bool flag = true;
    while (flag == true) {
        cout << "---------------------" << endl;
        menu();
        cout << "What do you want to do? ";
        int option; cin >> option;
        switch(option) {
            case 1:
                cout << "Key to check: ";
                int key; cin >> key;
                if (ht->exist(key))
                    cout << key << " exists!" << endl;
                else
                    cout << key << " does not exist :(" << endl;
                break;
            case 2:
                cout << "Key to insert: ";
                int keyInsert; cin >> keyInsert;
                ht->insert(keyInsert);
                cout << keyInsert << " successfully inserted!" << endl;
                break;
            case 3:
                cout << "Goodbye!" << endl;
                flag == false;
                exit(0);
        }
    }
    delete ht;
    return 0;
}

// Constructor
HashTable::HashTable() {
    _hashTable = new Node* [7];
    for (int i = 0; i < 7; i++)
        _hashTable[i] = nullptr;
}

int HashTable::hash(int key) {
    return key % 7;
}

bool HashTable::exist(int key) {
    int base = hash(key);
    // Item at _hashTable[base] is type Node*
    Node* temp = _hashTable[base];
    while (temp) {
        if (temp->_data == key)
            return true;
        temp = temp->_next;
    }
    return false;
}

void HashTable::insert(int key) {
    int base = hash(key);
    Node* temp = new Node(key);
    if (_hashTable[base] == nullptr)
        _hashTable[base] = temp;
    else {
        Node* head = _hashTable[base];
        Node* tail = nullptr;
        while (head && head->_data < key) {
            tail = head;
            head = head->_next;
        }
        // Case 1: Inserted key is head element, ie tail never traverse
        if (tail == nullptr) {
            temp->_next = _hashTable[base];
            _hashTable[base] = temp;
        }
        // Case 2: Inserted key is somewhere behind base element
        else {
            temp->_next = tail->_next;
            tail->_next = temp;
        }
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < 7; i++) {
        while (_hashTable[i]) {
            Node* del = _hashTable[i];
            _hashTable[i] = _hashTable[i]->_next;
            delete del;
        }
    }
    delete[] _hashTable;
    cout << "Hash Table deleted from heap!" << endl;
}
