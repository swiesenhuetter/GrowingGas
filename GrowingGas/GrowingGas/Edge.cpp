#include "Edge.h"

Edge::Edge(void)
{
    // Default constructor - all members initialized by in-class initializers
}

Edge::Edge(Unit* u1, Unit* u2)
    : _u1(u1)
    , _u2(u2)
    // _age is initialized by in-class initializer
{
}
