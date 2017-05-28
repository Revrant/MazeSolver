/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 06 Maze Solver
Date Last Modified: 02/27/2017
File Summary:
------------------------------------------*/
#ifndef FINDER_H
#define FINDER_H
#include <iostream>
#include <fstream>
#include <string>

class Finder
{
private:
  int m_rows;
  int m_colls;
  int m_startR;
  int m_startC;
  int truefile;
  std::ifstream inFile;
  std::string m_filename;
  char** m_maze;

public:
  Finder(std::string filename);
  ~Finder();
  void buildMaze();
  const char *const *const getMaze() const;
  int getRows();
  int getColls();
  int getStartR();
  int getStartC();
};
#endif
