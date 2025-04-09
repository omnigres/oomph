#pragma once

namespace oomph {
// Primary template declaration
template <typename T, typename Variant> struct variant_index;

// Specialization when the first type of the variant is T.
template <typename T, typename... Ts>
struct variant_index<T, std::variant<T, Ts...>> : std::integral_constant<std::size_t, 0> {};

// Recursively check the rest of the types.
template <typename T, typename U, typename... Ts>
struct variant_index<T, std::variant<U, Ts...>>
    : std::integral_constant<std::size_t, 1 + variant_index<T, std::variant<Ts...>>::value> {};

template <typename T, typename Variant>
constexpr std::size_t variant_index_v = variant_index<T, Variant>::value;

} // namespace oomph
