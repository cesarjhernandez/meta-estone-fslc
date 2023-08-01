SUMMARY = "DSP firmware for Estone Technology, Inc."

LICENSE = "CLOSED"

SRC_URI = "file://cs47l24-dsp2-misc.wmfw \
           file://cs47l24-dsp3-misc.wmfw \
           file://cs47l24-dsp3-misc.bin \
           file://rtl8168e-3.fw"

S = "${WORKDIR}"

do_install() {
    install -d ${D}/lib/firmware
    install -m 777 cs47l24-dsp2-misc.wmfw ${D}/lib/firmware/cs47l24-dsp2-misc.wmfw
    install -m 777 cs47l24-dsp3-misc.wmfw ${D}/lib/firmware/cs47l24-dsp3-misc.wmfw
    install -m 777 cs47l24-dsp3-misc.bin ${D}/lib/firmware/cs47l24-dsp3-misc.bin
    install -m 777 rtl8168e-3.fw ${D}/lib/firmware/rtl8168e-3.fw
}

FILES_${PN} += "/lib/firmware/cs47l24-dsp2-misc.wmfw"
FILES_${PN} += "/lib/firmware/cs47l24-dsp3-misc.wmfw"
FILES_${PN} += "/lib/firmware/cs47l24-dsp3-misc.bin"
FILES_${PN} += "/lib/firmware/rtl8168e-3.fw"
