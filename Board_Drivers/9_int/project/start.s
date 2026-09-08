
.global _start

_start:
    ldr pc, =Reset_Handler
    ldr pc, =Undefined_Handler
    ldr pc, =SVC_Handler
    ldr pc, =PreAbort_Handler
    ldr pc, =DataAbort_Handler
    ldr pc, =NotUsed_Handler
    ldr pc, =IRQ_Handler
    ldr pc, =FIQ_Handler

Reset_Handler:

    cpsid i         /* 关闭IRQ */

    /*关闭I、D cache */
    MRC p15, 0, r0, c1, c0, 0
    bic r0, r0, #(1 << 12)
    bic r0, r0, #(1 << 11)
    bic r0, r0, #(1 << 2)
    bic r0, r0, #(1 << 1)
    bic r0, r0, #(1 << 0)
    MCR p15, 0, r0, c1, c0, 0
#if 0
    /*设置中断向量偏移 */
    ldr r0, =0x87800000
    dsb
    isb
    MCR p15, 0, r0, c12, c0, 0
    dsb
    isb
#endif
.global _bss_start
_bss_start:
    .word _bss_start

.global _bss_end
_bss_end:
    .word _bss_end
    /*清除bss段 */
    ldr r0, _bss_start
    ldr r1, _bss_end
    mov r2, #0
bss_loop:
    stmia r0!, {r2}
    cmp r0, r1
    ble bss_loop

/*设置管理器进入IRQ模式 */
    mrs r0, cpsr
    bic r0, r0, #0x1f
    orr r0, r0, #0x12
    msr cpsr, r0
    ldr sp, =0x80600000

/*设置管理器进入SYS模式 */
    mrs r0, cpsr
    bic r0, r0, #0x1f
    orr r0, r0, #0x1f
    msr cpsr, r0
    ldr sp, =0x80400000


/*设置管理器进入SVC模式 */
    mrs r0, cpsr
    bic r0, r0, #0x1f
    orr r0, r0, #0x13
    msr cpsr, r0
    ldr sp, =0x80200000
    
    cpsie i         /*打开IRQ */
    b main          /*跳转到main函数 */

Undefined_Handler:
    ldr r0, =Undefined_Handler
    bx r0

SVC_Handler:
    ldr r0, =SVC_Handler
    bx r0

PreAbort_Handler:
    ldr r0, =PreAbort_Handler
    bx r0
    
DataAbort_Handler:
    ldr r0, =DataAbort_Handler
    bx r0

NotUsed_Handler:
    ldr r0, =NotUsed_Handler
    bx r0

IRQ_Handler:
    push {lr}       /*保存lr地址 */
    push {r0-r3, r12}       /*保存r0-r3，r12寄存器 */

    mrs r0, spsr        /*读取spsr寄存器 */
    push {r0}       /*保存spsr寄存器 */

    mrc p15, 4, r1, c15, c0, 0  /*从cp15的c0寄存器内的值到r1寄存器中 */

    add r1, r1, #0x2000     /*GIC基地址加0x2000，也就是GIC的CPU接口端基地址*/
    ldr r0, [r1, #0xC]      /* GIC的CPU接口端基地址加0x0C就是GICC_IAR寄存器
                            * GICC_IAR寄存器保存当前发生中断的中断号，用这个
                            * 中断号决定调用哪个中断函数 */
    push {r0, r1}
    cps #0x13           /*进入SVC模式，允许其他中断再次进去 */

    push {lr}           /*保存SVC模式的lr寄存器 */
    ldr r2, =system_irqhandler /*加载c语言中断处理函数到r2寄存器中 */
    blx r2              /* 运行c语言中断处理函数，带有一个参数，保存在r0 */

    pop {lr}            /*执行完c语言中断服务函数，lr出栈 */
    cps #0x12           /*进入IRQ模式 */
    pop {r0, r1}
    str r0, [r1, #0x10] /*中断执行完成，写EOIR */

    pop {r0}
    msr spsr_cxsf, r0   /*恢复spsr */

    pop {r0-r3, r12}
    pop {lr}
    subs pc, lr, #4     /*将lr-4赋给pc */


FIQ_Handler:
    ldr r0, =FIQ_Handler
    bx r0




