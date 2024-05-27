#ifndef MISIS2024S_23_03_SERDESHNOV_V_S_QUEUELSTPR_H
#define MISIS2024S_23_03_SERDESHNOV_V_S_QUEUELSTPR_H
#include <stdexcept>

class QueueLstPr {
public:
	QueueLstPr() = default;
	QueueLstPr(const QueueLstPr& rhs);
	~QueueLstPr();

	QueueLstPr& operator=(const QueueLstPr& rhs);

	[[nodiscard]] bool IsEmpty() const noexcept;

	void Push(const float& val);

	float& Top();
	[[nodiscard]] const float& Top() const;

	void Pop() noexcept;

	void Clear() noexcept;

	QueueLstPr(QueueLstPr&& rhs) noexcept;
	QueueLstPr& operator=(QueueLstPr&& rhs) noexcept;

private:
	struct Node {
		float val = 0;
		Node* next_ = nullptr;
	};

	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};

#endif //MISIS2024S_23_03_SERDESHNOV_V_S_QUEUELSTPR_H
