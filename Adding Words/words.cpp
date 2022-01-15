#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stack>

using namespace std;
bool is_operator(string character) {
  return character == "+" || character == "-";
}

bool isExists(map<string,int> &var, string key) {
  map<string,int>::iterator it;
  it = var.find(key);
  if (it == var.end()) {
    return false;
  } return true;
}

int main() {
  string fullCommand;
  map<string, int> var;
  while(getline(cin, fullCommand)) {
    if (fullCommand == "clear") {
      var.clear();
    } else {
      string command = "";
      vector<string> commands;
      for (int i = 0; i < fullCommand.length(); i++) {
        if (fullCommand[i] == ' ') {
          commands.push_back(command);
          command = "";
        }
        else {
          command += fullCommand[i];
        }
      }
      commands.push_back(command);
      if (commands.size() == 3 && commands[0] == "def") {
        if (isExists(var, commands[1])) {
          var[commands[1]] = stoi(commands[2]);
        } else {
          var.insert(std::pair<string,int>(commands[1], stoi(commands[2])));
        }
      } else {
        for (int i = 1; i < commands.size(); i++) {
          cout << commands[i] << " ";
        }
        bool failed = false;
        int calc = 0, number = 0;
        stack<int> numbers;
        stack<string> operators;
        for (int i = 1; i < commands.size(); i++) {
          if (commands[i] == "=") continue;
          if (is_operator(commands[i])){
            operators.push(commands[i]);
          } else {
            if (!isExists(var, commands[i])) {
              cout << "unknown" << endl;
              failed = true;
              break;
            } else {
              map<string,int>::iterator it;
              it = var.find(commands[i]);
              number = it->second;
              if (!operators.empty()) {
                string op = operators.top();
                if (op == "+") {
                  calc = numbers.top() + number;
                } else if (op == "-") {
                  calc = numbers.top() - number;
                }
                operators.pop();
                numbers.pop();
                numbers.push(calc);
              } else {
                numbers.push(number);
              }
            }
          }
        }
        if (!failed) {
          bool found = false;
          for (auto& it : var) {
            if (it.second == numbers.top()) {
              cout << it.first << endl;
              found = true;
              break;
            }
          }
          if (!found) {
            cout << "unknown" << endl;
          }
        }
      }
    }
  }
  return 0;
} 