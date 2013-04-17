#include "datagodz.hpp"
#include<string>

DataGodz::DataGodz(): hour(currentDate->tm_hour), minute(currentDate->tm_min), second(currentDate->tm_sec) {}

DataGodz::DataGodz(int godz, int min, int sek, int da, int mo, int ye): Data(da, mo, ye), hour(godz), minute(min), second(sek) {
    if( hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
        throw std::string("niepoprawna godzina [00-23] : [00-59] : [00-59]");
}

DataGodz::DataGodz(const DataGodz &other) : Data(other.day, other.month, other.year), hour(other.hour), minute(other.minute), second(other.second) { }

bool operator== (const DataGodz &a, const DataGodz &b) {
  return a.iloscDniOdStalej(a) == b.iloscDniOdStalej(b) && a.hour == b.hour && a.minute == b.minute && a.second == b.second;
}

bool operator < (const DataGodz &a, const DataGodz &b) {
    int days = a.roznicaDni(a, b);
    if(days != 0) return (days < 0);
    if(a.hour != b.hour) return (a.hour < b.hour);
    if(a.minute != b.minute) return (a.minute < b.minute);
    return (a.second < b.second);
}

bool operator > (const DataGodz &a, const DataGodz &b) {
    return !(a <= b);
}

bool operator >= (const DataGodz &a, const DataGodz &b) {
    return (a == b || a > b);
}

bool operator <= (const DataGodz &a, const DataGodz &b) {
    return (a == b || a < b);
}

int DataGodz::getHour() {
    return hour;
}

int DataGodz::getMinute() {
    return minute;
}

int DataGodz::getSecond() {
    return second;
}
