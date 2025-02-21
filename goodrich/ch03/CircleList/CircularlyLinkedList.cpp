#include <cstddef>
template <typename T> class CircleList;

template <typename T> class Node
{
public:
  Node<T>();
  Node<T>(const T &e);

private:
  T        _elem;
  Node<T> *_next;
  friend class CircleList<T>;
};

template <typename T>
Node<T>::Node()
  : _next(NULL)
{
}

template <typename T>
Node<T>::Node(const T &e)
  : _elem(e)
  , _next(NULL)
{
}

template <typename T> class CircleList
{
public:
  CircleList<T>();
  ~CircleList<T>();
  const T &front() const;
  const T &back() const;
  bool     empty() const;
  void     advance();
  void     add(const T &e);
  void     remove();

private:
  Node<T> *_cursor;
};

template <typename T>
CircleList<T>::CircleList()
  : _cursor(NULL)
{
}

template <typename T> CircleList<T>::~CircleList()
{
  while (!empty()) {
    remove();
  }
}

template <typename T> const T &CircleList<T>::front() const
{
  return _cursor->_next->_elem;
}

template <typename T> const T &CircleList<T>::back() const
{
  return _cursor->_elem;
}

template <typename T> bool CircleList<T>::empty() const
{
  return _cursor == NULL;
}

template <typename T> void CircleList<T>::advance()
{
  if (empty()) {
	return;
  }
  _cursor = _cursor->_next;
}

template <typename T> void CircleList<T>::add(const T &e)
{
  Node<T> *newNode = new Node<T>(e);
  if (_cursor == NULL) {
    _cursor        = newNode;
    _cursor->_next = _cursor;
  } else {
    newNode->_next = _cursor->_next;
    _cursor->_next = newNode;
  }
}

template <typename T> void CircleList<T>::remove() {
	Node<T> *oldNode = _cursor->_next;
	if (oldNode == _cursor) {
		_cursor = NULL;
	} else {
		_cursor->_next = oldNode->_next;
	}
	delete oldNode;
}
