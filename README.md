# AutomobileManager

Execution:
This Project has been designed to be compiled and run with Dev-C++ 5.11.

Description:

Write a C program to manage the components of a set of cars that will allow the user to view the details of already registered cars, import new cars and search for cars that meet certain specifications. More specifically, for each car there are the following items:

NUMBER (arithmetic only): e.g. 4352
COLOR: e.g. RED
MANUFACTURER: e.g. ALFA-ROMEO
DATE OF CONSTRUCTION: e.g. 2005

We consider that the car details are stored in the 'Cars.txt' file. We also assume that all colors are in the "BasicColors.txt" file. Finally, we consider that all car brands are in Companies.txt (all 3 original files are given).

Each line of the "Cars.txt" file contains a record of the details of a car as follows:

NUMBER - COLOR - MANUFACTURER - DATE

A menu of options such as the following should be displayed to the user:

1. SHOW ALL
2. IMPORT OF NEW SUBSCRIPTION
3. DELETE REGISTRATION
4. REGISTRATION UPDATE
5. SEARCH
6. BASE INFORMATION
0. EXIT

Depending on the number chosen by the user (1, 2, 3, 4, 5, 6, or 0) will be executed
the corresponding action according to the following specifications:
1. The details of all the cars registered in
CARS.TXT file.
2. The user will be asked to enter the details of a new car. The new car will be added to the existing ones. Obviously, it should be checked whether the user input is allowed for each field. No two cars may have the same number. Example (CAUTION: Underlining shows what the user is typing):

new registration
NUMBER: 4432
COLOR: BLUE
MANUFACTURER: FIAT
DATE OF CONSTRUCTION: 1999

SUCCESSFUL NEW SUBSCRIPTION

3. The user is asked to select an existing car registration
which it wishes to delete. For this purpose, the existing car numbers must be presented in ascending order and the user will have to enter the number corresponding to the car they wish to delete. An error message should be displayed if the user enters a non-existent number.

Example:
DELETE REGISTRATION
EXISTING NUMBERS: 3188, 3204, 5250, 7350, 8444
SELECTION: 3188
SUCCESSFUL SUBSCRIPTION DELETE

4. The user is asked to select an existing car registration which he wishes to modify. For this purpose, the existing numbers must be presented in ascending order and the user will have to enter the number corresponding to the car whose data he wishes to modify. An error message should be displayed if the user enters a non-existent number. Then the car details are displayed one by one and the user is asked to enter the new items.

Example:
REGISTRATION UPDATE
EXISTING NUMBERS: 3188, 3204, 5250, 7350, 8444
SELECTION: 3188
NUMBER (3188): 3188
COLOR: (BLUE): RED
MANUFACTURER (FIAT): FIAT
CUBIC (1600): 1800
DATE OF CONSTRUCTION (1999): 1999
SUCCESSFUL REGISTRATION UPDATE
5. The user wants to find out which cars match some of the criteria that he will set. When selecting the search another menu appears with the following options:
SEARCH MENU
1. BASED ON THE NUMBER
2. BASED ON COLOR
3. BASED ON THE MANUFACTURER
4. BASED ON THE DATE OF CONSTRUCTION
0. BACK TO MAIN MENU

5.1 If the user chooses a number search, he can search for cars with a number greater than or less than a number specified by him. To do this, he is required to enter a comparison symbol ('<' or '>') and a number of his choice, and all cars that meet this limitation are displayed.
Example:
SEARCH BY NUMBER
SEARCH CRITERIA:> 7000
DOCUMENTS FOUND
NUMBER: 7230
COLOR: WHITE
MANUFACTURER: NISSAN
DATE OF CONSTRUCTION: 2003


5.2 If the user selects a color-based search, all the different colors corresponding to the existing records (each color must be displayed once) should first appear and select one by typing it again (WARNING: not necessarily all).

Example:
SEARCH BY COLOR
AVAILABLE COLORS: RED, BLUE, YELLOW, WHITE
SEARCH COLOR: WH
DOCUMENTS FOUND
NUMBER: 7230
COLOR: WHITE
MANUFACTURER: NISSAN
DATE OF CONSTRUCTION: 2003


5.3 A search similar to that of color is followed by manufacturer search. Initially all the different manufacturers appear and the user selects the one they want and all the cars corresponding to it are displayed.
5.4 For a search by date of manufacture, a procedure similar to the number is followed. The user is asked to enter a special symbol ('<' or '>') and one year and all cars that meet this limitation are displayed.
5.0 With 0 we return to the main menu.
6. This option should update the CARS.TXT file with
current car information.
0. Terminate the program.
For convenience, you consider that up to 100 Cars can be processed. This number should be easily changed with minimal numbers
modifications to the code.
After selecting a user action and displaying the corresponding results, the main options menu should reappear. That is, the user will be able to select a number of actions when using the program.




