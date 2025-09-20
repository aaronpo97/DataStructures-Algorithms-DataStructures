#pragma once

template <typename ValueType> class SingleLinkedList {
  private:
    struct Node {
        ValueType data;
        Node     *next;
        Node(ValueType const &d = ValueType{}, Node *n = nullptr)
            : data{d}, next{n} {
        }

        Node(ValueType &&d, Node *n = nullptr) : data{std::move(d)}, next(n) {
        }
    };

    Node  *m_head;
    size_t m_size;

  public:
    class const_iterator {

      protected:
        Node *m_current;

        const_iterator(Node *p) : m_current{p} {
        }

        friend class SinglyLinkedList<ValueType>;

      public:
        const_iterator() : m_current{nullptr} {
        }
        ValueType const &operator*() const {
            return m_current->data;
        }
        bool operator==(const_iterator const &rhs) const {
            return m_current == rhs.m_current;
        };
        bool operator!=(const_iterator const &rhs) const {
            return !(*this == rhs);
        }
    }

    class iterator : public const_iterator {
      public:
        iterator(Node *p = nullptr) : const_iterator(p) {
        }
        Value_Type &operator*() {
            return const_iterator::m_current->data;
        }
        iterator &operator++() {
            this->m_current = this->m_current->next;
            return *this;
        }
    };

    SingleLinkedList() : m_head(nullptr), m_size(0) {};
    SingleLinkedList(List const &rhs);
    ~SingleLinkedList() {
        clear();
    };
    List &operator=(List const &rhs);
    SingleLinkedList(List &&rhs);

    iterator begin() {
        return iterator(head);
    }
    const_iterator begin() const {
        return const_iterator(head);
    }
    iterator end() {
        return iterator(nullptr);
    };
    const_iterator end() const{
        return const_iterator(nullptr);
    };

    size_t size() const { 
        return m_size;
    };
    bool   empty() const
    {
        return m_size == 0;
    }
        ;

    void     push_front(ValueType const &x);
    void     pop_front();
    iterator insert_after();
    iterator erase_after();

    void clear() {
        while (!empty())
            pop_front();
    }
};