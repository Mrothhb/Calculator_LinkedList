/****************************************************************************
Matthew Roth, A15685519
CSE 12, Winter 2019
February 5, 2019
cs12xcm
Assignment Five

File Name:      stack.c

Description:	The stack will emulate a "Stack" data structure. The program 
will implement an array-based stack of longs and modify the driver.c file 
which allows for the testing of the stack. The array-based stack will be 
dynamically allocated from the heap with an offset of -3 to -1 structure
and start the index for the user at 0, with -3 to -1 hidden data structure.

****************************************************************************/
#include <stdio.h>
#include "list.h"
#include "stack.h"

/*--------------------------------------------------------------------------
Function Name:         delete_Stack
Purpose:               deallocate (free) the memory for the Main Stack 
Description:           make the call to delete_List in the list file
Input:                 spp: the pointer to a pointer of the main stack   
Result:                The stack is deallocated 
Return:				   void.
--------------------------------------------------------------------------*/
void delete_Stack (Stack ** spp) {
        delete_List (spp);
}

/*--------------------------------------------------------------------------
Function Name:         isempty_Stack
Purpose:               Check if the stack is empty
Description:           make a call to isempty_List with the stack parameter
Input:                 this_Stack: the stack pointer  
Result:                The stack is empty or its not empty 
Return:				   TRUE/FALSE
--------------------------------------------------------------------------*/
long isempty_Stack (Stack * this_stack) {
        return isempty_List (this_stack);
}

/*--------------------------------------------------------------------------
Function Name:         new_Stack
Purpose:               Constructor to initialize the data structure and create
a new stack.
Description:           delegate the initializations of data to the new_List 
function to generate a new List
Input:                 copy_func: the copy functions delete_func: the function
to delete nodes is_greater_than_func: the function to check for values greater
or less than write_func: the function to write out node elements to console
Result:                The new stack/list is created  
Return:				   new_List/stack 
--------------------------------------------------------------------------*/
Stack * new_Stack (void *(*copy_func) (void *),
        void (*delete_func) (void *),
        long (*is_greater_than_func) (void *, void *),
        FILE *(*write_func) (void *, FILE *)) {

        return new_List (copy_func, delete_func, 
		is_greater_than_func, write_func);
}

/*--------------------------------------------------------------------------
Function Name:         pop
Purpose:               pop the last item on the stack, remove the last element
Description:           call the remove_List function with the stack parameter 
to remove an element or node from the list/stack
Input:                 this_Stack: the stack pointer   
Result:                the last element is removed from the list/stack 
Return:			       remvove_List					  
--------------------------------------------------------------------------*/
void * pop (Stack * this_stack) {
        return remove_List (this_stack, END);
}

/*--------------------------------------------------------------------------
Function Name:         push
Purpose:               push a new item onto the stack 
Description:           call the insert function with the stack and the element
and the END as a parameter, to add an addtional node to the list
Input:                 this_Stack: the stack pointer item: the number to 
push onto the stack element: the data to be inserted into the list
Result:                the new item is added to the list/stack
Return:			       TRUE/FALSE					  
--------------------------------------------------------------------------*/
long push (Stack * this_stack, void * element) {
        return insert (this_stack, element, END);
}
/*--------------------------------------------------------------------------
Function Name:         top
Purpose:               top will return the last item on the list/stack  
Description:           call the view function with the parameter this stack 
and the END to view the last item in the list.
Input:                 this_Stack: the stack pointer   
Result:                the last element is viewed  
Return:			       view(item)	  
--------------------------------------------------------------------------*/
void * top (Stack * this_stack) {
        return view (this_stack, END);
}

/*--------------------------------------------------------------------------
Function Name:         write_Stack 
Purpose:               displays all the elements on the stack/list
Description:           make a call to the write_List function with the stack
and the stream as a parameter
Input:                 this_Stack: the stack pointer *stream: file stream    
Result:                print all the elements in the stack consecutively   
Return:			       stream				  
--------------------------------------------------------------------------*/
FILE * write_Stack (Stack * this_stack, FILE * stream) {
        return write_List (this_stack, stream);
}
