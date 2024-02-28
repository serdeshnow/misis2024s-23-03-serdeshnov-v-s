#ifndef STACKLST_LIB_HPP
#define STACKLST_LIB_HPP
#include <cstdint>


class StackLst() {
public:
  StackLst() = default;
  StackLst(const StackLst&) = default;
  ~StackLst() = default;






private:
	struct Node {
		int value_; // int --> int&
		Node* next = nullptr; // указатель на следующий элемент

	};
	Node* head_ = nullptr;



}

#endif // !STACKLST_LIB_HPP
