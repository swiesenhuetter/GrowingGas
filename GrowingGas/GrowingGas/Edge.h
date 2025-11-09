#pragma once

#include <utility>

class Unit;

struct Edge
{
    explicit Edge(void);
    explicit Edge(Unit* u1, Unit* u2);
    ~Edge(void) = default;

    // Add move operations since we manage pointers
    Edge(Edge&& other) noexcept = default;
    Edge& operator=(Edge&& other) noexcept = default;

    // Disable copy operations since we don't want to duplicate pointer ownership
    Edge(const Edge&) = delete;
    Edge& operator=(const Edge&) = delete;

    Unit* _u1{nullptr};
    Unit* _u2{nullptr};
    int _age{0};
};
