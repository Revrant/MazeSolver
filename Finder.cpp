/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 06 Maze Solver
Date Last Modified: 02/27/2017
File Summary:
------------------------------------------*/
#include "Finder.h"
//****************************************************
//                                                  //
//     CONSTRUCTOR                                  //
//                                                  //
//****************************************************
Finder::Finder(std::string filename)
{
  //Open File
  std::ifstream inFile;
  inFile.open(filename);

  truefile = 0;
  m_filename = filename;
  //--------------------

  //Sets starting position and size of maze then calls buildMaze
  if(inFile.is_open())
  {
     truefile = 1;
  }
  inFile.close();
  buildMaze();
}

//****************************************************
//                                                  //
//     DESTRUCTOR                                   //
//                                                  //
//****************************************************
Finder::~Finder()
{
  for(int i = 0; i < m_rows; i++)
  {
    delete m_maze[i];
  }
  delete m_maze;
}

//****************************************************
//                                                  //
//     BUILD MAZE - Builds the maze                 //
//                                                  //
//****************************************************
void Finder::buildMaze()
{
  if(truefile == 1)
  {
    inFile.open(m_filename);

    if(inFile.is_open())
    {
      inFile >> m_rows;
      inFile >> m_colls;
      inFile >> m_startR;
      inFile >> m_startC;
      m_maze = new char*[m_rows];

      //Creats a 2D Maze
      for(int i = 0; i < m_rows; i++)
      {
        m_maze[i] = new char[m_colls];
      }

      //Allows maze to be created correctly
      std::string temp = "";
      std::getline(inFile, temp);

      //Inputs values into Maze
      for(int r = 0; r < m_rows; r++)
      {

        std::getline(inFile, temp);
        for(int c = 0; c < m_colls; c++)
        {
          m_maze[r][c] = temp[c];
        }
      }
    }
    //Debugging
    /*std::cout << m_startR << " " << m_startC << '\n';
    std::cout << m_rows << " " << m_colls << '\n';

    for(int i = 0; i < m_rows; i++)
    {
      for(int j = 0; j < m_colls; j++)
      {
        std::cout << m_maze[i][j];
      }
      std::cout << '\n';
    }*/
  }
}

//****************************************************
//                                                  //
//     GET MAZE - Returns maze                      //
//                                                  //
//****************************************************
const char *const *const Finder::getMaze() const
{
    return(m_maze);
}

//****************************************************
//                                                  //
//     GET ROWS - Returns rows                      //
//                                                  //
//****************************************************
int Finder::getRows()
{
  return(m_rows);
}

//****************************************************
//                                                  //
//     GET COLLS - Returns columns                  //
//                                                  //
//****************************************************
int Finder::getColls()
{
  return(m_colls);
}

//****************************************************
//                                                  //
//     GET STARTR - Returns starting row coordinate //
//                                                  //
//****************************************************
int Finder::getStartR()
{
  return(m_startR);
}

//****************************************************
//                                                  //
//     GET STARTC- Returns starting coll coordinate //
//                                                  //
//****************************************************
int Finder::getStartC()
{
  return(m_startC);
}








//Free Space
