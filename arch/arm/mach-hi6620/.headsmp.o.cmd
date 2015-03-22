cmd_arch/arm/mach-hi6620/headsmp.o :=  /home/sebastian/android/sabermod/bin/arm-linux-androideabi-gcc -Wp,-MD,arch/arm/mach-hi6620/.headsmp.o.d  -nostdinc -isystem /home/sebastian/android/sabermod/bin/../lib/gcc/arm-linux-androideabi/4.9.0/include -I/home/sebastian/android/kernel/kernel/arch/arm/include -Iarch/arm/include/generated -Iinclude  -include include/generated/autoconf.h  -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/config/product/include/hi6620cs_oem_gutl_dsda -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/config/product/define/hi6620cs_oem_gutl_dsda/config -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/config/nvim/include/gu -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/platform/hi6620cs_asic -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/modem/drv/hi6620/src/comm/inc -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/modem/drv/common/src/comm/inc -I/home/sebastian/android/kernel/kernel/include/hisi/ -I/home/sebastian/android/kernel/kernel/drivers/ -I/home/sebastian/android/kernel/kernel/mm/ -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/include/drv -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/include/drv/MODULE_H -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/include/med -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/include/nv/gu/drv -I/home/sebastian/android/kernel/kernel/drivers/gpu/mali/platform/balong/ -I/home/sebastian/android/kernel/kernel/drivers/gpu/mali/common/ -I/home/sebastian/android/kernel/kernel/drivers/gpu/mali/linux/ -I/home/sebastian/android/kernel/kernel/drivers/hisi/nvim -I/home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/external/efipartition  -I/home/sebastian/android/kernel/kernel/../external/efipartition -I/home/sebastian/android/kernel/kernel/../external/dx/codesafe/src/secure_boot/boot_images_verifier -I/home/sebastian/android/kernel/kernel/../external/dx/host/src/sbromlib -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-hi6620/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork  -D__LINUX_ARM_ARCH__=7 -march=armv7-a  -include asm/unified.h -msoft-float -gdwarf-2        -DBSP_CORE_APP -DBSP_COMPILE_ALLY -DBOARD_ASIC -c -o arch/arm/mach-hi6620/headsmp.o arch/arm/mach-hi6620/headsmp.S

source_arch/arm/mach-hi6620/headsmp.o := arch/arm/mach-hi6620/headsmp.S

deps_arch/arm/mach-hi6620/headsmp.o := \
  /home/sebastian/android/kernel/kernel/arch/arm/include/asm/unified.h \
    $(wildcard include/config/arm/asm/unified.h) \
    $(wildcard include/config/thumb2/kernel.h) \
  include/linux/linkage.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  /home/sebastian/android/kernel/kernel/arch/arm/include/asm/linkage.h \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  arch/arm/mach-hi6620/include/mach/pwrctrl/pwrctrl_sleepasm.h \
  /home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/platform/hi6620cs_asic/soc_baseaddr_interface.h \
  /home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/modem/drv/hi6620/src/comm/inc/pwrctrl_multi_memcfg.h \
  /home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/modem/drv/hi6620/src/comm/inc/pwrctrl_multi_dfs_asm.h \
  /home/sebastian/android/kernel/kernel/drivers/hisi/modem/include/vendor/hisi/config/product/include/hi6620cs_oem_gutl_dsda/global_ddr_map.h \

arch/arm/mach-hi6620/headsmp.o: $(deps_arch/arm/mach-hi6620/headsmp.o)

$(deps_arch/arm/mach-hi6620/headsmp.o):
