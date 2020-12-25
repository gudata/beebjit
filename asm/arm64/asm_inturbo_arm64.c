#include "../asm_inturbo.h"

#include "../../util.h"
#include "../asm_common.h"

#include <assert.h>
/* For ssize_t. */
#include <sys/types.h>

static void
asm_patch_arm64_imm9(struct util_buffer* p_buf, ptrdiff_t delta, int32_t val) {
  uint8_t* p_raw;
  ssize_t pos;
  uint32_t insn;
  uint32_t* p_insn;
  assert((val <= 255) && (val >= -256));

  p_raw = util_buffer_get_ptr(p_buf);
  pos = util_buffer_get_pos(p_buf);
  pos -= delta;
  assert(pos >= 4);
  pos -=4;
  p_raw += pos;
  p_insn = (uint32_t*) p_raw;
  insn = *p_insn;
  insn &= ~(0x1FF << 12);
  insn |= ((val & 0x1FF) << 12);
  *p_insn = insn;
}

int
asm_inturbo_is_enabled(void) {
  return 1;
}

void
asm_emit_inturbo_check_special_address(struct util_buffer* p_buf,
                                       uint16_t special_addr_above) {
  (void) p_buf;
  (void) special_addr_above;
}

void
asm_emit_inturbo_check_countdown(struct util_buffer* p_buf, uint8_t opcycles) {
  (void) p_buf;
  (void) opcycles;
}

void
asm_emit_inturbo_check_countdown_with_page_crossing(struct util_buffer* p_buf,
                                                    uint8_t opcycles) {
  (void) p_buf;
  (void) opcycles;
}

