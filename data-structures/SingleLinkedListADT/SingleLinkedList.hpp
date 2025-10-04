#pragma once
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename ValueType>
class SingleLinkedList {
  private:
    struct Node {
        ValueType data;
        Node     *next;
        Node(ValueType const &d = ValueType{}, Node *n = nullptr)
            : data{d}, next{n} {
        }
        Node(ValueType &&d, Node *n = nullptr) : data{std::move(d)}, next{n} {
        }
    };

    Node  *m_head{nullptr};
    size_t m_size{0};

  public:
    class const_iterator {
      protected:
        Node *m_current{nullptr};
        explicit const_iterator(Node *p) : m_current{p} {
        }
        friend class SingleLinkedList;

      public:
        const_iterator() = default;

        // dereference
        ValueType const &operator*() const {
            return m_current->data;
        }
        ValueType const *operator->() const {
            return &m_current->data;
        }

        // advance
        const_iterator &operator++() { // pre-increment
            m_current = m_current ? m_current->next : nullptr;
            return *this;
        }
        const_iterator operator++(int) { // post-increment
            const_iterator tmp{*this};
            ++(*this);
            return tmp;
        }

        // compare
        bool operator==(const_iterator const &rhs) const {
            return m_current == rhs.m_current;
        }
        bool operator!=(const_iterator const &rhs) const {
            return !(*this == rhs);
        }
    };

    class iterator : public const_iterator {
      public:
        explicit iterator(Node *p = nullptr) : const_iterator(p) {
        }

        ValueType &operator*() {
            return this->m_current->data;
        }
        ValueType *operator->() {
            return &this->m_current->data;
        }

        iterator &operator++() {
            this->m_current = this->m_current ? this->m_current->next : nullptr;
            return *this;
        }
        iterator operator++(int) {
            iterator tmp{*this};
            ++(*this);
            return tmp;
        }
    };

    SingleLinkedList() = default;

    // no copying allowed
    SingleLinkedList(SingleLinkedList const &)            = delete;
    SingleLinkedList &operator=(SingleLinkedList const &) = delete;

    // move allowed
    SingleLinkedList(SingleLinkedList &&rhs) noexcept
        : m_head(rhs.m_head), m_size(rhs.m_size) {
        rhs.m_head = nullptr;
        rhs.m_size = 0;
    }
    SingleLinkedList &operator=(SingleLinkedList &&rhs) noexcept {
        if (this != &rhs) {
            clear();
            m_head     = rhs.m_head;
            m_size     = rhs.m_size;
            rhs.m_head = nullptr;
            rhs.m_size = 0;
        }
        return *this;
    }

    ~SingleLinkedList() {
        clear();
    }

    iterator begin() {
        return iterator(m_head);
    }
    const_iterator begin() const {
        return const_iterator(m_head);
    }
    iterator end() {
        return iterator(nullptr);
    }
    const_iterator end() const {
        return const_iterator(nullptr);
    }

    size_t size() const {
        return m_size;
    }
    bool empty() const {
        return m_size == 0;
    }

    void push_front(ValueType const &x) {
        m_head = new Node(x, m_head);
        ++m_size;
    }
    void push_front(ValueType &&x) {
        m_head = new Node(std::move(x), m_head);
        ++m_size;
    }

    void pop_front() {
        if (!m_head)
            return;
        Node *temp = m_head;
        m_head     = m_head->next;
        delete temp;
        --m_size;
    }

    iterator insert_after(iterator itr, ValueType const &value) {
        Node *current = itr.m_current;

        if (!current)
            return end();

        Node *n       = new Node(value, current->next);
        current->next = n;

        ++m_size;
        return iterator(n);
    }

    iterator erase_after(iterator itr) {
        Node *current = itr.m_current;
        if (!current || !current->next)
            return end();

        Node *to_delete = current->next;
        current->next   = to_delete->next;
        delete to_delete;

        --m_size;

        return iterator(current->next);
    }

    void insert_middle(size_t const idx, ValueType const &value) {
        Node *newNode = new Node(value);

        // if empty
        if (!m_head) {

            if (idx != 0) {
                throw std::invalid_argument("Invalid list location");
            }

            m_head = newNode;
            return;
        }

        // search for preceding node
        Node *current = m_head;
        for (size_t i = 1; i < idx; ++i) {
            if (!current->next)
                throw std::invalid_argument("Invalid list location");

            current = current->next;
        }

        insert_after(iterator(current), value);
    }

    void erase_middle(size_t const idx) {
        // if empty
        if (!m_head) {
            throw std::invalid_argument("Invalid list location");
        }

        // search for preceding node
        Node *current = m_head;
        for (size_t i = 1; i < idx; ++i) {
            if (!current->next)
                throw std::invalid_argument("Invalid list location");

            current = current->next;
        }

        erase_after(iterator(current));
    }

    void clear() {

        while (m_head) {
            Node *tmp = m_head->next;
            delete m_head;
            m_head = tmp;
        }
        m_size = 0;
    }

    friend std::ostream &operator<<(std::ostream &os, SingleLinkedList &ll) {
        for (auto it = ll.begin(); it != ll.end(); ++it) {
            os << "=> " << *it << '\n';
        }

        return os;
    }
};
