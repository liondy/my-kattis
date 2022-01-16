#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;
vector<int> removeBook(vector<int> books, int position) {
  books.erase(books.begin() + position);
  return books;
}

std::pair<int,int> getMaximal(vector<int> &books) {
  int n = books.size()-1;
  int max = books[n], pos = n;
  return std::pair<int,int>(max,pos);
}

int getTotalPrice(vector<int> &books) {
  int total = 0, pointer = 0;
  vector<int> removedBooks = books;
  for(int i = 0; i < books.size(); i++) {
    std::pair<int,int> result = getMaximal(removedBooks);
    if (pointer < 2){
      total += result.first;
      pointer++;
    } else {
      pointer = 0;
    }
    removedBooks = removeBook(removedBooks, result.second);
  }
  return total;
}

int main() {
  int n,book,totalPrice = 0;
  vector<int> books;
  cin >> n;
  while(n--) {
    cin >> book;
    books.push_back(book);
  }
  sort(books.begin(), books.end());
  cout << getTotalPrice(books) << endl;
  return 0;
}