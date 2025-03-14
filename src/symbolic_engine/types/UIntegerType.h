/**
 * @file UnsignedIntegerTypes.h
 * @brief Defines unsigned integer-based data types.
 */

#pragma once
#include "BaseType.h"
#include <stdint.h>

/**
 * @class UInteger16Type
 * @brief Represents a 16-bit unsigned integer type.
 */
class UInteger16Type : public BaseType {
public:
  /**
   * @brief Constructor for UInteger16Type.
   */
  UInteger16Type();

  /**
   * @brief Type alias for a 16-bit unsigned integer.
   */
  using var_type = uint16_t;
};

/**
 * @class UInteger32Type
 * @brief Represents a 32-bit unsigned integer type.
 */
class UInteger32Type : public BaseType {
public:
  /**
   * @brief Constructor for UInteger32Type.
   */
  UInteger32Type();

  /**
   * @brief Type alias for a 32-bit unsigned integer.
   */
  using var_type = uint32_t;
};

/**
 * @class UInteger64Type
 * @brief Represents a 64-bit unsigned integer type.
 */
class UInteger64Type : public BaseType {
public:
  /**
   * @brief Constructor for UInteger64Type.
   */
  UInteger64Type();

  /**
   * @brief Type alias for a 64-bit unsigned integer.
   */
  using var_type = uint64_t;
};
