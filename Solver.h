/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 06 Maze Solver
Date Last Modified: 02/27/2017
File Summary:
------------------------------------------*/
#ifndef SOLVER_H
#define SOLVER_H
#include "Finder.h"

class Solver
{
private:
  int startR;
  int startC;
  int s_rows;
  int s_colls;
  int** trackmaze;
  std::string m_finalMoves;
  const char* const* s_maze;

public:
  Solver(Finder& find);
  ~Solver();
  bool solveMaze(int currR, int currC, std::string moves);
  bool validPath(std::string path);
  bool validPosition(int currR, int currC);
  bool canGo(std::string direction);
};
#endif
