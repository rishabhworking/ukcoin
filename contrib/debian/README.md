
Debian
====================
This directory contains files used to package ukcoind/ukcoin-qt
for Debian-based Linux systems. If you compile ukcoind/ukcoin-qt yourself, there are some useful files here.

## ukcoin: URI support ##


ukcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install ukcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your ukcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/ukcoin128.png` to `/usr/share/pixmaps`

ukcoin-qt.protocol (KDE)

