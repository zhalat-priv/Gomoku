# Gomoku
The project provides gomoku game implementation.
The goal of the game is to put unbroken row of five stones horizontally, vertically or diagonally.

Project uses kind of facade pattern so it can be compiled to two GUI versions: Console & Android 

#### GUI - Android
The first release is avaliable at google store apps:
https://play.google.com/store/apps/details?id=org.qtproject.GomokuHalsoft

![](Design/intro.png)  

#### GUI - Console
However you can compile&run game from your local console.
To do this from project root:

###### Compilation
~~~cmake
├── DbgTools
├── Design
├── README.md
└── src

$ mkdir build
$ cd build
$ cmake
$ make
~~~
###### Running
It accepts 5 parameters. The meaning and limitation are given below:

	1-st: <5,19>	: a board size. Like 10x10
	2-nd: {x,o}		: human color. Like x or o
	3-rd: <0,3>		: game leve. 0-beginner..3-advanced
	4-th: {0,1}		: 1- randomize enabled. Algorithm takes random move if many has the same value
	5-th: <0,...>	: max time for move. 0 - unlimited
	
	$ ./Gomoku 15 o 2 1 0
###### Play
User move shall be provided: *row_number\r column_number\r*

	##
						   1 1 1 1 1 
	   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 
	   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	0 |. . . . . . . . . . . . . . .|
	1 |. . . . . . . . . . . . . . .|
	2 |. . . . . . . . . . . . . . .|
	3 |. . . . . . . . . . . . . . .|
	4 |. . . . . . . . . . . . . . .|
	5 |. . . . . . . . . . . . . . .|
	6 |. . . . . . . . . . . . . . .|
	7 |. . . . . . . x . . . . . . .|
	8 |. . . . . . . . . . . . . . .|
	9 |. . . . . . . . . . . . . . .|
	10|. . . . . . . . . . . . . . .|
	11|. . . . . . . . . . . . . . .|
	12|. . . . . . . . . . . . . . .|
	13|. . . . . . . . . . . . . . .|
	14|. . . . . . . . . . . . . . .|
	  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|
	
	--->>Last cpu move:
	(7, 7)
	
	##
	
	--->>Your move:
	
	##
	6 
	8
						   1 1 1 1 1 
	   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 
	   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	0 |. . . . . . . . . . . . . . .|
	1 |. . . . . . . . . . . . . . .|
	2 |. . . . . . . . . . . . . . .|
	3 |. . . . . . . . . . . . . . .|
	4 |. . . . . . . . . . . . . . .|
	5 |. . . . . . . . . . . . . . .|
	6 |. . . . . . . . o . . . . . .|
	7 |. . . . . . . x . . . . . . .|
	8 |. . . . . . . . . . . . . . .|
	9 |. . . . . . . . . . . . . . .|
	10|. . . . . . . . . . . . . . .|
	11|. . . . . . . . . . . . . . .|
	12|. . . . . . . . . . . . . . .|
	13|. . . . . . . . . . . . . . .|
	14|. . . . . . . . . . . . . . .|
	  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|
	
	--->>Last human move:
	(6, 8)
	
	##
						   1 1 1 1 1 
	   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 
	   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	0 |. . . . . . . . . . . . . . .|
	1 |. . . . . . . . . . . . . . .|
	2 |. . . . . . . . . . . . . . .|
	3 |. . . . . . . . . . . . . . .|
	4 |. . . . . . . . . . . . . . .|
	5 |. . . . . . . . . . . . . . .|
	6 |. . . . . . x . o . . . . . .|
	7 |. . . . . . . x . . . . . . .|
	8 |. . . . . . . . . . . . . . .|
	9 |. . . . . . . . . . . . . . .|
	10|. . . . . . . . . . . . . . .|
	11|. . . . . . . . . . . . . . .|
	12|. . . . . . . . . . . . . . .|
	13|. . . . . . . . . . . . . . .|
	14|. . . . . . . . . . . . . . .|
	  |_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|
	
	--->>Last cpu move:
	(6, 6)
	
	##
	
	--->>Your move:
	
	##

#### Development
To generate Eclipse project do the following:
1. define env **DEFAULT_TOOLCHAIN_PATH** in your system. Default it would be: DEFAULT_TOOLCHAIN_PATH="/usr/bin"
2. from *build* directory run command:
	~~~cmake
	cmake ../src/ -G"Eclipse CDT4 - Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE="../cmake/toolchain-gcc-default.cmake"
	~~~

	It generate eclipse project.

3. Run eclipse. 
  * import
  * General->Existing Projects into Workspace
  * provide path to *build* directory
	Now you should have prepared development envirnoment.
  * build project to be sure configuration is OK

#### CI
CI is based on cpp_unit framework. 