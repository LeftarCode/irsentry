/**
 * @file BaseInstruction.h
 * @brief Defines the BaseInstruction class and the InstructionType enumeration.
 */

#pragma once

namespace irsentry {
/**
 * @enum InstructionType
 * @brief Represents different types of instructions.
 */
enum InstructionType {
  AddInstruction,            /**< Integer addition instruction */
  FAddInstruction,           /**< Floating-point addition instruction */
  SubInstruction,            /**< Integer subtraction instruction */
  FSubInstruction,           /**< Floating-point subtraction instruction */
  MulInstruction,            /**< Integer multiplication instruction */
  FMulInstruction,           /**< Floating-point multiplication instruction */
  UDivInstruction,           /**< Unsigned integer division instruction */
  SDivInstruction,           /**< Signed integer division instruction */
  FDivInstruction,           /**< Floating-point division instruction */
  URemInstruction,           /**< Unsigned integer remainder instruction */
  SRemInstruction,           /**< Signed integer remainder instruction */
  FRemInstruction,           /**< Floating-point remainder instruction */
  ShlInstruction,            /**< Bitwise shift left instruction */
  LshrInstruction,           /**< Logical shift right instruction */
  AshrInstruction,           /**< Arithmetic shift right instruction */
  AndInstruction,            /**< Bitwise AND instruction */
  OrInstruction,             /**< Bitwise OR instruction */
  XorInstruction,            /**< Bitwise XOR instruction */
  ExtractElementInstruction, /**< Extracts an element from a vector */
  InsertElementInstruction,  /**< Inserts an element into a vector */
  ShuffleVectorInstruction,  /**< Shuffles elements of a vector */
  ExtractValueInstruction,   /**< Extracts a value from an aggregate type */
  InsertValueInstruction,    /**< Inserts a value into an aggregate type */
  AllocaInstruction,         /**< Memory allocation instruction */
  LoadInstruction,           /**< Memory load instruction */
  StoreInstruction,          /**< Memory store instruction */
  FenceInstruction,          /**< Synchronization fence instruction */
  CmpXchgInstruction,        /**< Atomic compare and exchange instruction */
  AtomicRMWInstruction,      /**< Atomic read-modify-write instruction */
  GetElementPtrInstruction,  /**< Get element pointer instruction */
  TruncInstruction,          /**< Integer truncation instruction */
  ZExtInstruction,           /**< Zero extension instruction */
  SExtInstruction,           /**< Sign extension instruction */
  FpTruncInstruction,        /**< Floating-point truncation instruction */
  FpExtInstruction,          /**< Floating-point extension instruction */
  FpToUIInstruction,   /**< Floating-point to unsigned integer conversion */
  FpToSIInstruction,   /**< Floating-point to signed integer conversion */
  UiToFPInstruction,   /**< Unsigned integer to floating-point conversion */
  SiToFPInstruction,   /**< Signed integer to floating-point conversion */
  PtrToIntInstruction, /**< Pointer to integer conversion */
  IntToPtrInstruction, /**< Integer to pointer conversion */
  BitCastInstruction,  /**< Bitwise type cast */
  AddrSpaceCastInstruction, /**< Address space cast instruction */
  ICmpInstruction,          /**< Integer comparison instruction */
  FCmpInstruction,          /**< Floating-point comparison instruction */
  PhiInstruction,           /**< Phi node instruction */
  SelectInstruction,        /**< Select instruction */
  CallInstruction,          /**< Function call instruction */
  VaArgInstruction,         /**< Variadic argument instruction */
  LandingPadInstruction,    /**< Exception handling landing pad instruction */
  CatchPadInstruction,      /**< Exception handling catch pad instruction */
  CleanupPadInstruction     /**< Exception handling cleanup pad instruction */
};

/**
 * @class BaseInstruction
 * @brief A base class representing an instruction.
 */
class BaseInstruction {
public:
  /**
   * @brief The type of instruction this object represents.
   */
  InstructionType type;
};
} // namespace irsentry
