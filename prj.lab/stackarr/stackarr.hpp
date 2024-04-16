#ifndef STACKARR_LIB_HPP
#define STACKARR_LIB_HPP

#include "complex/complex.hpp"

#include <cstdint>
#include <stdexcept>

class StackArr {
public:
  StackArr(); //! done
  StackArr(const StackArr&); //! done
  ~StackArr(); //! done
  StackArr& operator=(const StackArr&); //

  void Push(const Complex&); //! done (4)

  void Pop() noexcept; //! done (3)

  [[nodiscard]] bool IsEmpty() const noexcept; //! done (1)

  [[nodiscard]] const Complex& Top() const; //! done (2)

  Complex& Top(); //! done (2.1)

  void Clear() noexcept; //! done


private:
  std::ptrdiff_t capacity_ = 0;

	int head_ = -1; // head_

	Complex* data_ = nullptr; // arr_
};

#endif // !STACKARR_LIB_HPP


