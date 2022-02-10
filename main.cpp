#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1199;

tuple<vector<int>, int, int> testFixture1()
{
  return make_tuple(vector<int>{1}, 1, 1);
}

tuple<vector<int>, int, int> testFixture2()
{
  return make_tuple(vector<int>{1, 2}, 5, 7);
}

tuple<vector<int>, int, int> testFixture3()
{
  return make_tuple(vector<int>{1, 2, 3}, 1, 4);
}

void test1()
{
  auto fixture = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<2>(fixture))
       << endl;
  Solution sol;
  auto result = sol.minTime(get<0>(fixture), get<1>(fixture));
  cout << "result: " << to_string(result) << endl;
}

void test2()
{
  auto fixture = testFixture2();
  cout << "Test 1 - expect to see " << to_string(get<2>(fixture))
       << endl;
  Solution sol;
  auto result = sol.minTime(get<0>(fixture), get<1>(fixture));
  cout << "result: " << to_string(result) << endl;
}

void test3()
{
  auto fixture = testFixture3();
  cout << "Test 1 - expect to see " << to_string(get<2>(fixture))
       << endl;
  Solution sol;
  auto result = sol.minTime(get<0>(fixture), get<1>(fixture));
  cout << "result: " << to_string(result) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}