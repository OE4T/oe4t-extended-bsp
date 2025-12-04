DESCRIPTION = "Virtual/dtb provider for tegra194 device trees"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

inherit devicetree

COMPATIBLE_MACHINE = "(tegra194)"

SRC_URI = "\
    git://github.com/oe4t/tegra194-devicetrees.git;protocol=https;branch=master;name=oe4t;destsuffix=git/oe4t \
"

SRCREV = "8d8db474a53a080864dda0b0adb2f78966966b31"

S = "${WORKDIR}/git"
DT_FILES_PATH:xavier-nx = "${S}/oe4t/platform/t19x/jakku/kernel-dts"
DT_FILES_PATH:xavier-agx = "${S}/oe4t/platform/t19x/galen/kernel-dts"

DT_INCLUDE:append = " \
    ${S}/oe4t/soc/tegra/kernel-include \
    ${S}/oe4t/platform/t19x/common/kernel-dts \
    ${S}/oe4t/platform/tegra/common/kernel-dts \
    ${S}/oe4t/soc/t19x/kernel-include \
    ${S}/oe4t/soc/t19x/kernel-dts \
"

# re-implement function from devicetree.bbclass to preserve order of KERNEL_INCLUDE
def expand_includes(varname, d):
    import glob
    includes = list()
    # expand all includes with glob
    for i in (d.getVar(varname) or "").split():
        for g in glob.glob(i):
            if os.path.isdir(g): # only add directories to include path
                includes.append(g)
    return includes

