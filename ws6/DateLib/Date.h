#ifndef DATE_H_
#define DATE_H_

#include <iosfwd>

enum Month {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
enum Weekday {Sat, Sun, Mon, Tue, Wed, Thu, Fri};

inline Month operator++(Month &amonth){
	int month = (amonth+1)%(Dec);
	amonth = static_cast<Month>(month);
	return amonth;
}

struct Date{
	Month month;
	int year, day;
	void print(std::ostream& out) const;
	Weekday day_of_week();
	static bool isValidYear(int year);
	static bool isLeapYear(int year);
	static bool isValidDate(int year, Month month, int day);
	Date(int year, Month month, int day);
	Date(Month month, int day, int year):Date{year, month, day}{};
	static int  endOfMonth(int year, Month month);
	void nextDay();
	bool operator <(Date const& rhs) const;
private:
	static int getShiftedMonthForZellerAlgorithm(Month month);

};


inline bool operator>(Date const& lhs, Date const& rhs){
	return rhs < lhs;
}
inline bool operator>=(Date const& lhs, Date const& rhs){
	return !(lhs < rhs);
}
inline bool operator<=(Date const& lhs, Date const& rhs){
	return !(rhs < lhs);
}

inline bool operator==(Date const& lhs, Date const& rhs){
	return !(lhs < rhs) && !(rhs < lhs) ;
}
inline bool operator!=(Date const& lhs, Date const& rhs){
	return !(lhs == rhs);
}

#endif /* DATE_H_ */
