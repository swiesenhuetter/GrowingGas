#include "stdafx.h"
#include "Pattern.h"
#include <algorithm>


Pattern Pattern::operator+(Pattern other) const
{
    Pattern result{ position };
    auto new_pos = std::transform(result.position.begin(),
        result.position.end(),
        other.position.begin(),
        result.position.begin(),
        std::plus<double>());
    return result;
}

Pattern Pattern::operator-(Pattern other) const
{
    Pattern result{ other.position};
    std::transform(result.position.begin(),
        result.position.end(),
        other.position.begin(),
        result.position.begin(),
        std::minus<double>());
    return result;
}

Pattern Pattern::operator*(double factor) const
{
    Pattern result{ position };
    std::transform(result.position.begin(),
        result.position.end(),
        result.position.begin(),
        [factor](double x) {return x * factor; });
    return result;
}


