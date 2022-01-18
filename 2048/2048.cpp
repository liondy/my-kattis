#include <iostream>
#include <vector>
#include <map>

using namespace std;
void printBoards(vector<vector<int>> &boards) {
  for (int i = 0; i < boards.size(); i++) {
    for (int j = 0; j < boards[0].size(); j++) {
      if (j != 0) {
        cout << " ";
      }
      cout << boards[i][j];
    }
    cout << endl;
  }
}

bool isBorder(int x, int y) {
  if (x == 0 || y == 0 || x == 3 || y == 3) {
    return true;
  }
  return false;
}

bool isOutsideBoards(int x, int y) {
  if (x < 0 || y < 0 || x > 3 || y > 3) {
    return true;
  }
  return false;
}

std::pair<int,int> defineMovement(int move) {
  vector<std::pair<int,int>> movement = {{0,-1}, {-1,0}, {0,1}, {1,0}};
  return movement[move];
}

vector<vector<int>> playerMove(vector<vector<int>> &boards, int move) {
  for (int i = 0; i < 4; i++) {
    int location = -1, counter = 0, next = -1;
    int row, col;
    if (move == 0 || move == 1) {
      for (int j = 0; j < 4; j++) {
        row = i, col = j;
        if (move == 1) {
          row = j; col = i;
        }
        if (boards[row][col] == 0) {
          counter++;
          if (counter == 1) {
            location = j;
            next = j;
          } else if (counter == 2) {
            next = j;
          }
        }
        if (boards[row][col] != 0 && location != -1) {
          if (move == 0) {
            boards[row][location] = boards[row][col];
          } else {
            boards[location][col] = boards[row][col];
          }
          boards[row][col] = 0;
          if (counter < 2) location = j;
          else location = next;
          counter = 0;
        }
      }
    }
    else {
      for (int j = 3; j >= 0; j--) {
        row = i, col = j;
        if (move == 3) {
          row = j, col = i;
        }
        cout << "row: " << row << " col: " << col << endl;
        cout << "counter" << counter << endl;
        if (boards[row][col] == 0) {
          counter++;
          if (counter == 1) {
            location = j;
            next = j;
          } else if (counter == 2) {
            next = j;
          }
        }
        else if (boards[row][col] != 0 && location != -1) {
          if (move == 2) {
            boards[row][location] = boards[row][col];
          } else {
            boards[location][col] = boards[row][col];
          }
          boards[row][col] = 0;
          if (counter < 2) location = j;
          else location = next;
          counter = 0;
        }
      }
    }
  }
  printBoards(boards);
  cout << endl;
  cout << endl;
  std::pair<int,int> movement = defineMovement(move);
  for (int i = 0; i < boards.size(); i++) {
    for (int j = 0; j < boards[i].size(); j++) {
      int newX = i + movement.first;
      int newY = j + movement.second;
      cout << "newX: " << newX << ", " << "newY: " << newY;
      if (isOutsideBoards(newX, newY)) {
        cout << " outside" << endl;
        continue;
      }
      if (boards[i][j] == 0) {
        cout << " current is 0" << endl;
        continue;
      }
      if (boards[i][j] == boards[newX][newY]) {
        cout << " merged";
        boards[newX][newY] *= 2;
        if (move == 0) {
          for (int k = j; k < 3; k++) {
            boards[i][k] = boards[i][k+1];
          }
          boards[i][3] = 0;
        } else if (move == 1) {
          for (int k = i; k < 3; k++) {
            boards[k][j] = boards[k+1][j];
          }
          boards[3][j] = 0;
        } else if (move == 2) {
          for (int k = j; k > 0; k--) {
            boards[i][k] = boards[i][k-1];
          }
          boards[i][0] = 0;
        } else {
          for (int k = i; k > 0; k--) {
            boards[k][j] = boards[k-1][j];
          }
          boards[0][j] = 0;
        }
      } 
      cout << endl;
      printBoards(boards);
    }
  }
  return boards;
}

int main() {
  vector<vector<int>> boards(4);
  int puzzle, move;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> puzzle;
      boards[i].push_back(puzzle);
    }
  }
  cin >> move;
  vector<vector<int>> res = playerMove(boards, move);
  printBoards(res);
  return 0;
}