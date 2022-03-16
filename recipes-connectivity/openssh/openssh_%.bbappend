require ${@bb.utils.contains('DISTRO_FEATURES', 'selinux', '${BPN}_selinux.inc', '', d)}

# if pam feature is enabled in the distro then take sshd from the pam directory.
FILESEXTRAPATHS_prepend := "${@bb.utils.contains('DISTRO_FEATURES', 'pam', '${THISDIR}/files/pam:', '', d)}"

do_install_append(){

    if [ "${@bb.utils.filter('DISTRO_FEATURES', 'pam', d)}" ]; then
        # Make sure UsePAM entry is in the sshd_config file.
        # If entry not present then append it.
        grep -q 'UsePAM' "${D}/etc/ssh/sshd_config" && \
        sed -i 's/.*UsePAM.*/UsePAM yes/' "${D}/etc/ssh/sshd_config" || \
        echo 'UsePAM yes' >> "${D}/etc/ssh/sshd_config"
    fi
}
