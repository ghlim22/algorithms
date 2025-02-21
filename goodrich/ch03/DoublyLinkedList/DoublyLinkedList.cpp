#include <cstddef>
#include <exception>
#include <iostream>

template <typename T> class DLinkedList;

template <typename T> class Node {
	public:
		Node<T>();
		Node<T>(const T &e);
	private:
	  T _elem;
	  Node *_prev;
	  Node *_next;
	  friend class DLinkedList<T>;
	};


template<typename T>
Node<T>::Node():_prev(NULL), _next(NULL) {}

template<typename T>
Node<T>::Node(const T& e): _elem(e), _prev(NULL), _next(NULL) {}

template <typename T> class DLinkedList 
{
	public:
		DLinkedList<T>();
		~DLinkedList<T>();
		bool empty() const;
		const T& front() const;
		const T& back() const;
		void addFront(const T& e);
		void addBack(const T& e);
		void removeFront();
		void removeBack();
	protected:
		void add(Node<T> *v, const T& e); // Inserts new node before v
		void remove(Node<T> *v); // Remove node v
	private:
		Node<T> *_header;
		Node<T> *_trailer;
};

template<typename T>
DLinkedList<T>::DLinkedList():
_header(new Node<T>), _trailer(new Node<T>) {
	_header->_next = _trailer;
	_trailer->_prev = _header;
}


template<typename T>
DLinkedList<T>::~DLinkedList() {
	while (!empty()) {
		removeFront();
	}
	delete _header;
	delete _trailer;
}


template<typename T>
bool DLinkedList<T>::empty() const {
	return _header->_next == _trailer;
}

template<typename T>
const T& DLinkedList<T>::front() const {
	return _header->_next->_elem;
}

template<typename T>
const T& DLinkedList<T>::back() const {
	return _trailer->_prev->_elem;
}

template<typename T>
void DLinkedList<T>::addFront(const T& e) {
	add(_header->_next, e);
}

template<typename T>
void DLinkedList<T>::addBack(const T& e) {
	add(_trailer, e);
}

template<typename T>
void DLinkedList<T>::removeFront() {
	if (empty()) {
		throw std::exception();
	}
	remove(_header->_next);
}

template<typename T>
void DLinkedList<T>::removeBack() {
	if (empty()) {
		throw std::exception();
	}
	remove(_trailer->_prev);
}

template<typename T>
void DLinkedList<T>::add(Node<T> *v, const T& e) {
	Node<T> *newNode = new Node<T>(e);
	newNode->_prev = v->_prev;
	newNode->_next = v;
	v->_prev->_next = newNode;
	v->_prev=newNode;
}

template<typename T>
void DLinkedList<T>::remove(Node<T> *v) {
	v->_prev->_next = v->_next;
	v->_next->_prev = v->_prev;
	delete v;
}

template<typename T>
void listReverse(DLinkedList<T> &L) {
	DLinkedList<T> D;
	while (!L.empty()) {
		D.addFront(L.front());
		L.removeFront();
	}
	while (!D.empty()) {
		L.addBack(D.front());
		D.removeFront();
	}
}

int main(void) {
	DLinkedList<int> list;

	list.addFront(1);
	list.addFront(3);
	list.addBack(2);
	while (!list.empty()) {
		std::cout << list.front() << '\n';
		list.removeFront();
	}

	return 0;
}