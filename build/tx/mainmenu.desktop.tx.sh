[ -f /home/vathana/DriveD/vathana/project/koompi-os-panel/plugin-mainmenu/resources/mainmenu.desktop.in ] || exit 0
echo '[lxqt.mainmenu_desktop]'
echo 'type = DESKTOP'
echo 'source_lang = en'
echo 'source_file = plugin-mainmenu/resources/mainmenu.desktop.in'
echo 'file_filter = plugin-mainmenu/translations/mainmenu_<lang>.desktop'
echo ''
