#ifndef STACKARR_LIB_HPP
#define STACKARR_LIB_HPP

#include <complex/complex.h>

#include <cstdint>
#include <stdexcept>

class StackArr {
public:
  StackArr();
	StackArr(const StackArr&) = default;
  ~StackArr();
  StackArr& operator=(const StackArr&);

  void Push(const Complex); // (4)

  void Pop() noexcept; // (3)

  bool IsEmpty() noexcept; // done (1)

  const Complex& Top() const; // (2)

	Complex& Top(); // (2.1)


private:
  std::ptrdiff_t capacity_ = 0;

	int head_ = -1; // head_

	Complex* data_ = nullptr; // arr_

};

#endif // !STACKARR_LIB_HPP


