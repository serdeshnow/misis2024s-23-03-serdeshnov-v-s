#ifndef MISIS2024S_23_03_SERDESHNOV_V_S_BITSET_H
#define MISIS2024S_23_03_SERDESHNOV_V_S_BITSET_H

#include <cstdint>
#include <stdexcept>
#include <vector>

class BitSet {
public:
		BitSet();
		BitSet(const BitSet&);
		BitSet(BitSet&&) noexcept ;
		BitSet& operator=(const BitSet&);
		BitSet& operator=(BitSet&&);
		~BitSet();

		BitSet& operator&(const BitSet& value); // AND BIT
		BitSet& operator|(const BitSet& value); // OR BIT
		BitSet& operator^(const BitSet& value); // XOR BIT
		BitSet& operator~(); // BIT Negative (negation)

		[[nodiscard]] int32_t Size() const; // get size(?)
		void Resize(const int32_t size); // change size
		void Set(const int32_t index, const bool value); // position and value
		bool Get(const int32_t index);
		void Fill(const bool value); // fill all bits to 0/1

private:
		std::vector<uint32_t> vec_; // unsigned
		int32_t size_; // signed // amount of vec_ elements (?) // each element contains 32 bits
};


#endif //MISIS2024S_23_03_SERDESHNOV_V_S_BITSET_H
