# Hunt The Wumpus Game
## This repository contains a C implementation of the classic game "Hunt the Wumpus." The game is set in a dark cave with 20 rooms connected by tunnels. Your mission is to hunt down the elusive Wumpus without falling into pits or being carried away by super-bats.

### Game Description
The cave has 20 rooms, each connected to three other rooms.
Hazards include:
Two rooms with bottomless pits. Falling into one means game over.
Two rooms with super-bats that can carry you to a random room.
The Wumpus, a creature that will end the game if you encounter it in a room.
You are equipped with a single arrow to hunt the Wumpus. Shooting the arrow through the tunnels, you aim to hit the Wumpus without hitting yourself.

### Gameplay
On each turn, you can move to an adjacent room or shoot your arrow through up to three connected rooms.
The game provides hints about nearby hazards: a stench indicates the Wumpus is close, a breeze suggests a nearby pit, and bat noises signal close super-bats.
Use commands to navigate:
M to move to a room.
S to shoot the arrow.
R to reset the game.
C to cheat by revealing the locations of all game elements.
D to display instructions.
P to show the cave layout.
X to exit the game.

### Features
Dynamic Cave Generation: The game initializes with the player, Wumpus, pits, bats, and the arrow randomly placed in the cave's rooms.
Player Movements: Allows moving to adjacent rooms, checking for hazards and updating the game state accordingly.
Arrow Mechanics: Players can shoot an arrow through a sequence of rooms, aiming to hit the Wumpus while avoiding self-harm.
Hazard Warnings: Provides auditory and sensory cues indicating the proximity of hazards.
Win/Lose Conditions: Players win by shooting the Wumpus and lose by falling into pits or encountering the Wumpus.

### Installation
Clone this repository or download the source code.
Compile the program using a C compiler (e.g., gcc hunt_the_wumpus.c -o hunt_the_wumpus).
Run the executable (./hunt_the_wumpus) to start the game.

## How to Play
Follow the on-screen instructions to move through the rooms or shoot your arrow. Use the game commands to interact with the game world and strategize your hunt for the Wumpus.
