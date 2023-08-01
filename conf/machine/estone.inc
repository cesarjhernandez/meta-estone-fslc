require estone-mirrors.inc
INHERIT += "image-buildinfo"

MACHINE_FEATURES += " pci bluetooth wifi"

IMX_DEFAULT_BSP = "nxp"

USE_VT = "0"

DEFAULTTUNE_mx8mm  ?= "cortexa53-crypto"

# Use i.MX Gstreamer Version
MACHINE_GSTREAMER_1_0_PLUGIN_mx8 = "imx-gst1.0-plugin"
PREFERRED_VERSION_gstreamer1.0_mx8 = "1.16.imx"
PREFERRED_VERSION_gstreamer1.0-plugins-base_mx8 = "1.16.imx"
PREFERRED_VERSION_gstreamer1.0-plugins-good_mx8 = "1.16.imx"
PREFERRED_VERSION_gstreamer1.0-plugins-bad_mx8 = "1.16.imx"

# Add VPU and Cortex M4/M7 firmware
MACHINE_FIRMWARE_append_mx8 = " \
	firmware-imx-vpu-imx8 \
	"

MACHINE_EXTRA_RDEPENDS += " \
	gptfdisk \
	hostapd \
	hdparm \
	imx-kobs \
	iw \
	kernel-modules \
	kmod \
	${@bb.utils.contains('DISTRO', 'b2qt', '', \
           bb.utils.contains('DISTRO_FEATURES', 'wayland', 'networkmanager', \
                                                       '', d), d)} \
	packagegroup-tools-bluetooth \
	bluez-alsa \
	pm-utils \
	rng-tools \
	wpa-supplicant \
	wireless-regdb-static \
"

IMAGE_FSTYPES = "tar.gz wic.gz tar.bz2"

# Wayland based distros add systemd to DISTRO_FEATURES
# Remove sysvinit or systemd based on DISTRO_FEATURES to avoid conflicts
DISTRO_FEATURES_BACKFILL_CONSIDERED_append = "${@bb.utils.contains('DISTRO_FEATURES', 'systemd', ' sysvinit', '', d)}"
DISTRO_FEATURES_BACKFILL_CONSIDERED_append = "${@bb.utils.contains('DISTRO_FEATURES', 'sysvinit', ' systemd', '', d)}"

# Use bluez-alsa instead of pulseaudio
DISTRO_FEATURES_BACKFILL_CONSIDERED_append = " pulseaudio"
