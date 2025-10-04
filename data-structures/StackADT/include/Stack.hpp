#pragma once
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>

/**
 * @brief Last in, first out container (Stack).
 *
 * Example usage:
 *
 * Initial stack (top is at the highest index):
 *
 *   +-------+
 *   |   Y   |  <-- top
 *   +-------+
 *   |   E   |
 *   +-------+
 *   |   R   |
 *   +-------+
 *   |   B   |  <-- bottom
 *   +-------+
 *
 * After pop():
 *
 *   +-------+
 *   |   E   |  <-- top
 *   +-------+
 *   |   R   |
 *   +-------+
 *   |   B   |  <-- bottom
 *   +-------+
 *
 * After push('H'):
 *
 *   +-------+
 *   |   H   |  <-- top
 *   +-------+
 *   |   E   |
 *   +-------+
 *   |   R   |
 *   +-------+
 *   |   B   |  <-- bottom
 *   +-------+
 *
 */

template <typename ValueType>
class Stack {
  private:
    ValueType *m_items = nullptr;
    size_t     m_capacity;
    int64_t    m_currentIndex;

    void extendCapacity();

  public:
    Stack(size_t capacity);
    bool isEmpty() const;

    /**
     * Push an item onto the top of the stack.
     *
     * @note The stack will be resized if it reaches capacity.
     */
    void push(ValueType const &);

    /**
     * Take the top element off the stack.
     *
     * @return The element taken off the stack.
     */
    ValueType pop();

    size_t capacity() const {
        return m_capacity;
    }

    size_t size() const {
        return m_currentIndex + 1;
    }

    friend std::ostream &operator<<(std::ostream           &os,
                                    Stack<ValueType> const &stack) {
        os << "\n";
        os << std::setw(80) << std::setfill('=') << "" << std::setfill(' ')
           << "\n";
        os << std::setfill(' ');
        os << "STACK (capacity = " << stack.capacity()
           << ", size = " << stack.size() << ")\n";

        os << std::setw(80) << std::setfill('=') << "" << std::setfill(' ')
           << "\n";

        for (int64_t i = stack.size() - 1; i >= 0; --i) {
            bool is_last = i > 0;
            os << " [ " << i << " ] -> " << stack.m_items[i] << "\n";
        }
        if (stack.isEmpty()) {
            os << "<empty>\n";
        }

        os << std::setw(80) << std::setfill('=') << "" << std::setfill(' ')
           << "\n";
        os << "\n\n";
        return os;
    }

    ~Stack();
};

template <typename ValueType>
void Stack<ValueType>::extendCapacity() {
    size_t const new_capacity = m_capacity * 2;

    ValueType *temp = new ValueType[new_capacity];

    // Move elements to the new array, update the stack's pointer, and delete
    // the old storage.

    for (size_t i = 0; i <= m_currentIndex; ++i) {
        temp[i] = std::move(m_items[i]);
    }

    delete[] m_items;
    m_items    = temp;
    m_capacity = new_capacity;
}

template <typename ValueType>
Stack<ValueType>::Stack(size_t capacity)
    : m_capacity(capacity), m_currentIndex(-1),
      m_items(new ValueType[capacity]) {
}

template <typename ValueType>
Stack<ValueType>::~Stack() {
    delete[] m_items;
}

template <typename ValueType>
bool Stack<ValueType>::isEmpty() const {
    return m_currentIndex == -1;
}

template <typename ValueType>
void Stack<ValueType>::push(ValueType const &item) {
    if (m_currentIndex + 1 >= static_cast<int64_t>(m_capacity)) {
        extendCapacity();
    }
    m_items[++m_currentIndex] = item;
}

template <typename ValueType>
ValueType Stack<ValueType>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return m_items[m_currentIndex--];
}