FILESEXTRAPATHS:prepend:tegra194 := "${THISDIR}/${BPN}:"

ESPVARDIR:tegra194 ?= "${ESPMOUNT}/EFI/NVDA/Variables"
TNSPEC_COMPAT_MACHINE ??= "${TNSPEC_MACHINE}"

do_compile:append:tegra194() {

    sed -i -e's,@ESPMOUNT@,${ESPMOUNT},g' \
        -e's,@NVIDIA_ESPMOUNT@,${ESPMOUNT},g' \
        -e's,@ESPVARDIR@,${ESPVARDIR},g' \
        ${B}/uefi_common.func

    sed -i -e's,@ESPMOUNT@,${ESPMOUNT},g' \
        ${B}/setup-nv-boot-control.service

    sed -i -e's,@ESPMOUNT@,${ESPMOUNT},g' \
        ${B}/setup-nv-boot-control.init
}
