#include <iostream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
class SortingAlgorithm
{
  public :
 static void merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &v)
{
  int L = 0;
  int R = 0;
  int index = 0;
  while (L < left.size() && R < right.size())
  {
    if (left[L] < right [R])
    {
      v[index] = left[L];
      L++;
    }
    else
      {
         v[index] = right[R];
         R++;
      }
      index++;
  }
      while (L < left.size())
       {
        v[index] = left[L];
        L++;
        index++;
       }
       while (R < right.size())
       {
        v[index] = right[R];
        R++;
        index++;
       }
}
static void mergeSort(std::vector<int> &v)
{
  if (v.size() < 2) return;
    int mid = v.size() / 2;
    std::vector<int> left(mid);
    std::vector<int> right(v.size() - mid);
    for (int i=0;i<mid;i++)
    {
      left[i] = v[i];
    }
    for (int j=0;j<v.size()-mid;j++)
    {
      right[j] = v[mid + j];
    }
       mergeSort(left);
       mergeSort(right);
       merge(left,right,v);
       left.clear();
       right.clear();
}
};

int main()
{
  std::vector<int> vec = {4,5,1,3,2,6};
  SortingAlgorithm::mergeSort(vec);
  for (int i : vec)
    cout << i << " ";
 return 0;
}