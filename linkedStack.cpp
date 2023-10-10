#include "linkedStack.h"

template<class ItemType>
LinkedStack<ItemType>::LinkedStack(){
    top = NULL;
}
template<class ItemType>
Node<ItemType>* LinkedStack<ItemType>:: getNodeAt(int position) const{
		Node<ItemType>* curPtr = top;
		for (int skip = 1; skip < position; skip++){
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}

template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const{
    return top == NULL;
}

template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry){
    Node<ItemType>* n = new Node<ItemType>();
    n->setItem(newEntry);
    if (isEmpty()){
        top = n;
    }
    else{
        n->setNext(top);
        top = n;
    }
    return true;
}

template<class ItemType>
bool LinkedStack<ItemType>::pop(){
    bool canPop = !isEmpty();

    if (canPop){
        Node<ItemType>* temp = top;
        top = top->getNext();
        delete temp;
    }
    return canPop;
}

template<class ItemType>
ItemType LinkedStack<ItemType>::peek() const{
   
    if (!isEmpty()){
        return (top->getItem());
    }
    else{
        throw "Empty Stack.";
    }
}