#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m_; //ary-ness of heap tree 
  PComparator c_; //binary predicate function/functor that takes two items

  std::vector<T> vec1;

};

// Add implementation of member functions here

//Constructor
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c): m_(m), c_(c)
{
  if (m < 2)
  {
    throw std::invalid_argument("m must be greater than or equal to 2");
  }
}


//Destructor 
template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

}


//empty
template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return vec1.empty();
}


//size
template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return vec1.size();
}


//push
template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  vec1.push_back(item);
  size_t len = vec1.size() - 1;

  //loop through Heap
  while (len > 0)
  {
    size_t parent = (len - 1) / m_;

    //look at parent node's children
    if (c_(vec1[len], vec1[parent]))
    {
      std::swap(vec1[len], vec1[parent]);
      len = parent; 
    }

    else
    {
      break;
    }

  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return vec1[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){ //base case 1
    // ================================
    // throw the appropriate exception
    // ================================

    throw std::underflow_error("Heap is empty");
  }

  //base case 2
  if (vec1.size() == 1)
  {
    vec1.pop_back();
    return;
  }

  //element at back of Heap becomes root
  vec1[0] = vec1.back();

  //remove element that is NOW root, but WAS at back of Heap
  vec1.pop_back();

  size_t num = 0; 

  //relies on internal break conditions to fail --> otherwise is a continuous loop 
  while (1)
  {
    size_t child1 = num * m_ + 1;

    //there are no children
    if (child1 >= vec1.size())
    {
      break;
    }

    //loop to find child w/ highest priority 
    size_t priChild = child1;

    for (int i = 1; i < m_; i++)
    {

      //current child looking at in Heap
      size_t children = child1 + i;

      //exceeded loop 
      if (children >= vec1.size())
      {
        break;
      }

      //priority child is current child 
      if (c_(vec1[children], vec1[priChild]))
      {
        priChild = children;
      }

    }

      //compare previous priChild to current child
      if (c_(vec1[priChild], vec1[num]))
      {
        std::swap(vec1[priChild], vec1[num]);
        num = priChild;
      }

      else
      {
        break;
      }


  }

}


#endif
