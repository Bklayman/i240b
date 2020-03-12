#ifndef DLink_SEQ_HH_
#define DLink_SEQ_HH_

#include "seq.hh"

template <typename E> class DLinkSeqIter;

template <typename E> class DLinkSeq : public Seq<E>{
private:
  E element;
  DLinkSeq* next;
  DLinkSeq* prev;

public:
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
  }

  ~DLinkSeq() { delete[] next; delete[] prev; }

  void clear() { element = 0; }

  void unshift(const E& item){
    DLinkSeq<TestType> newNode = DLinkSeq<TestType>(item);
    if(prev == nullptr){
      prev = &newNode;
      return;
    }
    DLinkSeq<TestType>* curNode = prev;
    while(curNode->prev != nullptr){
      curNode = curNode->prev;
    }
    curNode->prev = &newNode;
  }

  void push(const E& item){
    DLinkSeq<TestType> newNode = DLinkSeq<TestType>(item);
    if(next == nullptr){
      next = &newNode;
      return;
    }
    DLinkSeq<TestType>* curNode = next;
    while(curNode->next != nullptr){
      curNode = curNode->next;
    }
    curNode->next = &newNode;
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
    ConstIterPtr<TestType> iterator = std::make_unique<ArraySeqConstIter<TestType>>(curNode);
    return iterator;
  }

  virtual ConstIterPtr<E> cend() const {
    return NULL;
  }

  DLinkSeq* getNext() const{
    return next;
  }

  DLinkSeq* getPrev() const{
    return prev;
  }

  E* getElement() const{
    return &element;
  }

};

template <typename E> class DLinkSeqIter : public ConstIter<E>{
private:
  const DLinkSeq<E>* curNode;

public:

  DLinkSeqIter(const DLinkSeq<E>* node){
    curNode = node;
  }

  DLinkSeqIter& operator++(){
    curNode = curNode->getNext();
    return *this;
  }

  DLinkSeqIter& operator--(){
    curNode = curNode->getPrev();
    return *this;
  }

  virtual operator bool() {
    if(curNode == nullptr){
      return false;
    }
    return true;
  }

  const E& operator*() {
    return *(curNode->getElement());
  }

  const E* operator->() {
    return curNode->getElement();
  }

};

#endif
