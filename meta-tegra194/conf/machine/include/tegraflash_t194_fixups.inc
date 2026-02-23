tegraflash_generate_bupgen_script:append:tegra194() {
    # t194 MB1 doesn't accept signatures for BCT, so we shouldn't be signing the bup contents.
    # This restores the behavior from r35

    sed -i 's/ --sign//' "$outfile"
}

tegraflash_populate_package:append:tegra194() {

    cp mb1_t194_prod.bin mb1_b_t194_prod.bin
    cp -R ${STAGING_DATADIR}/nv_tegra/rollback/t19x ./rollback/
    cp ${STAGING_DATADIR}/tegraflash/tegra19[4x]-*.cfg .
    cp ${STAGING_DATADIR}/tegraflash/tegra194-*-bpmp-*.dtb .

    if [ -e ${STAGING_DATADIR}/tegraflash/odmfuse_pkc_${MACHINE}.xml ]; then
        cp ${STAGING_DATADIR}/tegraflash/odmfuse_pkc_${MACHINE}.xml ./odmfuse_pkc.xml
    fi
}

tegraflash_custom_pre:append:tegra194() {
    if [ -e ./odmfuse_pkc.xml ]; then
        cat > burnfuses.sh <<END
#!/bin/sh
MACHINE=${TNSPEC_MACHINE} ./tegra-flash-helper.sh -c "burnfuses odmfuse_pkc.xml" --no-flash $DATAARGS flash.xml.in ${DTBFILE} ${EMMC_BCTS} ${ODMDATA} ${LNXFILE} ${IMAGE_BASENAME}.${IMAGE_TEGRAFLASH_FS_TYPE} "\$@"
END
        chmod +x burnfuses.sh
    fi
}

do_image_tegraflash_tar[depends] += "tegra-redundant-boot-rollback:do_populate_sysroot"

# missing from these fixups is a mod to create_tegraflash_pkg() to add the variable 
# BOOT_PARTITIONS_ON_EMMC=${BOOT_PARTITIONS_ON_EMMC}
# to the contents of .env.initrd-flash. It's not apparent this is used anywhere.
