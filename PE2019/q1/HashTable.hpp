#pragma once
#include "HashTable.h"

HashTable::HashTable(int n) {
	N = n;
	for (int i = 0; i < n; i++)
		ht[i] = 0;
	//initially, populate hashtable with 0s
}



void HashTable::insertWithoutCollision(int n) {
	int base = h(n) % 50;
	ht[base] = n;
}

void HashTable::deleteWithoutCollision(int n) {
	int base = h(n) % N;
	if (ht[base] == n)
		ht[base] = DEL;
}

bool HashTable::existWithoutCollision(int n) {
	int base = h(n) % N;
	return (ht[base] == n);
}

void HashTable::insertWithCollision(int n) {
	int base = h(n) % N; int probeCount = 0;
	while (ht[(base + probeCount) % N] != 0)
		probeCount++;
	ht[(base + probeCount) % N] = n;
}

//n does not necasarrily exist in the hash table
void HashTable::deleteWithCollision(int n) {
	if (!existWithCollision(n)) return;
	int base = h(n) % N; int probeCount = 0;
	while (ht[(base + probeCount) % N] != n)
		probeCount++;
	ht[(base + probeCount) % N] = DEL;
}

bool HashTable::existWithCollision(int n) {
	int base = h(n) % N; int probeCount = 0;
	while (probeCount <= N && ht[(base + probeCount) % N] != 0) {
		if (ht[(base + probeCount) % N] == n) 
			return true;
		probeCount++;
	}
	return false;
}

void HashTable::printHashTable() {
	
	cout << "Current hash table: " << endl;
	for (int i = 0; i < N; i++) {
		cout << ht[i] << " ";
	}
	cout << endl;
}

