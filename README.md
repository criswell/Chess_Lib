# Sample chess game
## Overview

The game is self-explanatory, but basically it's a very simple chess game for two players.

No AI implemented yet. You type the uppercase letter of the piece you want 
to move as you see it on the board and the coordinates of the square you want to move to 
(for example if you want to move Pawn to square A3 you type Pa3), and the game will find the piece you want to move
and move it by itself.

The game ends if the king has no moves to make, but it won't prevent you from moving the King to a square that will threaten him,
so it can end after the other player directly kills the King.

A log file that records all the moves that took place, is created during the game.

With the Linux version if you type 'pieces' you will get the Unicode chess characters and if you type 'letters' it reverts back.

The thought process behind this project was for me to implement a chess engine for the first time, without seeing
code from other projects or how implementations of chess engines are generally done.

## Building

Needs libncurses to compile on Linux.

If you're compiling on Windows, try using Mingw-w64 to install gcc and dmake (or make). I don't think it will compile as well 
with MSVC.

To compile and run on Windows with dmake (or make):

    dmake dll & dmake exe & chessgame.exe
    
or if you're using Powershell:

    dmake dll;dmake exe;./chessgame.exe

To compile and run on Linux:

    make && make run

I will be releasing precompiled binaries made on Ubuntu 14.04 i386 
and Windows 7 32bit, when bugs are fixed or something in the UI changes.

## TODO

* fix stupid bugs like this (DONE)

 ![Alt text](http://i.imgur.com/u7DMUjg.png)

* implement that horrible piecesOverlap function (DONE)

* fix bug on Windows that rejects input other than the first character after some time (DONE)

* add the functionality for the game to end when a King is unable to make a move without being threatened by another piece/checkmate (WIP)

* fix this bug that only happens with black Pawns (DONE)

  <img src="http://i.imgur.com/cVGe6Sd.png" alt="step1" width = "257" height = "341"/> <img src="http://i.imgur.com/mkwlxOY.png" alt="step1" width = "257" height = "341"/>

* prevent the King from moving to a square that might threaten him (WIP)

* port the main engine to other languages

### License stuff

![GPLv3 logo](http://www.gnu.org/graphics/gplv3-127x51.png)

See COPYING for more information.

Copyright © 2015 G.K. <cyberchiller@gmail.com>
