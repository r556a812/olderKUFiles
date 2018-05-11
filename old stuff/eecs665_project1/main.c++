/**
*	@file : main.cpp
*	@author :  Richard Aviles
*	@date : 2017.10.24
*	Purpose: The main to run the conversion for NFA to DFA
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


/**
 * Changes the string into int
 *
 * @param data: The string to to be changed
 * @return A vector containing the int.  If no number in the string then return -1
 */
std::vector<int> translateString(std::string data)
{
  int nums;
  std::string temp;//Holds the number seperated from the string
  std::vector<int> v;//The return vector

  if(data.length() == 2)
  {
    v.push_back(-1);
  }
  else
  {
    for (int i=0; i<data.length(); i++)
    {
      if (isdigit(data[i]))
      {
        temp += data[i];
      }
      else
      {
        if (temp != "")
        {
          nums = std::stoi(temp);
          v.push_back(nums);
          temp = "";
        }
      }
    }
  }
  return v;
}

/**
 * Gets the e moves and stores them into the vector places
 *
 * @param table: the string array holding all transitions
 * @param eSpot: the location in the table of the e transitions(last input spot)
 * @param currState: The current state to find the e transitions for
 * @param places: Vector passed by reference to hold the posible transitions.
 * @return Nothing
 */
void eTransition(std::string** table, int eSpot, int currState, std::vector<int>& places)
{
  std::string s = table[currState][eSpot]; //The string holding e transitions for currState
  std::vector<int> temp = translateString(s); //The translated ints of the string
  bool isThere = false;

  places.push_back(currState+1); //Put the current State into the place holder

  for(int i = 0; i < temp.size(); i++) //iterate through the new spots and see if need to add to the place holder
  {
    isThere = ( std::find(places.begin(), places.end(), temp[i]) != places.end() );
    if(temp[i] != -1 && !isThere)
    {
      eTransition(table, eSpot, temp[i]-1, places);
    }
  }
}

/**
 * Prints the e closure information
 *
 * @param moves: The vector containg the e transition move
 * @param places: The vector containing the e closure places
 * @param startState: A bool, only used to determine if its the start state for formatting purposes
 * @param currMark: The current Mark, used for printing
 * @return Nothing
 */
void eClosurePrint(std::vector<int>& moves, std::vector<int>& places, bool startState, int currMark)
{
  //std::sort (places.begin(), places.end()); //Sorts the places vector in ascending order
  //std::sort (moves.begin(), moves.end()); //Sorts the moves vector in ascending order
  if(startState)
  {
    std::cout << "E-closure(IO) = {";
  }
  else
  {
    std::cout << "E-closure{";
    for (int j = 0; j < moves.size(); j++)
    {
      if(j != moves.size() - 1)
      {
        std::cout << moves[j] << ",";
      }
      else
      {
        std::cout << moves[j];
      }
    }
    std::cout << "} = {";
  }

  for(int i = 0; i < places.size(); i++)
  {
    if(i != places.size() - 1)
    {
      std::cout << places[i] << ",";
    }
    else
    {
      std::cout << places[i];
    }
  }

  std::cout << "} = " << currMark << "\n";
}

/**
 * Prints the move information information
 *
 * @param places: The vector containing the e closure places
 * @param input: The current input letter, given in number form and later translated into char
 * @param moves: The vector containg the e transition move
 * @return Nothing
 */
void markPrint(std::vector<int>& places, int input, std::vector<int>& moves)
{
  char inp = static_cast<char>(input+97); //Convert the number into the corresponding lowercase alphabet
  std::cout << "{";
  for (int i = 0; i < places.size(); i++)
  {
    if(i != places.size() - 1)
    {
      std::cout << places[i] << ",";
    }
    else
    {
      std::cout << places[i];
    }
  }
  std::cout << "} --" << inp << "--> {";
  for (int j = 0; j < moves.size(); j++)
  {
    if(j != moves.size() - 1)
    {
      std::cout << moves[j] << ",";
    }
    else
    {
      std::cout << moves[j];
    }
  }
  std::cout << "}\n";
}

