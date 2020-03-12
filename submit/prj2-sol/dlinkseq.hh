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

  }

  void push(const E& item){

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
    return NULL;
  }

  virtual ConstIterPtr<E> cend() const {
    return NULL;
  }

};

template <typename E> class DLinkSeqIter : public ConstIter<E>{
private:
  DLinkSeq<E>* next;
  DLinkSeq<E>* prev;
  E element;
public:

  DLinkSeqIter(DLinkSeq<E>* node){
    next = node->next;
    prev = node->prev;
    element = node->element;
  }

  DLinkSeqIter& operator++(){
    return NULL;
  }

  DLinkSeqIter& operator--(){
    return NULL;
  }

  virtual operator bool() {
    return false;
  }

  const E& operator*() {
    return NULL;
  }

  const E* operator->() {
    return NULL;
  }

};

#endif
