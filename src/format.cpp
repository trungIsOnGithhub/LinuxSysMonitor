#include <string>

#include "format.h"

using std::string;

// Done: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) {
    string elapsed = "";

    long hh = 0L, mm = 0L, ss = 0L; // avoid overflow

    hh = seconds / 3600L;

    mm = (seconds - hh*3600L) / 60L;

    ss = seconds - hh*3600L - mm*60L;

    return std::to_string(hh) + ":" + std::to_string(mm) + ":" + std::to_string(ss);
}