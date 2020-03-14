#ifndef DLink_SEQ_HH_
#define DLink_SEQ_HH_

#include "seq.hh"

template <typename E> class DLinkSeqIter;

template <typename E> class DLinkSeq : public Seq<E>{
public:
  E element;
  DLinkSeq* next;
  DLinkSeq* prev;
  bool isEmpty = false;

  static SeqPtr<E> make() {
    return std::make_unique<DLinkSeq<E>>();
  }

  DLinkSeq(const E& it){
    element = it;
    next = nullptr;
    prev = nullptr;
  }

  DLinkSeq(const E& it, DLinkSeq* prevp, DLinkSeq* nextp){
    element = it;
    next = nextp;
    prev = prevp;
  }

  DLinkSeq(DLinkSeq* prevp = NULL, DLinkSeq* nextp = NULL){
    prev = prevp;
    next = nextp;
    isEmpty = true;
  }

  ~DLinkSeq() { delete[] next; delete[] prev; }

  void clear() {
    element = 0;
    isEmpty = true;
    if(next != nullptr){
      next = nullptr;
    }
    if(prev != nullptr){
      prev = nullptr;
    }
  }

  void unshift(const E& item){
    if(isEmpty){
      isEmpty = !isEmpty;
      element = item;
      return;
    }
    DLinkSeq<TestType>* newNode = new DLinkSeq<TestType>(item);
    DLinkSeq<TestType>* curNode = this;
    while(curNode->prev != nullptr){
      curNode = curNode->prev;
    }
    curNode->prev = newNode;
    newNode->next = curNode;
  }

  void push(const E& item){
    if(isEmpty){
      isEmpty = !isEmpty;
      element = item;
      return;
    }
    DLinkSeq<TestType>* newNode = new DLinkSeq<TestType>(item);
    DLinkSeq<TestType>* curNode = this;
    while(curNode->next != nullptr){
      curNode = curNode->next;
    }
    curNode->next = newNode;
    newNode->prev = curNode;
  }

  E pop() {
    if(isEmpty == true){
      return 0;
    }
    if(next == nullptr && prev == nullptr){
      isEmpty = true;
      E returnValue = element;
      element = 0;
      return returnValue;
    } else if(next == nullptr){
      E returnValue = element;
      element = prev->element;
      prev = prev->prev;
      next = nullptr;
      return returnValue;
    }
    DLinkSeq<TestType>* curNode = this;
    while(curNode->next != nullptr){
      curNode = curNode->next;
    }
    E returnValue = curNode->element;
    curNode->prev->next = NULL;
    return returnValue;
  }

  E shift(){
    if(isEmpty == true){
      return 0;
    }
    if(next == nullptr && prev == nullptr){
      isEmpty = true;
      E returnValue = element;
      element = 0;
      return returnValue;
    } else if(prev == nullptr){
      E returnValue = element;
      element = next->element;
      next = next->next;
      prev = nullptr;
      return returnValue;
    }
    DLinkSeq<TestType>* curNode = this;
    while(curNode->prev != nullptr){
      curNode = curNode->prev;
    }
    E returnValue = curNode->element;
    curNode->next->prev = NULL;
    return returnValue;
  }

  int size() const { return 0; }

  ConstIterPtr<E> cbegin() const {
    const DLinkSeq<E>* curNode = static_cast<const DLinkSeq*>(this);
    while(curNode->prev != nullptr){
      curNode = curNode->prev;
    }
    return std::make_unique<DLinkSeqIter<E>>(curNode);
  }

  virtual ConstIterPtr<E> cend() const {
    const DLinkSeq<E>* curNode = static_cast<const DLinkSeq*>(this);
    while(curNode->next != nullptr){
      curNode = curNode->next;
    }
    return std::make_unique<DLinkSeqIter<E>>(curNode);
  }

};

template <typename E> class DLinkSeqIter : public ConstIter<E>{
private:
  const DLinkSeq<E>* curNode;

public:

  DLinkSeqIter(const DLinkSeq<E>* node)
    : curNode(node)
  { }

  DLinkSeqIter& operator++(){
    curNode = curNode->next;
    return *this;
  }

  DLinkSeqIter& operator--(){
    curNode = curNode->prev;
    return *this;
  }

  virtual operator bool() {
    if(curNode == nullptr){
      return false;
    }
    return true;
  }

  const E& operator*() {
    return curNode->element;
  }

  const E* operator->() {
    return &(curNode->element);
  }

};

#endif
