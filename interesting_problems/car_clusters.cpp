/*
  Consider the speed of cars on a road is represented using an array as below
  Each index represents a car travelling at the speed corresponding to vlaue at
  the index. So the front car is going at 8 units, the behind is going at 6 units
  and so on until the last car going at 3 units of speed. 

  [8, 6, 7, 5, 2, 1, 4, 3]

  Since 3 car is going at higer spped than 2 car ( 7 > 6) 2nd and 3rd car will form
  a cluster. So accordingly the above array has the following clusters
  
  [[8], [6, 7], [5], [2], [1, 4, 3]]

  So the problem is given an array of speeds return all the cluster sizes. For the
  above example the output will be [1, 2, 1, 1, 3].
  
  Enhancement:
  Assume that you can add a 9th car to the above array at a random position, then
  find out all possible cluster sizes.

  Find time and space complexity for all the approaches 
*/
