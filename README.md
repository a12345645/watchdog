# watchdog
This is a watchdog service for sch311x chip.<br>
The timer was set for 20 seconds.<br>
No motion before 20 seconds will reboot.<br>

## Install
1. Move the folder to a fixed place.
2. Run `install.sh` as the root user.
```
sudo ./install.sh
```
3. Reboot!

## Result
After installation, you will see the new system service `watchdog.service` be enabled on boot.<br>
It will reflash the watchdog timer.<br>
If the service crash and the watchdog timer count to 0, the system will reboot.<br>

## Reference
https://www.796t.com/content/1550356580.html<br>
https://github.com/torvalds/linux/blob/master/drivers/watchdog/sch311x_wdt.c<br>
