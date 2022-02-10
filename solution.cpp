#include "solution.h"
#include <queue>

using namespace sol1199;
using namespace std;

/*takeaways
  - why this has anything to do with
    Huffman's tree?
    - the time needed to build a block
      is the frequency of a letter
    - you want to push the blocks needed
      shorter time to build toward the
      bottom of the tree as they can
      afford to wait without increasing
      the overall time needed to finish
      building all blocks

  - take this as an example
    blocks = [1,2,3], split=1
    - let's build a tree
          4
         / \
        3  3
       / \
      1   2
    - each leaf node represents a block
      , and each edge the split
    - we want to start working the
      block that takes the longest
      time to build as soon as possible!
    - the blocks that take shorter time
      to build can afford to start later
      without affecting the overall time
      to finish
    - in this case, block "3" waited for
      one split time while block "1" and
      "2" waited for 2 split time

    - let's build the tree differently
      and let block 3 wait for 2 split
      time - overall time is 5!
          5
         / \
        4   1
       / \
      3   2

*/

int Solution::minTime(vector<int> blocks, int split)
{
  /* min-heap */
  auto heap = priority_queue<int, vector<int>, greater<int>>();

  for (auto b : blocks)
    heap.push(b);

  /*
    - merging two blocks is the same
      as splitting a worker as you need
      two workers to work on the merged
      block
    - why we merge two blocks? as they
      are started being worked on at
      the same time, and it's the same
      as just looking at the finish time
      of the block that takes longer to
      build
  */
  while (heap.size() > 1)
  {
    /*
      - this is a min-heap
      - the second on the top
        takes longer to build
        than the first one on
        the top
    */
    /* disregard this */
    heap.pop();
    auto t = heap.top();
    heap.pop();
    heap.push(t + split);
  }

  return heap.top();
}