void
asm_emit_inturbo_check_decimal(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_inturbo_check_interrupt(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_inturbo_advance_pc_and_next(struct util_buffer* p_buf,
                                     uint8_t advance) {
  void asm_inturbo_advance_pc_and_next(void);
  void asm_inturbo_advance_pc_and_next_END(void);
  void asm_inturbo_advance_pc_and_next_ldr_patch(void);
  asm_copy(p_buf,
           asm_inturbo_advance_pc_and_next,
           asm_inturbo_advance_pc_and_next_END);
  asm_patch_arm64_imm9(p_buf,
		       (asm_inturbo_advance_pc_and_next_END -
			    asm_inturbo_advance_pc_and_next_ldr_patch),
		       advance);
}

void
asm_emit_inturbo_enter_debug(struct util_buffer* p_buf) {
  void asm_inturbo_enter_debug(void);
  void asm_inturbo_enter_debug_END(void);
  asm_copy(p_buf, asm_inturbo_enter_debug, asm_inturbo_enter_debug_END);
}

void
asm_emit_inturbo_call_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_inturbo_mode_zpg(struct util_buffer* p_buf) {
  void asm_inturbo_mode_zpg(void);
  void asm_inturbo_mode_zpg_END(void);
  asm_copy(p_buf, asm_inturbo_mode_zpg, asm_inturbo_mode_zpg_END);
}

void
asm_emit_inturbo_mode_abs(struct util_buffer* p_buf) {
  void asm_inturbo_mode_abs(void);
  void asm_inturbo_mode_abs_END(void);
  asm_copy(p_buf, asm_inturbo_mode_abs, asm_inturbo_mode_abs_END);
}

void
asm_emit_inturbo_mode_abx(struct util_buffer* p_buf) {
  void asm_inturbo_mode_abx(void);
  void asm_inturbo_mode_abx_END(void);
  asm_copy(p_buf, asm_inturbo_mode_abx, asm_inturbo_mode_abx_END);
}

void
asm_emit_inturbo_mode_abx_check_page_crossing(struct util_buffer* p_buf) {
  void asm_inturbo_mode_abx_check_page_crossing(void);
  void asm_inturbo_mode_abx_check_page_crossing_END(void);
  asm_copy(p_buf,
           asm_inturbo_mode_abx_check_page_crossing,
           asm_inturbo_mode_abx_check_page_crossing_END);
}

void
asm_emit_inturbo_mode_aby(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_inturbo_mode_aby_check_page_crossing(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_inturbo_mode_zpx(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_inturbo_mode_zpy(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_inturbo_mode_idx(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_inturbo_mode_idy(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_inturbo_mode_idy_check_page_crossing(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_inturbo_mode_ind(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BCC_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BCC_interp_accurate(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BCS_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BCS_interp_accurate(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BEQ_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BEQ_interp_accurate(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BIT_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BMI_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BMI_interp_accurate(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BNE_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BNE_interp_accurate(struct util_buffer* p_buf) {
  void asm_instruction_BNE_interp(void);
  void asm_instruction_BNE_interp_END(void);
  asm_copy(p_buf, asm_instruction_BNE_interp, asm_instruction_BNE_interp_END);
}

void
asm_emit_instruction_BPL_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BPL_interp_accurate(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BRK_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BVC_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BVC_interp_accurate(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BVS_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_BVS_interp_accurate(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ADC_imm_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ADC_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ADC_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ALR_imm_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_AND_imm_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_AND_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_AND_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ASL_acc_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ASL_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ASL_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_CMP_imm_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_CMP_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_CMP_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_CPX_imm_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_CPX_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_CPY_imm_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_CPY_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_DEC_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_DEC_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_EOR_imm_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_EOR_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_EOR_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_INC_scratch_interp(struct util_buffer* p_buf) {
  void asm_instruction_INC_scratch_interp(void);
  void asm_instruction_INC_scratch_interp_END(void);
  asm_copy(p_buf,
           asm_instruction_INC_scratch_interp,
           asm_instruction_INC_scratch_interp_END);
}

void
asm_emit_instruction_INC_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_JMP_scratch_interp(struct util_buffer* p_buf) {
  void asm_instruction_JMP_scratch_interp(void);
  void asm_instruction_JMP_scratch_interp_END(void);
  asm_copy(p_buf,
           asm_instruction_JMP_scratch_interp,
           asm_instruction_JMP_scratch_interp_END);
}

void
asm_emit_instruction_JSR_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_LDA_imm_interp(struct util_buffer* p_buf) {
  void asm_instruction_LDA_imm_interp(void);
  void asm_instruction_LDA_imm_interp_END(void);
  asm_copy(p_buf,
           asm_instruction_LDA_imm_interp,
           asm_instruction_LDA_imm_interp_END);
}

void
asm_emit_instruction_LDA_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_LDA_scratch_interp_based(struct util_buffer* p_buf) {
  void asm_instruction_LDA_scratch_interp_based(void);
  void asm_instruction_LDA_scratch_interp_based_END(void);
  asm_copy(p_buf,
           asm_instruction_LDA_scratch_interp_based,
           asm_instruction_LDA_scratch_interp_based_END);
}

void
asm_emit_instruction_LDX_imm_interp(struct util_buffer* p_buf) {
  void asm_instruction_LDX_imm_interp(void);
  void asm_instruction_LDX_imm_interp_END(void);
  asm_copy(p_buf,
           asm_instruction_LDX_imm_interp,
           asm_instruction_LDX_imm_interp_END);
}

void
asm_emit_instruction_LDX_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_LDX_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_LDY_imm_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_LDY_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_LDY_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_LSR_acc_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_LSR_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_LSR_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ORA_imm_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ORA_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ORA_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ROL_acc_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ROL_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ROL_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ROR_acc_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ROR_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_ROR_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_RTI_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_RTS_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_SAX_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_SBC_imm_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_SBC_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_SBC_scratch_interp_based(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_SLO_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_STA_scratch_interp(struct util_buffer* p_buf) {
  void asm_instruction_STA_scratch_interp(void);
  void asm_instruction_STA_scratch_interp_END(void);
  asm_copy(p_buf,
           asm_instruction_STA_scratch_interp,
           asm_instruction_STA_scratch_interp_END);
}

void
asm_emit_instruction_STA_scratch_interp_based(struct util_buffer* p_buf) {
  void asm_instruction_STA_scratch_interp_based(void);
  void asm_instruction_STA_scratch_interp_based_END(void);
  asm_copy(p_buf,
           asm_instruction_STA_scratch_interp_based,
           asm_instruction_STA_scratch_interp_based_END);
}

void
asm_emit_instruction_STX_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}

void
asm_emit_instruction_STY_scratch_interp(struct util_buffer* p_buf) {
  (void) p_buf;
}
