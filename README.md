# doodlebuggies

Ants and Doodlebugs README 

Victoria Bowen and Hava Kantrowitz 

Summary:

This project simulates an n by n grid of ants and doodlebugs. The program can take up to six optional arguments: the grid size (default 20), the initial number of doodlebugs (default 5), the initial number of ants (default 100), the max number of time steps (default 1000), the seed number (default 1), and the pause number (default 0). Once the game is started the production generates a random configuration of the given number of ants and doodlebugs. 
	
The simulation is then played through a series of time steps. In each step the doodlebug plays before the ant. There are three actions the doodlebug can take during one turn: move, eat, and breed. First, the doodlebug tries to eat an ant in an adjacent cell (not a diagonal cell). If there are no ants to be eaten, the doodlebug moves to an empty adjacent cell. If all the surrounding cells are occupied or off the edge of the board then the doodlebug stays put. If the doodlebug is alive for three turns without eating an ant, then the doodlebug starves and will be removed from the grid. If the doodlebug survives eight time steps, then the doodlebug breeds and a new doodlebug is born in an adjacent cell. If no cells are available for the new doodlebug, then the doodlebug can breed on the next turn. 

The ant can take two actions during the time step: move and breed. First, the ant tries to move into the adjacent cell (no diagonal moves allowed). If there are no empty cells, the ant stays put until the next turn. If the ant survives three time steps, then it is able to breed into an adjacent cell in the same manner as the doodlebug. Throughout the time steps neither the ants nor the doodlebugs are able to breed or move off the edge of the board. 

The simulation terminates when the max number of time steps is reached. However, if either all the doodlebugs or all the ants die before reaching the max number of time steps then the simulation will terminate. 

Running the Program:  

To run this program, the executable and any number of the six additional arguments should be entered on the command line. All of the arguments should be integer values that are greater than or equal to zero except for the seed and the grid size. The seed is also able to be a negative value, and the grid size cannot equal zero. If any of the arguments do not meet these requirements, they will be set to their default values. The grid size should be able to fit the total number of ants and doodlebugs. If the input size is not large enough, the grid will be resized to fit the input number of ants and doodlebugs. 

Challenges Faced:  

This was our first time coding with C++; therefore, it took a little while to get used to some of the new syntax. It also took some time to figure out how to get the include statements to work without including the same header files multiple times. 
	
Algorithms Used: 

We used the starter code that was released with this assignment to create our program.
