#pragma once
#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <utility>

template <typename ValueType>
class Vector {
  private:
    ValueType *m_data{nullptr};
    size_t     m_capacity{0};
    size_t     m_size{0};

    static constexpr size_t m_extraCapacity{16};

  public:
    // default/normal constructor
    explicit Vector(size_t init_size = 0) noexcept
        : m_size{init_size}, m_capacity{init_size + m_extraCapacity}, m_data{} {
        m_data = new ValueType[m_capacity];

        std::fill(std::begin(*this), std::end(*this), ValueType());
    }

    // initializer_list constructor
    Vector(std::initializer_list<ValueType> init) noexcept
        : m_size{init.size()}, m_capacity{init.size() + m_extraCapacity},
          m_data{} {
        m_data   = new ValueType[m_capacity];
        size_t i = 0;
        for (auto const &v : init)
            m_data[i++] = v;
    }

    // copy constructor
    Vector(Vector const &rhs) noexcept
        : m_size(rhs.m_size), m_capacity(rhs.m_capacity), m_data() {
        m_data = new ValueType[m_capacity];
        for (size_t i = 0; i < m_size; ++i)
            m_data[i] = rhs.m_data[i];
    }

    // move constructor
    Vector(Vector &&rhs) noexcept
        : m_data{rhs.m_data}, m_capacity{rhs.m_capacity}, m_size{rhs.m_size} {
        rhs.m_data     = nullptr;
        rhs.m_capacity = 0;
        rhs.m_size     = 0;
    }

    // destructor
    ~Vector() {
        delete[] m_data;
    }

    // copy-and-swap assignment
    Vector &operator=(Vector rhs) noexcept {
        std::swap(m_data, rhs.m_data);
        std::swap(m_capacity, rhs.m_capacity);
        std::swap(m_size, rhs.m_size);
        return *this;
    }

    // resize and reserve

    void resize(size_t new_size) {
        if (new_size > m_capacity)
            reserve(new_size * 2);

        auto old_size = m_size;
        m_size        = new_size;

        for (size_t i = old_size; i < new_size; ++i) {
            m_data[i] = ValueType();
        }
    }

    void reserve(size_t new_capacity) {
        if (new_capacity <= m_capacity)
            return;

        ValueType *temp = new ValueType[new_capacity];

        for (size_t i = 0; i < m_size; ++i)
            temp[i] = std::move(m_data[i]);

        delete[] m_data;

        m_data     = temp;
        m_capacity = new_capacity;
    }

    // getters

    size_t size() const {
        return m_size;
    }
    size_t capacity() const {
        return m_capacity;
    }
    bool empty() const {
        return m_size == 0;
    }

    // push back (regular)
    void push_back(ValueType const &item) {
        if (m_size == m_capacity)
            reserve(m_capacity ? 2 * m_capacity + 1 : 1);

        m_data[m_size++] = item;
    }

    // push back (move semantics)
    void push_back(ValueType &&x) {
        if (m_size == m_capacity)
            reserve(m_capacity ? 2 * m_capacity + 1 : 1);

        m_data[m_size++] = std::move(x);
    }

    void pop_back() {
        if (m_size)
            --m_size;
    }

    ValueType &back() {
        return m_data[m_size - 1];
    }

    ValueType const &back() const {
        return m_data[m_size - 1];
    }

    // random access operations
    ValueType &operator[](size_t i) {
        return m_data[i];
    }

    ValueType const &operator[](size_t i) const {
        return m_data[i];
    }

    ValueType &at(size_t i) {
        if (i >= m_size)
            throw std::out_of_range("Index out of range");
        return m_data[i];
    }

    ValueType const &at(size_t i) const {
        if (i >= m_size)
            throw std::out_of_range("Index out of range");
        return m_data[i];
    }

    // iterators
    ValueType *begin() {
        return m_data;
    }

    ValueType const *begin() const {
        return m_data;
    }

    ValueType *end() {
        return m_data + m_size;
    }

    ValueType const *end() const {
        return m_data + m_size;
    }
};
