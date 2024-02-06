By: Ethan Kostiuk

To compile: In the terminal run the command "make compileProject".
To run: In the terminal run the command "./project".

About the program:

Note: When you run the program, the output is each state that has been visited until the goal. The program will get to the goal but I could not figure out why I kept getting a seg error evertime I tried returning the goal node.

State Space: The two sides and the boat.
Succesor Functions:
  - Move one cannibal
  - Move two cannibals
  - Move one Missionary
  - Move two Missionary
  - Move one Cannibal and One Missionary
  ^^(In either direction)
Start State: Three Missionaries and Three Cannibals and a boat on the left side of the river.
Goalt State: Three Missionaries and Three Cannibals and a boat on the right side of the river.

"What is the best abstraction of a state?" I made a state class that contains a count for each missionary and cannibal on each side, and which side the boat is on. Each state class is contained in a node which is part of a tree that will be searched for the goal.

"Is it a good idea to check for repeated states?" Yes, my succesor functions in the Actions class check for repeated states, along with many other conditions.

