#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{

  //base case 
  if (head == nullptr)
  {
    smaller = nullptr;
    larger = nullptr;
    return;
  }

  Node* temp = head;
  head = head->next;

  llpivot(head, smaller, larger, pivot);

    //greater than
    if (temp->val > pivot)
    {
      temp->next = larger;
      larger = temp; 
    }

    //less than or equal
    else if (temp->val <= pivot)
    {
      temp->next = smaller;
      smaller = temp; 
    }

}
