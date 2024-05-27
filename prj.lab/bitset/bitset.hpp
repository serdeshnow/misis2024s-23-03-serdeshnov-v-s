#ifndef MISIS2024S_23_03_SERDESHNOV_V_S_BITSET_HPP
#define MISIS2024S_23_03_SERDESHNOV_V_S_BITSET_HPP

#include <vector>
#include <cstdint>
#include <iostream>

class BitSet {
public:
	BitSet() = default;
	explicit BitSet(const int32_t& size);
	BitSet(const BitSet& rhs);
	BitSet(BitSet&& rhs) noexcept;
	BitSet& operator=(const BitSet& rhs);
	BitSet& operator=(BitSet&& rhs) noexcept;
	~BitSet();

	class BitAccessor {
		int32_t idx_;
		BitSet& bst_;
		BitSet::BitAccessor& operator=(const bool &val);
		explicit operator bool() const noexcept;
	};

	BitAccessor& operator[](const int32_t idx);
	bool operator[](const int32_t idx) const;

	void Fill() noexcept;
	bool Get(const int32_t& idx) const;
	void Set(const int32_t& idx, const bool& v);

	[[nodiscard]] int32_t Size() const noexcept;
	void Resize(const int32_t& newSize);

	bool operator==(const BitSet& rhs) const noexcept;
	bool operator!=(const BitSet& rhs) const noexcept;

	BitSet& operator~() noexcept;
	BitSet& operator&=(const BitSet& rhs);
	BitSet& operator|=(const BitSet& rhs);
	BitSet& operator^=(const BitSet& rhs);
private:
	std::vector<uint32_t> data_;
	int32_t size_ = 0;
};

BitSet operator&(const BitSet& lhs, const BitSet& rhs);
BitSet operator|(const BitSet& lhs, const BitSet& rhs);
BitSet operator^(const BitSet& lhs, const BitSet& rhs);


#endif //MISIS2024S_23_03_SERDESHNOV_V_S_BITSET_HPP
