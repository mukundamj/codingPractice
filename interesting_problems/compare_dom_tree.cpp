/*
  Compare two dom trees and return true if the concatenated strings of both
  the trees are same

  Eg:

  Dom tree 1: <h1>hello <h2>world</h2></h1>

  The thee structure is

           h1
          /  \
       hello  h2
               \
              world

  All string put together is hello world


  Dom tree 2: <h1>hell<h2>o wor</h2><h3>ld</h3></h1>

             h1
          /  \   \
       hell   h2  h3 
               \    \ 
              o wor  ld

   
  All string put together is hello world

  Since the combined string is same in tree 1 and 2 the trees are same.

  Solve this problem when the combined string is larger than the memory.

  Find the time complexity for all the appraches
*/
