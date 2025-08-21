inherit enable-selinux enable-audit

FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += " \
    file://50-selinux.conf \
"

do_install:append() {
    install -d ${D}${sysconfdir}/ssh/sshd_config.d
    install -m 0644 ${UNPACKDIR}/50-selinux.conf \
        ${D}${sysconfdir}/ssh/sshd_config.d/50-selinux.conf
}

FILES:${PN}-sshd:append = " ${sysconfdir}/ssh/sshd_config.d/50-selinux.conf"

PACKAGECONFIG[selinux] = "--with-selinux,--without-selinux,libselinux"
PACKAGECONFIG[audit] = "--with-audit=linux,--without-audit,audit"
