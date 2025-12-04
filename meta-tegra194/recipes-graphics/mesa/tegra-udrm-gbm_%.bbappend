do_install:append:tegra194() {
    ln -s tegra-udrm_gbm.so ${D}${libdir}/gbm/tegra_gbm.so
}
