#ifndef RING_H_
#define RING_H_

#include <memory>

template <class T>
class ring {
private:
  // Size of the ring
  int m_size;
  // Actual position of the ring. It is used to add a new value in the right position
  int m_pos;
  // Smart pointer that stores the values of the template type 
  std::unique_ptr<T[]> m_values;
public:
  // Class iterator allows to loop through the ring
  class iterator;

  // Custom constructor to initialize the ring with an input size
  ring(int size): m_size(size), m_pos(0), m_values(new T[size]) { }
  // Custom destructor is not needed since the smart pointer manages the memory allocation

  // Copy constructor. Copy the values of the ring in a new unique_ptr and maintains the position
  ring(ring &other) : m_size(other.m_size), m_pos(other.m_pos), m_values(new T[other.m_size]) {
    copy(&other.m_values[0], &other.m_values[0]+other.m_size, &m_values[0]);
  }

  // Returns a ring iterator in the first position of the ring
  iterator begin () {
    return iterator(0, *this);
  }
  // Returns a ring iterator in the last position of the ring
  iterator end () {
    return iterator(m_size, *this);
  }
  // Saves the input value in the actual position (m_pos) and then increases m_pose by 1.
  // If it is the last position, restarts the m_pos to 0
  void add (T value) {
    // Postfix operator. m_pos is increased after saving the value
    m_values[m_pos++] = value;
    if(m_pos == m_size) {
      m_pos = 0;
    }
  }

  // Returns the value of template type stored in the pos position.
  T &get (int pos) {
    return m_values[pos];
  }
};

template <class T>
class ring<T>::iterator {
private:
  // Actual position of the iterator in the ring
  int m_pos;
  // Reference of the ring that the iterator
  ring &m_ring;
public:
  // Iterator constructor with input the desired position and the reference to the ring
  iterator(int pos, ring &ring_ref): m_pos(pos), m_ring(ring_ref) {
  }
  // Postfix operator. The iterator before being modified is returned
  iterator operator++(int) {
    iterator prev_it = *this;
    // The plus operator needs to be prefix to call the other plus operator and not itself
    ++(*this);
    return prev_it;
  }
  // Prefix operator. The new modified iterator is returned
  iterator operator++() {
    ++m_pos;
    return *this;
  }
  T &operator*() {
    return m_ring.get(m_pos);
  }
  // Returns if the smart pointers have the same memory address and the position is the same
  bool operator==(const iterator &other) const {
    return m_ring.m_values == other.m_ring.m_values && m_pos == other.m_pos;
  }
  // Returns if the smart pointers do not have the same address or the position is not the same
  bool operator!=(const iterator &other) const {
    return !(*this == other);
  }
};

#endif