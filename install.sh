path=`pwd`
target=(".", "..", "feed_dog.sh", "feed_dog")

# # create systen service
# echo "[Unit]
# Description=watchdog

# [Service]
# ExecStart=sh $path/feed_dog.sh
# Restart=always
# RestartSec=10s
# TimeoutSec=infinity

# [Install]
# WantedBy=multi-user.target" > watchdog.service


# cp watchdog.service /etc/systemd/system/watchdog.service
# chmod 644 /etc/systemd/system/watchdog.service
# systemctl daemon-reload
# systemctl enable watchdog.service

# make

# if [ -f "/lib/modules/`uname -r`/kernel/drivers/watchdog/sch311x_wdt.ko" ]; then
#     modules_path="/lib/modules/\`uname -r\`/kernel/drivers/watchdog/sch311x_wdt.ko"
# else
#     modules_path="$path/sch311x_wdt.ko"
#     target += ("sch311x_wdt.ko")
# fi

# echo "lsmod | grep sch311x_wdt
# if [ "\$?" -eq 0 ]
# then
#     NOW=\$( date '+%F_%H:%M:%S' )
#     echo \$NOW watchdog driver is exist  >> $path/log.txt
# else
#     insmod $modules_path
#     if [ "\$?" -ne 0 ]
#     then
#         NOW=$( date '+%F_%H:%M:%S' )
#         echo \$NOW load watchdog driver error >> $path/log.txt
#     else
#         NOW=$( date '+%F_%H:%M:%S' )
#         echo \$NOW load watchdog driver successfully >> $path/log.txt
#     fi
# fi
# $path/feed_dog"> feed_dog.sh

# chmod +x feed_dog.sh

rmf=`ls -a | tr ',' ' '`

for i in $rmf
do
    echo $i
done

echo  -e "\033[32m Complete the installation after reboot\033[0m"