FILESEXTRAPATHS:prepend:tegra194 := "${THISDIR}/${BPN}:"

SRC_URI:append:tegra194 = " \
    file://tegra194.cfg \
"

KERNEL_FEATURES:append:tegra194 = " \
    cgl/features/audit/audit.scc \
"
