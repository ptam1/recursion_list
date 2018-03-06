
#include "list.h"
#include "node1.h"
#include <assert.h>
using namespace std;


/**
 * Return a list consisting of the list pointed by head_ptr without the first
 * element.
 * It is acceptable to use part or all of the argument list provided that no
 * change is made to the list.
 *
 * precondition: the list pointed to by head_ptr is not empty.
 */
list tail(list lst)
{
 node* head_ptr = lst;
 if(head_ptr != NULL)
 {
 head_ptr = lst->link();
 }
 return head_ptr;
}	
   
   




/*
 * Return the first element of the list pointed to by head_ptr.
 *
 * precondition: the list pointed by head_ptr is not empty.
 */
value_type head(list lst)
{
 node* head_ptr = lst;
 
 if(head_ptr != NULL)
 {
	 return head_ptr->data();
 }
}



/**
 * Return true if and only if the list 'head' is empty.
 */
bool list_is_empty(list lst)
{
    node* head = lst;
	if(head == NULL)
	{
		return true;
	}
    else
    {
        return false;
    }
}


/**
 * Return a list that consists of 'val' followed by the list pointed to by head_ptr.
 * It is acceptable to use part or all of the argument  list provided that no
 * change is made to the list.
 */
list cons(value_type val, const list lst)
{
node* head_ptr = lst;
list_head_insert(head_ptr,val);
return head_ptr;
}



/*
 *   Create a new list that starts with the elements in the list pointed
 *   to by head_ptr and ends with 'val'.
 *   Return a pointer to the head of the new list.
*/
 list append(const list lst, value_type val)
{
    list newList = NULL;
    list newList2 = NULL;
    list newList3;
	if(list_is_empty(lst))
    {
       newList = cons(val, newList2);
       return newList;
    }
     else 
     {
        newList = append(tail(lst), val);
     }
    newList2 = cons(head(lst), newList); 
    return newList2;    
}   
  
/**
 *   Return a new list that consists of the two lists combined
 *   into one list.
 *   It is acceptable to use part or all of one or both argument lists provided that
 *   no change is made to them.
 */
 list append(const list lst_first, const list lst_second)
{
    node* head_ptr = lst_first;
    list lst1 = NULL;
    list lst2 = NULL;
	if(list_is_empty(lst_first))
    {
        return lst_second;
    }
    else
    {
        lst1 = append(tail(lst_first), lst_second);
    }
    lst2 = cons(head(lst_first), lst1);
    return lst2;
    
}


/**
 * Create and return a new list that contains the elements of head_ptr that
 * are not equal to val.
 */
list remove_all_of(const list lst, value_type val)
{
    list newList = NULL;
    list newList2 = NULL;
	if(list_is_empty(lst))
    {
        return lst;
    }
    else if (head(lst) == val)
    {
        newList = remove_all_of(tail(lst), val);
        return newList;
    }
    else
    {
        newList = remove_all_of(tail(lst), val);
    }
    newList2 = cons(head(lst), newList);
    return newList2;
}

/**
 *  Create a new list with the same values as the list pointed to by
 *  head_ptr but omitting the last element.
 *
 *  precondition:  the list pointed to by head_ptr is not empty.
 */
list remove_last(const list lst)
{
    list newList = NULL;
    list newList2 = NULL;
    
	assert(head(lst));
    if(tail(lst) == NULL)
     {
      return tail(lst);
     }
     else
    {
       newList = remove_last(tail(lst));
    }
        newList2 = cons(head(lst), newList);
        return newList2;
       
}


/**
 * Return the last value in the list pointed to by head_ptr.

 *  precondition:  the list pointed to by head_ptr is not empty.
 */
value_type last(const list lst)
{
	assert(head(lst));
    if(tail(lst) == NULL)
     {
      return head(lst);
     }
    else
    {
     return last(tail(lst));
    }
       
}
 

bool equals(const list list1, const list list2)
{
 if(list_is_empty(list1)) 
{
 return list_is_empty(list2);
} 
else if(list_is_empty(list2))
{
 return false;
}
 else if(head(list1) != head(list2))
{
 return false;
} 
else 
{
 return equals(tail(list1), tail(list2));
} 
}