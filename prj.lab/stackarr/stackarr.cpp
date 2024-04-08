#include "stackarr.h"

StackArr::StackArr() {
	capacity_ = 1;
	data_ = new Complex[capacity_];
}

StackArr::StackArr(const StackArr &old_stack) : head_(old_stack.head_), capacity_(head_ + 1) {
	data_ = new Complex[capacity_];
	for (int i = 0; i < head_ + 1; i += 1) {
//		Push(old_stack.data_[i]);
      data_[i] = old_stack.data_[i];
	}
}

StackArr::~StackArr() {
	delete[] data_;
}

StackArr& StackArr::operator=(const StackArr& rhs){
	if(capacity_ >= rhs.capacity_) {
		head_ = rhs.head_;
		for (int i = 0; i < head_ + 1; i += 1) {
			data_[i] = rhs.data_[i];
		}
	}
	else{
		head_ = rhs.head_;
		capacity_ = head_;
		data_ = new Complex[capacity_];
		for (int i = 0; i < head_ + 1; i += 1) {
			data_[i] = rhs.data_[i];
		}
	}
}

void StackArr::Push(const Complex& elem) {
	if (head_ + 1 == capacity_) {
		capacity_ *= 2;
		Complex* new_ptr = new Complex[capacity_];
		for(int i = 0; i < (head_ + 1); i += 1) {
			new_ptr[i] = data_[i];
		}
		delete[] data_;
		data_ = new_ptr;
	}
	head_ += 1;
	data_[head_] = elem;
}

void StackArr::Pop() noexcept {
	if(head_ != -1) {
		head_ -= 1;
	}
}

bool StackArr::IsEmpty() const noexcept {
	return head_ == -1;
}

Complex& StackArr::Top() {
	if (head_ != -1) {
		return data_[head_];
	} else {
		throw std::logic_error ("No data in StackArr"); // error
	}
}

const Complex& StackArr::Top() const{
	if (head_ != -1) {
		return data_[head_];
	} else {
		throw std::logic_error ("No data in StackArr"); // error
	}
}

void StackArr::Clear() noexcept {
	head_ = -1;
}

