/*-----------------------------------------
Name: Tristen Schwarzenberger
ID: 2878034
Class: EECS 268
Lab: 06 Maze Solver
Date Last Modified: 02/27/2017
File Summary:
------------------------------------------*/
#include "Solver.h"

//****************************************************
//                                                  //
//     CONSTRUCTOR                                  //
//                                                  //
//****************************************************
Solver::Solver(Finder& find)
{
  s_maze = find.getMaze();
  s_rows = find.getRows();
  s_colls = find.getColls();
  startR = find.getStartR();
  startC = find.getStartC();
  bool start = true;

  if(s_maze[startR][startC] == 'X')
  {
  	start = false;
  	std::cout << s_rows << " " << s_colls << '\n';
 	std::cout << startR << " " << startC << '\n';
  	std::cout << "Invalid starting position!\n";
  }

  trackmaze = new int*[s_rows];
  for(int i = 0; i < s_rows; i++)
  {
    trackmaze[i] = new int[s_colls];
  } 

  for(int i = 0; i < s_rows; i++)
  {
    for(int j = 0; j < s_colls; j++)
    {
      trackmaze[i][j] = 0;
    }
  }

  
  if(start)
  {
  //Solves the maze
  if(solveMaze(startR, startC, ""))
  {
  	int count = 0;
  	int r = startR;
  	int c = startC;
  	std::cout << "Starting position: " << startR << "," << startC << '\n';
 	std::cout << "Size: " << s_rows << "," << s_colls << '\n';
 	

 //Makes final maze path
 for(unsigned int i = 0; i <= m_finalMoves.length(); i++)
  {   
  	if(m_finalMoves[i] == 0)
  	{
  		trackmaze[r][c] = count + 1;
  	}
  	else if(m_finalMoves[i] == 'L')
  	{
  		trackmaze[r][c] = count + 1;
  		c--;
  	}
  	else if(m_finalMoves[i] == 'U')
  	{
  		trackmaze[r][c] = count + 1;
  		r++;
  	}
  	else if(m_finalMoves[i] == 'D')
  	{
  		trackmaze[r][c] = count + 1;
  		r--;
  	}
  	else if(m_finalMoves[i] == 'R')
  	{
  		trackmaze[r][c] = count + 1;
  		c++;
  	}
  	count++;
  }

  //Prints the final maze path
  for(int i = 0; i < s_rows; i++)
  {
  	for(int j = 0; j < s_colls; j++)
  	{
  		std::cout << trackmaze[i][j] << "\t";
  	}
  	std::cout << '\n';
  }
  std::cout << "We escaped!\n";
  }
  else
  {
  	std::cout << s_rows << ", " << s_colls << '\n';
 	std::cout << startR << ", " << startC << '\n';
  	std::cout << "No escape!\n";
  }	
 }
}

//****************************************************
//                                                  //
//     DESTRUCTOR                                   //
//                                                  //
//****************************************************
Solver::~Solver()
{
  for(int i = 0; i < s_rows; i++)
  {
    delete[] s_maze[i];
    delete[] trackmaze[i];
  }
  delete[] s_maze;
  delete[] trackmaze;

}

//****************************************************
//                                                  //
//  VALID PATH - Makes sure you don't go back where //
//        you came from                             //
//****************************************************
bool Solver::validPath(std::string path)
{
	int vertical = 0;
	int horizontal = 0;
  for(int i = path.length(); i >= 0; i--)
  {
  	if(path[i] == 'U')
  	{
  		vertical++;
  	}
  	else if(path[i] == 'D')
  	{
  		vertical--;
  	}
  	else if(path[i] == 'R')
  	{
  		horizontal++;
  	}
  	else if(path[i] == 'L')
  	{
  		horizontal--;
  	}
  }
  return(horizontal != 0 || vertical != 0);
}

//****************************************************
//                                                  //
//   CAN GO - See's if you can adnvance in maze //
//                                                  //
//****************************************************
bool Solver::canGo(std::string directions)
{
	if(directions == "")
	{
		return(true);
	}

	bool valid = true;
	for(unsigned int i = 0; i < directions.length(); i++)
	{
		std::string sub = directions.substr(directions.length() - 1 - i, directions.length());
		//Takes all substrings greater than length one which include the most recent character and see if there's any loops
		if(!validPath(sub))
		{
			valid = false;
			break;
		}
	}
	
	return(valid);
}

bool Solver::validPosition(int currR, int currC)
{
	return(currR >= 0 && currR <= s_rows && currC >= 0 && currC <= s_colls && s_maze[currR][currC] != 'X');
}

//****************************************************
//                                                  //
//     SOLVE MAZE - Trys to solve maze              //
//                                                  //
//****************************************************
bool Solver::solveMaze(int currR, int currC, std::string moves)
{

	if(s_maze[currR][currC] == 'E')
	{
		m_finalMoves = moves;
		return(true);
	}
	
	if(validPosition(currR - 1, currC))
	{
		if(canGo(moves + "D"))
		{   
			if(solveMaze(currR - 1, currC, moves + "D"))
			{
				return(true);
			}
		}
	}

	if (validPosition(currR + 1, currC))
	{
		if(canGo(moves + "U"))
		{
			if(solveMaze(currR + 1, currC, moves + "U"))
			{
				return(true);
			}
		}
	}
	if (validPosition(currR, currC + 1))
	{
		if(canGo(moves + "R"))
		{
			if(solveMaze(currR, currC + 1, moves + "R"))
			{
				return(true);
			}
		}
	}
	if (validPosition(currR, currC - 1))
	{
		if(canGo(moves+"L"))
		{
			if(solveMaze(currR, currC - 1, moves + "L"))
			{
				return(true); 
			}
		}
	}

	return(false);
}














//Free Space
