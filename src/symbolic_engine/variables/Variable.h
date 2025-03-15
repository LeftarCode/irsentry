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
template <InheritedFromBaseWithVarType T> struct Variable {
  /**
   * @brief Indicates whether the variable is constant.
   */
  bool isConst;

  /**
   * @brief The type of the variable.
   */
  T type;

  /**
   * @brief The name of the variable.
   */
  std::string name;

  /**
   * @brief The optional value of the variable.
   */
  std::optional<typename T::var_type> optValue;
};
} // namespace irsentry
