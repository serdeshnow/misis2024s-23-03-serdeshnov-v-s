#include "stacklst.h"

StackLst::StackLst(const StackLst& old_stack) : head_(old_stack.head_) {

}

StackLst::~StackLst() {
  StackLst::Clear();
}

StackLst& StackLst::operator=(const StackLst&) {

}

void StackLst::Push(const Complex& val) {
  Node* temp = head_;
  Node* new_node = new Node;
  head_ = new_node;
  (*head_).next_node = temp; // == head_ -> next_node = temp;
  (*head_).value_ = val;
}

void StackLst::Pop() noexcept {
  if(head_ != nullptr) {
    Node* temp = head_ -> next_node;
    delete head_;
    head_ = temp;
  }
}

Complex& StackLst::Top() {
  if (head_ != nullptr) {
    return head_ -> value_;
  } else {
    throw std::logic_error("No data in StackLst");
  }
} // запись

const Complex &StackLst::Top() const {
  if (head_ != nullptr) {
    return head_ -> value_;
  } else {
    throw std::logic_error("No data in StackLst");
  }
} // чтение


void StackLst::Clear() noexcept {
  while (head_ != nullptr) {
    Pop();
  }
}

bool StackLst::IsEmpty() noexcept {
  return head_ == nullptr;
}


