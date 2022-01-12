#include <iostream>
#include <vector>

using namespace std;

vector<int> sort(int curr, int max, vector<int> &numbers)
{
  numbers.push_back(curr);
  for (int j = numbers.size() - 1; j >= 0; j--)
  {
    if (curr < numbers[j - 1])
    {
      numbers[j] = numbers[j - 1];
    }
    else
    {
      numbers[j] = curr;
      break;
    }
  }
  return numbers;
}

int main()
{
  string numberString;
  getline(cin, numberString);
  vector<int> numbers;
  int max = INT16_MIN;
  int curr = 0;
  for (int i = 0; i < numberString.length(); i++)
  {
    if (numberString[i] == ' ')
    {
      if (curr >= max)
      {
        numbers.push_back(curr);
        max = curr;
      }
      else
      {
        numbers = sort(curr, max, numbers);
      }
      curr = 0;
    }
    else
    {
      int num = numberString[i] - '0';
      curr = (curr * 10) + num;
    }
  }
  numbers = sort(curr, max, numbers);
  string sorter;
  cin >> sorter;
  for (int i = 0; i < sorter.length(); i++)
  {
    if (i != 0)
      cout << ' ';
    cout << numbers[sorter[i] - 'A'];
  }

  return 0;
}