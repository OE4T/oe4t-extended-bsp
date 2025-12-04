NVDISPLAY_INIT = ""
NVDISPLAY_INIT:tegra194 = "${DEPLOY_DIR_IMAGE}/nvdisp-init.bin"
NVDISPLAY_INIT_DEPS = ""
NVDISPLAY_INIT_DEPS:tegra194 = "nvdisp-init:do_deploy"

do_compile:append:tegra194() {
    if [ -n "${NVDISPLAY_INIT}" -a ${@'false' if bb.utils.to_boolean(d.getVar('TEGRA_UEFI_MINIMAL')) else 'true'} ]; then
        cat "${NVDISPLAY_INIT}" ${B}/images/${EDK2_BIN_NAME} > ${B}/images/${EDK2_BIN_NAME}.tmp
        # cat ${B}/images/${EDK2_BIN_NAME} > ${B}/images/${EDK2_BIN_NAME}.tmp
        mv ${B}/images/${EDK2_BIN_NAME}.tmp ${B}/images/${EDK2_BIN_NAME}
    fi
}

do_compile[depends] += "${NVDISPLAY_INIT_DEPS}"
