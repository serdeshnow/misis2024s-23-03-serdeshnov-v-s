#include "bitset/bitset.hpp"

BitSet::BitSet() {
//	new std::vector<uint32_t> (size_); // who the fc is this
}

BitSet::BitSet(const BitSet&) {
	
}

BitSet::BitSet(BitSet&&) {

}

BitSet& BitSet::operator=(const BitSet&) {

}

BitSet& BitSet::operator=(BitSet&&) {

}

BitSet::~BitSet() {

}

BitSet& BitSet::operator&(const BitSet& value) {}
BitSet& BitSet::operator|(const BitSet& value) {} // OR BIT
BitSet& BitSet::operator^(const BitSet& value) {} // XOR BIT
BitSet& BitSet::operator~() {} // BIT Negative (negation)


int32_t BitSet::Size() const {return size_;}
void BitSet::Resize(const int32_t size) {

}
void BitSet::Set(const int32_t index, const bool value) {}
bool BitSet::Get(const int32_t index) {}
void BitSet::Fill(const bool value) {
}
