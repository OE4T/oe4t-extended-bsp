# Settings common to all Xavier (tegra194) SoCs

SOC_FAMILY = "tegra194"

require conf/machine/include/soc-family.inc
DEFAULTTUNE ?= "armv8a-crc"
require conf/machine/include/arm/arch-armv8-2a.inc

SERIAL_CONSOLES ?= "115200;ttyTCU0"

KERNEL_MODULE_AUTOLOAD ?= "nvmap nvgpu pwm-fan ina3221"

NVIDIA_CHIP = "0x19"
NVIDIA_BOARD = "t186ref"

TEGRA_BOARDID ?= "2888"
TEGRA_FAB ?= "400"
TEGRA_BOARDSKU ?= "0001"
TEGRA_BOARDREV ?= "H.0"
TEGRA_CHIPREV ?= "2"

TEGRA_CUDA_ARCHITECTURE ?= "72"

require conf/machine/include/tegra-common.inc
require conf/machine/include/tegra-common-r35.inc
require conf/machine/include/tegraflash_t194_fixups.inc

L4T_BSP_PREFIX = "Jetson"
L4T_DEB_SOCNAME_R35 = "t194"
L4T_DEB_SOCNAME = "t234"

OPTEE_NV_PLATFORM:tegra194 = "t194"

NVPMODEL ?= "nvpmodel_t194"
NVPOWER ?= "jetsonpower_t194"
NVFANCONTROL ?= "nvfancontrol_p2888"

PARTITION_LAYOUT_EXTERNAL_DEFAULT ?= "flash_l4t_nvme.xml"

TEGRA_BOOT_FIRMWARE_FILES = "\
    adsp-fw.bin \
    bpmp-2_t194.bin \
    camera-rtcpu-t194-rce.img \
    dram-ecc-t194.bin \
    mb1_t194_prod.bin \
    nvtboot_applet_t194.bin \
    nvtboot_t194.bin \
    preboot_c10_prod_cr.bin \
    mce_c10_prod_cr.bin \
    mts_c10_prod_cr.bin \
    nvtboot_cpu_t194.bin \
    nvtboot_recovery_t194.bin \
    nvtboot_recovery_cpu_t194.bin \
    spe_t194.bin \
    xusb_sil_rel_fw \
    warmboot_t194_prod.bin \
    sce_t194.bin \
    dram-ecc-t194.bin \
"

PREFERRED_VERSION_tegra-bootfiles = "35.6%"
PREFERRED_VERSION_tegra-tools = "35.6%"
PREFERRED_VERSION_tegra-redundant-boot-base = "35.6%"
# PREFERRED_VERSION_tegra-storage-layout = "35.6%"
# PREFERRED_VERSION_tegra-storage-layout-base = "35.6%"
PREFERRED_VERSION_tegra-nvpower = "35.6%"
PREFERRED_VERSION_tegra-flashtools-native = "35.6%"
PREFERRED_VERSION_tegra-firmware = "35.6%"

TEGRA_OPTEE_VERSION = "3.21.0-l4t%"
PREFERRED_VERSION_optee-os = "${TEGRA_OPTEE_VERSION}"
PREFERRED_VERSION_optee-os-tadevkit = "${TEGRA_OPTEE_VERSION}"
PREFERRED_VERSION_optee-client = "${TEGRA_OPTEE_VERSION}"
PREFERRED_VERSION_optee-test = "${TEGRA_OPTEE_VERSION}"
PREFERRED_VERSION_optee-samples = "35.6%"

PREFERRED_VERSION_edk2-basteools-tegra-native = "35.6%"
PREFERRED_VERSION_edk2-firmware-tegra = "35.6%"
PREFERRED_VERSION_standalone-mm-optee-tegra = "35.6%"

PREFERRED_PROVIDER_virtual/dtb:tegra194 ?= "tegra194-devicetrees"
PREFERRED_PROVIDER_virtual/kernel:tegra194 ?= "linux-yocto"
PREFERRED_RPROVIDER_tegra-gbm-backend = "tegra-udrm-gbm"
PREFERRED_RPROVIDER_kernel-module-tegra-drm = "kernel-module-tegra-drm"

TEGRA_FLASHVARS:append:tegra194 = " EMMC_CFG MISC_COLD_BOOT_CONFIG SCR_COLD_BOOT_CONFIG"
TEGRA_FLASHVAR_UEFI_IMAGE = "uefi_jetson"
TEGRA_FLASHVAR_RCM_UEFI_IMAGE = "uefi_jetson"

UBOOT_EXTLINUX_FDT = "/boot/${DTBFILE}"

TOSIMGFILENAME:tegra194 = "tos-optee_t194.img"
TEGRA_RCM_EDK2_DEPENDS = ""
