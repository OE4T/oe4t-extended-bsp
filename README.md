# Extended BSP Layers for NVIDIA Jetson Platforms

This is a collection of third-party and non-official BSP (Board Support Package) layers for NVIDIA Jetson platforms. These layers provide support for hardware and configurations that fall outside the scope of the official [meta-tegra](https://github.com/OE4T/meta-tegra) BSP layer and are not officially supported by NVIDIA JetPack.

## Purpose

This project aims to collect and maintain:

- **Third-party Carrier Board BSPs**: Board support for non-NVIDIA-manufactured carrier boards and modules
- **Legacy Machine Configurations**: Support for older or discontinued Jetson modules and platforms
- **Community Extensions**: Custom board configurations and enhancements developed by the community

These layers extend the capabilities of the core meta-tegra layer by providing support for hardware platforms and use cases that fall outside the official NVIDIA ecosystem.

## Structure

See the `conf/layer.conf` file for layer dependencies and configuration details.

## Using These Layers

Branch names in this repository correspond to the branch names in [meta-tegra](https://github.com/OE4T/meta-tegra). Ensure you are using a compatible branch for your meta-tegra version.

To use these BSP layers in your Yocto/OpenEmbedded build:

1. Ensure the base `meta-tegra` layer is properly configured
2. Add the desired extended BSP layer to your `bblayers.conf`
3. Select your target machine in your `local.conf`

## Contributing

Contributions are welcome! When adding new BSP layers, please:

- Include comprehensive documentation in the layer's README
- Clearly specify machine compatibility and requirements
- Provide any necessary patches or recipes for third-party hardware
- Document any JetPack version dependencies or limitations

Please see the [meta-tegra README](https://github.com/OE4T/meta-tegra/blob/master/README.md) for general information on contributing to Tegra-based projects.

## Support

These layers are community-maintained and provided as-is. For issues specific to third-party hardware, please refer to the carrier board manufacturer's documentation. For issues related to the Yocto/OpenEmbedded integration, please open an issue in this repository.

## License

Each layer in this collection may have its own license. Please refer to the COPYING file in each layer for license information.
