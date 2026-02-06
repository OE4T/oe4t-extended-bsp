require tegra-binaries-${PV}.inc
require tegra-shared-binaries-r35.inc

PACKAGE_ARCH = "${SOC_FAMILY_PKGARCH}"

inherit nopackages

do_configure() {
	:
}
do_compile() {
	:
}

do_install() {
	:
}

do_install:append:tegra194() {
	install -d ${D}${datadir}/nv_tegra/rollback/t19x
	install -m 0644 ${S}/bootloader/rollback/t19x/rollback.cfg ${D}${datadir}/nv_tegra/rollback/t19x/
}

PACKAGES = "${PN}-dev"
FILES:${PN}-dev = "${datadir}"
RRECOMMENDS:${PN}-dev = ""
