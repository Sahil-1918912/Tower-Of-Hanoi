#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

//To print the heading at the center of output screen
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// A structure to create the stack
struct Stack
{
	int capacity;
	int top;
	int *array;
};

//creating a stack of finite capacity
struct Stack* createStack(int capacity)
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack -> capacity = capacity;
	stack -> top = -1;            //initializing the stack as empty (initializing top to -1)
	stack -> array = (int*) malloc(stack -> capacity * sizeof(int));          //Assigning memory to stack
	return stack;
}

int isFull(struct Stack* stack)
{
return (stack->top == stack->capacity - 1);
}

int isEmpty(struct Stack* stack)
{
return (stack->top == -1);
}

void push(struct Stack *stack, int item)
{
	if (isFull(stack))
		return;
	stack -> array[++stack -> top] = item;
}

int pop(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack -> array[stack -> top--];
}

//Function to show the movement of disks from source to destination using auxiliary rods
void moveDisk(char fromPeg, char toPeg, int disk)
{
	printf("Move the disk %d from \'%c\' to \'%c\'\n",disk, fromPeg, toPeg);
}

// Function to implement valid movement between two rods
void moveDisksBetweenRods(struct Stack *from, struct Stack *to, char A, char C)
{
	int rod1TopDisk = pop(from);
	int rod2TopDisk = pop(to);

	// When rod 1 is empty
	if (rod1TopDisk == INT_MIN)
	{
		push(from, rod2TopDisk);
		moveDisk(C, A, rod2TopDisk);
	}

	// When rod 2 pole is empty
	else if (rod2TopDisk == INT_MIN)
	{
		push(to, rod1TopDisk);
		moveDisk(A, C, rod1TopDisk);
	}

	// When top disk of rod 1 > top disk of rod 2
	else if (rod1TopDisk > rod2TopDisk)
	{
		push(from, rod1TopDisk);
		push(from, rod2TopDisk);
		moveDisk(C, A, rod2TopDisk);
	}

	// When top disk of rod 1 < top disk of rod 2
	else
	{
		push(to, rod2TopDisk);
		push(to, rod1TopDisk);
		moveDisk(A, C, rod1TopDisk);
	}
}

//Function to implement Tower of Hanoi
void TOH(int n, struct Stack *from, struct Stack *using, struct Stack *to)
{
	int i, total_moves;
	char A = 'A', C = 'C', B = 'B';

	//If the number of disks is even, then interchange destination auxiliary
	if (n % 2 == 0)
	{
		char temp = C;
		C = B;
		B = temp;
	}
	total_moves = pow(2, n) - 1;

    printf("\n\nMinimum number of steps required to solve the puzzle: %d\n\n",total_moves);

    printf("To get the puzzle solved in %d moves, follow the given steps:\n\n",total_moves);

	for (i = n; i >= 1; i--)
		push(from, i);

    //this loop iterates from 1 to total moves, during each iteration it decides which disk moves to which rod depending on the situation
	for (i = 1; i <= total_moves; i++)
	{
	    //It follows a set of 3 moves
	    //Move 1: Move a disk from the source rod to the destination rod.
        //Move 2: Move a disk from the source rod to the auxiliary rod.
        //Move 3: Move a disk from the auxiliary rod to the destination rod.
        //It ensures that at each step, the largest possible disk is moved without violating the rules of the puzzle.

		if (i % 3 == 1)           //is true when when current move is the first move in a sequence of 3 moves
		moveDisksBetweenRods(from, to, A, C);

		else if (i % 3 == 2)      //is true when when current move is the second move in a sequence of 3 moves
		moveDisksBetweenRods(from, using, A, B);

		else if (i % 3 == 0)      //is true when when current move is the third move in a sequence of 3 moves
		moveDisksBetweenRods(using, to, B, C);
	}
}

int main()
{
	gotoxy(40,0);
	printf("Mindful Towers: The Puzzle of Hanoi");
	usleep(3000000);
	printf("\n\nThe Tower of Hanoi is a mathematical game or puzzle consisting of three rods (A,B & C) and a number of disks of various diameters,which can slide onto any rod.");
	usleep(5000000);
	printf("\nThe puzzle begins with the disks stacked on one rod (A) in order of decreasing size, the smallest at the top, thus approximating a conical shape.");
	usleep(5000000);
	printf("\nThe objective of the puzzle is to replicate the entire stack on rod C (Rod B acts as auxiliary rod), obeying the following rules:");
	usleep(4000000);
	printf("\n1. Only one disk may be moved at a time.");
	usleep(3000000);
	printf("\n2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.");
	usleep(4000000);
	printf("\n3. No disk may be placed on top of a disk that is smaller than it.");
	usleep(4000000);
	printf("\nNote: The numbering of disks is done in ascending order of their respective sizes.");
	usleep(4000000);
	printf("\n\nPress enter key to continue.");
	getchar();

	int n;
	printf("\nEnter number of disks to be stacked on initial tower: ");
	scanf("%d", &n);

	struct Stack *from, *using, *to;

	// Create three stacks of size 'n'
	from = createStack(n);       //Tower A
	using = createStack(n);      //Tower B
	to = createStack(n);         //Tower C

	TOH(n, from,using,to);

	return 0;
}

//code by B23CS1060
