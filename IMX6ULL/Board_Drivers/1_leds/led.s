.global _start @全局标号

_start:
    /*使能所有外设时钟 */
    ldr r0, =0x020C4068
    ldr r1, =0xFFFFFFFF
    str r1, [r0]

    ldr r0, =0x020C406C
    str r1, [r0]

    ldr r0, =0x020C4070
    str r1, [r0]

    ldr r0, =0x020C4074
    str r1, [r0]

    ldr r0, =0x020C4078
    str r1, [r0]

    ldr r0, =0x020C407C
    str r1, [r0]

    ldr r0, =0x020C4080
    str r1, [r0]

    /*复用GPIO_IO03_PIN为GPIO */
    ldr r0, =0x020E0068
    ldr r1, =0x00000005
    str r1, [r0]

    /*配置电气属性GPIO1_IO03，地址：20E_02F4h */
    ldr r0, =0x020E02F4
    ldr r1, =0x10B0
    str r1, [r0]

    /*配置GPIO1_GDIR：209_C004 GPIO1_GPIO03为输出*/
    ldr r0, =0x0209C004
    ldr r1, =0x00000008
    str r1, [r0]

    /*配置数据寄存器GPIO1_GPIOI03地址：0x0209_C000 */
    ldr r0, =0x0209C000
    ldr r1, =0
    str r1, [r0]

loop:
    b loop
