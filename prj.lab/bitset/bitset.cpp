#include "bitset/bitset.hpp"

void BitSet::Set(const int32_t &idx, const bool &v) {
	if (idx < size_ && idx >= 0) {
		uint32_t page = idx / 32;
		uint32_t mask = 1 << (idx - page * 32);
		if (v) {
			data_[page] = data_[page] | mask;
		} else {
			mask = 0 - 1 - mask;
			data_[page] = data_[page] & mask;
		}
	} else {
		throw std::range_error("[bitset] - index is out of bitset range while set");
	}
}

bool BitSet::Get(const int32_t &idx) const {
	if (idx < size_ && idx >= 0) {
		uint32_t page = idx / 32;
		uint32_t mask = 1 << (idx - page*32);
		if ((data_[page] & mask) >> (idx - page*32) == true) {
			return true;
		} else {
			return false;
		}
	} else {
		throw std::range_error("[bitset] - index is out of bitset range while get");
	}
}

BitSet::BitSet(const int32_t &size) {
	if (size > 0) {
		int32_t count = (size) / 32 + 1;
		if (size % 32 == 0) {
			count -= 1;
		}
		for (int i = 0; i < count; i++) {
			data_.push_back(0);
		}
	} else {
		throw std::logic_error("[bitset] - You can't ctor a bitset with size less than 0");
	}
}

void BitSet::Fill() noexcept {
	for(unsigned int & i : data_){
		i = 0;
	}
}

int32_t BitSet::Size() const noexcept {
	return size_;
}

void BitSet::Resize(const int32_t &newSize) {
	if (size_ >= 0) {
		if (newSize < size_) {
			size_ = newSize;
		} else if (newSize <= data_.size() * 32) {
			size_ = newSize;
		} else if (newSize > data_.size() * 32) {
			int32_t diff_count = (newSize - data_.size() * 32) / 32 + 1;
			if ((newSize - data_.size() * 32) % 32 == 0) {
				diff_count -= 1;
			}
			for (int i = 0; i < diff_count; i++) {
				data_.push_back(0);
			}
			size_ = newSize;
		}
	} else {
		throw std::logic_error("[bitset] - You can't resize a bitset with size less than 0");
	}
}

BitSet::~BitSet() {
	data_.clear();
}

BitSet::BitSet(BitSet &&rhs) noexcept {
	std::swap(data_, rhs.data_);
	std::swap(size_, rhs.size_);
}

BitSet &BitSet::operator=(BitSet &&rhs) noexcept {
	std::swap(data_, rhs.data_);
	std::swap(size_, rhs.size_);
	return *this;
}

BitSet::BitSet(const BitSet &rhs) {
	for (unsigned int i : rhs.data_){
		data_.push_back(i);
	}
	size_ = rhs.size_;
}

BitSet &BitSet::operator=(const BitSet &rhs) {
	Resize(rhs.size_);
	for (int i = 0; i < rhs.data_.size(); i++){
		data_[i] = rhs.data_[i];
	}
	return *this;
}

bool BitSet::operator==(const BitSet &rhs) const noexcept {
	for (int i = 0; i < data_.size();i++){
		if (data_[i] != rhs.data_[i]){
			return false;
		}
	}
	return true;
}

bool BitSet::operator!=(const BitSet &rhs) const noexcept {
	return !(*this == rhs);
}

BitSet& BitSet::operator~() noexcept {
	for (int i = 0; i < data_.size();i++){
		data_[i] = 0 - data_[i] - 1;
	}
	return *this;
}

BitSet &BitSet::operator&=(const BitSet &rhs) {
	uint32_t page = size_ / 32;
	uint32_t mask = 0 - 1 << (size_ - page*32);
	mask = 0 - 1 - mask;
	for (int i = 0; i < page - 1;i++){
		data_[i] = rhs.data_[i] & data_[i];
	}
	data_[page] = rhs.data_[page] & mask;
	return *this;
}

BitSet::BitAccessor& BitSet::operator[](const int32_t idx) {
	if (idx >= 0 && idx < size_) {
		return {*this, idx};
	} else {
		throw std::range_error("[bitset] - index of out of range")
	}

}

bool BitSet::operator[](const int32_t idx) const {
	return bool(Get(idx));
}

BitSet::BitAccessor &BitSet::BitAccessor::operator=(const bool &val) {
	bst_.Set(idx_, val);
	return *this;
}

BitSet::BitAccessor::operator bool() const noexcept {
	return bst_.Get(idx_) == 1;
}