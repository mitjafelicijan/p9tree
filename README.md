# Plan9 tree util

`tree` is written with Plan9 Operating System in mind so it may not work
with other systems.

It is using [Plan9 C compiler](https://plan9.io/sys/doc/compiler.html).

## Description

Tree is a recursive directory listing program that displays files in a 
hierarchical structure with indentation based on their depth. The program 
outputs the listing to the terminal.

If no arguments are provided, tree lists all the files in the current 
directory. When directory arguments are given, tree lists all the files and 
directories found within each specified directory.

