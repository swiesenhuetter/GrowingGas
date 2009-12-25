#pragma once

#include <utility>

class Unit;

struct Edge
{
	Edge(void);
	Edge(Unit* u1, Unit* u2);
	~Edge(void);

	Unit* _u1;
	Unit* _u2;
	int _age;
};
