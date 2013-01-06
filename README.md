gametheory
==========

Packing multi-dimensional data for game theory applications.  
BSD license.  
For version log, view the individual files.  

To run the units tests, use the command:

    bash test-gametheory.c
    
It uses a bash script combined with C preprocessor-macroes to compile and run the program.  

##Introduction

Game theory is the study of strategic decision making.  

A "normal form" is represented as a multi-dimensional grid where each payoff depends on the combination of choices.  
The number of items in a such grid increases with:

    players * choices ^ players
    
This is for a Symmetric game, where all players have the same number of choices.

It is therefore only practical to deal with games with relative few players.  

This module helps you to calculate the index position in a such grid.  
