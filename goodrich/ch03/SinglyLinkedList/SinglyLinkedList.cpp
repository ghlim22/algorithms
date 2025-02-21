
#include <cstddef>
#include <exception>
template <typename T> class SLinkedList;

template <typename T> class Node {
public:
	Node<T>();
	Node<T>(const T &e);
private:
  T _elem;
  Node *_next;
  friend class SLinkedList<T>;
};

template<typename T>
Node<T>::Node(): _next(NULL) {}

template<typename T>
Node<T>::Node(const T& e): _elem(e), _next(NULL) {}

template <typename T> class SLinkedList 
{
	public:
		SLinkedList<T>();
		~SLinkedList<T>();
		bool empty() const;
		const T& front() const;
		void addFront(const T& e);
		void removeFront();
	private:
		Node<T> *_head;
};

template <typename T>
SLinkedList<T>::SLinkedList() :
_head(NULL) {}

template <typename T>
SLinkedList<T>::~SLinkedList() {
	while (!empty()) {
		removeFront();
	}
}

template<typename T>
bool SLinkedList<T>::empty() const {
	return _head == NULL;
}

template<typename T>
const T& SLinkedList<T>::front() const {
	return _head->_elem;
}

template< typename T>
void SLinkedList<T>::addFront(const T& e) {
	Node<T> *n = new Node<T>(e);
	n->_next = _head;
	_head = n;
}

template<typename T>
void SLinkedList<T>::removeFront() {
	if (_head == NULL) {
		throw std::exception();
	}
	Node<T> *old = _head;
	_head = old->_next;
	delete old;
}
