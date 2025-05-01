/**
 * @file Variable.h
 * @brief Defines the Variable template struct and associated concepts.
 */

#pragma once
#include "../types/SEETypeDef.h"
#include <optional>
#include <string>

namespace irsentry {

/**
 * @struct Variable
 * @brief Represents a variable with an optional value.
 *
 * @tparam T A type that satisfies the InheritedFromBaseWithDataType concept.
 */
class Value {
public:
  Value() {};
  Value(SEETypeDefPtr dataTypePtr);

  SEETypeDefPtr dataType;
  /**
   * @brief Indicates whether the value is variable expression.
   */
  bool isVariable = false;

  /**
   * @brief The name of the variable.
   */
  std::optional<std::string> optName;

  /**
   * @brief The optional value of the variable.
   */
  std::optional<TypeVariant> optValue;
};
} // namespace irsentry
