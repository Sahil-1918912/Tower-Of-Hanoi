
# Mindful Towers: The Puzzle of Hanoi

## Description
Tower of Hanoi is a mathematical game or puzzle consisting of three rods and a number of disks of various diameters, which can slide onto any rod. The puzzle begins with the disks stacked on one rod in order of decreasing size, the smallest at the top, thus approximating a conical shape.

## Rules
The objective of the puzzle is to move the entire stack to one of the other rods, obeying the following rules:

1. Only one disk may be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
3. No disk may be placed on top of a disk that is smaller than it.

## Result
The program returns the most efficient solution possible by printing all the steps one by one required to solve the puzzle of Hanoi based on the users input of number of disks.

## Example
For 3 disks:
Minimum possible steps = 7
The steps:
Move the disk 1 from 'A' to 'C'
Move the disk 2 from 'A' to 'B'
Move the disk 1 from 'C' to 'B'
Move the disk 3 from 'A' to 'C'
Move the disk 1 from 'B' to 'A'
Move the disk 2 from 'B' to 'C'
Move the disk 1 from 'A' to 'C' 

## Installation
1. Compile the source code: `gcc TOH.c`

## Requirements
- C compiler (e.g., GCC)

## Credits
- Developed by Sahil Narkhede [B23CS1060].

## License
This project is licensed under the [MIT License](LICENSE).