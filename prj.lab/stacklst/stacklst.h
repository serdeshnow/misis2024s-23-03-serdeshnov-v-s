#ifndef STACKLST_LIB_HPP
#define STACKLST_LIB_HPP

#include "complex/complex.h"

#include <cstdint>
#include <stdexcept>


class StackLst {
public:
  StackLst() = default; //! default
  StackLst(const StackLst&); // (6)
  ~StackLst(); //! done (6.1)
  StackLst& operator=(const StackLst&); // (7)

  void Push(const Complex& val); //! done (3)

  void Pop() noexcept; //! done (4)

  [[nodiscard]] Complex& Top(); //! done (2.1)

  [[nodiscard]] const Complex& Top() const; //! done (2.2)

  void Clear() noexcept; //! done (5)

  bool IsEmpty() noexcept; //! done (1)

private:
	struct Node {
		Complex value;
		Node* next_node = nullptr; // указатель на следующий элемент
	};
	Node* head_ = nullptr;
};

#endif
