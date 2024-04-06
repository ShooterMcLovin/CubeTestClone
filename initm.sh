#!/bin/bash

cd lib

if ([ -d "MLX42" ] && [ -z "$(ls -A MLX42)" ]) || [ ! -d "MLX42" ] ;then
    git clone https://github.com/codam-coding-college/MLX42.git
    echo "-- MLX Cloned"
else
    echo "-- MLX42 directory already exists, skipping cloning."
fi

