#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tritset.h"

TEST_CASE("Creating tritset") {
	tritset set(0);
	REQUIRE(set.capacity() == 0);
	REQUIRE(set.trit_capacity() == 0);
	
	REQUIRE_THROWS_AS(tritset(-1), std::invalid_argument);

	tritset set1(100);
	REQUIRE(set1.capacity() == 25);
	REQUIRE(set1.trit_capacity() == 100);

	tritset set2(112);
	REQUIRE(set2.capacity() >= 25);
}

TEST_CASE("Indexing operator and memory allocation") {
	tritset set0(100);
	tritset set1(200);

	int allocLength0 = set0.capacity();

	REQUIRE_THROWS_AS(set0[-2], std::invalid_argument);

	set0[0] = trit::True;
	set0[1] = trit::False;
	set1[1] = trit::True;

	REQUIRE(set0[0] == trit::True);
	REQUIRE(set0[1] == trit::False);
	REQUIRE(set0[2] == set1[0]);

	set0[101] = trit::True;
	REQUIRE(set0[101] == trit::True);
	REQUIRE(set0.capacity() == allocLength0+1);

	set0[113] = trit::False;
	REQUIRE(set0[113] == trit::False);
	REQUIRE(set0.capacity() == 29);

	set0[130] = trit::Unknown;
	REQUIRE(set0.capacity() == 29);
	REQUIRE(set0[130] == trit::Unknown);

	set0[0] = set1[209];
	REQUIRE(set0[0] == trit::Unknown);

	set0[130] = set1[209];
	REQUIRE(set0.capacity() == 29);
	REQUIRE(set0[130] == trit::Unknown);

	set0[130] = set1[1];
	REQUIRE(set0[130] == trit::True);
	REQUIRE(set0.capacity() == 33);

	set0[10] = set1[1];
	set0[12] = set1[0];
	REQUIRE(set0[10] == trit::True);
	REQUIRE(set0[12] == trit::Unknown);
}

TEST_CASE("tritset = tritset") {
	tritset a(10);
	tritset b(16);

	a[0] = trit::True;
	a[2] = trit::False;
	a[15] = trit::True;

	b = a;

	REQUIRE(b[0] == trit::True);
	REQUIRE(b[2] == trit::False);
	REQUIRE(b[15] == trit::True);
}

TEST_CASE("Bit operations") {
	tritset a(10);
	tritset b(20);
	tritset d(5);
	a[0] = trit::False;
	a[1] = trit::True;
	b[0] = trit::True;
	b[1] = trit::False;
	SECTION("Trit with Trit") {
		REQUIRE((a[0] & a[1]) == trit::False);
		REQUIRE((a[0] | b[0]) == trit::True);
		REQUIRE((a[0] & a[3]) == trit::False);
		REQUIRE((a[1] | b[4]) == trit::True);
		REQUIRE((!a[0]) == trit::True);
		REQUIRE((!b[4]) == trit::Unknown);
		REQUIRE((a[0] & trit::False) == trit::False);
		REQUIRE((b[0] | trit::True) == trit::True);
		REQUIRE((!trit::False) == trit::True);
	}
	SECTION("tritset with tritset") {
		d = (a & b);
		REQUIRE(d.capacity() == b.capacity());
		REQUIRE(d[1] == trit::False);
		REQUIRE(d[20] == trit::Unknown);
		d = (a | b);
		REQUIRE(d[0] == trit::True);
		REQUIRE(d[1] == trit::True);
		d = (!a);
		REQUIRE(d[0] == trit::True);
		REQUIRE(d[1] == trit::False);
		REQUIRE(d[12] == trit::Unknown);
	}
}

TEST_CASE("Convenient Methods") {
	tritset a(10), b(16);
	SECTION("capacity") {
		REQUIRE(a.capacity() == 3);
		REQUIRE(b.capacity() == 4);
	}
	SECTION("trit_capacity") {
		REQUIRE(a.trit_capacity() == 10);
		REQUIRE(b.trit_capacity() == 16);
	}
	SECTION("Shrink") {
		a[6] = trit::True;
		a.shrink();
		b.shrink();
		REQUIRE(a.capacity() == 2);
		REQUIRE(a.trit_capacity() == 7);
		REQUIRE(b.capacity() == 0);
		REQUIRE(b.trit_capacity() == 0);
		tritset e(0);
		e.shrink();
		REQUIRE(e.capacity() == 0);
	}
	SECTION("Trit's Cardinality") {
		a[0] = trit::True;
		a[1] = trit::False;
		a[2] = trit::False;
		a[50] = trit::True;
		a[46] = trit::False;
		REQUIRE(a.cardinality(trit::True) == 2);
		REQUIRE(a.cardinality(trit::False) == 3);
		REQUIRE(a.cardinality(trit::Unknown) == 46);
		REQUIRE(b.cardinality(trit::True) == 0);
	}
	SECTION("All Cardinalities") {
		a[0] = trit::True;
		a[1] = trit::False;
		a[2] = trit::False;
		a[50] = trit::True;
		a[46] = trit::False;
		std::unordered_map<trit, int> tempMap;
		tempMap = a.cardinality();
		REQUIRE(tempMap[trit::False] == 3);
		REQUIRE(tempMap[trit::True] == 2);
		REQUIRE(tempMap[trit::Unknown] == 46);
		tempMap = b.cardinality();
		REQUIRE(tempMap[trit::True] == 0);
		REQUIRE(tempMap[trit::Unknown] == 16);
	}
	SECTION("Trim") {
		b[10] = trit::True;
		b[9] = trit::False;
		b[1] = trit::True;
		b.trim(9);
		REQUIRE(b[10] == trit::Unknown);
		REQUIRE(b[9] == trit::Unknown);
		REQUIRE(b[1] == trit::True);
		REQUIRE(b.capacity() == 4);
		tritset e(0);
		e.trim(0);
		REQUIRE(e.capacity() == 0);
		REQUIRE_THROWS_AS(a.trim(-2), std::invalid_argument);
		REQUIRE_THROWS_AS(b.trim(17), std::invalid_argument);
	}
	SECTION("Length") {
		a[7] = trit::True;
		REQUIRE(a.t_length() == 8);
		REQUIRE(b.t_length() == 0);
		tritset e(0);
		REQUIRE(e.t_length() == 0);
	}
}