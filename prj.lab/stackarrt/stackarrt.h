#ifndef StackArrT_h
#define StackArrT_h

#include <cstdint>
#include <stdexcept>

template <class T>
class StackArrT {
public:
	StackArrT();

	StackArrT(const StackArrT& lhs);

	// StackArrT(StackArrT&& src) noexcept;

	~StackArrT();

	StackArrT& operator=(const StackArrT& lhs);

	//  StackArrT& operator=(StackArrT&& src) noexcept;

	void Push(const T& val);

	void Pop() noexcept;

	bool IsEmpty() const noexcept;

	const T& Top() const;

	T& Top();

	void Clear() noexcept;

private:
	std::ptrdiff_t capacity_ = 0;

	int head_ = -1;

	T* data_ = nullptr;
};

template<class T>
StackArrT<T>::StackArrT() {
	capacity_ = 1;
	data_ = new T[capacity_];
}

template<class T>
StackArrT<T>::StackArrT(const StackArrT &lhs) : head_(lhs.head_), capacity_(head_ + 1)  {
	data_ = new T[capacity_];
	for (int i = 0; i < head_ + 1; ++i) {
		data_[i] = lhs.data_[i];
	}
}

template<class T>
StackArrT<T>::~StackArrT() {
	Clear();
}

template<class T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT<T>& rhs) {
	if(capacity_ >= rhs.capacity_) {
		head_ = rhs.head_;
		for (int i = 0; i < head_ + 1; i += 1) {
			data_[i] = rhs.data_[i];
		}
	}
	else{
		head_ = rhs.head_;
		capacity_ = head_;
		data_ = new T[capacity_];
		for (int i = 0; i < head_ + 1; i += 1) {
			data_[i] = rhs.data_[i];
		}
	}
}

template<class T>
void StackArrT<T>::Push(const T &val) {
	if (head_ + 1 == capacity_) {
		capacity_ *= 2;
		T* new_ptr = new T[capacity_]; // T
		for(int i = 0; i < (head_ + 1); i += 1) {
			new_ptr[i] = data_[i];
		}
		delete[] data_;
		data_ = new_ptr;
	}
	head_ += 1;
	data_[head_] = val; // val
}


#endif //StackArrT_h
