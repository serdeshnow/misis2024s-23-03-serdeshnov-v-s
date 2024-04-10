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

StackLst& StackLst::operator=(const StackLst& rhs) noexcept{
	if (this != &rhs) {
		Clear();
		if(!rhs.IsEmpty()) {
			StackLst tStack;  // temporary StackList

			Node* cur_rhs_node = rhs.head_;
			while (cur_rhs_node != nullptr) {  // from rhs to temporary
				tStack.Push(cur_rhs_node -> value);
				cur_rhs_node = cur_rhs_node -> next_node;
			}

			while(!tStack.IsEmpty()) {  // from temporary to this (&lhs)
				Push(tStack.Top()); // push top node from temporary to bottom position in this
				tStack.Pop(); // delete top node from temporary to get next node
			}
		}
	}
	return *this;
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
} // writing

const Complex &StackLst::Top() const {
  if (head_ != nullptr) {
    return head_ -> value;
  } else {
    throw std::logic_error("No data in StackLst");
  }
} // reading


void StackLst::Clear() noexcept {
  while (head_ != nullptr) {
    Pop();
  }
}

const bool StackLst::IsEmpty() const noexcept {
	return head_ == nullptr;
}

bool StackLst::IsEmpty() noexcept {
  return head_ == nullptr;
}




