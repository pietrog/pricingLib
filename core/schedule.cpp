#include "schedule.hpp"

namespace pricing{

  Schedule::Schedule(const Date& settlementStart, const Date& settlementEnd, const TimePeriod& step, const SplitRules& rules)
  {
    //first, create the basic schedule without adjustment
    Date incr(settlementStart);
    while (incr <= settlementEnd){
      mFixingDates.push_back(incr);
      incr.addPeriod(step);
    }
    //then adjust the basic schedule (backward adjustment)
    std::vector<Date>::iterator it = mFixingDates.begin();
    std::vector<Date>::iterator end = mFixingDates.end();
    backward_adjustment(end,  it, rules);
    mPayDates = mFixingDates;
  }

  std::ostream& operator<<(std::ostream& os, const Schedule& sched){
    os << "Schedule : " << std::endl;
    for(int i=0; i< sched.mFixingDates.size(); ++i)
      os << sched.mFixingDates[i].getDate() << " ; ";
    os << "--------------------" << std::endl;
    return os;
  }


  template<class U>
  void backward_adjustment(U& end,  U& it, const SplitRules& rules){
    if (it != end){
      apply(*it, rules);
      backward_adjustment(end, ++it, rules);
    }    
  }

}
