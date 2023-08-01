FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI_append_imx8mm-est-4910 = " file://usb-power.rules"

do_install_append_imx8mm-est-4910 () {
        install -d ${D}${sysconfdir}/udev/rules.d
        install -m 0644 ${WORKDIR}/usb-power.rules ${D}${sysconfdir}/udev/rules.d/
}

