DESCRIPTION = "Tegra-specific firmware from the L4T BSP"
L4T_DEB_COPYRIGHT_MD5 = "e29dee9e20f35e3193d929de8b69873b"

L4T_DEB_TRANSLATED_BPN = "nvidia-l4t-firmware"

require tegra-debian-libraries-common-r35.inc

COMPATIBLE_MACHINE = "(tegra194)"

MAINSUM = "23868b5ff85ed4b6198e22b60ad0f846e2a5ba9f068bb62bdc1b8a8133a92b8e"

do_install() {
    install -d ${D}${nonarch_base_libdir}/firmware
    cp -R -f ${S}/lib/firmware/gv11b ${D}${nonarch_base_libdir}/firmware
}

FILES:${PN} = "${nonarch_base_libdir}/firmware/gv11b"

INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_SYSROOT_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"
PACKAGE_ARCH = "${SOC_FAMILY_PKGARCH}"
