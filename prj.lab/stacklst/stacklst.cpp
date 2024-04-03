#include "stacklst.h"

StackLst::StackLst(const StackLst& rhs) : head_(rhs.head_) { // rhs == old_stack
  Node* rhs_ptr = rhs.head_;
  while (rhs_ptr != nullptr) {
    Complex lhs_value = rhs_ptr->value;
    Push(lhs_value);
    rhs_ptr = rhs_ptr->next_node;
  }
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
  (*head_).value = val;
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
    return head_ -> value;
  } else {
    throw std::logic_error("No data in StackLst");
  }
} // запись

const Complex &StackLst::Top() const {
  if (head_ != nullptr) {
    return head_ -> value;
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


