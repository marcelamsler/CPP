#include "Date.h"
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <sstream>
#include <stdexcept>

void testOtherCtor() {
	Date testDate{Aug, 20, 2012};
	Date otherDate{2012, Aug, 20};
	ASSERT(testDate == otherDate);

}

void testPrintADate() {
	std::ostringstream os;
	Date day { 2012, Aug, 20 };
	day.print(os);
	ASSERT_EQUAL("20.08.2012", os.str());
}

void testPrintADateDoesntChangeFillChar() {
	std::ostringstream os;
	Date day { 2012, Aug, 20 };
	auto ch = os.fill();
	day.print(os);
	ASSERT_EQUAL(ch, os.fill());
}

void testIsValidYearLowerBoundary() {
	ASSERT(Date::isValidYear(1813));
	ASSERT(!Date::isValidYear(1812));
}
void testIsValidYearUpperBoundary() {
	ASSERT(Date::isValidYear(9999));
	ASSERT(!Date::isValidYear(10000));
}

void testIsLeapYear() {
	ASSERT(Date::isLeapYear(1964));
	ASSERT(Date::isLeapYear(2000));
	ASSERT(Date::isLeapYear(2400));
	ASSERT(Date::isLeapYear(2012));
	ASSERT(!Date::isLeapYear(1900));
	ASSERT(!Date::isLeapYear(2013));
	ASSERT(!Date::isLeapYear(2100));
}

void testIsValidDateValid() {
	ASSERT(Date::isValidDate(2012, Aug, 20));
	ASSERT(Date::isValidDate(2012, Feb, 29));
	ASSERT(Date::isValidDate(2000, Feb, 29));
	ASSERT(Date::isValidDate(2011, Dec, 31));
}
void testIsValidDateInValid() {
	ASSERT(!Date::isValidDate(2012, Jun, 31));
	ASSERT(!Date::isValidDate(2011, Feb, 29));
	ASSERT(!Date::isValidDate(1900, Feb, 29));
}

void testDateCtorThrowsIfInvalid() {
	ASSERT_THROWS((Date { 2012, Jun, 31 }), std::out_of_range);
	ASSERT_THROWS((Date { 1900, Feb, 29 }), std::out_of_range);
}

bool datesAreEqual(Date const &l, Date const &r) {
	std::ostringstream o1;
	l.print(o1);
	std::ostringstream o2;
	r.print(o2);
	return o1.str() == o2.str();
}

void testNextDaySimple() {
	Date aday { 2012, Aug, 20 };
	aday.nextDay();
	ASSERT(datesAreEqual(aday, Date { 2012, Aug, 21 }));
}

void testNextDayEndOfMonth() {
	Date eom { 2012, Aug, 31 };
	eom.nextDay();
	ASSERT(datesAreEqual(eom, Date { 2012, Sep, 1 }));
}
void testNextDayEndOfShortMonth() {
	Date eosep { 2012, Sep, 30 };
	eosep.nextDay();
	ASSERT(datesAreEqual(eosep, Date { 2012, Oct, 1 }));
}
void testNextDayEndOfFeburary() {
	Date eofeb { 2012, Feb, 29 };
	eofeb.nextDay();
	ASSERT(datesAreEqual(eofeb, Date { 2012, Mar, 1 }));
}
void testNextDayEndOfFeburaryNonLeapYear() {
	Date eofeb { 2013, Feb, 28 };
	eofeb.nextDay();
	ASSERT(datesAreEqual(eofeb, Date { 2013, Mar, 1 }));
}
void testNextDayNotEndOfFeburaryInLeapYear() {
	Date aday { 2012, Feb, 28 };
	aday.nextDay();
	ASSERT(datesAreEqual(aday, Date { 2012, Feb, 29 }));
}

void testNextDayEndOfYear() {
	Date silvester { 2012, Dec, 31 };
	silvester.nextDay();
	ASSERT(datesAreEqual(silvester, Date { 2013, Jan, 1 }));
}
void testNextDayEndOfLastAllowedYear() {
	Date lastdayever { 9999, Dec, 31 };
	ASSERT_THROWS(lastdayever.nextDay(), std::out_of_range);
}

