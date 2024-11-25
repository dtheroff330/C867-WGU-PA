# C867 Scripting and Programming - Applications


This project is the PA for WGU's C867 course and is intended to demonstrate knowledge learned from the coursework, and skill in general usage of c++.


## Features of this program:
- Parses and stores student data from a given table, defined in main.cpp
- Adds, removes, and displays student information
- Ensures correct email address formatting from email addresses provided in the student data table
- Calculates the average time for course completion in days for students
- Can list students by degree program


## Compilation and Running instructions:
- This program was designed on Visual Studio Code with the C++ extension and C++'s requirements for VSC.
- It was designed to be run from bash (made on linux), but powershell will likely work as well.


1. Open a terminal in VSC.
2. Press CTRL + SHIFT + B to build the program.

If this doesn't work - follow the below instructions!
Run this command to ensure all files are being included in compilation, g++ -g main.cpp roster.cpp student.cpp -o main

3. Following compilation, run ./main in the terminal or if configured correctly, simply hit F5. (F5 on my system led to a multitude of issues with the debugging terminal, but your mileage may vary, as this is a known linux issue.)
4. If you wish to debug the program after using the "run ./main" method, simply type gdb ./main in the terminal.
