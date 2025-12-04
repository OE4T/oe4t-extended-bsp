# meta-tegra194 Layer

This is a Yocto/OE BSP layer for NVIDIA Jetson AGX Xavier and Xavier NX platforms.

## Overview

The meta-tegra194 layer provides board support for the following NVIDIA Jetson tegra194-based machines:

- `jetson-agx-xavier-devkit` - Jetson AGX Xavier Developer Kit
- `jetson-agx-xavier-industrial` - Jetson AGX Xavier Industrial
- `jetson-xavier-nx-devkit` - Jetson Xavier NX Developer Kit
- `jetson-xavier-nx-devkit-emmc` - Jetson Xavier NX Developer Kit with eMMC

## Dependencies

This layer depends on:
- `meta-tegra` - Base NVIDIA Tegra BSP layer

## Status

This layer is still under development and should be considered incomplete. It is intended to:

- Port the necessary boot binaries from NVIDIA JetPack 5 for tegra194 platforms
- Use the `linux-yocto` kernel with NVIDIA's out-of-tree modules

## Adding the Layer to Your Build

Run the following command to add the layer to your build:

```bash
bitbake-layers add-layer oe4t-extended-bsp/meta-tegra194
```

Then configure your `local.conf` to select your target machine:

```bash
MACHINE = "jetson-agx-xavier-devkit"
```
