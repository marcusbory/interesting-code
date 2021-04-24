#include <iostream>
#include <vector>
using namespace std;

void solution(int* arr, int* start, int* end, int len, int ans);

int main() {
  int N, S;
  cin >> N >> S;
  int* arr = new int[N];
  for (int i = 0; i < N; i++)
    cin >> arr[i];
  int start, end;
  solution(arr, &start, &end, N, S);
  cout << "Index pos: " << start << ", " << "End pos: "<<  end << endl;
  return 0;
}

void solution(int* arr, int* start, int* end, int len, int ans) {
  int s, e, found;
  s = e = found = 0;
  int sum = arr[0];
  while (e < len) {
    if (sum < ans)
      sum += arr[++e];
    else if (sum > ans)
      sum -= arr[s++];
    if (sum == ans) {
      found = 1;
      break;
    }
  }
  if (found == 1) {
    *start = s;
    *end = e;
  }
  else {
    *start = -1;
    *end = -1;
  }
}
