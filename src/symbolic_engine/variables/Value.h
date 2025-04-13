/**
 * @file Variable.h
 * @brief Defines the Variable template struct and associated concepts.
 */

#pragma once
#include "../types/BaseType.h"
#include <optional>
#include <string>

namespace irsentry {
/**
 * @brief Concept ensuring the type has a data_type alias.
 */
template <typename T>
concept HasDataType = requires { typename T::data_type; };

/**
 * @brief Concept ensuring the type is derived from BaseType and has a data_type
 * alias.
 */
template <typename T>
concept InheritedFromBaseWithDataType =
    std::is_base_of_v<BaseType, T> && HasDataType<T>;

/**
 * @struct Variable
 * @brief Represents a variable with an optional value.
 *
 * @tparam T A type that satisfies the InheritedFromBaseWithDataType concept.
 */
template <InheritedFromBaseWithDataType IRType> struct Value {
  Value() = default;
  /**
   * @brief Indicates whether the value is variable expression.
   */
  bool isVariable;

  /**
   * @brief The type of the variable.
   */
  using llvm_type = IRType;

  /**
   * @brief The name of the variable.
   */
  std::optional<std::string> optName;

  /**
   * @brief The optional value of the variable.
   */
  std::optional<typename IRType::data_type> optValue;
};
} // namespace irsentry
