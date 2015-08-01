# Sample chess library
## Overview

The game is self-explanatory, but basically it's a very simple chess game for two players.

No AI implemented. You type the uppercase letter of the piece you want 
to move as you see it on the board and the coordinates of the square you want to move to 
(for example if you want to move Pawn to square A3 you type Pa3), and the game will find the piece you want to move
and move it by itself.

A log file that records all the moves that took place, is created during the game.

The thought process behind this project was for me to implement a chess engine for the first time, without seeing
code from other projects.

There might be tons of other implementations that are probably way smarter than mine but even so, I just did this to have fun :D

## Prerequisites

Needs libncurses to compile. (on Linux)

If you're compiling on windows, try using Mingw-w64 to install gcc. It's the only compiler for Windows I've tested it on.

Would recommend to compile through the Makefile, if you're on a linux distro, only after you've installed
gcc, make and libncurses though.

## TODO

fix stupid bugs like this (DONE)

![Alt text](http://i.imgur.com/u7DMUjg.png)

implement that dreaded piecesOverlap function (WIP)

fix bug on Windows that rejects input other than the first character after some time (weird that I can't recreate this bug on Linux)

add the functionality for the game to end when a king is unable to make a move without being threatened by another piece

### License stuff

![WTFPL logo](http://www.wtfpl.net/wp-content/uploads/2012/12/logo-220x1601.png)

Copyright © 2015 G.K. <cyberchiller@gmail.com>

This work is free. You can redistribute it and/or modify it under the
terms of the Do What The Fuck You Want To Public License, Version 2,
as published by Sam Hocevar. See http://www.wtfpl.net for more details.
