#include <iostream>
#include "PathFinding.h"
using namespace std;

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(10000, '\n');
}

bool readInt(int& value)
{
    if (!(cin >> value))
    {
        if (!cin.eof())
            clearInputBuffer();
        return false;
    }
    return true;
}

bool readCoords(int& row, int& col)
{
    if (!(cin >> row >> col))
    {
        if (!cin.eof())
            clearInputBuffer();
        return false;
    }
    return true;
}

int main()
{
    Grid grid;
    int choice = 0;

    do
    {
        cout << "\n================================" << endl;
        cout << "     PATHFINDING VISUALIZER" << endl;
        cout << "================================" << endl;
        cout << "1.  Display Grid" << endl;
        cout << "2.  Add Wall" << endl;
        cout << "3.  Remove Wall" << endl;
        cout << "4.  Set Start & End Positions" << endl;
        cout << "5.  BFS" << endl;
        cout << "6.  DFS" << endl;
        cout << "7.  Dijkstra" << endl;
        cout << "8.  A Star" << endl;
        cout << "9.  Clear Walls" << endl;
        cout << "10. Set Terrain Cost (1-9)" << endl;
        cout << "11. Clear Terrain" << endl;
        cout << "12. Exit" << endl;

        cout << "\nEnter choice: ";
        if (!readInt(choice))
        {
            if (cin.eof())
            {
                cout << "\nInput closed. Exiting." << endl;
                break;
            }
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        if (choice == 1)
        {
            grid.display(NULL, 0);
        }
        else if (choice == 2)
        {
            int row, col;
            cout << "Enter row and column: ";
            if (readCoords(row, col))
                grid.addWall(row, col);
            else if (cin.eof())
            {
                cout << "\nInput closed. Exiting." << endl;
                break;
            }
            else
                cout << "Invalid input! Enter two integers." << endl;
        }
        else if (choice == 3)
        {
            int row, col;
            cout << "Enter row and column: ";
            if (readCoords(row, col))
                grid.removeWall(row, col);
            else if (cin.eof())
            {
                cout << "\nInput closed. Exiting." << endl;
                break;
            }
            else
                cout << "Invalid input! Enter two integers." << endl;
        }
        else if (choice == 4)
        {
            int sRow, sCol, eRow, eCol;
            cout << "Enter Start (row col): ";
            if (!readCoords(sRow, sCol))
            {
                if (cin.eof())
                {
                    cout << "\nInput closed. Exiting." << endl;
                    break;
                }
                cout << "Invalid input! Enter two integers." << endl;
                continue;
            }

            cout << "Enter End (row col): ";
            if (!readCoords(eRow, eCol))
            {
                if (cin.eof())
                {
                    cout << "\nInput closed. Exiting." << endl;
                    break;
                }
                cout << "Invalid input! Enter two integers." << endl;
                continue;
            }

            grid.setStartEnd(sRow, sCol, eRow, eCol);
        }
        else if (choice == 9)
        {
            grid.clearWalls();
        }
        else if (choice == 10)
        {
            int row, col, cost;
            cout << "Enter row and column: ";
            if (!readCoords(row, col))
            {
                if (cin.eof())
                {
                    cout << "\nInput closed. Exiting." << endl;
                    break;
                }
                cout << "Invalid input! Enter two integers." << endl;
                continue;
            }

            cout << "Enter cost (" << MIN_COST << "-" << MAX_COST << "): ";
            if (!readInt(cost))
            {
                if (cin.eof())
                {
                    cout << "\nInput closed. Exiting." << endl;
                    break;
                }
                cout << "Invalid input! Enter a number." << endl;
                continue;
            }

            grid.setCost(row, col, cost);
        }
        else if (choice == 11)
        {
            grid.clearTerrain();
        }
        else if (choice >= 5 && choice <= 8)
        {
            SearchResult result;

            if (choice == 5)
            {
                cout << "\nRunning BFS..." << endl;
                result = BFS(grid);
            }
            else if (choice == 6)
            {
                cout << "\nRunning DFS..." << endl;
                result = DFS(grid);
            }
            else if (choice == 7)
            {
                cout << "\nRunning Dijkstra..." << endl;
                result = Dijkstra(grid);
            }
            else if (choice == 8)
            {
                cout << "\nRunning A*..." << endl;
                result = AStar(grid);
            }

            grid.display(result.path, result.pathSize);

            cout << "\n========== RESULTS ==========" << endl;
            if (result.found)
            {
                cout << "Path Found!" << endl;
                cout << "Path Length (steps): " << result.pathLength << endl;
                cout << "Path Cost (terrain): " << result.pathCost << endl;
            }
            else
            {
                cout << "No Path Found!" << endl;
            }

            cout << "Visited Nodes: " << result.visitedCount << endl;
        }
        else if (choice != 12)
        {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 12);

    cout << "\nProgram ended!" << endl;
    return 0;
}
