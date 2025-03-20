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
 * @brief Concept ensuring the type has a var_type alias.
 */
template <typename T>
concept HasVarType = requires { typename T::var_type; };

/**
 * @brief Concept ensuring the type is derived from BaseType and has a var_type
 * alias.
 */
template <typename T>
concept InheritedFromBaseWithVarType =
    std::is_base_of_v<BaseType, T> && HasVarType<T>;

/**
 * @struct Variable
 * @brief Represents a variable with an optional value.
 *
 * @tparam T A type that satisfies the InheritedFromBaseWithVarType concept.
 */
template <InheritedFromBaseWithVarType IRType> struct Value {
  /**
   * @brief Indicates whether the variable is constant.
   */
  bool isVariable;

  /**
   * @brief The type of the variable.
   */
  using llvmType = IRType;

  /**
   * @brief The name of the variable.
   */
  std::string name;

  /**
   * @brief The optional value of the variable.
   */
  std::optional<typename IRType::dataType> optValue;
};
} // namespace irsentry
