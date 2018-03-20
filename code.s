ldr r0, =12
mov r3 #50
ldr r1, [r0, #2]
LDR r2  [r1,#16]
ADD r0, r1, r2
str r0 #14
str r1, [r0, #0]
str r2, [r0,#1]
mul r0, r1, #3