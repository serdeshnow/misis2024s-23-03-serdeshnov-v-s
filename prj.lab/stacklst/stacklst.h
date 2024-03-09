#ifndef STACKLST_LIB_HPP
#define STACKLST_LIB_HPP

#include "complex/complex.h"

#include <cstdint>
#include <stdexcept>


class StackLst {
public:
  StackLst() = default; // default
  StackLst(const StackLst&) = default; // (0)
  ~StackLst() = default; // (0)

  void Push(); // (3)

  void Pop(); // (4)

  Complex& Top(); // (2.1)

  const Complex& Top(); // (2.2)

  void Clear(); // (5)

  bool IsEmpty(); // (1)

private:
	struct Node {
		Complex& value_; // int --> int&

		Node* next = nullptr; // указатель на следующий элемент
	};
  Node* FindLast(); // (2.0)
	Node* head_ = nullptr;
}

#endif // !STACKLST_LIB_HPP
