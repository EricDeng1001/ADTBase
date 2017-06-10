#ifndef _MAP_H_
#define _MAP_H_

#include "VirtualBase/BASICBase/loop.h"
#include "HashTable.h"

namespace Antinus{

template<class KeyType,class ValueType>
class map{
private:
	HashTable<KeyType>* KeyTable;
	list<ValueType>* ValueTable;
public:
	map(unsigned long MapSize = 10007);
	~map();
public:
	void Write(KeyType Key,ValueType Value);
	bool Find(KeyType Key);
	void Delete(KeyType Key);
	ValueType Query(KeyType Key);//Please use a existed Key(using Find to make sure it exist),or you will recieve random value;
	//To make sure no problem will happen when you use the non-exist key, I defaultly use safe-mod which slow down the speed;
	//To speed up(which make non-exist Query unstable), #define _IN_ADTBASE_MAP_FAST_QUERY_
public:
	ValueType& operator [](KeyType Key);
};

}

#include "map.inl"
#endif