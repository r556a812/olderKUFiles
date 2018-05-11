/**
*	@file : MazeWalker.hpp
*	@author :  Richard Aviles
*	@date : 2015.11.12
*	Purpose:
*/


#include "MazeWalker.h"
#include <stack>
#include <queue>

MazeWalker::MazeWalker(const char * const *mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice):m_startPos(startRow, startCol)
{
    m_maze = mazePtr;
    m_rows = rows;
    m_cols = cols;
    m_searchType = searchChoice;
    m_curPos = m_startPos;
    m_curStep = 1;
    m_visited = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        m_visited[i] = new int[cols];

    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m_visited[i][j] = 0;
        }
    }

    m_visited[startRow][startCol] = m_curStep;



}


MazeWalker::~MazeWalker()
{
    for (int i = 0; i < m_rows; i++)
        {
            delete[] m_visited[i];
            m_visited[i] = nullptr;
        }

        delete[] m_visited;
        m_visited = nullptr;
}

bool MazeWalker::walkMaze()
{


    if (m_searchType == Search::BFS)
    {
        do
        {
            storeValidMoves();
            move(m_curPos);


        }while (!isGoalReached() && !m_moveQueue.empty());

    }

    if (m_searchType == Search::DFS)
    {
        do
        {
            storeValidMoves();
            move(m_curPos);


        }while (!isGoalReached() && !m_moveStack.empty());
    }

    if (isGoalReached())
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

const int* const* MazeWalker::getVisited() const
{
   return (m_visited);
}

int MazeWalker::getVisitedRows() const
{
    return (m_rows);
}

int MazeWalker::getVisitedCols() const
{
    return (m_cols);
}

const char* const* MazeWalker::getMaze() const
{
    return (m_maze);
}

void MazeWalker::storeValidMoves()
{
    //Up
    if (m_curPos.getRow() - 1 >= 0 && (m_visited[m_curPos.getRow() - 1][m_curPos.getCol()] == 0) && (m_maze[m_curPos.getRow() - 1][m_curPos.getCol()]) != 'W')
    {
        Position up(m_curPos.getRow() - 1, m_curPos.getCol());
        if (m_searchType == Search::DFS)
        {
            m_moveStack.push(up);
        }
        else
        {
            m_moveQueue.push(up);
        }
    }

    //Right
    if (m_curPos.getCol() + 1 < m_cols && (m_visited[m_curPos.getRow()][m_curPos.getCol() + 1] == 0) && (m_maze[m_curPos.getRow()][m_curPos.getCol() + 1]) != 'W')
    {
        Position right(m_curPos.getRow(), m_curPos.getCol() + 1);
        if (m_searchType == Search::DFS)
        {
            m_moveStack.push(right);
        }
        else
        {
            m_moveQueue.push(right);
        }
    }

    //Down
    if (m_curPos.getRow() + 1 < m_rows && (m_visited[m_curPos.getRow() + 1][m_curPos.getCol()] == 0) && (m_maze[m_curPos.getRow() + 1][m_curPos.getCol()]) != 'W')
    {
        Position down(m_curPos.getRow() + 1, m_curPos.getCol());
        if (m_searchType == Search::DFS)
        {
            m_moveStack.push(down);
        }
        else
        {
            m_moveQueue.push(down);
        }
    }

    //Left
    if (m_curPos.getCol() - 1 >= 0 && (m_visited[m_curPos.getRow()][m_curPos.getCol() - 1] == 0) && (m_maze[m_curPos.getRow()][m_curPos.getCol() - 1]) != 'W')
    {
        Position left(m_curPos.getRow(), m_curPos.getCol() - 1);
        if (m_searchType == Search::DFS)
        {
            m_moveStack.push(left);
        }
        else
        {
            m_moveQueue.push(left);
        }
    }
}

void MazeWalker::move(Position &p)
{
    if (m_searchType == Search::BFS)
    {
        p = m_moveQueue.front();
        m_moveQueue.pop();
        m_curPos = p;
        m_curStep++;
        m_visited[p.getRow()][p.getCol()] = m_curStep;
    }
    else if (m_searchType == Search::DFS)
    {
        p = m_moveStack.top();
        m_moveStack.pop();
        m_curPos = p;
        m_curStep++;
        m_visited[p.getRow()][p.getCol()] = m_curStep;
    }
}

bool MazeWalker::isGoalReached() const
{
    if (m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E')
    {
        return (true);
    }
    else
    {
        return (false);
    }
}






