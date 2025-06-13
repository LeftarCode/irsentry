#include "InstructionParser.h"
#include "../../symbolic_engine/instructions/Instructions.h"
#include "../../utilities/Logger.h"
#include <memory>

namespace irsentry {

static std::string labelOf(const llvm::BasicBlock *BB) {
  if (BB->hasName())
    return BB->getName().str();

  std::string tmp;
  llvm::raw_string_ostream rso(tmp);
  BB->printAsOperand(rso, false);
  return rso.str();
}

SEEInstruction
InstructionParser::parseBinaryInstr(const llvm::BinaryOperator &op) const {
  auto parsedType = m_typeParser.parseType(op.getType());

  auto makeValue = [&](ValueInstrType kind) -> SEEInstruction {
    ValueInstruction instr{kind, parsedType};
    instr.operators[0] = m_valueParser.parseValue(parsedType, op.getOperand(0));
    instr.operators[1] = m_valueParser.parseValue(parsedType, op.getOperand(1));
    return instr;
  };

  auto makeBit = [&](BitwiseInstrType kind) -> SEEInstruction {
    BitwiseInstruction instr{kind, parsedType};
    instr.operators[0] = m_valueParser.parseValue(parsedType, op.getOperand(0));
    instr.operators[1] = m_valueParser.parseValue(parsedType, op.getOperand(1));
    return instr;
  };

  switch (op.getOpcode()) {
  case llvm::Instruction::Add:
    return makeValue(ValueInstrType::AddInstrType);
  case llvm::Instruction::FAdd:
    return makeValue(ValueInstrType::FAddInstrType);
  case llvm::Instruction::Sub:
    return makeValue(ValueInstrType::SubInstrType);
  case llvm::Instruction::FSub:
    return makeValue(ValueInstrType::FSubInstrType);
  case llvm::Instruction::Mul:
    return makeValue(ValueInstrType::MulInstrType);
  case llvm::Instruction::FMul:
    return makeValue(ValueInstrType::FMulInstrType);
  case llvm::Instruction::UDiv:
    return makeValue(ValueInstrType::UDivInstrType);
  case llvm::Instruction::SDiv:
    return makeValue(ValueInstrType::SDivInstrType);
  case llvm::Instruction::FDiv:
    return makeValue(ValueInstrType::FDivInstrType);
  case llvm::Instruction::URem:
    return makeValue(ValueInstrType::URemInstrType);
  case llvm::Instruction::SRem:
    return makeValue(ValueInstrType::SRemInstrType);
  case llvm::Instruction::FRem:
    return makeValue(ValueInstrType::FRemInstrType);
  case llvm::Instruction::Shl:
    return makeBit(BitwiseInstrType::ShlInstrType);
  case llvm::Instruction::LShr:
    return makeBit(BitwiseInstrType::LShrInstrType);
  case llvm::Instruction::AShr:
    return makeBit(BitwiseInstrType::AShrInstrType);
  case llvm::Instruction::And:
    return makeBit(BitwiseInstrType::AndInstrType);
  case llvm::Instruction::Or:
    return makeBit(BitwiseInstrType::OrInstrType);
  case llvm::Instruction::Xor:
    return makeBit(BitwiseInstrType::XorInstrType);

  default:
    throw std::runtime_error("parseBinaryInstr: unsupported opcode " +
                             std::string(op.getOpcodeName()));
  }
}

SEEInstruction
InstructionParser::parseCastInstr(const llvm::CastInst &ci) const {

  auto toKind = [](unsigned opc) -> CastInstrType {
    switch (opc) {
    case llvm::Instruction::Trunc:
      return CastInstrType::Trunc;
    case llvm::Instruction::ZExt:
      return CastInstrType::ZExt;
    case llvm::Instruction::SExt:
      return CastInstrType::SExt;
    case llvm::Instruction::FPTrunc:
      return CastInstrType::FPTrunc;
    case llvm::Instruction::FPExt:
      return CastInstrType::FPExt;
    case llvm::Instruction::FPToUI:
      return CastInstrType::FPToUI;
    case llvm::Instruction::FPToSI:
      return CastInstrType::FPToSI;
    case llvm::Instruction::UIToFP:
      return CastInstrType::UIToFP;
    case llvm::Instruction::SIToFP:
      return CastInstrType::SIToFP;
    case llvm::Instruction::PtrToInt:
      return CastInstrType::PtrToInt;
    case llvm::Instruction::IntToPtr:
      return CastInstrType::IntToPtr;
    case llvm::Instruction::BitCast:
      return CastInstrType::BitCast;
    case llvm::Instruction::AddrSpaceCast:
      return CastInstrType::AddrSpaceCast;
    default:
      throw std::runtime_error("parseCastInstr: unsupported opcode");
    }
  };

  auto fromType = m_typeParser.parseType(ci.getSrcTy());
  auto toType = m_typeParser.parseType(ci.getDestTy());

  CastInstruction instr{fromType, toType};
  instr.from = m_valueParser.parseValue(fromType, ci.getOperand(0));

  return instr;
}

SEEInstruction
InstructionParser::parseICmpInstr(const llvm::ICmpInst &ci) const {
  auto opTy = m_typeParser.parseType(ci.getOperand(0)->getType());
  auto pred = m_cmpPredParser.parseICmpPred(ci.getPredicate());

  ICmpInstruction instr{pred, opTy};
  instr.operators[0] = m_valueParser.parseValue(opTy, ci.getOperand(0));
  instr.operators[1] = m_valueParser.parseValue(opTy, ci.getOperand(1));

  return instr;
}

SEEInstruction
InstructionParser::parseFCmpInstr(const llvm::FCmpInst &ci) const {
  auto opTy = m_typeParser.parseType(ci.getOperand(0)->getType());
  auto pred = m_cmpPredParser.parseFCmpPred(ci.getPredicate());

  FCmpInstruction instr{pred, opTy};
  instr.operators[0] = m_valueParser.parseValue(opTy, ci.getOperand(0));
  instr.operators[1] = m_valueParser.parseValue(opTy, ci.getOperand(1));

  return instr;
}

SEEInstruction
InstructionParser::parseAllocaInstr(const llvm::AllocaInst &ai) const {
  auto elemType = m_typeParser.parseType(ai.getAllocatedType());

  auto numTy = m_typeParser.parseType(ai.getArraySize()->getType());
  Value numElements = m_valueParser.parseValue(numTy, ai.getArraySize());

  AllocaInstruction instr(elemType, numElements);
  return instr;
}

SEEInstruction
InstructionParser::parseLoadInstr(const llvm::LoadInst &li) const {

  auto loadedTy = m_typeParser.parseType(li.getType());
  auto ptrTy = m_typeParser.parseType(li.getPointerOperandType());

  Value from = m_valueParser.parseValue(ptrTy, li.getPointerOperand());
  LoadInstruction instr(loadedTy, from);
  return instr;
}

SEEInstruction
InstructionParser::parseGEPInstr(const llvm::GetElementPtrInst &gep) const {
  auto resultTy = m_typeParser.parseType(gep.getType());
  auto baseTy = m_typeParser.parseType(gep.getPointerOperandType());

  Value basePtr = m_valueParser.parseValue(baseTy, gep.getPointerOperand());
  GetElementPtrInstruction instr(resultTy, basePtr);
  return instr;
}

SEEInstruction
InstructionParser::parseStoreInstr(const llvm::StoreInst &si) const {
  auto valTy = m_typeParser.parseType(si.getValueOperand()->getType());
  Value what = m_valueParser.parseValue(valTy, si.getValueOperand());

  auto ptrTy = m_typeParser.parseType(si.getPointerOperand()->getType());
  Value where = m_valueParser.parseValue(ptrTy, si.getPointerOperand());

  StoreInstruction instr(what, where);
  return instr;
}

SEEInstruction InstructionParser::parseExtractValueInstr(
    const llvm::ExtractValueInst &evi) const {
  auto resultTy = m_typeParser.parseType(evi.getType());
  auto aggTy = m_typeParser.parseType(evi.getAggregateOperand()->getType());

  Value from = m_valueParser.parseValue(aggTy, evi.getAggregateOperand());

  std::vector<size_t> idx;
  idx.reserve(evi.getNumIndices());
  for (unsigned i : evi.indices())
    idx.emplace_back(static_cast<size_t>(i));

  ExtractValueInstruction instr(resultTy, from, std::move(idx));
  return instr;
}

SEEInstruction
InstructionParser::parseCallInstr(const llvm::CallBase &call) const {
  auto retTy = m_typeParser.parseType(call.getType());

  std::string callee;
  if (const auto *fn =
          llvm::dyn_cast<llvm::Function>(call.getCalledOperand())) {
    callee = fn->getName().str();
  } else if (call.getCalledOperand()->hasName()) {
    callee = call.getCalledOperand()->getName().str();
  }

  std::vector<Value> args;
  args.reserve(call.arg_size());
  for (unsigned i = 0; i < call.arg_size(); ++i) {
    auto argTy = m_typeParser.parseType(call.getArgOperand(i)->getType());
    args.emplace_back(m_valueParser.parseValue(argTy, call.getArgOperand(i)));
  }

  CallInstruction instr(retTy, std::move(callee), std::move(args));
  return instr;
}

SEEInstruction
InstructionParser::parseBrInstr(const llvm::BranchInst &br) const {
  if (br.isUnconditional()) {
    std::string succ = labelOf(br.getSuccessor(0));
    BrTerminator instr(BrTerminatorType::Unconditional, std::move(succ));
    return instr;
  }

  auto condTy = m_typeParser.parseType(br.getCondition()->getType());
  Value cond = m_valueParser.parseValue(condTy, br.getCondition());

  std::string succTrue = labelOf(br.getSuccessor(0));
  std::string succFalse = labelOf(br.getSuccessor(1));

  BrTerminator instr(BrTerminatorType::Conditional, std::move(cond),
                     std::move(succTrue), std::move(succFalse));
  return instr;
}

SEEInstruction
InstructionParser::parseRetInstr(const llvm::ReturnInst &ret) const {
  if (ret.getNumOperands() == 0) {
    RetTerminator instr;
    instr.isVoid = true;
    return instr;
  }

  auto valTy = m_typeParser.parseType(ret.getReturnValue()->getType());
  Value val = m_valueParser.parseValue(valTy, ret.getReturnValue());

  RetTerminator instr(std::move(val));
  return instr;
}

SEEInstruction InstructionParser::parseExtractElementInstr(
    const llvm::ExtractElementInst &ee) const {

  auto resultTy = m_typeParser.parseType(ee.getType());
  auto vecTy = m_typeParser.parseType(ee.getVectorOperand()->getType());
  auto idxTy = m_typeParser.parseType(ee.getIndexOperand()->getType());

  Value vec = m_valueParser.parseValue(vecTy, ee.getVectorOperand());
  Value idx = m_valueParser.parseValue(idxTy, ee.getIndexOperand());

  ExtractElementInstruction instr(resultTy, std::move(vec), std::move(idx));
  return instr;
}

SEEInstruction InstructionParser::parseInsertElementInstr(
    const llvm::InsertElementInst &ie) const {

  auto resultTy = m_typeParser.parseType(ie.getType());
  auto vecTy = m_typeParser.parseType(ie.getOperand(0)->getType());
  auto eltTy = m_typeParser.parseType(ie.getOperand(1)->getType());
  auto idxTy = m_typeParser.parseType(ie.getOperand(2)->getType());

  Value vec = m_valueParser.parseValue(vecTy, ie.getOperand(0));
  Value elt = m_valueParser.parseValue(eltTy, ie.getOperand(1));
  Value idx = m_valueParser.parseValue(idxTy, ie.getOperand(2));

  InsertElementInstruction instr(resultTy, std::move(vec), std::move(elt),
                                 std::move(idx));
  return instr;
}

SEEInstruction InstructionParser::parseShuffleVectorInstr(
    const llvm::ShuffleVectorInst &sv) const {

  auto resultTy = m_typeParser.parseType(sv.getType());
  auto v1Ty = m_typeParser.parseType(sv.getOperand(0)->getType());
  auto v2Ty = m_typeParser.parseType(sv.getOperand(1)->getType());

  Value v1 = m_valueParser.parseValue(v1Ty, sv.getOperand(0));
  Value v2 = m_valueParser.parseValue(v2Ty, sv.getOperand(1));

  llvm::ArrayRef<int> llvmMask = sv.getShuffleMask();
  std::vector<int> mask(llvmMask.begin(), llvmMask.end());

  ShuffleVectorInstruction instr(resultTy, std::move(v1), std::move(v2),
                                 std::move(mask));
  return instr;
}

static std::string blockLabel(const llvm::BasicBlock &BB) {
  if (BB.hasName())
    return BB.getName().str();
  std::string tmp;
  llvm::raw_string_ostream rso(tmp);
  BB.printAsOperand(rso, false);
  return rso.str();
}

SEEInstruction InstructionParser::parseInsertValueInstr(
    const llvm::InsertValueInst &iv) const {

  auto resultTy = m_typeParser.parseType(iv.getType());
  auto aggTy = m_typeParser.parseType(iv.getAggregateOperand()->getType());
  auto eltTy = m_typeParser.parseType(iv.getInsertedValueOperand()->getType());

  Value agg = m_valueParser.parseValue(aggTy, iv.getAggregateOperand());
  Value elt = m_valueParser.parseValue(eltTy, iv.getInsertedValueOperand());

  std::vector<size_t> idx;
  idx.reserve(iv.getNumIndices());
  for (unsigned i : iv.indices())
    idx.emplace_back(i);

  return InsertValueInstruction(resultTy, std::move(agg), std::move(elt),
                                std::move(idx));
}

SEEInstruction InstructionParser::parseAddrSpaceCastInstr(
    const llvm::AddrSpaceCastInst &ac) const {

  auto toTy = m_typeParser.parseType(ac.getDestTy());
  auto fromTy = m_typeParser.parseType(ac.getSrcTy());

  Value from = m_valueParser.parseValue(fromTy, ac.getOperand(0));

  return AddrSpaceCastInstruction(toTy, std::move(from));
}

SEEInstruction
InstructionParser::parsePhiInstr(const llvm::PHINode &phi) const {

  auto resTy = m_typeParser.parseType(phi.getType());
  PhiInstruction instr(resTy);

  unsigned n = phi.getNumIncomingValues();
  instr.incomings.reserve(n);

  for (unsigned i = 0; i < n; ++i) {
    const llvm::Value *llvmVal = phi.getIncomingValue(i);
    const llvm::BasicBlock *bb = phi.getIncomingBlock(i);

    auto valTy = m_typeParser.parseType(llvmVal->getType());
    Value val = m_valueParser.parseValue(valTy, llvmVal);

    instr.incomings.emplace_back(std::move(val), blockLabel(*bb));
  }
  return instr;
}

SEEInstruction InstructionParser::parseUnreachableInstr(
    const llvm::UnreachableInst &phi) const {
  return UnreachableTerminator{};
}

SEEInstruction
InstructionParser::parseSwitchInstr(const llvm::SwitchInst &si) const {
  auto condTy = m_typeParser.parseType(si.getCondition()->getType());
  Value condV = m_valueParser.parseValue(condTy, si.getCondition());

  SwitchTerminator instr;
  instr.condition = std::move(condV);
  instr.defaultSuccessor = labelOf(si.getDefaultDest());

  instr.cases.reserve(si.getNumCases());
  for (auto &Case : si.cases()) {
    auto caseTy = m_typeParser.parseType(Case.getCaseValue()->getType());
    Value cVal = m_valueParser.parseValue(caseTy, Case.getCaseValue());

    instr.cases.push_back(
        SwitchCase{std::move(cVal), labelOf(Case.getCaseSuccessor())});
  }
  return instr;
}

SEEInstruction
InstructionParser::parseSelectInstr(const llvm::SelectInst &si) const {
  // condition
  auto condTy = m_typeParser.parseType(si.getCondition()->getType());
  Value cond = m_valueParser.parseValue(condTy, si.getCondition());

  // true / false operands
  auto tvTy = m_typeParser.parseType(si.getTrueValue()->getType());
  Value tv = m_valueParser.parseValue(tvTy, si.getTrueValue());

  auto fvTy = m_typeParser.parseType(si.getFalseValue()->getType());
  Value fv = m_valueParser.parseValue(fvTy, si.getFalseValue());

  SelectInstruction instr;
  instr.condition = std::move(cond);
  instr.trueValue = std::move(tv);
  instr.falseValue = std::move(fv);
  return instr;
}

SEEInstruction
InstructionParser::parseInstruction(const llvm::Instruction &instr) const {
  if (auto *bo = llvm::dyn_cast<llvm::BinaryOperator>(&instr)) {
    return parseBinaryInstr(*bo);
  } else if (auto *ci = llvm::dyn_cast<llvm::CastInst>(&instr)) {
    return parseCastInstr(*ci);
  } else if (auto *ci = llvm::dyn_cast<llvm::ICmpInst>(&instr)) {
    return parseICmpInstr(*ci);
  } else if (auto *ci = llvm::dyn_cast<llvm::FCmpInst>(&instr)) {
    return parseFCmpInstr(*ci);
  } else if (auto *si = llvm::dyn_cast<llvm::StoreInst>(&instr)) {
    return parseStoreInstr(*si);
  } else if (auto *evi = llvm::dyn_cast<llvm::ExtractValueInst>(&instr)) {
    return parseExtractValueInstr(*evi);
  } else if (auto *bi = llvm::dyn_cast<llvm::BranchInst>(&instr)) {
    return parseBrInstr(*bi);
  } else if (auto *ri = llvm::dyn_cast<llvm::ReturnInst>(&instr)) {
    return parseRetInstr(*ri);
  } else if (auto *ee = llvm::dyn_cast<llvm::ExtractElementInst>(&instr)) {
    return parseExtractElementInstr(*ee);
  } else if (auto *ie = llvm::dyn_cast<llvm::InsertElementInst>(&instr)) {
    return parseInsertElementInstr(*ie);
  } else if (auto *sv = llvm::dyn_cast<llvm::ShuffleVectorInst>(&instr)) {
    return parseShuffleVectorInstr(*sv);
  } else if (auto *ai = llvm::dyn_cast<llvm::AllocaInst>(&instr)) {
    return parseAllocaInstr(*ai);
  } else if (auto *li = llvm::dyn_cast<llvm::LoadInst>(&instr)) {
    return parseLoadInstr(*li);
  } else if (auto *gepi = llvm::dyn_cast<llvm::GetElementPtrInst>(&instr)) {
    return parseGEPInstr(*gepi);
  } else if (auto *ci = llvm::dyn_cast<llvm::CallBase>(&instr)) {
    return parseCallInstr(*ci);
  } else if (auto *iv = llvm::dyn_cast<llvm::InsertValueInst>(&instr)) {
    return parseInsertValueInstr(*iv);
  } else if (auto *ac = llvm::dyn_cast<llvm::AddrSpaceCastInst>(&instr)) {
    return parseAddrSpaceCastInstr(*ac);
  } else if (auto *pn = llvm::dyn_cast<llvm::PHINode>(&instr)) {
    return parsePhiInstr(*pn);
  } else if (auto *ui = llvm::dyn_cast<llvm::UnreachableInst>(&instr)) {
    return parseUnreachableInstr(*ui);
  } else if (auto *si = llvm::dyn_cast<llvm::SwitchInst>(&instr)) {
    return parseSwitchInstr(*si);
  } else if (auto *sli = llvm::dyn_cast<llvm::SelectInst>(&instr)) {
    return parseSelectInstr(*sli);
  }

  switch (instr.getOpcode()) {
  case llvm::Instruction::VAArg:
  case llvm::Instruction::LandingPad:
  case llvm::Instruction::CatchPad:
    throw std::runtime_error("Unimplemented instruction: " +
                             std::string(instr.getOpcodeName()));
  default:
    throw std::runtime_error("Instruction parser encountered unknown LLVM "
                             "opcode: " +
                             std::string(instr.getOpcodeName()));
  }
}

} // namespace irsentry
