[ -f /home/vathana/DriveD/vathana/project/koompi-os-panel/plugin-actioncenter/resources/actioncenter.desktop.in ] || exit 0
echo '[lxqt.actioncenter_desktop]'
echo 'type = DESKTOP'
echo 'source_lang = en'
echo 'source_file = plugin-actioncenter/resources/actioncenter.desktop.in'
echo 'file_filter = plugin-actioncenter/translations/actioncenter_<lang>.desktop'
echo ''
