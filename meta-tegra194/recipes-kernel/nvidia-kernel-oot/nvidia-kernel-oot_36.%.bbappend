FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://0001-tegra194-actmon-fix-set-up-of-mc-utils-and-actmon.patch \
    file://0002-drm-tegra-dp-initialize-displayport-preferring-wides.patch \
    file://0003-drm-tegra-hub-disable-SRGB-degamma-in-absence-of-CMU.patch \
    file://0004-gpu-host1x-fence-add-tegra194-to-module-device-table.patch \
"
