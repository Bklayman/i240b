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

  void clear() { element = 0; }

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
    return 0;
  }

  E shift(){
    return 0;
  }

  E unshift(){
    return 0;
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
