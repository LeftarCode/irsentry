/**
 * @file BaseInstrType.h
 * @brief Defines the BaseInstrType class and the InstrTypeType enumeration.
 */

#pragma once
#include "../types/BaseType.h"
#include "../visitors/InstructionVisitorBase.h"

namespace irsentry {
/**
 * @enum InstrType
 * @brief Represents different types of instructions.
 */
enum InstrType {
  AddInstrType,            /**< Integer addition instruction */
  FAddInstrType,           /**< Floating-point addition instruction */
  SubInstrType,            /**< Integer subtraction instruction */
  FSubInstrType,           /**< Floating-point subtraction instruction */
  MulInstrType,            /**< Integer multiplication instruction */
  FMulInstrType,           /**< Floating-point multiplication instruction */
  UDivInstrType,           /**< Unsigned integer division instruction */
  SDivInstrType,           /**< Signed integer division instruction */
  FDivInstrType,           /**< Floating-point division instruction */
  URemInstrType,           /**< Unsigned integer remainder instruction */
  SRemInstrType,           /**< Signed integer remainder instruction */
  FRemInstrType,           /**< Floating-point remainder instruction */
  ShlInstrType,            /**< Bitwise shift left instruction */
  LshrInstrType,           /**< Logical shift right instruction */
  AshrInstrType,           /**< Arithmetic shift right instruction */
  AndInstrType,            /**< Bitwise AND instruction */
  OrInstrType,             /**< Bitwise OR instruction */
  XorInstrType,            /**< Bitwise XOR instruction */
  ExtractElementInstrType, /**< Extracts an element from a vector */
  InsertElementInstrType,  /**< Inserts an element into a vector */
  ShuffleVectorInstrType,  /**< Shuffles elements of a vector */
  ExtractValueInstrType,   /**< Extracts a value from an aggregate type */
  InsertValueInstrType,    /**< Inserts a value into an aggregate type */
  AllocaInstrType,         /**< Memory allocation instruction */
  LoadInstrType,           /**< Memory load instruction */
  StoreInstrType,          /**< Memory store instruction */
  FenceInstrType,          /**< Synchronization fence instruction */
  CmpXchgInstrType,        /**< Atomic compare and exchange instruction */
  AtomicRMWInstrType,      /**< Atomic read-modify-write instruction */
  GetElementPtrInstrType,  /**< Get element pointer instruction */
  // TruncInstrType,          /**< Integer truncation instruction */
  // ZExtInstrType,           /**< Zero extension instruction */
  // SExtInstrType,           /**< Sign extension instruction */
  // FpTruncInstrType,        /**< Floating-point truncation instruction */
  // FpExtInstrType,          /**< Floating-point extension instruction */
  // FpToUIInstrType,         /**< Floating-point to unsigned integer conversion
  // */ FpToSIInstrType,         /**< Floating-point to signed integer
  // conversion */ UiToFPInstrType,         /**< Unsigned integer to
  // floating-point conversion */ SiToFPInstrType,         /**< Signed integer
  // to floating-point conversion */ PtrToIntInstrType,       /**< Pointer to
  // integer conversion */ IntToPtrInstrType,       /**< Integer to pointer
  // conversion */ BitCastInstrType,        /**< Bitwise type cast */
  CastInstrType,          /**< Generic type cast */
  AddrSpaceCastInstrType, /**< Address space cast instruction */
  ICmpInstrType,          /**< Integer comparison instruction */
  FCmpInstrType,          /**< Floating-point comparison instruction */
  PhiInstrType,           /**< Phi node instruction */
  SelectInstrType,        /**< Select instruction */
  CallInstrType,          /**< Function call instruction */
  VaArgInstrType,         /**< Variadic argument instruction */
  LandingPadInstrType,    /**< Exception handling landing pad instruction */
  CatchPadInstrType,      /**< Exception handling catch pad instruction */
  CleanupPadInstrType     /**< Exception handling cleanup pad instruction */
};

/**
 * @class BaseInstrType
 * @brief A base class representing an instruction.
 */
class BaseInstruction {
public:
  virtual ~BaseInstruction() = default;
  /**
   * @brief The type of instruction this object represents.
   */
  InstrType instrType;
  DataType dataType;
};
} // namespace irsentry
