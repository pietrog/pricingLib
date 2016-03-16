#ifndef _schedule_h_
#define _schedule_h_

#include "enums.h"
#include <vector>
#include <iostream>

namespace pricing{

  struct TimePeriod{
    e_period period;
    short nbPeriod;
    TimePeriod (e_period _period, short _nbPeriod): period(_period), nbPeriod(_nbPeriod){}
  };
  
  struct SplitRules{
    /*e_date_adjust dateAdj;
    int payLag;
    SplitRules()*/
  };
  
  class Date {
    double mDate;
    
    public:
    //constructors
    Date(double date) : mDate(date){}
    Date(const Date& lhs){
      if (this != &lhs){
	mDate = lhs.mDate;
      }
    }
    Date& operator= (const Date& lhs){
      if (this != &lhs){
	mDate = lhs.mDate;
      }
    }

    //getter
    double getDate() const {return mDate;}

    //increment/decrement date
    Date& operator+=(const Date& lhs);
    Date& operator+=(const TimePeriod& tp);

    int addPeriod(const TimePeriod& tp)
    {
      switch (tp.period){
      case e_period::A:
	mDate += tp.nbPeriod * 12;
	break;
      case e_period::Q:
	mDate += tp.nbPeriod * 3;
	break;
      case e_period::M:
	mDate += tp.nbPeriod * 1;
	break;
      }
    }
    
  };

  inline bool operator<=(const Date& d1, const Date& d2){return (d1.getDate() <= d2.getDate());}
  
  class Schedule {

    std::vector<Date> mFixingDates;
    std::vector<Date> mPayDates;
    
  public:

    Schedule(const Date& settlementStart, const Date& settlementEnd, const TimePeriod& timePeriod ,const SplitRules& rules);

    friend std::ostream& operator<<(std::ostream& os, const Schedule& sched);
  };
  
  std::ostream& operator<<(std::ostream& os, const Schedule& sched);
  
  

  template <class U>
  void backward_adjustment(U& end,  U& it, const SplitRules& rules);
  
  //apply function
  template <class D, class R>
  void apply( D& date, R& rules)
  {
    std::cout << date.getDate() << " - "  << std::endl;
  }

}

#endif
