#! /usr/bin/env bash

for f in $@ ; do
  if  test -f "${f}" ; then
    echo "processing '${f}' "
    unifdef -B \
      -o${f} \
      -DCRYPTO_EXTPKG_MOD \
     ${f}
  fi
done

exit
