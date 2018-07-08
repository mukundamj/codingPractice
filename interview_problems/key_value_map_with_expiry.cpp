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
    size_t get_size_of_map() { return k_v_map.size(); }

  private:
    map<int, val_and_expiry> k_v_map;
};

/*
  Time complexity = O(lon(N)), where N is the number of elements in the map
  Space comlexity = O(N)
*/
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

/*
  Time complexity = O(lon(N)), where N is the number of elements in the map
*/

int key_val_map::get(int key)
{
  if (k_v_map[key].expiry >=
     static_cast<int64_t> (std::chrono::system_clock::now().time_since_epoch().count()))
  {
    return k_v_map[key].val;
  }
  return -1;
}

/*
  Time complexity = O(Nlon(N)), where N is the number of elements in the map
  Space complexity = O(N);
*/

void key_val_map::cleanup()
{
  typedef pair<int, val_and_expiry> MY_PAIR;
  vector<MY_PAIR> vector_k_v;
  map<int, val_and_expiry>::iterator it;
  for(it = k_v_map.begin(); it != k_v_map.end(); it++)
  {
    vector_k_v.emplace_back((*it).first, (*it).second);
  }

  sort(vector_k_v.begin(), vector_k_v.end(), 
    [](MY_PAIR a, MY_PAIR b)
    {
      return a.second.expiry <= b.second.expiry;
    }
  );
  
  for (auto p : vector_k_v)
  {
    int i = 0;
    if (p.second.expiry > 
      static_cast<int64_t> (std::chrono::system_clock::now().time_since_epoch().count()))
      break;
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
  my_k_v_map.insert(3, 9, 6000000);
  my_k_v_map.insert(4, 16, 8000000);

  printf("Square of 1 = %d\n", my_k_v_map.get(1));
  printf("Square of 2 = %d\n", my_k_v_map.get(2));
  printf("Square of 3 = %d\n", my_k_v_map.get(3));
  printf("Square of 4 = %d\n", my_k_v_map.get(4));

  sleep(2);

  cout << "After waiting for 2 seconds\n";
  printf("Square of 1 = %d\n", my_k_v_map.get(1));
  printf("Square of 2 = %d\n", my_k_v_map.get(2));
  printf("Square of 3 = %d\n", my_k_v_map.get(3));
  printf("Square of 4 = %d\n", my_k_v_map.get(4));

  printf("Before cleanup the size of my_k_v_map is %lu\n", 
    my_k_v_map.get_size_of_map());

  printf("Cleaning up the map\n");

  my_k_v_map.cleanup();

  printf("After cleanup the size of my_k_v_map is %lu\n", 
    my_k_v_map.get_size_of_map());

  printf("Square of 1 = %d\n", my_k_v_map.get(1));
  printf("Square of 2 = %d\n", my_k_v_map.get(2));
  printf("Square of 3 = %d\n", my_k_v_map.get(3));
  printf("Square of 4 = %d\n", my_k_v_map.get(4));
  
  return 0;
}
