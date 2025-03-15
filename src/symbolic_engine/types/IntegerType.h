/**
 * @file IntegerTypes.h
 * @brief Defines integer-based data types.
 */

#pragma once
#include "BaseType.h"
#include <concepts>
#include <stdint.h>
#include <type_traits>

namespace irsentry {
/**
 * @class Integer16Type
 * @brief Represents a 16-bit signed integer type.
 */
class Integer16Type : public BaseType {
public:
  /**
   * @brief Constructor for Integer16Type.
   */
  Integer16Type();

  /**
   * @brief Type alias for a 16-bit signed integer.
   */
  using var_type = int16_t;
};

/**
 * @class Integer32Type
 * @brief Represents a 32-bit signed integer type.
 */
class Integer32Type : public BaseType {
public:
  /**
   * @brief Constructor for Integer32Type.
   */
  Integer32Type();

  /**
   * @brief Type alias for a 32-bit signed integer.
   */
  using var_type = int32_t;
};

/**
 * @class Integer64Type
 * @brief Represents a 64-bit signed integer type.
 */
class Integer64Type : public BaseType {
public:
  /**
   * @brief Constructor for Integer64Type.
   */
  Integer64Type();

  /**
   * @brief Type alias for a 64-bit signed integer.
   */
  using var_type = int64_t;
};

/**
 * @brief Concept ensuring only allowed integer types are used.
 */
template <typename T>
concept AllowedInt =
    std::same_as<T, Integer16Type> || std::same_as<T, Integer32Type> ||
    std::same_as<T, Integer64Type>;
} // namespace irsentry
