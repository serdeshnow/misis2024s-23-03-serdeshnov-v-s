#include "stackarr.h"



StackArr::StackArr() {
	capacity_ = 10;
	data_ = new Complex[capacity_];
}

StackArr::~StackArr() {
	delete[] data_;
}

StackArr& StackArr::operator=(const StackArr&) {

}

void StackArr::Push() {

}

bool StackArr::IsEmpty() noexcept {
	return head_ == -1;
}

Complex& StackArr::Top() {
	if (head_ != -1) {
		return data_[head_];
	} else {
		throw std::logic_error ("No data in StackArr"); // error
	}
}

