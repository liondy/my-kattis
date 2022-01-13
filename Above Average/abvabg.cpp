#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;
int main(){
  int c,n,grade;
  cin >> c;
  while(c--) {
    cin >> n;
    vector<int> grades;
    float avg = 0;
    int totalGrade = 0, totalStudents = 0;
    for (int i = 1 ; i <= n ; i++) {
      cin >> grade;
      totalGrade += grade;
      avg = totalGrade / i;
      grades.push_back(grade);
    }
    for (int i = 0 ; i < n ; i++) {
      if (grades[i] > avg) {
        totalStudents++;
      }
    }
    printf("%.3f%%\n", ((float)totalStudents/(float)n)*100);
  }
  return 0;
}