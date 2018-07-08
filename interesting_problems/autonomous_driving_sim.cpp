#include <iostream>
#include <vector>
#include <list>
#include <time.h>
#include <unistd.h>

using namespace std;

class vehicle {
  public:
    vehicle(int lane, int speed, int max_speed, string type);
    int lane;
    int position;
    int speed;
    int max_speed;
    string type; //Car or truck
    time_t last_update_time;
};

vehicle::vehicle(int lane, int speed, int max_speed, string type) {
  this->lane = lane;
  position = 0;
  this->speed = speed;
  this->max_speed = speed;
  this->type = type;
  last_update_time = time(0);
}

int main(int argc, const char *argv[])
{
  cout << "\n==============Welcome to Autonomous driving simulator===============\n";
  
  int MAX_VEHICLES = 10;
  int MIN_CAR_SPEED = 20;
  int MAX_CAR_SPEED = 100;
  int MIN_TRUCK_SPEED = 20;
  int MAX_TRUCK_SPEED = 70;
  int NUM_OF_LANES = 2;
  int LENGTH_OF_LANE = 1000;
  int MIN_GAP_BETWEEN_VEHICLES = 3;

  int num_of_vehicles;
  while (1)
  {
    cout << "Please enter positive integer greater than 0 and less than or equal";
    cout << "to " << MAX_VEHICLES << "\n";
    cin >> num_of_vehicles;
    if (!cin || num_of_vehicles <= 0 || num_of_vehicles > MAX_VEHICLES)
    {
      cout << "Invalid input, please try again";
    }
    else break;
  }

  list<vehicle*> vehicles;
  srand(time(NULL));
  while(num_of_vehicles || vehicles.size() != 0)
  {
    int random_num = rand() % 100 + 1;
    if (num_of_vehicles)
    {
      if (random_num > 50)
      {
        int speed = rand() % MAX_CAR_SPEED + 1;
        speed = speed > MIN_CAR_SPEED ? speed : MIN_CAR_SPEED; 
        int lane = rand() % NUM_OF_LANES + 1;
        vehicle * car = new vehicle(lane, speed, MAX_CAR_SPEED, "car");
        vehicles.push_back(car);
        num_of_vehicles--;
        printf("Car created, speed = %d, lane = %d", speed, lane);
      }

      else if (random_num > 75)
      {
        int speed = rand() % MAX_TRUCK_SPEED + 1;
        speed = speed > MIN_TRUCK_SPEED ? speed : MIN_TRUCK_SPEED; 
        int lane = rand() % NUM_OF_LANES + 1;
        vehicle * truck = new vehicle(lane, speed, MAX_TRUCK_SPEED, "truck");
        vehicles.push_back(truck);
        num_of_vehicles--;
        printf("Truck created, speed = %d, lane = %d", speed, lane);
      }
    }

    for (list<vehicle*>::iterator v = vehicles.begin(); v != vehicles.end(); v++)
    {
      time_t cur = time(0);
      (*v)->position += (cur - (*v)->last_update_time) * (*v)->speed;
      (*v)->last_update_time = cur;
      printf("Lane = %d, Pos = %d, Cur_speed = %d || ", (*v)->lane, (*v)->position, (*v)->speed);
      for (list<vehicle*>::iterator scan_v = vehicles.begin(); scan_v != vehicles.end(); scan_v++)
      {
        if (*v == *scan_v) continue;
        else
        {
          if ((*scan_v)->lane == (*v)->lane && 
              (abs((*scan_v)->position - (*v)->position) <= MIN_GAP_BETWEEN_VEHICLES) &&
              ((*v)->speed > (*scan_v)->speed))
          {
            (*v)->speed = (*v)->speed/2;
          }
          else {
            int new_speed = (*v)->speed + 2;
            (*v)->speed = new_speed > (*v)->max_speed ? (*v)->speed : new_speed; 
          }
        }
      }

      if ((*v)->position > LENGTH_OF_LANE)
      {
        vehicles.erase(v);
      }
    }
    sleep(1);
    cout << endl;
  }

  cout << "\n================Simulation completed===============================\n";
  return 0;
}
