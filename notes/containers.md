# Containers / Collections

## Definition

A _container_ or _collection_ gathers and organizes other objects, known as elements.

The _container_ defines specific ways in which elements are managed and accessed.

The user of the container must interact with the container only in the prescribed ways.

---

## Categories

![Types of Containers]()

### Linear Containers

In a _linear container_, all elements are organized in a straight line, with each element having a unique predecessor and successor. The elements may or may not be stored in contiguous memory.

#### Examples:

- Array
- Vector
- Stack
- Queue
- Linked List

---

### Non-linear Containers

In a _non-linear container_, elements are organized in a hierarchy or a network. Each item may have one predecessor but multiple successors.

#### Examples:

- Tree
- Graph
- Set

## **Abstract Data Types (ADT)**

- An ADT is a **set of objects** together with a **set of operations**, independent of implementation.
- Examples: lists, sets, stacks, queues.
- Operations are defined mathematically (e.g., `insert`, `remove`, `find`), while actual implementations can vary (array, linked list, etc.) (Weiss p. 77–78).
- The C++ class allows us to implement our own ADTs.

---

## Standard Template Library (STL)

- Part of the C++ Standard Library.
- Provides:
  - **Generic Containers** (e.g., vector, list, map).
  - **Generic Algorithms** (e.g., sort, find).
  - **Functors** (function objects).
  - **Iterators** (generalized pointers).
- Benefits:
  - Abstract Data Types (ADTs) with built-in operations.
  - Separation of interface and implementation.
  - Templates allow use with any type (built-in or user-defined).
