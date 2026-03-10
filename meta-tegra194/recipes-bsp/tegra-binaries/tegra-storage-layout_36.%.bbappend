# Applies any fixed, per-SoC rewrites.  Consult the flash.sh script
# and conf files in the L4T kit for how these are derived.
copy_in_flash_layout:tegra194() {
    local srcfile="$1"
    local dstfile="$2"
    cp "$srcfile" "$dstfile"
    # Multiple seds here since the 2nd occurrence of MB1FILE
    # gets a different rewrite than the first
    sed -i -e':a;N;$!ba;s,MB1FILE,mb1_b_t194_prod.bin,2' "$dstfile"
    sed -i -e"s,TEGRABOOT,nvtboot_t194.bin," \
            -e"s,MTSPREBOOT,preboot_c10_prod_cr.bin," \
            -e"s,MTS_MCE,mce_c10_prod_cr.bin," \
            -e"s,MTSPROPER,mts_c10_prod_cr.bin," \
            -e"s,SCEFILE,sce_t194.bin," \
            -e"s,MB1FILE,mb1_t194_prod.bin," \
            -e"s,BPFFILE,bpmp-2_t194.bin," \
            -e"s,TBCFILE,uefi_jetson.bin," \
            -e"s,CAMERAFW,camera-rtcpu-t194-rce.img," \
            -e"s,DRAMECCTYPE,dram_ecc," -e"s,DRAMECCFILE,dram-ecc-t194.bin," -e"s,DRAMECCNAME,dram-ecc-fw," \
            -e"s,BADPAGETYPE,black_list_info," -e"s,BADPAGEFILE,badpage.bin," -e"s,BADPAGENAME,badpage-fw," \
            -e"s,SPEFILE,spe_t194.bin," \
            -e"s,WB0BOOT,warmboot_t194_prod.bin," \
            "$dstfile"
}
