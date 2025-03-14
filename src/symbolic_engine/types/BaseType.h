/**
 * @file BaseType.h
 * @brief Defines the BaseType class and the DataType enumeration.
 */

#pragma once

/**
 * @enum DataType
 * @brief Represents different data types that can be used.
 */
enum DataType {
  Int16,  /**< 16-bit signed integer */
  Int32,  /**< 32-bit signed integer */
  Int64,  /**< 64-bit signed integer */
  UInt16, /**< 16-bit unsigned integer */
  UInt32, /**< 32-bit unsigned integer */
  UInt64, /**< 64-bit unsigned integer */
  Float,  /**< Single-precision floating point */
  Double, /**< Double-precision floating point */
  Array,  /**< Represents an array type */
  Struct  /**< Represents a structured data type */
};

/**
 * @class BaseType
 * @brief A base class representing a data type.
 */
class BaseType {
public:
  /**
   * @brief The type of data this object represents.
   */
  DataType type;
};
