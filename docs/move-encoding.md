### Move Encoding

```
   Move Encoding:
   FFFF FFTT TTTT PCXY |
   ==== ==== ==== ==== |=============
   xxxx xx00 0000 0000 | from square
   0000 00xx xxxx 0000 | to square

00 0000 0000 0000 0000 | quiet move
01 0000 0000 0000 000x | double pawn push
02 0000 0000 0000 00x0 | kingside castling
03 0000 0000 0000 00xx | queenside castling
04 0000 0000 0000 0x00 | capture flag
05 0000 0000 0000 0x0x | ep capture flag
06 0000 0000 0000 0xx0 | not used
07 0000 0000 0000 0xxx | not used
08 0000 0000 0000 x000 | knight promotion
09 0000 0000 0000 x00x | bishop promotion
10 0000 0000 0000 x0x0 | rook promotion
11 0000 0000 0000 x0xx | queen promotion
12 0000 0000 0000 xx00 | knight capture promotion
13 0000 0000 0000 xx0x | bishop capture promotion
14 0000 0000 0000 xxx0 | rook capture promotion
15 0000 0000 0000 xxxx | queen capture promotion

F - from square bit
T - to square bit
P - promotion bit
C - capture bit
X - auxillary-x bit
Y - auxillary-y bit
```

notes:
* quiet moves do not alter material-- no captures nor promotions
* even though the following moves are "quiet", for purposes of encoding they have their own flags and will be encoded in a mutally exclisive mannor from pure quiet moves
  * double pawn push
  * kingside castling
  * queenside castling

reference: 
https://www.chessprogramming.org/Encoding_Moves
