#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<int64_t>> split_and_multiply(int s, int e, 
  unordered_map<int, vector<vector<int64_t>>> &stored_matrix)
{
  //printf("s = %d, e = %d\n", s, e);
  if (stored_matrix.find(e - s + 1) != stored_matrix.end())
  {
    return stored_matrix[e - s + 1];
  }
 
  int m; 
  if (e - s == 1) m = s; 
  else m = e + (s - e)/2;
  vector<vector<int64_t>> left_product =  split_and_multiply(s, m, stored_matrix);
  vector<vector<int64_t>> right_product =  split_and_multiply(m + 1, e, stored_matrix);
  vector<vector<int64_t>> final_product(2, vector<int64_t>(2, 0));
  
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      int64_t sum = 0;
      for (int k = 0; k < 2; k++)
      {
        sum = (sum + left_product[i][k] * right_product[k][j]) % 1000000;
      }
      final_product[i][j] = sum;
    }
  }
  
  //printf("%lld %lld\n %lld %lld\n", final_product[0][0], final_product[0][1], final_product[1][0], final_product[1][1]);
  return stored_matrix[e - s + 1] = final_product;
}

int solution(int N) {
  int64_t fib;
  unordered_map<int, vector<vector<int64_t>>> stored_matrix;
  stored_matrix[1] = {{1, 1}, {1, 0}};
  if (N == 0) return 0;
  else if (N == 1) return 1;
  else if (N == 2) return 1;
  else if (N == 3) return 2;
  else if (N == 4) return 3;
  else
  {
    int pow = N - 3;
    vector<vector<int64_t>> resultant_matrix = split_and_multiply(1, pow, stored_matrix);
    fib = resultant_matrix[0][0] + resultant_matrix[0][1] + 
          resultant_matrix[1][0] + resultant_matrix[1][1];
  }
  cout << "Fibonacci value is " << fib << "\n";
  return fib % 1000000; 
}


int main(int argc, const char* argv[])
{
  int N = 0;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));
  N = 1;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));
  N = 2;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  N = 3;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  N = 4;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  N = 5;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  N = 6;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  N = 7;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  N = 8;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));
  N = 36;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));
  N = 100;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));
  N = 200;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));
 
  N = 1000;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  N = 10000;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  N = 100000;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  N = 1000000;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  N = 1000001;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  N = 1000000001;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  N = 2147483647;
  printf("Fibonacci at N = %d is %d\n", N, solution(N));

  return 0;
}

