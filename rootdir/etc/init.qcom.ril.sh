#!/system/bin/sh
export PATH=/system/xbin:$PATH

device=`getprop ro.product.name`

if [ "$device" = "trlteduosctc" ]; then
    stop ril-daemon1
    start ril-daemon1-09w
fi

