#!/bin/bash
systemctl list-unit-files | grep watchdog.service
if [ "$?" -eq 0 ]; then
    systemctl disable watchdog.service
    rm /etc/systemd/system/watchdog.service
    systemctl daemon-reload
    echo  -e "\033[32m Complete!\033[0m"
else
    echo  -e "\033[31m watchdog service isn't exist.\033[0m"
fi