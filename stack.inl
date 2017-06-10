#define STACK(return_type) template<class ElementType> return_type stack<ElementType>::
#define constructor(para) template<class ElementType> stack<ElementType>::stack()
#define destructor() template<class ElementType> stack<ElementType>::~stack()

namespace Antinus{

constructor(){
	core = new list<ElementType>();
	length = 0;
}
	
destructor(){
	delete core;
}

STACK(void) Pop(){
	if(length > 0){
		core->Delete(0);
		length--;
	}
}

STACK(ElementType) PopOut(){
	ElementType mid;
	if(length > 0){
		mid = core->Query(0);
		core->Delete(0);
	}
	return mid;
}

STACK(void) Push(ElementType Value){
	core->Push(Value);
	length++;
}

}

#undef STACK
#undef constructor
#undef destructor