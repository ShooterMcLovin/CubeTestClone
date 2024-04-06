#!/bin/bash

cd
curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
brew install glfw
@echo "change LIBS := in the makefile for LIBS	:= $(LIBMLX)/build/libmlx42.a  -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -ldl -pthread -lm"