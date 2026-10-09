#!/bin/bash
sudo ip route del default via 10.100.78.1 dev ens33
sudo ip route add default via 10.100.78.1 dev ens33 metric 100
route -n
