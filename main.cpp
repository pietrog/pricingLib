#include <iostream>
#include "core/schedule.hpp"

using std::cout;
using std::endl;
using namespace pricing;
int main(){
  cout << "coucou " << endl ;
  Date start (0);
  Date end(12);
  TimePeriod tp(e_period::M, 3);
  SplitRules sr;

  Schedule sched(start, end, tp, sr);

  cout << sched;
  cout << "end " << endl ;
}
