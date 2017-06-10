#ifndef _STACK_H_
#define _STACK_H_

#include "list.h"
#include "VirtualBase/BASICBase/loop.h"

namespace Antinus{
template<class ElementType>
class stack{
private:
	list<ElementType>* core;
	unsigned long length;
public:
	stack();
	~stack();
public:
	void Pop();
	ElementType PopOut();
	void Push(ElementType Value);
};

}

#include "stack.inl"
#endif