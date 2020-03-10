#ifndef DLink_SEQ_HH_
#define DLink_SEQ_HH_

#include "seq.hh"

template <typename E> class DLinkSeqIter;

template <typename E> class DLinkSeq : public Seq<E>{
private:
  E element;
  DLinkSeq* next;
  DLinkSeq* prev;

  enum class Private { TAG, DEFAULT_SIZE = 8 };
public:
  static SeqPtr<E> make(int size = static_cast<int>(Private::DEFAULT_SIZE)) {
    return std::make_unique<DLinkSeq<E>>(size, Private::TAG);
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
    return NULL;
  }

  E shift(){
    return NULL;
  }

  E unshift(){
    return NULL;
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

public:

  DLinkSeqIter(DLinkSeq<E>* node, bool isHead = true)
    : node(node),
      
  { }

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
