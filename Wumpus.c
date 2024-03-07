/*---------------------------------------------
  Wumpus
  
  System: Mac using Replit
  Author: Ceasar Attar
  ---------------------------------------------
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>		// for srand

void movePlayer(int *pit1, int *pit2, int *Wumpus, int *person, int **roomArray, int *moveNumber, int *bat1, int *bat2, int *arrow)  // function that pulls in the integer after inputting M
{  // recieves integer pointers pit1, pit2, Wumpus, person, moveNumber, and int array roomArray as parameters and returns different outputs after comparing the values
  int inputM;
  
  scanf(" %d", &inputM);
  if (inputM == roomArray[*person][0] || inputM == roomArray[*person][1] || inputM == roomArray[*person][2]) {  // checks if the move is a valid move by comparing 
    *person = inputM;  // to the adjacent rooms ascendingly
    *moveNumber += 1;  // increments the move number after every valid move
    
    if (inputM == *pit1 || inputM == *pit2) {  // checks if the user moves to a pit and outputs a message accordinggly 
      printf("Aaaaaaaaahhhhhh....\n    You fall into a pit and die. \n\nExiting Program ...");
      exit(0);  // exits the program after the user dies
    }
    
    if (inputM == *Wumpus) {  // checks if the user moves to a room that has the wumpus in it 
      
      if (*Wumpus % 2 == 0) {  // nested if statement that checks if the room the user moves to is even and displays a message accordingly
        printf("You briefly feel a slimy tentacled arm as your neck is snapped.\nIt is over.\n\n");
        printf("Exiting Program ...");
        exit(0);
      }
        
      else {  // nested if statement that checks if the room the user moves to is even and displays a message accordingly
        printf("You hear a slithering sound, as the Wumpus slips away. \nWhew, that was close! \n");
        *Wumpus = roomArray[*person][0];  // moves the wumpus to the lowest numbered adjoining room
      }
    }

    if (inputM == *bat1) {
      int temp;
      temp = *person;
      *bat1 = rand() % 20 + 1;
      printf("Woah... you're flying!\nYou've just been transported by bats to room %d. \n", *bat1);
      *person = *bat1;
      while (*bat1 == *person || *bat1 == *bat2 || *bat1 == temp) {
        *bat1 = rand() % 20 + 1;
      }
    }
    
    if (inputM == *bat2) {
      int temp;
      temp = *person;
      *bat2 = rand() % 20 + 1;
      printf("Woah... you're flying!\nYou've just been transported by bats to room %d. \n", *bat2);
      *person = *bat2;
      while (*bat2 == *person || *bat2 == *bat1 || *bat2 == temp) {
        *bat2 = rand() % 20 + 1;
      }
    }
  }
    
  else { // else statement that prints out an invalid move message if the move does not match one of the three tunnels
    printf("Invalid move.  Please retry. \n");
  }
}

void checker(int *pit1, int *pit2, int *Wumpus, int *person, int **roomArray, int *moveNumber, int *bat1, int *bat2, int *arrow)  // function that checks if a wumpus, pit1, or pit2 are in adjacent rooms to the user (in that respective order) and prints out messages accordingly
{  // recieves integer pointers pit1, pit2, Wumpus, person, moveNumber, and int array roomArray as parameters and returns different outputs after comparing the values
  if (*Wumpus == roomArray[*person][0] || *Wumpus == roomArray[*person][1] || *Wumpus == roomArray[*person][2]) {
      printf("You smell a stench. ");  // prints out a message if the wumpus is adjacent to the player's room
    }
  if (*pit1 == roomArray[*person][0] || *pit1 == roomArray[*person][1] || *pit1 == roomArray[*person][2]) {
    printf("You feel a draft. ");  // prints out a message if pit1 is adjacent to the player's room
  }
  if (*pit2 == roomArray[*person][0] || *pit2 == roomArray[*person][1] || *pit2 == roomArray[*person][2]) {
    printf("You feel a draft. ");  // prints out a message if pit2 is adjacent to the player's room
  }
  if (*bat1 == roomArray[*person][0] || *bat1 == roomArray[*person][1] || *bat1 == roomArray[*person][2]) {
    printf("You hear rustling of bat wings. ");  // prints out a message if bat1 is adjacent to the player's room
  }
  if (*bat2 == roomArray[*person][0] || *bat2 == roomArray[*person][1] || *bat2 == roomArray[*person][2]) {
    printf("You hear rustling of bat wings. ");  // prints out a message if bat2 is adjacent to the player's room
  }
}

void randCheck(int *pit1, int *pit2, int *Wumpus, int *person, int *bat1,int *bat2, int *arrow)  // function that checks if any of the randomly assigned variables are equal and reassigns them if they are
{  // recieves integer pointers pit1, pit2, Wumpus, and person as parameters and returns a value that is stored in each variable
  // *pit1 == *pit2 == *Wumpus == *person == *bat1 == *bat2 == *arrow) {  // if statement that compares and checks if the values of the variables are 
  while (1)
  {
    if (*Wumpus == *person) {
      *Wumpus = rand() % 20 + 1;
      continue;
    }
    
    if (*pit1 == *person || *pit1 == *Wumpus) {
      *pit1 = rand() % 20 + 1;
      continue;
    }

    if (*pit2 == *person || *pit2 == *Wumpus || *pit2 == *pit1) {
      *pit2 = rand() % 20 + 1;
      continue;
    }

    if (*bat1 == *person || *bat1 == *Wumpus || *bat1 == *pit1 || *bat1 == *pit2) {
      *bat1 = rand() % 20 + 1;
      continue;
    }

    if (*bat2 == *person || *bat2 == *Wumpus || *bat2 == *pit1 || *bat2 == *pit2 || *bat2 == *bat1) {
      *bat2 = rand() % 20 + 1;
      continue;
    }

    if (*arrow == *person || *arrow == *Wumpus || *arrow == *pit1 || *arrow == *pit2 || *arrow == *bat1 || *arrow == *bat2) {
      *arrow = rand() % 20 + 1;
      continue;
    }
    break;
  }
}

void resetVar(int *pit1, int *pit2, int *Wumpus, int *person, int *bat1, int *bat2, int *arrow)  // function that allows the user set their own values for the player, wumpus, pit1, pit2, bat1, bat2, and arrow.
{  // recieves integer pointers pit1, pit2, Wumpus, and person as parameters and returns a value that is stored in each of their memory spaces
  printf("Enter the room locations (1..20) for player, wumpus, pit1, pit2, bats1, bats2, and arrow: \n\n");
  scanf(" %d %d %d %d %d %d %d", &*person, &*Wumpus, &*pit1, &*pit2, &*bat1, &*bat2, &*arrow);
  return;
}

bool adjCheck(int *arrow, int arrowRoom1,int **roomArray) { // function that checks if the rooms are adjacent 
  for (int i = 0; i < 3; i++) { // for loop that loops 3 times
        if (roomArray[*arrow][i] == arrowRoom1) { 
          return true; // returns true if the rooms are adjacent
        }
  }
  return false; // returns false if the rooms are not adjacent 
}

void shootArrow(int *person, int *Wumpus, int *arrow, int **roomArray, int *roomNumber, int *arrowRoom1, int *moveNumber) {
  int i;
  int checkadj = 0;
  int temp;
  int *temp2;

  if ( *arrow == -1) { // if arrow = -1 then it means that user has the arrow
      printf("Enter the number of rooms (1..3) into which you want to shoot, followed by the rooms themselves: ");
    }
  else {
    printf("Sorry, you can't shoot an arrow you don't have.  Go find it.\n"); // user does not have aroow
      return;
  }
  scanf(" %d", &*roomNumber); // scanfs in the amount of rooms
    if (*roomNumber > 3) {
      printf("Sorry, the max number of rooms is 3.  Setting that value to 3.");
      *roomNumber = 3; // sets roomnumber to 3 if rthe user inputs a number bigger than 3
    }
    
    int *arrowArray = (int *)malloc(3 * sizeof(int)); // dynamically allocates and creates an array for the arrow rooms
  
    for(int i =0; i < *roomNumber; i ++){
      scanf("%d",&(arrowArray[i])); // reads in aall the room numbers
    }
  *arrow = *person; // sets the arrow to the person, meaning the aroow has been picked up
  
  for (i = 0; i < *roomNumber; i++) {
    checkadj = 0;
    
    if(adjCheck( arrow,arrowArray[i],roomArray) && checkadj == 0){
      *arrow=arrowArray[i]; // checks if the rooms are adjacent if checkadj is 0, sets the arrow to the adjacent room
    }
      
    else {
      checkadj = 1;
      printf("Room %d is not adjacent.  Arrow ricochets...\n", arrowArray[i]); // sets checkadj to 1 if not adjacent
      *arrow = roomArray[*arrow][0]; // sets arrow to the lowest numbered adjacent room
    }

    if (*arrow == *person) { // checks if the user shot themselves and displays a message accordingly 
      if (checkadj == 1) {
        printf( "You just shot yourself, and are dying.\n"
            "It didn't take long, you're dead.\n");
      }
      else {
      printf("You just shot yourself.\n");
      printf("Maybe Darwin was right. You're dead.\n");
      }

      printf("\nExiting Program ...\n");
      exit (0);
    }
     if (*arrow == *Wumpus) {
      if (checkadj == 1) {  // checks if the user shot the wumpus and displays a message accordingly 
  
        printf("Your arrow ricochet killed the Wumpus, you lucky dog!\n"
               "Accidental victory, but still you win!");    
      }
      else{
        printf("Wumpus has just been pierced by your deadly arrow!\n");
        printf("Congratulations on your victory, you awesome hunter you.\n");
      }
       
      printf("\nExiting Program ...\n");
      exit (0);
    }
    
  }
  *Wumpus = roomArray[*Wumpus][0]; // sets the wumpus to the lowest numbered adjacent room
  free(arrowArray); // frees the dynamic array
}


void displayCave() // displays the cave
{
    printf( "\n"
			"       ______18______             \n"
    		"      /      |       \\           \n"
    		"     /      _9__      \\          \n"
    		"    /      /    \\      \\        \n"
    		"   /      /      \\      \\       \n"
    		"  17     8        10     19       \n"
    		"  | \\   / \\      /  \\   / |    \n"
    		"  |  \\ /   \\    /    \\ /  |    \n"
    		"  |   7     1---2     11  |       \n"
    		"  |   |    /     \\    |   |      \n"
    		"  |   6----5     3---12   |       \n"
    		"  |   |     \\   /     |   |      \n"
    		"  |   \\       4      /    |      \n"
    		"  |    \\      |     /     |      \n"
    		"  \\     15---14---13     /       \n"
    		"   \\   /            \\   /       \n"
    		"    \\ /              \\ /        \n"
    		"    16---------------20           \n"
    		"\n");
}


//--------------------------------------------------------------------------------
void displayInstructions() // displays the instructions 
{
    printf( "Hunt the Wumpus:                                             \n"
    		"The Wumpus lives in a completely dark cave of 20 rooms. Each \n"
    		"room has 3 tunnels leading to other rooms.                   \n"
    		"                                                             \n"
    		"Hazards:                                                     \n"
        	"1. Two rooms have bottomless pits in them.  If you go there you fall and die.   \n"
        	"2. Two other rooms have super-bats.  If you go there, the bats grab you and     \n"
        	"   fly you to some random room, which could be troublesome.  Then those bats go \n"
        	"   to a new room different from where they came from and from the other bats.   \n"
    		"3. The Wumpus is not bothered by the pits or bats, as he has sucker feet and    \n"
        	"   is too heavy for bats to lift.  Usually he is asleep.  Two things wake       \n"
        	"    him up: Anytime you shoot an arrow, or you entering his room.  The Wumpus   \n"
        	"    will move into the lowest-numbered adjacent room anytime you shoot an arrow.\n"
        	"    When you move into the Wumpus' room, then he wakes and moves if he is in an \n"
        	"    odd-numbered room, but stays still otherwise.  After that, if he is in your \n"
        	"    room, he snaps your neck and you die!                                       \n"
        	"                                                                                \n"
        	"Moves:                                                                          \n"
        	"On each move you can do the following, where input can be upper or lower-case:  \n"
        	"1. Move into an adjacent room.  To move enter 'M' followed by a space and       \n"
        	"   then a room number.                                                          \n"
        	"2. Shoot your guided arrow through a list of up to three adjacent rooms, which  \n"
        	"   you specify.  Your arrow ends up in the final room.                          \n"
        	"   To shoot enter 'S' followed by the number of rooms (1..3), and then the      \n"
        	"   list of the desired number (up to 3) of adjacent room numbers, separated     \n"
        	"   by spaces. If an arrow can't go a direction because there is no connecting   \n"
        	"   tunnel, it ricochets and moves to the lowest-numbered adjacent room and      \n"
        	"   continues doing this until it has traveled the designated number of rooms.   \n"
        	"   If the arrow hits the Wumpus, you win! If the arrow hits you, you lose. You  \n"
        	"   automatically pick up the arrow if you go through a room with the arrow in   \n"
        	"   it.                                                                          \n"
        	"3. Enter 'R' to reset the person and hazard locations, useful for testing.      \n"
        	"4. Enter 'C' to cheat and display current board positions.                      \n"
        	"5. Enter 'D' to display this set of instructions.                               \n"
        	"6. Enter 'P' to print the maze room layout.                                     \n"
        	"7. Enter 'X' to exit the game.                                                  \n"
        	"                                                                                \n"
        	"Good luck!                                                                      \n"
        	" \n\n");
}//end displayInstructions()

//--------------------------------------------------------------------------------
int main(void) 
{
  srand(0);  // seeds srand to 0
  int person = rand() % 20 + 1;  // initializes and sets person to a random variable
  int Wumpus = rand() % 20 + 1;  // initializes and sets wumpus to a random variable 
  int pit1 = rand() % 20 + 1;  // initializes and sets pit1 to a random variable 
  int pit2 = rand() % 20 + 1;  // initializes and sets pit2 to a random variable 
  int bat1 = rand() % 20 + 1;  // initializes and sets bat1 to a random variable 
  int bat2 = rand() % 20 + 1;  // initializes and sets bat2 to a random variable 
  int arrow = rand() % 20 + 1;  // initializes and sets arrow to a random variable 
  int moveNumber = 1;
  char userInput;
  int userGuess, inputM, wumpusGuess;
  int i;
  int roomNumber;
  int arrowRoom1;


  int **roomArray = malloc(20 *sizeof(int *)); // dynamically allocates memory for the cave 
  for (i = 0; i < 21; i++) { // size of 21 rooms
    roomArray[i] = malloc(sizeof(int) * 3); // and 3 tunnels for each room
  }

  roomArray[1][0] = 2, roomArray[1][1] = 5, roomArray[1][2] = 8;
  roomArray[2][0] = 1, roomArray[2][1] = 3, roomArray[2][2] = 10;
  roomArray[3][0] = 2, roomArray[3][1] = 4, roomArray[3][2] = 12;
  roomArray[4][0] = 3, roomArray[4][1] = 5, roomArray[4][2] = 14;
  roomArray[5][0] = 1, roomArray[5][1] = 4, roomArray[5][2] = 6;
  roomArray[6][0] = 5, roomArray[6][1] = 7, roomArray[6][2] = 15;
  roomArray[7][0] = 6, roomArray[7][1] = 8, roomArray[7][2] = 17;
  roomArray[8][0] = 1, roomArray[8][1] = 7, roomArray[8][2] = 9;
  roomArray[9][0] = 8, roomArray[9][1] = 10, roomArray[9][2] = 18;
  roomArray[10][0] = 2, roomArray[10][1] = 9, roomArray[10][2] = 11;
  roomArray[11][0] = 10, roomArray[11][1] = 12, roomArray[11][2] = 19;
  roomArray[12][0] = 3, roomArray[12][1] = 11, roomArray[12][2] = 13;
  roomArray[13][0] = 12, roomArray[13][1] = 14, roomArray[13][2] = 20;
  roomArray[14][0] = 4, roomArray[14][1] = 13, roomArray[14][2] = 15;
  roomArray[15][0] = 6, roomArray[15][1] = 14, roomArray[15][2] = 16;
  roomArray[16][0] = 15, roomArray[16][1] = 17, roomArray[16][2] = 20;
  roomArray[17][0] = 7, roomArray[17][1] = 18, roomArray[17][2] = 16;
  roomArray[18][0] = 9, roomArray[18][1] = 7, roomArray[18][2] = 19;
  roomArray[19][0] = 11, roomArray[19][1] = 18, roomArray[19][2] = 20;
  roomArray[20][0] = 13, roomArray[20][1] = 16, roomArray[20][2] = 19;

  randCheck(&pit1, &pit2, &Wumpus, &person, &bat1, &bat2, &arrow);
  
  while (userInput != '@') {  // infinite loop that keeps the game running unless you hit X, die, or win!
      printf("You are in room %d. ", person);
      checker(&pit1, &pit2, &Wumpus, &person, roomArray, &moveNumber, &bat1, &bat2, &arrow);  // checks if the variables are adjacent to the person
      printf("\n\n%d. Enter your move (or 'D' for directions): ", moveNumber);
      scanf(" %c", &userInput);  // takes in the users menu option choice 

      if (toupper(userInput) == 'M') {  // calls movePlayer if the user enters M or m, and checks if the user dies by falling into any of the pits or wumpus
        movePlayer(&pit1, &pit2, &Wumpus, &person, roomArray, &moveNumber, &bat1, &bat2, &arrow);
        if (person == arrow) {
          printf("Congratulations, you found the arrow and can once again shoot.\n");
          arrow = -1; // sets the arrow to -1 meaning the user picked up the arrow
        }
        continue;
      }
      if (toupper(userInput) == 'R') {  // calls resetVar if the user enters R or r, which sets the variables to the user's specidifed input
        resetVar(&pit1, &pit2, &Wumpus, &person, &bat1, &bat2, &arrow);
        continue;
      }
      if (toupper(userInput) == 'C') {  // prints out the cheating menu option with the game elemnt positions if the user inputs C or c.
        printf("Cheating! Game elements are in the following rooms: \nPlayer Wumpus Pit1 Pit2 Bats1 Bats2 Arrow  \n   %d     %d     %d    %d    %d    %d    %d \n\n", person, Wumpus, pit1, pit2, bat1, bat2, arrow);
        continue;
      }
      if (toupper(userInput) == 'D') {  // displays the cave and then the instructions if the user inputs D or d
        displayCave();
        displayInstructions();
        continue;
      }
      if (toupper(userInput) == 'S') { // handles all the shooting functions if the user enter s or S
        moveNumber++; // increments the move number after every shot
        shootArrow(&person, &Wumpus, &arrow, roomArray, &roomNumber, &arrowRoom1, &moveNumber);
      }
      if (toupper(userInput) == 'P') {  // displays the cave if the user inputs P or p
        displayCave();
        continue;
      }
      if (toupper(userInput) == 'G') { // menu option g allows the user to guess the room the wumpus is in to win 
        printf("Enter room (1..20) you think Wumpus is in: ");
        scanf("%d", &userGuess);  // assigns the user's guess to the memory location of variable userGuess
        if (userGuess == Wumpus) {  // checks if the user's guess matches the wumpus and prints out a winning message and ends the game
          printf("You won!\n\n");
          printf("Exiting Program ...");
          break;
        }
        else {  // ends the game if the user the user guess the wrong wumpus room
          break;
        }
      }
      if (toupper(userInput) == 'X') {  // ends the program if the user inputs X or x
        printf("\nExiting Program ...");
        break;
      }
    }
	return 0;
}
