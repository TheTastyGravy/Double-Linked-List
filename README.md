# Double-Linked-List
Implementation of a custom double-linked list in C++, and demonstraited using raylib.


In order to start from nullptr, the *go to first* and *go to last* buttons have to be used to jump to their respective element.
The list can be navigated using the *next* and *previous* buttons.

The *sort* button will perform an insertion sort on the list, and return current to a nullptr.

The delete buttons will remove the specified node from the list, and set current to a nullptr to prevent dangling pointers.
The add buttons will create a new element of the input value, and place it at the start/end of the list.
The *insert at current* button will create a new element of the input value, and insert it before the currently selected element.

The textbox will accept numerical input of up to 9 digits, and be cleared after being used.

Note: Nodes are not restricted to their list, and it is possible to pass a node to another list's remove function.
This can cause problems, and may throw exceptions, so dont do it.
