// #ifndef RECCHECK
// #include <set>
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <map>
// #include <algorithm>
// // add or remove necessary headers as you please

// #endif

// #include "schedwork.h"

// using namespace std;

// // a constant that can be used to indicate an INVALID 
// // worker ID if that is useful to your implementation.
// // Feel free to not use or delete.
// static const Worker_T INVALID_ID = (unsigned int)-1;


// // Add prototypes for any helper functions here


// // Add your implementation of schedule() and other helper functions here

// bool schedule(
//     const AvailabilityMatrix& avail,
//     const size_t dailyNeed,
//     const size_t maxShifts,
//     DailySchedule& sched
// )
// {
//     if(avail.size() == 0U){
//         return false;
//     }
//     sched.clear();
//     // Add your code below




// }

#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please

#endif

#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here
bool scheduleHelper(const AvailabilityMatrix& avail,
    size_t dailyNeed,
    size_t maxShifts,
    DailySchedule& sched,
    size_t n,
    size_t d,
    vector<size_t>& numshifts);

// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below


    if(avail[0].size()<dailyNeed){
        return false;
    }

    vector<size_t> numshifts(avail[0].size(), 0);

    for (size_t i = 0; i < avail.size(); i++) {
        sched.push_back(vector<Worker_T>(dailyNeed, INVALID_ID));
    }

    return scheduleHelper(avail, dailyNeed, maxShifts, sched, 0, 0, numshifts);
}


bool scheduleHelper(const AvailabilityMatrix& avail,
     size_t dailyNeed,
     size_t maxShifts,
    DailySchedule& sched,
     size_t n,
     size_t d,
    vector<size_t>& numshifts)
{
    if(d == dailyNeed && n==avail.size()-1){
        return true;
    }

    if(d >= dailyNeed){
        return scheduleHelper(avail, dailyNeed, maxShifts, sched, n+1, 0, numshifts);
    }


    for(size_t i=0;i<avail[0].size();i++){
        sched[n][d] = i;
        numshifts[i]++;

        if(avail[n][i] ==1 && 
        count(sched[n].begin(),sched[n].end(),i)==1 &&
         numshifts[i] <= maxShifts){

            if(scheduleHelper(avail,dailyNeed,maxShifts,sched,n,d+1,numshifts)){
                return true;
            } 

        }
        numshifts[i]--;
    }
    sched[n][d] = INVALID_ID;
    return false;
}