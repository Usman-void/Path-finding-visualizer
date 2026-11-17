const int ROWS = 10;
const int COLS = 10;
const int SIZE = ROWS * COLS;
const int MAX_BUFFER = SIZE * 4;
const int INF = 999999;

class Node
{
@@ -17,6 +19,8 @@ class Node
bool isWall;
bool isVisited;
int distance;
    int parentRow;
    int parentCol;

Node()
{
@@ -25,6 +29,8 @@ class Node
isWall = false;
isVisited = false;
distance = INF;
        parentRow = -1;
        parentCol = -1;
}
};

@@ -54,3 +60,16 @@ class Grid
}
}

    bool isValid(int row, int col) const
    {
        return row >= 0 && row < ROWS &&
               col >= 0 && col < COLS;
    }
     void display(const int path[], int pathSize) const
    {
        cout << endl;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                int position = i * COLS + j;
                bool isPath = false;

                if (path != NULL)
                {
                    for (int k = 0; k < pathSize; k++)
                    {
                        if (path[k] == position)
                        {
                            isPath = true;
                            break;
                        }
                    }
                }

                if (isStart(i, j))
                    cout << "S ";
                else if (isEnd(i, j))
                    cout << "E ";
                else if (nodes[i][j].isWall)
                    cout << "# ";
                else if (isPath)
                    cout << "* ";
                else if (nodes[i][j].isVisited)
                    cout << ". ";
                else
                    cout << "- ";
            }

            cout << endl;
        }
    }
};

int main(void){
    Grid grid;
    int choice = 0;
    do{
        cout << "     PATHFINDING VISUALIZER" << endl;
        cout << "1. Display Grid" << endl;
        cout << "0. Exit" << endl;
    while(choice != 0);
}
