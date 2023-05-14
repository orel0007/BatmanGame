# BatmanGameGeneral explanation of the exercise:
In this project, we were required to create a version of the game "The Digger".
In which the player controls a character who must consume diamonds while avoiding monster attacks and is given a set number of stones to eat at the start of each stage.
We reboot the digger and monsters to their original locations if the digger is consumed by a monster.
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
When it is their turn to move, each intelligent monster measures the distance from every possible 
location to the digger's location and then selects the site where the distance is the shortest. 
We originally developed the algorithm to let the monster stay in its location if that was a closer spot to the digger but it looked uninteresting that the monsters wouldn't move sometimes. 
It should be noted that the creatures will only stay in their place if they have no feasible method to move..

###### Known bugs:
Smart Monster chase can be improve.
