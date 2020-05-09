#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

UKCD=${UKCD:-$SRCDIR/ukcoind}
UKCCLI=${UKCCLI:-$SRCDIR/ukcoin-cli}
UKCTX=${UKCTX:-$SRCDIR/ukcoin-tx}
UKCQT=${UKCQT:-$SRCDIR/qt/ukcoin-qt}

[ ! -x $UKCD ] && echo "$UKCD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
UKCVER=($($UKCCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for ukcoind if --version-string is not set,
# but has different outcomes for ukcoin-qt and ukcoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$UKCD --version | sed -n '1!p' >> footer.h2m

for cmd in $UKCD $UKCCLI $UKCTX $UKCQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${UKCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${UKCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
