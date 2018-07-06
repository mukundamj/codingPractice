/*
  Implement the following two function

  void insert(int key, int val, long duration_ms);

  int get(int key)

  if the key has been in the map for a time longer than the duration then the
  get(int key) should return -1

  After implementing this cleanup the map which has expired keys.

  Find time complexity of approaches. Consider scaling problem when writing the 
  solution
*/


/* TODO: Implement map cleanup and then calculate time complexity*/

#include <iostream>
#include <map>
#include <vector>
#include <chrono> //Required for system_clock
#include <unistd.h> //Required for sleep(int)

using namespace std;

struct val_and_expiry {
  int val;
  int64_t expiry;
};

class key_val_map {
  public:
    void insert(int key, int val, long duration_ms);
    int get(int key); 
    void cleanup();

  private:
    map<int, val_and_expiry> k_v_map;
};

void key_val_map::insert(int key, int val, long duration_ms)
{
  val_and_expiry v_and_e;
  v_and_e.val = val; 
  v_and_e.expiry = 
    static_cast<int64_t> (std::chrono::system_clock::now().time_since_epoch().count()) + 
    static_cast<int64_t> (duration_ms);
  k_v_map[key] = v_and_e;
  return;
}

int key_val_map::get(int key)
{
  if (k_v_map[key].expiry >=
     static_cast<int64_t> (std::chrono::system_clock::now().time_since_epoch().count()))
  {
    return k_v_map[key].val;
  }
  return -1;
}

void key_val_map::cleanup()
{
  typedef pair<int, val_and_expiry> MY_PAIR;
  vector<MY_PAIR> vector_k_v;
  map<int, val_and_expiry>::iterator it;
  for(it = k_v_map.begin(); it != k_v_map.end(); it++)
  {
    vector_k_v.push_back(make_pair((*it).first, (*it).second));
  }
  sort(vector_k_v.begin(), vector_k_v.end(), 
    [](MY_PAIR a, MY_PAIR b)
    {
      return a.second.expiry <= b.second.expiry;
    }
  )
  
  for (auto p : vector_k_v)
  {
    if (p.second.expiry > 0) break;
    k_v_map.erase(p.first);
  }
  return;
}

int main(int argc, const char* argv[])
{
  key_val_map my_k_v_map;
  //The below 2 print statements show that for each second the time value increases
  //by 1000,000
  printf("Time at 0s = %lld\n",
    static_cast<int64_t> (std::chrono::system_clock::now().time_since_epoch().count()));
  sleep(1);
  printf("Time at 1s = %lld\n",
    static_cast<int64_t> (std::chrono::system_clock::now().time_since_epoch().count()));

  my_k_v_map.insert(1, 1, 2000000);
  my_k_v_map.insert(2, 4, 4000000);
  printf("Square of 1 = %d\n", my_k_v_map.get(1));
  printf("Square of 2 = %d\n", my_k_v_map.get(2));
  sleep(2);
  cout << "After waiting for 2 seconds\n";
  printf("Square of 1 = %d\n", my_k_v_map.get(1));
  printf("Square of 2 = %d\n", my_k_v_map.get(2));
  return 0;
}
