cmd_kernel/sys_ni.o :=  /home/sebastian/android/sabermod/bin/arm-linux-androideabi-gcc -Wp,-MD,kernel/.sys_ni.o.d  -nostdinc -isystem /home/sebastian/android/sabermod/bin/../lib/gcc/arm-linux-androideabi/4.9.0/include -I/home/sebastian/android/kernel/kernel/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include include/generated/autoconf.h  -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/config/product/include/hi6620cs_oem_gutl_dsda -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/config/product/define/hi6620cs_oem_gutl_dsda/config -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/config/nvim/include/gu -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/platform/hi6620cs_asic -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/modem/drv/hi6620/src/comm/inc -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/modem/drv/common/src/comm/inc -I/home/sebastian/android/kernel/kernel/include/hisi/ -I/home/sebastian/android/kernel/kernel/drivers/ -I/home/sebastian/android/kernel/kernel/mm/ -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/include/drv -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/include/drv/MODULE_H -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/include/med -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/include/nv/gu/drv -I/home/sebastian/android/kernel/kernel/drivers/gpu/mali/platform/balong/ -I/home/sebastian/android/kernel/kernel/drivers/gpu/mali/common/ -I/home/sebastian/android/kernel/kernel/drivers/gpu/mali/linux/ -I/home/sebastian/android/kernel/kernel/drivers/hisi/nvim -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/external/efipartition  -I/home/sebastian/android/kernel/kernel/../external/efipartition -I/home/sebastian/android/kernel/kernel/../external/dx/codesafe/src/secure_boot/boot_images_verifier -I/home/sebastian/android/kernel/kernel/../external/dx/host/src/sbromlib -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-hi6620/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -DBSP_CORE_APP -DBSP_COMPILE_ALLY -DBOARD_ASIC -O2 -marm -fno-dwarf2-cfi-asm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=7 -march=armv7-a -msoft-float -Uarm -Wframe-larger-than=1024 -fno-stack-protector -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO    -DBSP_CORE_APP -DBSP_COMPILE_ALLY -DBOARD_ASIC -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(sys_ni)"  -D"KBUILD_MODNAME=KBUILD_STR(sys_ni)" -c -o kernel/sys_ni.o kernel/sys_ni.c

source_kernel/sys_ni.o := kernel/sys_ni.c

deps_kernel/sys_ni.o := \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  /home/sebastian/android/kernel/kernel/arch/arm/include/asm/linkage.h \
  include/linux/errno.h \
  /home/sebastian/android/kernel/kernel/arch/arm/include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  /home/sebastian/android/kernel/kernel/arch/arm/include/asm/unistd.h \
    $(wildcard include/config/aeabi.h) \
    $(wildcard include/config/oabi/compat.h) \

kernel/sys_ni.o: $(deps_kernel/sys_ni.o)

$(deps_kernel/sys_ni.o):
