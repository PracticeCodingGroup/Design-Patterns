#pragma once
#include <type_traits> //for std::underlying_type
template<typename E>
constexpr auto Enum_v(E e) -> typename std::underlying_type<E>::type
{
	return static_cast<typename std::underlying_type<E>::type>(e);
}