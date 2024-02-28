#ifndef QUEUEARR_LIB_HPP
#define QUEUEARR_LIB_HPP
#include <cstdint>
#include <stdexcept>

class QueueArr {
public:
		QueueArr() ;
		QueueArr(const QueueArr&) = default;
		~QueueArr();
		QueueArr& operator=(const QueueArr&);

		void Push(const int);
		void Pop() noexcept;
		bool Is_empty() noexcept;

		const int Top() const;
		int Top();

private:
	int64_t tail_ = -1;
	int64_t head_ = -1;
	int64_t capacity_ = 0;
	int* data_ = nullptr;
};

#endif //QUEUEARR_LIB_HPP
