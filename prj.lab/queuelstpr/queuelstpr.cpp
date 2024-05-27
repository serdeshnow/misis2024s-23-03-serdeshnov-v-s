#include "queuelstpr.hpp"

bool QueueLstPr::IsEmpty() const noexcept {
	return (head_ == nullptr);
}

float& QueueLstPr::Top() {
	if (IsEmpty()) {
		throw std::invalid_argument("QueueLstPr - No top element!");
	} else {
		return head_->val;
	}
}

const float& QueueLstPr::Top() const {
	if (IsEmpty()) {
		throw std::invalid_argument("QueueLstPr - No top element!");
	} else {
		return head_->val;
	}
}

void QueueLstPr::Clear() noexcept {
	while(!IsEmpty()) {
		Pop();
	}
}

void QueueLstPr::Pop() noexcept {
	if (!IsEmpty()) {
		Node* oldNode = head_;
		head_ = head_->next_;
		delete oldNode;
	}
}

QueueLstPr::~QueueLstPr() {
	Clear();
}

QueueLstPr::QueueLstPr(const QueueLstPr &rhs) {
	if (!rhs.IsEmpty()) {
		Node* checkP = rhs.head_;
		head_ = new Node;
		head_->val = checkP->val;
		tail_ = head_;
		checkP = checkP->next_;
		while (checkP != nullptr) {
			Node* newNode = new Node;
			newNode->val = checkP->val;
			tail_->next_ = newNode;
			checkP = checkP->next_;
		}
		tail_ = tail_->next_;
	}
}

void QueueLstPr::Push(const float &val) {
	if (IsEmpty()) {
		Node* newNode = new Node;
		head_ = newNode;
		tail_ = newNode;
		head_->val = val;
		head_->next_ = nullptr;
	} else {
		if (val < head_->val) {
			Node* newNode = new Node;
			newNode->val = val;
			newNode->next_ = head_;
			head_ = newNode;
		} else {
			Node* checkP = head_;
			bool flag = false;
			while (checkP != nullptr && !flag) {
				if (val < checkP->next_->val) {
					Node *newNode = new Node;
					newNode->val = val;
					newNode->next_ = checkP->next_;
					checkP->next_ = newNode;
					flag = true;
				} else {
					checkP = checkP -> next_;
				}
			}
			if (!flag) {
				Node* newNode = new Node;
				newNode->val = val;
				newNode->next_ = nullptr;
				tail_->next_ = newNode;
				tail_ = tail_->next_;
			}
		}

	}

}

QueueLstPr &QueueLstPr::operator=(const QueueLstPr &rhs) {
	Clear();
	if (!rhs.IsEmpty()) {
		Node* checkP = rhs.head_;
		head_ = new Node;
		head_->val = checkP->val;
		tail_ = head_;
		checkP = checkP->next_;
		while (checkP != nullptr) {
			Node* newNode = new Node;
			newNode->val = checkP->val;
			tail_->next_ = newNode;
			checkP = checkP->next_;
		}
		tail_ = tail_->next_;
	}
}

QueueLstPr::QueueLstPr(QueueLstPr &&rhs) noexcept {
	Node* p = rhs.head_;
	std::swap(head_, rhs.head_);
	Node* myP = head_;
	while(p->next_!= nullptr) {
		std::swap(myP->next_, p->next_);
		p = p->next_;
		myP = myP -> next_;
	}
}

QueueLstPr &QueueLstPr::operator=(QueueLstPr &&rhs) noexcept {
	Node* p = rhs.head_;
	std::swap(head_, rhs.head_);
	Node* myP = head_;
	while(p->next_!= nullptr) {
		std::swap(myP->next_, p->next_);
		p = p->next_;
		myP = myP -> next_;
	}
	return *this;
}





