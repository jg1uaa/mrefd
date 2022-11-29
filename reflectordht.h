//  Copyright © 2022 Thomas A. Early, N7TAE
//
// ----------------------------------------------------------------------------
//    This file is part of M17Refd.
//
//    M17Refd is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    M17Refd is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    with this software.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#pragma once

#include <opendht.h>

template<typename E> constexpr auto toUType(E enumerator) noexcept
{
	return static_cast<std::underlying_type_t<E>>(enumerator);
}

enum class EMrefdValueID : uint64_t { Config=1, Peers=2 };

struct SReflectorPeers0
{
	std::vector<std::pair<std::string, std::string>> peers;

	MSGPACK_DEFINE(peers);
};

struct SReflectorConfig0
{
	std::string cs, ipv4;
	std::string ipv6, mods, emods, url, email;
	std::string sponsor, country;
	uint16_t port;

	MSGPACK_DEFINE(cs, ipv4, ipv6, mods, emods, url, email, sponsor, country, port);
};
