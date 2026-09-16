inherit ${@bb.utils.contains('DISTRO_FEATURES', 'selinux', 'enable-selinux', '', d)}

PACKAGECONFIG:class-native:append = " ${@bb.utils.filter('DISTRO_FEATURES', 'selinux', d)}"