void testDateBuildIn() {
	Date aday { 2012, Aug, 10 };
	Date bday { aday };
	ASSERT(datesAreEqual(aday, bday));
	Date cday { 2000, Jan, 1 };
	aday = cday;
	ASSERT(datesAreEqual(aday, cday));
}

void testDateLessThanAdjacentDates() {
	Date aday { 2012, Aug, 13 };
	Date later { 2012, Aug, 14 };
	ASSERT(aday < later);
	ASSERT(!(later < aday)); // asymmetric
	ASSERT(!(aday < aday)); // not reflexive
}

void testDateLessThanYearOff() {
	Date aday { 2011, Aug, 13 };
	Date yearlater { 2012, Aug, 13 };
	ASSERT(aday < yearlater);
	ASSERT(!(yearlater < aday));
}

void testDateLessThanMonthOff() {
	Date aday { 2012, Jul, 13 };
	Date later { 2012, Aug, 13 };
	ASSERT(aday < later);
	ASSERT(!(later < aday));
}

void testDateGreaterThan() {
	Date aday { 2012, Feb, 29 };
	Date later { 2012, Mar, 1 };
	ASSERT(later > aday);
	ASSERT(!(aday > later));
}

void testDateGreaterThanOrEqual() {
	Date aday { 2012, Feb, 29 };
	Date later { 2012, Mar, 1 };
	ASSERT(later >= aday);
	ASSERT(aday >= aday);
	ASSERT(!(aday >= later));
}

void testDateLessThanOrEqual() {
	Date aday { 2012, Feb, 29 };
	Date later { 2012, Mar, 1 };
	ASSERT(aday <= aday);
	ASSERT(aday <= later);
	ASSERT(!(later <= aday));
}

void testDateEqual() {
	Date aday { 2012, Jul, 29 };
	ASSERT(aday == aday);
	ASSERT(aday == (Date { 2012, Jul, 29 }));
	ASSERT(!(aday == Date { 2012, Jul, 28 }));
}

void testDateInEqual() {
	Date aday { 2012, Jul, 29 };
	ASSERT(!(aday != aday));
	ASSERT(aday != (Date { 2012, Jul, 28 }));
}

void testInputShortLimit() {
	std::istringstream is("70000");
	unsigned short x { };
	is >> x;
	ASSERT_EQUAL(0xffffUL, x);
}

void runAllTests(int argc, char const *argv[]) {
	cute::suite s;
	s.push_back(CUTE(testOtherCtor));
	s.push_back(CUTE(testPrintADate));
	s.push_back(CUTE(testPrintADateDoesntChangeFillChar));
	s.push_back(CUTE(testIsValidYearLowerBoundary));
	s.push_back(CUTE(testIsValidYearUpperBoundary));
	s.push_back(CUTE(testIsLeapYear));
	s.push_back(CUTE(testIsValidDateValid));
	s.push_back(CUTE(testIsValidDateInValid));
	s.push_back(CUTE(testDateCtorThrowsIfInvalid));
	s.push_back(CUTE(testNextDaySimple));
	s.push_back(CUTE(testNextDayEndOfMonth));
	s.push_back(CUTE(testNextDayEndOfShortMonth));
	s.push_back(CUTE(testNextDayEndOfFeburary));
	s.push_back(CUTE(testNextDayEndOfFeburaryNonLeapYear));
	s.push_back(CUTE(testNextDayNotEndOfFeburaryInLeapYear));
	s.push_back(CUTE(testNextDayEndOfYear));
	s.push_back(CUTE(testNextDayEndOfLastAllowedYear));
	s.push_back(CUTE(testDateBuildIn));
	s.push_back(CUTE(testDateLessThanAdjacentDates));
	s.push_back(CUTE(testDateLessThanYearOff));
	s.push_back(CUTE(testDateLessThanMonthOff));
	s.push_back(CUTE(testDateGreaterThan));
	s.push_back(CUTE(testDateGreaterThanOrEqual));
	s.push_back(CUTE(testDateLessThanOrEqual));
	s.push_back(CUTE(testDateEqual));
	s.push_back(CUTE(testDateInEqual));
	s.push_back(CUTE(testInputShortLimit));
	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
	cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
	runAllTests(argc, argv);
	return 0;
}

