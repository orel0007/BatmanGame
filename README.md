# BatmanGameGeneral explanation of the exercise:
In this project, we were required to create a version of the game "The Digger," in which the player controls a character who must consume diamonds while avoiding monster attacks and is given a set number of stones to eat at the start of each stage. We reboot the digger and monsters to their original locations if the digger is consumed by a monster.
The game also has a time limit; if the time limit expires, the stage is restarted and taken down to the "fish for life" screen. 
Additionally, the digger will be able to consume gifts, which will increase life, time, and the number of stones that may be consumed.
if the digger consumes more stones than it is permitted to the player will have to start over the level.

## Design:
We created a game controlled by a controller. It makes use of the BORAD's memory.
Additionally, we created a department that assists controllers in managing the game in a "object-oriented" programming manner by breaking it up into objects, each of which has distinct functions.
Additionally, we have a ResourceManager class that runs in Singleton mode, reads all game-related files including photos, FONT, music, and SPRITESHEET, and is initialized just once.
Additionally, there are classes for every item in the game, including monsters, dig tools, gifts, walls, and stones.
In order to check for conflicts between the game's objects, we also employed the double-dispatch mechanism



#### Key data structures and their function:
- vector of levels in the game control
- vector of monsters in the board
- vector of unmovable objects in the board

##### Notable algorithms:
Each smart monster when is its turn to move, calculates the distance from every available spot that.
 it could move to, to the location where the digger is, and then chooses the place where the distance is the minimal.
 Note: the monsters will only stay in their place if they have no possible way to move, we first designed
 the algorithm to let the monster stay in its place if that was a closer spot to the digger but it seemed
 boring that the monsters wouldnt move sometimes.

###### Known bugs:
None.
