#define MAP(return_type) template<class KeyType,class ValueType> return_type map<KeyType,ValueType>::
#define constructor(para) template<class KeyType,class ValueType> map<KeyType,ValueType>::map(para)
#define destructor() template<class KeyType,class ValueType> map<KeyType,ValueType>::~map()

namespace Antinus{

constructor(unsigned long MapSize){
	KeyTable = new HashTable<KeyType>(MapSize);
	ValueTable = new list<ValueType>[MapSize];
}

destructor(){
	delete KeyTable;
	delete [] ValueTable;
}

MAP(void) Write(KeyType Key,ValueType Value){
	typename HashTable<KeyType>::Position tmp;
	tmp = KeyTable->Find(Key);
	if(tmp.Exist){
		ValueTable[tmp.Index_of_HashTable][tmp.Index_of_list] = Value;
	}
	else{
		KeyTable->Insert(Key);
		tmp = KeyTable->Find(Key);
		ValueTable[tmp.Index_of_HashTable].Push(Value);
	}
}

MAP(bool) Find(KeyType Key){
	return KeyTable->Find(Key).Exist;
}

MAP(void) Delete(KeyType Key){
	typename HashTable<KeyType>::Position tmp;
	tmp = KeyTable->Find(Key);
	if(tmp.Exist){
		KeyTable->Delete(Key);
		ValueTable[tmp.Index_of_HashTable].Delete(tmp.Index_of_list);
	}
}

#ifndef _IN_ADTBASE_MAP_FAST_QUERY_
MAP(ValueType) Query(KeyType Key){
	typename HashTable<KeyType>::Position tmp;
	ValueType res;
	tmp = KeyTable->Find(Key);
	if(tmp.Exist){
		return ValueTable[tmp.Index_of_HashTable][tmp.Index_of_list];
	}
	else{
		return res;
	}
}
#else
MAP(ValueType) Query(KeyType Key){
	typename HashTable<KeyType>::Position tmp;
	tmp = KeyTable->Find(Key);
	return ValueTable[tmp.Index_of_HashTable][tmp.Index_of_list];
}
#endif
MAP(ValueType&) operator [](KeyType Key){
	typename HashTable<KeyType>::Position tmp;
	ValueType res;
	tmp = KeyTable->Find(Key);
	if(tmp.Exist){
		return ValueTable[tmp.Index_of_HashTable][tmp.Index_of_list];
	}
	else{
		KeyTable->Insert(Key);
		tmp = KeyTable->Find(Key);
		ValueTable[tmp.Index_of_HashTable].Push(res);
		return ValueTable[tmp.Index_of_HashTable][0];
	}
}

}

#undef MAP
#undef constructor
#undef destructor