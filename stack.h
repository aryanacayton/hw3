#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: private std::vector<T>
{
public:
    Stack()
    {

    }

    ~Stack()
    {

    }
    
    bool empty() const
    {
      return std::vector<T>::empty();
    }

    size_t size() const
    {
      return std::vector<T>::size();
    }

    //vector push_back = Stack push()
    void push(const T& item)
    {
      std::vector<T>::push_back(item);
    }

    //vector pop_back() = Stack pop()
    void pop()  // throws std::underflow_error if empty
    {
      if (empty())
      {
        throw std::underflow_error("Stack empty");
      }

      else
      {
        std::vector<T>::pop_back();
      }

    }
    
    const T& top() const // throws std::underflow_error if empty
    {
      if (empty())
      {
        throw std::underflow_error("Stack empty");
      }

      //vector back() = Stack top()
      else
      {
        return std::vector<T>::back();
      }
    }

    // Add other members only if necessary
};


#endif