#include <iostream>
using namespace std;
#define EMPTY -1
#define DEL -2

class HashTable {
private:
    int* _ht;
    int _load;
    int _capacity;
public:
    HashTable(int cap);
    void insert(int key);
    void deleteKey(int key);
    int search(int key);
    int hash(int key);
    int linearProbe(int key);
    bool isFull() { return (_load == _capacity); }
    void printTable();
    ~HashTable() { delete _ht; cout << "Hash Table deleted." << endl;}
};

void menu();

int main() {
    cout << "Enter size of Hash Table (Linear Probing version): ";
    int size; cin >> size;
    HashTable* ht = new HashTable(size);
    while (true) {
        menu();
        int option; cin >> option;
        switch(option) {
            case 1:
                cout << "The current hash table you created is: " << endl;
                ht->printTable();
                cout << endl;
                break;
            case 2:
                if (!ht->isFull()) {
                    cout << "Key to insert: ";
                    int keyInsert; cin >> keyInsert;
                    ht->insert(keyInsert);
                    cout << keyInsert << " inserted successfully!" << endl;
                }
                else
                    cout << "HASH TABLE FULL" << endl;
                break;
            case 3:
                cout << "Enter key to search: ";
                int keySearch; cin >> keySearch;
                if (ht->search(keySearch) == -1)
                    cout << "Key not found :(" << endl;
                else
                    cout << keySearch << " is found at index " << ht->search(keySearch) << endl;
                break;
            case 4:
                cout << "Enter key to delete: ";
                int keyDel; cin >> keyDel;
                if (ht->search(keyDel) == -1)
                    cout << "Key not found :(" << endl;
                else {
                    ht->deleteKey(keyDel);
                    cout << "Key " << keyDel << " successfully deleted." << endl;
                }
                break;
            case 5:
                cout << "Goodbye!" << endl;
                delete ht;
                exit(0);
        }
    }
    return 0;
}

HashTable::HashTable(int cap) {
    _ht = new int [cap];
    _load = 0;
    _capacity = cap;
    for (int i = 0; i < cap; i++)
        _ht[i] = EMPTY;
}

int HashTable::hash(int key) {
    return key % _capacity;
}

int HashTable::linearProbe(int key) {
    int base = hash(key);
    int probeCount = 0;
    while (_ht[(base + probeCount) % _capacity] != EMPTY)
        probeCount++;
    return (base + probeCount) % _capacity;
}

void HashTable::insert(int key) {
    int base, insertIndex;
    base = insertIndex = hash(key);
    if (_ht[base] != EMPTY && _ht[base] != DEL)
        insertIndex = linearProbe(key);
    _ht[insertIndex] = key;
    _load++;
}

void HashTable::deleteKey(int key) {
    int deleteIndex = search(key);
    if (deleteIndex == -1) return;
    _ht[deleteIndex] = DEL;    
}

int HashTable::search(int key) {
    int base = hash(key);
    int probeCount = 0;
    while (_ht[(base + probeCount) % _capacity] != key) {
        probeCount++;
        if (_ht[(base + probeCount) % _capacity] == EMPTY)
            return -1;
    }
    return (base + probeCount) % _capacity;
}

void HashTable::printTable() {
    for (int i = 0; i < _capacity; i++) {
        if (_ht[i] == EMPTY)
            cout << "EMPTY ";
        else if (_ht[i] == DEL)
            cout << "DEL ";
        else
            cout << _ht[i] << " ";
    }
}

void menu() {
    cout << "----------------------------" << endl;
    cout << "Option 1. Check hash table." << endl;
    cout << "Option 2. Insert a key. (Only if hash table is not full!)" << endl;
    cout << "Option 3. Search for the index of a key." << endl;
    cout << "Option 4. Delete a key (existing)." << endl;
    cout << "Option 5. Quit." << endl;
    cout << "What do you want to do? ";
}
