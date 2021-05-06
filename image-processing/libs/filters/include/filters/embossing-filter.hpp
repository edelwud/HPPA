#pragma once

#include <map>

static std::map<int, int> embossingFilter = {
        { 1,  1 },
        { 3,  1 },
        { 5, -1 },
        { 7, -1 }
};