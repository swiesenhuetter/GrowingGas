#include "StdAfx.h"
#include "Edge.h"

Edge::Edge(void)
:_age(0)
,_u1(nullptr)
,_u2(nullptr)
{
}

Edge::Edge(	Unit* u1, Unit* u2)
:_age(0)
,_u1(u1)
,_u2(u2)
{
}

Edge::~Edge(void)
{
}
