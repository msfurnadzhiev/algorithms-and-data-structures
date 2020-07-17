#pragma once
#include <iostream>

static const size_t INITIAL_CAPACITY = 32;
static const size_t EXPANSION_FACTOR = 2;

class Deque {

  double * m_container = nullptr;
  size_t   m_capacity = 0;
  size_t   m_size = 0;
  size_t   m_front = 0;

 public:

  /* --------- Constructors --------- */

  /**
   * Default constructor
   * @see void reserve(size_t n);
   */
  Deque();

  /**
   * Constructor with parameter
   * @param n The memory that will be allocated
   * @see void reserve(size_t n);
   */
  explicit Deque(size_t n);

  /**
   * Copy constructor
   * @param source Reference to deque whose data will be copied
   * @see void copy(Deque& other);
   */
  Deque(const Deque & source);

  /**
   * Copy assignment constructor
   * @param source Reference to deque whose data will be copied
   * @see void copy(Deque& other);
   */
  Deque & operator=(const Deque & source);

  //TODO move constructor
  //Deque(Deque &&other);

  //TODO move assignment operator
  //Deque & operator=(Deque &&other);

  /**
   * Destructor
   * @see void erase();
   */
  ~Deque() noexcept;


  /* --------- Capacity --------- */

  /**
   * @return true if deque is empty else false
   */
  bool empty() const noexcept;

  /**
   * @return the number of elements of the deque
   */
  size_t size() const noexcept;

  /**
   * @return the size of allocated storage capacity
   */
  size_t capacity() const noexcept;

  /**
   * Requests that the deque capacity be at least enough to contain n elements.
   * If n is greater than the current vector capacity, the function causes
   * the container to reallocate its storage increasing its capacity to n.
   * In all other cases, the function call does not cause a reallocation
   * and the vector capacity is not affected.
   * This function has no effect on the deque size and cannot alter its elements.
   * This function satisfies the strong exception safety guarantee.
   * @param n Minimum capacity for the deque
   * @throw std::bad_alloc
   */
  void reserve(size_t n);



  /* --------- Element access --------- */

  /**
   * Access element without checking if index is out of range
   * Accessing out of range element causes undefined behavior
   * @param index The index whose value we want to get
   */
  double & operator[](size_t index) noexcept;
  const double & operator[](size_t index) const noexcept;

  /**
   * Access element with checking if index is out of range
   *
   * @param index The index whose value we want to get
   * @throw std::out_of_range
   */
  double & at(size_t index);
  const double & at(size_t index) const;

  /**
   * @return a reference to the first element in the deque
   * @throw std::logic_error if deque is empty
   */
  double & front();
  const double & front() const;

  /**
   * @return a reference to the last element in the deque
   * @throw std::logic_error if deque is empty
   */
  double & back();
  const double & back() const;

  /**
   * @return a pointer to the fist element in the deque
   */
  double * data() noexcept;
  const double * data() const noexcept;

  /* --------- Modifiers --------- */

  /**
   * Adds a new element at the end of the deque.
   * @param value The content of parameter is copied to the new element.
   */
  void push_back(double value);

  /**
  * Adds a new element at the beginning of the deque.
  * @param value The content of parameter is copied to the new element.
  */
  void push_front(double value);

  /**
   * Remove the last element in the deque.
   */
  void pop_back();

  /**
  * Remove the last element in the deque.
  */
  void pop_front();

  /**
   * Remove all elements from the deque.
   * @param erase_flag If is true, the container will be erased
   */
  void clear(bool erase_flag = false) noexcept;


  /* --------- Comparisons --------- */

  /**
   * The equality operator first comparing sizes, and if they match,
   * the elements are compared sequentially.
   */
  friend bool operator==(const Deque & alpha, const Deque & beta) noexcept;
  friend bool operator!=(const Deque & alpha, const Deque & beta) noexcept;

 private:

  /* --------- Help Functions --------- */

  /**
   *  Copy each of the elements in other deque.
   *  If necessary, construct a container with larger capacity.
   *  This function satisfies the strong exception safety guarantee.
   *  @param source Reference to deque whose data will be copied
   */
  void copy(const Deque & source);

  /**
   * Destroys the container object.
   */
  void erase() noexcept;
};
