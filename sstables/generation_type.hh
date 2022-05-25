/*
 * Copyright (C) 2022-present ScyllaDB
 */

/*
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#pragma once

#include "api/api.hh"
#include "utils/UUID.hh"
#include <seastar/core/sstring.hh>
#include <variant>

namespace sstables {
using generation_type = std::variant<int64_t, utils::UUID>;

sstring to_string(const generation_type& gen);
int calc_shard_num(const generation_type& gen);
generation_type generation_from_string(const sstring& str);
generation_type increment(const generation_type& gen);

bool operator<(const generation_type& a, const generation_type& b);

} // namespace sstables
