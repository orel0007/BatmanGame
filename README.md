# BatmanGameGeneral explanation of the exercise:
In this exercise we were asked to build a version of theDigger game, the Digger has to eat diamonds, and be careful not to be eaten by monsters, and is allowed to eat stones in a limited amount given to him at the beginning of each stage. If the digger is eaten by a monster, we reboot the diggerand monsters to their initial location at that point.
The game also runs by time, each stage has a different time, if the time runs out we reboot the stage and take it down to fish for life. 
The digger will also be able to eat gifts and this will add life, time, stones that are allowed to be eaten.
If the digger eats more stones than it is allowed to, the stage is rebooted and returns the digger, monsters, and diamonds to the beginning of the stage.
As long as the player has life remaining, he continues and progresses through the stages inserted into him in the file "Board.txt
## Design:
We built a game run by , Controller It uses the memory of the BORAD
And we built aboard department, which helpscontrollers manage the game in an "object-oriented" programming form by dividing into objects, and each object has its own functions.
We also have aResourceManager class which runs in Singletonstyle whichis initialized only once and reads all files needed for the game like images,FONT,music,SPRITESHEET.
And we have classes for every object in the game like monsters,digger,gifts, wall, stones
We also used thedouble-dispatch method to check conflicts betweenthe objects in the game.

### Step file format:
We read the steps from a file inResourceswhere we draw the steps that we are
We want to play, so if you want to add a step, just go to this file and draw the stage you want.
List of files created by us:
Controller.h/cpp–The department that manages the game:It uses the memory of theBOARD
Manages the stages and turn of the player is the monsters and updates the screen accordingly.
Board.h/cpp – The department tasked with building and maintaining the game board.
Updates the location of the Digger and the locations of theMonsters that the controller can update with him.
In addition, 1)initiates a new phase and 2)restores the phase again


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
