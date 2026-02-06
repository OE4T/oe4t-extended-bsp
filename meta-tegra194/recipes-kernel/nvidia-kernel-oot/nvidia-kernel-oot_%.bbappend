FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append:tegra194 = " \
    file://0001-tegra194-actmon-fix-set-up-of-mc-utils-and-actmon.patch;patchdir=nvidia-oot \
    file://0002-drm-tegra-dp-initialize-displayport-preferring-wides.patch;patchdir=nvidia-oot \
    file://0003-drm-tegra-hub-disable-SRGB-degamma-in-absence-of-CMU.patch;patchdir=nvidia-oot \
    file://0004-gpu-host1x-fence-add-tegra194-to-module-device-table.patch;patchdir=nvidia-oot \
"
