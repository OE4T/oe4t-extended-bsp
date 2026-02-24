FILESEXTRAPATHS:prepend:tegra194 := "${THISDIR}/${PN}:"

SRC_URI:append:tegra194 = " file://0001-flash-helper-support-tegra194.patch"
