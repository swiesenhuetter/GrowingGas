#define _USE_MATH_DEFINES
#include "catch.hpp"
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include "GrowingGas.h"
#include "Unit.h"
#include "Pattern.h"
#include "ImageData2D.h"
#include <cmath>
#include <iostream>
#include <limits>



Position generateRingCoordinates(double inner_radius, double outer_radius)
{
	auto epsilon = 1e-10;  // to avoid points outside the ring (sin/cos precision)
	inner_radius += epsilon;
	outer_radius -= epsilon;
	
    // Generate a random angle in radians
    double angle = (rand() % 360) * (M_PI / 180.0);
	// Generate a random distance from the center within the inner and outer radius
	double distance = inner_radius + (rand() % (int)(outer_radius - inner_radius));
    // Convert polar coordinates to Cartesian coordinates
    double x = distance * cos(angle);
    double y = distance * sin(angle);
	return Position{ x, y };
}

double dist_2d(Position p1, Position p2)
{
	auto dx = p1[0] - p2[0];
	auto dy = p1[1] - p2[1];
	return sqrt(dx * dx + dy * dy);
}


TEST_CASE("100 Disk points", "[disk]") {

	int n = 100;
    double inner_radius{ 10.0 };
	double outer_radius{ 20.0 };
	std::vector<Position> points;
	for (int i = 0; i < n; ++i) {
		points.push_back(generateRingCoordinates(inner_radius, outer_radius));
	}

	REQUIRE(points.size() == n);
	
	SECTION("Points are within the ring") {
		for (auto p : points) {
			REQUIRE(dist_2d(p, { 0, 0 }) >= inner_radius);
			REQUIRE(dist_2d(p, { 0, 0 }) <= outer_radius);
		}
	}
		
	Unit unit_a(Position{ -15.0, 0 });
	Unit unit_b(Position{ 15.0,  0 });

	REQUIRE(unit_a.isSingle());
	REQUIRE(unit_b.isSingle());
	auto dist_a_b = dist_2d(unit_a.loc(), unit_b.loc());
	auto d = unit_a.euclideanDistance(unit_b.loc());
	REQUIRE_THAT(dist_a_b, Catch::Matchers::WithinAbs(30.0, 1e-10));
	REQUIRE_THAT(d, Catch::Matchers::WithinAbs(30.0, 1e-10));

	GrowingGas gas(points);
	
	for (int i = 0; i < 100; ++i) {
		gas.learnRandomPattern();
	}
	
	
	
}


int main(int argc, char* argv[]) {
    Catch::Session session;
    int result = session.run(argc, argv);
	return result;
}




