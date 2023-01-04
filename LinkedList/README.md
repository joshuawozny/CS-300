# CS-300: DSA: Analysis and Design
## Assignment Two
This assignment is designed to explore linked lists, so you will implement a singly linked list to hold a collection of bids loaded from a CSV file. 

In this version, the following menu is presented when the program is run:

> Menu:<br>
> 1. Enter a Bid <br>
> 2. Load Bids<br>
> 3. Display All Bids<br>
> 4. Find Bid<br>
> 5. Remove<br>
> 9. Exit<br>
> 
> Enter choice:<br>

##### Public API for LinkedList.cpp that you have to complete:
> public:
> 
> LinkedList() <br>
> virtual ~LinkedList()<br>
> void Append(Bid bid)<br>
> void Prepend(Bid bid)<br>
> void PrintList()<br>
> void Remove(string bidId)<br>
> Bid Search(string bidId)
