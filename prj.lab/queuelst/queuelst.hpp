#ifndef MISIS2024S_23_03_SERDESHNOV_V_S_QUEUELST_HPP
#define MISIS2024S_23_03_SERDESHNOV_V_S_QUEUELST_HPP

#include <cstdint>
#include "complex/complex.hpp"

class QueueLst {
public:
		QueueLst() = default;
		QueueLst(const QueueLst&);
		~QueueLst();
		QueueLst& operator=(const QueueLst&);

		bool IsEmpty() noexcept; //

		void Pop() noexcept; // from head_

		void Push(const Complex& val); //into tail_

		void Clear();

		Complex& Top();

		const Complex& Top() const;

private:
	struct Node {
		Node* next_node_ = nullptr;
		Complex value_;
	};
	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};


#endif //MISIS2024S_23_03_SERDESHNOV_V_S_QUEUELST_HPP
