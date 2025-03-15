/**
 * @file FloatDoubleType.h
 * @brief Defines the FloatType and DoubleType classes.
 */

#pragma once
#include "BaseType.h"
#include <concepts>
#include <type_traits>

namespace irsentry {
/**
 * @class FloatType
 * @brief Represents a floating-point data type.
 */
class FloatType : public BaseType {
public:
  /**
   * @brief Constructor for FloatType.
   */
  FloatType();

  /**
   * @brief Type alias for the floating-point type.
   */
  using var_type = float;
};

/**
 * @class DoubleType
 * @brief Represents a double-precision floating-point data type.
 */
class DoubleType : public BaseType {
public:
  /**
   * @brief Constructor for DoubleType.
   */
  DoubleType();

  /**
   * @brief Type alias for the double-precision floating-point type.
   */
  using var_type = double;
};

/**
 * @brief Concept ensuring only allowed floating-point types are used.
 */
template <typename T>
concept AllowedFloat =
    std::same_as<T, FloatType> || std::same_as<T, DoubleType>;
} // namespace irsentry
