#ifndef DATAGODZ_HPP_INCLUDED
#define DATAGODZ_HPP_INCLUDED

#include "data.hpp"

class DataGodz : public Data {
  private:
  const int hour, minute, second;

  public:
	DataGodz();
	DataGodz(int godz, int minuty, int sekundy, int d, int m, int y);
	DataGodz(const DataGodz &other);

  public:
    int getHour();
    int getMinute();
    int getSecond();

  public:
	friend bool operator == (const DataGodz &a, const DataGodz &b);
	friend bool operator < (const DataGodz &a, const DataGodz &b);
	friend bool operator > (const DataGodz &a, const DataGodz &b);
	friend bool operator <= (const DataGodz &a, const DataGodz &b);
	friend bool operator >= (const DataGodz &a, const DataGodz &b);
};

#endif // DATAGODZ_HPP_INCLUDED
