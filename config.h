/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
static const int interval = 1500;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function             description                     argument
 *
 * battery_perc         battery percentage              battery name
 * battery_power        battery power usage             battery name
 * battery_state        battery charging state          battery name
 * cpu_perc             cpu usage in percent            NULL
 * cpu_iowait           cpu iowait in percent           NULL
 * cpu_freq             cpu frequency in MHz            NULL
 * datetime             date and time                   format string
 * disk_free            free disk space in GB           mountpoint path
 * disk_perc            disk usage in percent           mountpoint path
 * disk_total           total disk space in GB          mountpoint path
 * disk_used            used disk space in GB           mountpoint path
 * entropy              available entropy               NULL
 * gid                  GID of current user             NULL
 * hostname             hostname                        NULL
 * ipv4                 IPv4 address                    interface name
 * ipv6                 IPv6 address                    interface name
 * kernel_release       `uname -r`                      NULL
 * keyboard_indicators  caps/num lock indicators        NULL
 * load_avg             load average                    format string
 * num_files            number of files in a directory  path
 * ram_free             free memory in GB               NULL
 * ram_perc             memory usage in percent         NULL
 * ram_total            total memory size in GB         NULL
 * ram_used             used memory in GB               NULL
 * run_command          custom shell command            command
 * swap_free            free swap in GB                 NULL
 * swap_perc            swap usage in percent           NULL
 * swap_total           total swap size in GB           NULL
 * swap_used            used swap in GB                 NULL
 * temp                 temperature in degree celsius   sensor file
 * uid                  UID of current user             NULL
 * uptime               system uptime                   NULL
 * username             username of current user        NULL
 * vol_perc             OSS/ALSA volume in percent      "/dev/mixer"
 * wifi_perc            WiFi signal in percent          interface name
 * wifi_essid           WiFi ESSID                      interface name
 */
static const struct arg args[] = {
	/* function format          argument */
	{ run_command, "%s", "~/bin/mpdsong.sh" },
	{ wifi_perc, " \ue21a %s", "wlp2s0" },
	{ wifi_essid, " %s ", "wlp2s0" },
    { run_command, " \ue05d%4s ", "amixer sget Master | awk -F\"[][]\" '/%/ { print $2 }' | head -n1" },
    { run_command, " \ue1c3%2s  ", "xbacklight -get |  awk '{print int($1)}'" },
	{ cpu_perc, "\ue027%s  ", NULL    },
	{ battery_state, "%s", "BAT1"    },
	{ battery_perc, "%3s%% ", "BAT1"    },
	{ datetime, "%s", " \ue266 %d/%m  \ue018 %H:%M " },
};