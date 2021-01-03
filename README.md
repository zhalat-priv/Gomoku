# Gomoku
The project provides gomoku game implementation.
The goal of the game is to put unbroken row of five stones horizontally, vertically or diagonally.

Project uses kind of facade pattern so it can be compiled to two GUI versions: Console & Android GUI 

#### GUI - Android
The first release is avaliable at google store apps:
https://play.google.com/store/apps/details?id=org.qtproject.GomokuHalsoft

![](Design/intro.png)  

#### GUI - Console
However, you can compile&run game from your local console.
To put your move on a board provide number of row <enter> and column <enter>

```
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
```

#### Develompent and tests

##### Requirements

* C++-17 compiler (gcc-8 or higher)
  `apt install build-essential`

* [CMake](https://cmake.org/) (3.13 or higher)
  `apt install cmake`

* [Google Test with Google Mock](https://github.com/google/googletest)
  `apt install libgmock-dev libgtest-dev`

* Python3
	
##### How to use

Project is based uses cmake buildsystem. Unit tests are based on GoogleTest framework.
I recomend to use eclipse IDE, but you can compile and run directly form console.

```cmake
├── build<you are here>
└── Gomoku
	├── ci
	├── cmake
	├── CMakeLists.txt
	├── Design
	├── scripts
	├── README.md
	├ ...
	└── src
```
1. define env **DEFAULT_TOOLCHAIN_PATH** in your system. 
	Default it would be: DEFAULT_TOOLCHAIN_PATH="/usr/bin"
2. from *build* directory run command:
	~~~cmake
	cmake ../Gomoku -DCMAKE_BUILD_TYPE=Debug -G"Eclipse CDT4 - Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE="../Gomoku/cmake/toolchain-gcc-default.cmake"
	~~~
	It generates eclipse project which can be imported to IDE as existing project
	Run eclipse
	* import
	* General->Existing Projects into Workspace
	* provide path to *build* directory
	* Now you should have prepared development environment.
	* build project to be sure configuration is OK
3. Doxygen documentation
	There is provided docker file with configured environment to be able generate doxygen doc.
	
	* build image
	~~~cmake
	docker build -t gomoku_doxy scripts/docker_doxygen
	~~~
	* run container
	~~~cmake
	docker run --rm -v <path_to_project>/Gomoku:/gomoku -it gomoku_doxy	
	~~~
	That command runs container in interactive mode.
	Navigate to project and run doxygen command to generate documentation
	~~~cmake
	cd gomoku
	doxygen
	~~~
	
	
