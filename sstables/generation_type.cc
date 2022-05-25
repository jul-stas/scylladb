/*
 * Copyright (C) 2022-present ScyllaDB
 */

/*
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#include "sstables/generation_type.hh"
#include <fmt/core.h>
#include <cstdint>
#include <stdexcept>

namespace sstables {

sstring to_string(const generation_type& gen) {
    return std::visit([] (const auto &x) {
        return fmt::format("{}", x);
    }, gen);
}

int calc_shard_num(const generation_type& gen) {
    return std::visit(make_visitor(
        [] (int64_t x) { return int(x % smp::count); },
        [] (utils::UUID u) -> int { throw std::runtime_error("unimplemented"); }
    ), gen);
}

generation_type generation_from_string(const sstring& str) {
    throw std::runtime_error("unimplemented");
}

generation_type increment(const generation_type& gen) {
    throw std::runtime_error("unimplemented");
}

bool operator<(const generation_type& a, const generation_type& b) {
    throw std::runtime_error("unimplemented");
}

} // namespace sstables
