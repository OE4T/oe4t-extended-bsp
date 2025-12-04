MACHINE_ESSENTIAL_EXTRA_RDEPENDS = "tegra-firmware ${TEGRA_ESSENTIAL_EXTRA_RDEPENDS} nvidia-kernel-oot-base"
MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS = "kernel-module-ina3221 kernel-module-lm90 kernel-module-tegra-bpmp-thermal kernel-module-spi-tegra114 kernel-module-pwm-fan \
                                       kernel-module-governor-userspace kernel-module-ucsi-ccg kernel-module-pcie-tegra194 kernel-module-phy-tegra194-p2u \
                                       kernel-module-nvme kernel-module-pwm-tegra kernel-module-tegra-xudc"
MACHINE_EXTRA_RDEPENDS = "tegra-nvphs tegra-nvs-service tegra-nvsciipc tegra-nvstartup tegra-nvfancontrol tegra-configs-udev tegra-redundant-boot nvidia-kernel-oot-display"
MACHINE_EXTRA_RRECOMMENDS = "kernel-module-snd-hda-tegra kernel-module-snd-hda-codec-hdmi nvidia-kernel-oot-cameras nvidia-kernel-oot-canbus"
