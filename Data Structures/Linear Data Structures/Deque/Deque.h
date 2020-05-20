#pragma once
#include <iostream>

static const size_t INITIAL_CAPACITY = 32;
static const size_t EXPANSION_FACTOR = 2;

class Deque {

    double *_container = nullptr; //allocated memory
    size_t _capacity = 0;
    size_t _size = 0;
    size_t _front = 0;

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
     * @see void copy(Deque& other);
     */
    Deque(const Deque &other);

    /**
     * Copy assignment constructor
     * @see void copy(Deque& other);
     */
    Deque & operator=(const Deque &other);

    //TODO move constructor
    //TODO move assignment operator

    /**
     * Destructor
     * @see void erase();
     */
    ~Deque();

    /* --------- Capacity --------- */

    /**
     * @return true if deque is empty else false
     */
    bool empty() const;

    /**
     * @return the number of elements of the deque
     */
    size_t size() const;

    /**
     * @return the size of allocated storage capacity
     */
    size_t capacity() const;

    /**
     * Requests that the deque capacity be at least enough to contain n elements.
     * If n is greater than the current vector capacity, the function causes
     * the container to reallocate its storage increasing its capacity to n.
     * In all other cases, the function call does not cause a reallocation
     * and the vector capacity is not affected.
     * This function has no effect on the vector size and cannot alter its elements.
     * This function satisfies the strong exception safety guarantee.
     * @param n Minimum capacity for the deque
     */
    void reserve(size_t n);



    /* --------- Element access --------- */

    /**
     * Access element without checking if index is out of range
     * Accessing out of range element causes undefined behavior
     * @param index The index whose value we want to get
     */
    double & operator[](size_t index);
    const double & operator[](size_t index) const;

    /**
     * Access element with checking if index is out of range
     * @param index The index whose value we want to get
     * @throw std::out_of_range
     */
    double & at(size_t index);
    const double & at(size_t index) const;

    /**
     * @return a reference to the first element in the deque
     * @throw std::out_of_range if deque is empty
     */
    double & front() const;

    /**
     * @return a reference to the last element in the deque
     * @throw std::out_of_range if deque is empty
     */
    double & back() const;

    /**
     * @return a pointer to the fist element in the deque
     */
    double * data() const;

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
    void clear(bool erase_flag = false);

    /* --------- Comparisons --------- */

    /**
     * The equality operator first comparing sizes, and if they match,
     * the elements are compared sequentially.
     */
    friend bool operator==(const Deque &deque1, const Deque &deque2);
    friend bool operator!=(const Deque &deque1, const Deque &deque2);

private:

    /* --------- Help Functions --------- */
    /**
     *  Copy each of the elements in other deque.
     *  If necessary, construct a container with larger capacity.
     *  This function satisfies the strong exception safety guarantee.
     */
    void copy(const Deque & other);

    /**
     * Destroys the container object.
     */
    void erase();

};
