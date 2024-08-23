#!/bin/sh
set -e

# Ensure that autoreconf is installed
if ! [ -x "$(command -v autoreconf)" ]; then
  echo 'Error: autoreconf is not installed.' >&2
  exit 1
fi

# Run autoreconf to generate configuration files
autoreconf --install --force --warnings=all

echo "Configuration files have been generated. Now run './configure'."
