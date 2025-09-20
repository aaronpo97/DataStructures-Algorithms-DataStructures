# The Linear List Abstract Data Type (ADT)

In a **linear container** or **linear list**, all elements are organized in a straight line, with each element having a unique predecessor and successor.

A list is defined in the form:
A*0, A_1, A_2, ..., A*(n-1).

The size of the list is _N_ (number of elements).

(Data Structures & Algorithm Analysis, Chapter 3: List, Stacks and Queues p. 77–78).

---

## **Array**

- Stores data in **contiguous memory**.
- **Fixed size and capacity** (must be estimated at creation).
- Supports **random access** in **O(1)** time.
- Insert/delete in arbitrary positions is costly (**O(N)**) due to shifting (p. 78–79).
- Common operations:

  - `size`
  - `empty`
  - `front`
  - `back`

---

## **Vector (Dynamic Array)**

- A **growable array**; expands capacity by doubling when full.
- Stores elements contiguously; supports **random access**.
- Efficient for **end operations** (`push_back`, `pop_back`) but costly (**O(N)**) for middle insert/erase.
- STL `vector` methods include (p. 80–83):

  - `size`, `capacity`, `empty`, `clear`
  - `push_back`, `pop_back`, `back`, `front`
  - `operator[]`, `at`
  - `reserve`

---

## **Linked Lists**

### **Singly Linked List**

- Nodes contain `data` + `next`.
- Traversal only forward.
- Insert/delete are **O(1)** if position known; otherwise search is **O(N)** (p. 79–80).
- Deletion is **O(1)** when the position is known because the deletion process only involves an update to the `next` pointer of the preceding node.

### **Doubly Linked List**

- Nodes contain `data`, `next`, and `prev`.
- Efficient insertion/deletion from both ends or any known position.
- STL `list` implements this with methods like (p. 92–101):

  - `push_front`, `pop_front`
  - `push_back`, `pop_back`
  - `insert`, `erase`

---

## **Stack (LIFO)**

- **Last In, First Out** structure.
- Operations (p. 103–107):

  - `push` (insert at top)
  - `pop` (remove from top)
  - `top/peek` (inspect top element)
  - `empty`

- Implementations: arrays (using `push_back`/`pop_back`) or linked lists (insert/delete at front).
- **Uses:**

  - Undo/redo in applications.
  - Compiler syntax checking (balanced symbols).
  - Call stack for function calls/recursion.
  - Backtracking in algorithms.

---

## **Queue (FIFO)**

- **First In, First Out** structure.
- Operations (p. 103–104):

  - `enqueue` (insert at rear)
  - `dequeue` (remove from front)
  - `peek` (inspect front element)
  - `empty`, `clear`

- Implementations: arrays (circular buffer) or linked lists.
- **Uses:**

  - Print job scheduling.
  - Transaction processing.
  - Input buffering.

---

## **Priority Queue**

- Elements dequeued by **priority**, not arrival order.
- Operations (p. 103–104):

  - `insert_with_priority`
  - `pull_highest_priority_element`
  - `peek`, `is_empty`

- Usually implemented with a **heap**.
- **Uses:**

  - Process scheduling.
  - Simulations and queuing systems.
