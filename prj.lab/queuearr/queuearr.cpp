#include "queuearr.h"

QueueArr::QueueArr() {
	capacity_ = 10;
	data_ = new int[capacity_];
	head_ = data_[0];
}

QueueArr::~QueueArr() {
	delete[] data_;
}

 /// CHECK OUT PUSH() HERE
void QueueArr::Push(const int) {
	if (tail_ < capacity_) {
		tail_ += 1;
		// more code
	}
	else if (tail_ >= capacity_ && head_ != data_[0]) {
		//code??
	}
}
///

void QueueArr::Pop() noexcept{
	head_ += 1; // до переполнения
}

bool QueueArr::Is_empty() noexcept {
	return head_ == -1;
}

int QueueArr::Top(){
	if (head_ != -1) {
		return data_[head_];
	}
	else{
		throw std::logic_error ( "No data in QueueArr" );
	}
}

