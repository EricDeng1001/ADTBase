#define HASHTABLE(return_type) template<class elementType> return_type HashTable<elementType>::
#define constructor(para) template<class elementType>  HashTable<elementType>::HashTable(para)
#define destructor() template<class elementType> HashTable<elementType>::~HashTable()
namespace Antinus{

constructor(unsigned long TableSize){
	lists = new list<elementType>[TableSize];
	this->TableSize = TableSize;
}

destructor(){
	delete [] lists;
}


HASHTABLE(unsigned long) Hash(elementType Key){
	unsigned long hs;  
	hs = (unsigned long)Key;
    return hs % TableSize;  
}

HASHTABLE(void) Insert(elementType Key){
	unsigned long position = Hash(Key);
	if(Find(Key).Exist){
		return;
	}
	lists[position].Push(Key);
}

HASHTABLE(typename HashTable<elementType>::Position) Find(elementType Key){
	typename  HashTable<elementType>::Position tmp;
	unsigned long position = Hash(Key);
	tmp.Index_of_HashTable = position;
	unsigned long i = 0;
	unsigned long len = lists[position].length();
	while(i < len){
		if(lists[position].Query(i) == Key){
			Finded = tmp.Exist = true;
			tmp.Index_of_list = i;
			return tmp;
		}
		i++;
	}
	tmp.Index_of_list = 0;
	Finded = tmp.Exist = false;
	return tmp;
}

HASHTABLE(void) Delete(elementType Key){
	typename HashTable<elementType>::Position tmp;
	tmp = Find(Key);
	if(tmp.Exist){
		lists[tmp.Index_of_HashTable].Delete(tmp.Index_of_list);
	}
}

HASHTABLE(elementType) Query(typename HashTable<elementType>::Position p){
	return lists[p.Index_of_HashTable][p.Index_of_list];
} 

HASHTABLE(bool) NoFind(){
	return Finded == false;
}


template <>
unsigned long HashTable<char*>::Hash(char* str){
	unsigned long hs = 0;  
    while(*str) {
    	hs = (hs + (*str << 4) + (*str++ >> 4)) * 11;
    }  
    return hs % TableSize;  
}


template<>
void HashTable<char*>::Insert(char* Key){
	unsigned long position = Hash(Key);
	lists[position].Push(Key);
}

template<>
typename HashTable<char*>::Position HashTable<char*>::Find(char* Key){
	HashTable<char*>::Position tmp;
	unsigned long position = Hash(Key);
	tmp.Index_of_HashTable = position;
	unsigned long i = 0;
	unsigned long len = lists[position].length();
	while(i < len){
		if(!strcmp(lists[position].Query(i),Key)){
			Finded = tmp.Exist = true;
			tmp.Index_of_list = i;
			return tmp;
		}
		i++;
	}
	tmp.Index_of_list = 0;
	Finded = tmp.Exist = false;
	return tmp;
}

template <>
unsigned long HashTable<const char*>::Hash(const char* str){
	unsigned long hs = 0;  
    while(*str) {
    	hs = (hs + (*str << 4) + (*str++ >> 4)) * 11;
    }  
    return hs % TableSize;  
}


template<>
void HashTable<const char*>::Insert(const char* Key){
	unsigned long position = Hash(Key);
	lists[position].Push(Key);
}

template<>
typename HashTable<const char*>::Position HashTable<const char*>::Find(const char* Key){
	HashTable<const char*>::Position tmp;
	unsigned long position = Hash(Key);
	tmp.Index_of_HashTable = position;
	unsigned long i = 0;
	unsigned long len = lists[position].length();
	while(i < len){
		if(!strcmp(lists[position].Query(i),Key)){
			Finded = tmp.Exist = true;
			tmp.Index_of_list = i;
			return tmp;
		}
		i++;
	}
	tmp.Index_of_list = 0;
	Finded = tmp.Exist = false;
	return tmp;
}

}

#undef HASHTABLE
#undef constructor
#undef destructor
