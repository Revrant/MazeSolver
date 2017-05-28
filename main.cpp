/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 06 Maze Solver
Date Last Modified: 02/27/2017
File Summary:
------------------------------------------*/
#include <iostream>
#include "Finder.h"
#include "Solver.h"

int main(int argc, char* argv[])
{
  if(argc < 2)
  {
    std::cout << "Incorrect number of parameters!\n";
  }
  else
  {
    Finder find(argv[1]);
    Solver solve(find);
  }

  return(0);
}
