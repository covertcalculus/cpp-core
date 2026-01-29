#!/usr/bin/env bash
theDir="$(realpath "${BASH_SOURCE[0]}")"
theDir="$(dirname "$theDir")/../include/covertcalculus/"
theDir="$(realpath "$theDir")"
find $theDir \( -name '*.cpp' -o -name '*.hpp' \) \
  -type f \
  -print0 \
| while IFS= read -r -d '' file; do
    echo "/// covertcalculus${file#"$theDir"}"
    cat "$file"
    echo
    echo
    echo
    echo
done
