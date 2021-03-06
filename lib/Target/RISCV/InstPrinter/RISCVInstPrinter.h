//===-- RISCVInstPrinter.h - Convert RISCV MCInst to asm syntax ---*- C++ -*--//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class prints a RISCV MCInst to a .s file.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_RISCV_INSTPRINTER_RISCVINSTPRINTER_H
#define LLVM_LIB_TARGET_RISCV_INSTPRINTER_RISCVINSTPRINTER_H

#include "MCTargetDesc/RISCVMCTargetDesc.h"
#include "llvm/MC/MCInstPrinter.h"

namespace llvm {
class MCOperand;

class RISCVInstPrinter : public MCInstPrinter {
public:
  RISCVInstPrinter(const MCAsmInfo &MAI, const MCInstrInfo &MII,
                   const MCRegisterInfo &MRI)
      : MCInstPrinter(MAI, MII, MRI) {}

  void printInst(const MCInst *MI, raw_ostream &O, StringRef Annot,
                 const MCSubtargetInfo &STI) override;
  void printRegName(raw_ostream &O, unsigned RegNo) const override;

  void printOperand(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                    raw_ostream &O, const char *Modifier = nullptr);
  void printCSRSystemRegister(const MCInst *MI, unsigned OpNo,
                              const MCSubtargetInfo &STI, raw_ostream &O);
  void printFenceArg(const MCInst *MI, unsigned OpNo,
                     const MCSubtargetInfo &STI, raw_ostream &O);
  void printFRMArg(const MCInst *MI, unsigned OpNo, const MCSubtargetInfo &STI,
                   raw_ostream &O);

  // Autogenerated by tblgen.
  void printInstruction(const MCInst *MI, const MCSubtargetInfo &STI,
                        raw_ostream &O);
  bool printAliasInstr(const MCInst *MI, const MCSubtargetInfo &STI,
                       raw_ostream &O);
  void printCustomAliasOperand(const MCInst *MI, unsigned OpIdx,
                               unsigned PrintMethodIdx,
                               const MCSubtargetInfo &STI, raw_ostream &O);
  static const char *getRegisterName(unsigned RegNo,
                                     unsigned AltIdx = RISCV::ABIRegAltName);
};
} // namespace llvm

#endif
