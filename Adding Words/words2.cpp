#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;
map<string,int> var;
bool is_operator(string character) {
  return character == "+" || character == "-";
}

void def(string command, int value) {
  var[command] = value;
}

string evaluate(vector<string> &commands) {
  stack<int> numbers;
  stack<string> operators;
  for (int i = 1; i < commands.size(); i++) {
    if (commands[i] == "=") continue;
    if (is_operator(commands[i])){
      operators.push(commands[i]);
    } else {
      if (var.find(commands[i]) == var.end()) {
        return "unknown";
      } else {
        int number = var.find(commands[i])->second;
        int calc = 0;
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
  for (auto& it : var) {
    if (it.second == numbers.top()) {
      return it.first;
    }
  }
  return "unknown";
}

int main(){
  string fullCommand;
  while(getline(cin, fullCommand)) {
    if (fullCommand == "clear"){
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
      if (commands[0] == "def") {
        def(commands[1], stoi(commands[2]));
      } else if (commands[0] == "calc") {
        for (int i = 1; i < commands.size(); i++) {
          cout << commands[i] << " ";
        }
        cout << evaluate(commands) << endl;
      }
    }
  }
  return 0;
}