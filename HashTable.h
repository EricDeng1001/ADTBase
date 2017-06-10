#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <string.h>
#include "VirtualBase/BASICBase/loop.h"
#include "list.h"

namespace Antinus{
template <class T>
class HashTable{
public:
	typedef struct {
		unsigned long Index_of_HashTable;
		unsigned long Index_of_list;
		bool Exist;
	}Position;
private:
	list<T>* lists;
	unsigned long TableSize;
	bool Finded;
private:
	unsigned long Hash(T Key);
public:
	HashTable(unsigned long TableSize = 10007);
	~HashTable();
public:
	void Insert(T Key);
	Position Find(T Key);
	void Delete(T Key);
	T Query(Position p);
public:
	bool NoFind();
};

template <> 
void HashTable<char*>::Insert(char* str);
template <> 
unsigned long HashTable<char*>::Hash(char* str);
template <> 
typename HashTable<char*>::Position HashTable<char*>::Find(char* Key);

template <> 
void HashTable<const char*>::Insert(const char* str);
template <> 
unsigned long HashTable<const char*>::Hash(const char* str);
template <> 
typename HashTable<const char*>::Position HashTable<const char*>::Find(const char* Key);

}

#include "HashTable.inl"
#endif