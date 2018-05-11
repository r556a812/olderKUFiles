/**
*	@file : MazeWalker.h
*	@author : Richard Aviles
*	@date : 2015.11.12
	Purpose:  
*/

#ifndef MAZE_WALKER_H
#define MAZE_WALKER_H 
#include "Position.h"
#include <stack>
#include <queue>

enum class Search
{
    DFS,
    BFS
};


class MazeWalker
{
    
public:
    MazeWalker(const char* const* mazePtr=nullptr, int startRow=0, int startCol=0, int rows=0, int cols=0, Search searchChoice=Search::DFS);
    ~MazeWalker();
    bool walkMaze();
    const int* const* getVisited() const;
    int getVisitedRows() const;
    int getVisitedCols() const;
    const char* const* getMaze() const;
    
protected:
    void storeValidMoves();
    void move(Position& p);
    bool isGoalReached() const;
    Search m_searchType;
    const char* const* m_maze;
    int** m_visited;
    int m_rows;
    int m_cols;
    Position m_curPos;
    Position m_startPos;
    std::stack<Position> m_moveStack;
    std::queue<Position> m_moveQueue;
    int m_curStep;
    
};


#endif
