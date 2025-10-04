#pragma once
#include <iostream>
#include <stdexcept>

template <typename ValueType>
class Queue {
    struct Node {
        ValueType data;
        Node     *next;
        Node(ValueType const &d = ValueType{}, Node *n = nullptr)
            : data{d}, next{n} {
        }
        Node(ValueType &&d, Node *n = nullptr) : data{std::move(d)}, next{n} {
        }
    };

    Node  *m_front{};
    Node  *m_back{};
    size_t m_count{};

  public:
    // constructor
    Queue() = default;

    bool empty() const {
        return !m_front;
    }

    size_t size() const {
        return m_count;
    }

    // Add a new node at the rear
    void enqueue(ValueType val) {
        auto *node = new Node(val);
        if (empty()) {
            m_front = m_back = node;
            ++m_count;

            return;
        }

        // Link the current rear to the newly created node, and update the rear
        // to the new node
        m_back->next = node;
        m_back       = node;
        ++m_count;
    }

    // Remove the front node and return its value
    ValueType dequeue() {
        if (empty())
            throw std::range_error("Queue is empty!");

        // Isolate front node and value
        Node     *temp = m_front;
        ValueType val  = m_front->data;

        // Reset the front node to next in queue
        m_front = m_front->next;

        // Delete the old front node and update the count;
        --m_count;
        delete temp;

        return val;
    }

    ~Queue() {
        while (!empty())
            dequeue();
    }

    // Retrieve the value of the front node
    ValueType &peek() const {
        if (empty())
            throw std::range_error("Queue is empty!");

        return m_front->data;
    }

    friend std::ostream &operator<<(std::ostream &os, Queue const &q) {
        if (q.empty()) {
            os << "Queue is empty.\n";
            return os;
        }

        Node *current = q.m_front;
        while (current) {
            os << current->data << ", ";
            current = current->next;
        }

        os << "\n";
        return os;
    }
};