/**
 * Checks to see if can move given the input, if it can it places the moves into vector moves
 *
 * @param table: the string array holding all transitions
 * @param input: The current input spot in the table array
 * @param currState: The current state to find the e transitions for
 * @param places: Vector passed by reference to hold the posible transitions.
 * @param moves: The vector containg the input transition moves
 * @return A boolean, true if it was able to move, false otehrwise
 */
bool inputTransition(std::string** table, int input, std::vector<int>& places, std::vector<int>& moves)
{
  int place; //Holder for the current state
  std::vector<int> move; //Holder for a move if one is possible
  bool anyMoves = false; //Bool being returned
  bool add = true;

  for (int i = 0; i < places.size(); i++)
  {
    place = places[i]-1;
    move = translateString(table[place][input]);
    if(move[0] != -1)
    {

      for(int j = 0; j < move.size(); j++)
      {
        for(int k = 0; k < moves.size(); k++)
        {
          if(move[j] == moves[k])
          {
            add = false;
          }
        }
        if(add)
        {
          moves.push_back(move[j]);
        }
        add = true;
      }

      anyMoves = true;
    }
  }
  return anyMoves;
}

int main (int argc, char* argv[])
{
  std::string file;
  if (argc < 2)
  {
    std::cout << "Please give an input file:  ";
    std::cin >> file;
  }
  else
  {
    file = argv[1];
  }

  int istate = 0; //Holds the start state
  int tstates = 0; //Holds the total states
  std::vector<int> fstates; //Vector to hold the final states
  std::string s; //String used to input the lines
  std::string temp; //Temp string for converting string s
  int nums = 0; //Holder for the final states values that get pushed into the fstates vector

  //Open the file
  ifstream infile;
  infile.open(file);

  //Get the initial state
  std::getline(infile, s, '{');
  infile >> istate;
  std::getline(infile, s);

  //Get the final states
  std::getline(infile, s);
  for (int j=0; j<s.size(); j++)
  {
    if (isdigit(s[j]))
    {
      temp += s[j];
    }
    else
    {
      if (temp != "")
      {
        nums = std::stoi(temp);
        fstates.push_back(nums);
        temp = "";
      }
    }
  }

  //Get the total states
  std::getline(infile, s, ':');
  infile >> tstates;
  std::getline(infile, s);

  // Get the number of inputs
  std::getline(infile, s);
  istringstream iss(s);
  iss >> temp;
  int inputTotal = 0;
  while (temp != "E")
  {
    iss >> temp;
    inputTotal++;
  }

  //Read the data into the table array
  //Left as strings and convert to numbers later
  std::string** table;
  table = new std::string* [tstates];
  int j = 0;
  while(getline(infile, s))
  {
    table[j] = new std::string[inputTotal];
    istringstream iss(s);
    iss>>temp;
    for (int i = 0; i < inputTotal; i++)
    {
      iss >> temp;
      table[j][i] = temp;
    }
    j++;
  }
  infile.close(); //Finished with the file

  std::vector<int> places; //Holder for e transition moves
  std::vector<int> moves; //Holder for input moves
  std::vector<int> v; //Holder for the final states
  bool move = false; //Bool for return on inputTransition function call
  bool same = false; //Bool to check if moves is the same from a previous step
  bool goBack = false; //Bool to go back an increment in mark if same becomes true
  int state = 0; //Current state
  int mark = 1; //The amount of marks at after each e transition
  int currMark = 0; //The current mark being worked on
  int finalArray[tstates*4][inputTotal - 1]; //Holds the final information to be printed
  std::vector<std::vector<int>> markHolder; //2d vector to hold the moves depending on the current mark
  std::vector<std::vector<int>> placeHolder; //2d vector holding the places vectors depending on the current mark
  placeHolder.resize(tstates*4); //Initialize to greatest possible amount since actual size is unknown(Can't be bigger than the original amount of states)
  markHolder.resize(tstates*4); //Initialize to greatest possible amount since actual size is unknown(Can't be bigger than the original amount of states)

  bool add = true;
  int markTemp = mark;

  //The moves for the initial state is outside the do while loop
  eTransition(table, inputTotal-1, istate-1, places);

  std::sort (places.begin(), places.end()); //Sorts the places vector in ascending order
  std::sort (moves.begin(), moves.end()); //Sorts the moves vector in ascending order
  places.erase( unique( places.begin(), places.end() ), places.end() ); //Erases any duplicates

  eClosurePrint(moves, places, true, currMark+1);
  markHolder[mark] = moves;
  placeHolder[mark] = places;
  mark++;

  //Do while loop to calculate all transitions. Ends when currMark == mark+1
  do {
    currMark++;
    moves.clear();

    if(currMark != mark)
    {
      std::cout << "\nMark " << currMark << "\n";

    //Iterate through all the inputs minus the e closure
    for(int i = 0; i < inputTotal-1; i++)
    {
      places = placeHolder[currMark];
      move = inputTransition(table, i, places, moves);

      if(move) //If was able to find moves
      {
        markTemp = mark;
        add = true;
        markPrint(places, i, moves);
        places.clear();

        for(int g = 0; g < moves.size(); g++)
        {
          eTransition(table, inputTotal-1, moves[g]-1, places);
        }

        std::sort (places.begin(), places.end()); //Sorts the places vector in ascending order
        std::sort (moves.begin(), moves.end()); //Sorts the moves vector in ascending order
        places.erase( unique( places.begin(), places.end() ), places.end() ); //Erases any duplicates

        for(int q=0; q<placeHolder.size(); q++)
        {
          if (places == placeHolder[q])
          {
            add = false;
            markTemp = q;
            break;
          }
        }

        if (add)
        {
          placeHolder[mark] = places;
          mark++;
        }

        eClosurePrint(moves, places, false, markTemp);

        finalArray[currMark-1][i] = markTemp;
      }
      else //Set finalArray at -1 to know that no transition is there
      {
        finalArray[currMark-1][i]= -1;
      }
      moves.clear();
      places.clear();
    }
  }

  }while(currMark != mark);

  //Final printing to give the DFA
  for(int r = 0; r < currMark-1; r++)
  {
    for(int s = 0; s < inputTotal-1; s++)
    {
      if(finalArray[r][s] == currMark-1)
      {
        v.push_back(r+1);
      }
    }
  }
  std::sort (v.begin(), v.end());
  v.erase( unique( v.begin(), v.end() ), v.end() );
  std::cout << "\nInitial State: {" << istate << "}\n";
  std::cout << "Final States: {";
  for (int j = 0; j < v.size(); j++)
  {
    if(j != v.size() - 1)
    {
      std::cout << v[j] << ",";
    }
    else
    {
      std::cout << v[j];
    }
  }
  std::cout << "}\n";
  std::cout << "State\t";
  for (int a = 0; a < inputTotal-1; a++)
  {
    char c = static_cast<char>(a+97);
    if(a != inputTotal-2)
    {
      std::cout << c << "\t";
    }
    else
    {
      std::cout << c << "\n";
    }
  }

  for(int r = 0; r < currMark-1; r++)
  {
    std::cout << r+1 << "\t";
    for (int c = 0; c < inputTotal-1; c++)
    {
      if (finalArray[r][c] != -1)
      {
        std::cout << "{" << finalArray[r][c] << "}\t";
      }
      else
      {
        std::cout << "{}\t";
      }

    }
    std::cout << "\n";
  }

  //Delete the table
  for (int i = 0; i < tstates; i++)
  {
    delete[] table[i];
  }
  delete[] table;

  return(0);
}
