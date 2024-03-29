#ifndef STACKLST_LIB_HPP
#define STACKLST_LIB_HPP

#include "complex/complex.h"

#include <cstdint>
#include <stdexcept>


class StackLst {
public:
  StackLst() = default; // default
  StackLst(const StackLst&) = default; // (6)
  ~StackLst() = default; // (6.1)

  void Push(const Complex); // (3)

  void Pop() noexcept; // (4)

  Complex& Top(); // (2.1)

  const Complex& Top() const; // (2.2)

  void Clear() noexcept; // (5)

  bool IsEmpty() noexcept; // done (1)

private:
	struct Node {
		Complex& value_;
		Node* next_node = nullptr; // указатель на следующий элемент
	};
	Node* head_ = nullptr;
};

#endif // !STACKLST_LIB_HPP
